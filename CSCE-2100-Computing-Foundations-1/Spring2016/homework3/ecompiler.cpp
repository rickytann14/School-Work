/// \file ecompiler.cpp

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>

#include "ecompiler.h"
#include "defines.h"

/// Output strings for compiler error codes.

char const* g_pCompilerErrcodeTable[CERR_NUMCODES] = {
  "Syntax error",
  "Unexpected symbol",
  "Malformed expression"
}; //g_pCompilerErrcodeTable

CExpression::CExpression(): 
  m_strBuffer(NULL), m_nCurChar(0), m_pExpressionTree(NULL){
} //constructor

/////////////////////////////////////////////////////////////////////////////////////////////
//Helper functions

/// Test that a character is numeric.
/// \param c Character to be tested
/// \return true if character is numeric

bool isNumeric(const char c){
  return c >= '0' && c <= '9';
} //isNumeric

/// Test that a character is white space.
/// \param c Character to be tested
/// \return true if character is white space

bool isWhitespace(const char c){
  return c == ' ' || c =='\t';
} //isWhitespace

/////////////////////////////////////////////////////////////////////////////////////////////
//Lexical analyzer functions

/// Get next symbol (at index m_nCurChar) from m_strBuffer into m_eSymbol.
/// \return true if there is an error.

bool CExpression::getsym(){
  bool error = false;

  //skip white space
  while(m_nCurChar < (int)strlen(m_strBuffer) && isWhitespace(m_strBuffer[m_nCurChar]))
    m_nCurChar++;

  if(m_nCurChar >= (int)strlen(m_strBuffer)) //overflow
    m_eSymbol = eNullSymbol;

  else{ //normal case, no overflow
    char c = m_strBuffer[m_nCurChar]; //shorthand for current character

    if(isNumeric(c)){ //first character is a digit
      m_eSymbol = eNumberSymbol; //it's going to be a number
      error = getnumber(); //get the rest of it
    } //if

    else{ //single character symbols
      switch(c){
        case '(': m_eSymbol = eLParenSymbol; break;     
        case ')': m_eSymbol = eRParenSymbol; break;
        case '*': m_eSymbol = eMultSymbol; break;
        case '/': m_eSymbol = eDivSymbol; break;    
        case '+': m_eSymbol = eAddSymbol; break; 
        case '-': m_eSymbol = eSubtractSymbol; break;
      } //switch
      m_nCurChar++; //ready for next character
    } //else
  } //else

  return error;
} //getsym

/// Get a number.
/// Assumes that m_strBuffer[m_nCurChar] is a digit. 
/// Reads the unsigned number starting there into m_nNumber.
/// \retun true is the number is larger than an unsigned int can hold.

bool CExpression::getnumber(){
  m_nNumber = 0;
  do{
    m_nNumber = m_nNumber*10 + m_strBuffer[m_nCurChar] - '0';
    m_nCurChar++;
  }while(m_nNumber < 0xFFFFFFFF/10 && m_nCurChar < (int)strlen(m_strBuffer) && isNumeric(m_strBuffer[m_nCurChar]));

  return m_nCurChar <= (int)strlen(m_strBuffer) && isNumeric(m_strBuffer[m_nCurChar]); //error if there are digits left
} //getnumber


/////////////////////////////////////////////////////////////////////////////////////////////
//LL(1) recursive descent parser for arithmetic expressions.

void CExpression::error(const eCompilerErrCode e){
  printf("%s\n", m_strBuffer);
  for(int i=0; i<m_nCurChar; i++)
    putchar(' ');
  printf("^ %s\n", g_pCompilerErrcodeTable[e]);
} //error

/// Accept a symbol.
/// If the current symbol is s, then skip to the next one and return true. Otherwise return false.
/// \param s Expected symbol
/// \return true if m_eSymbol == s

bool CExpression::accept(const eLexSymbol s){
  if(m_eSymbol != s)return false;
  if(getsym())return false;
  return true;
} //accept

/// Expect a symbol.
/// Same as function accept, but throw an error if it fails.
/// \param s Expected symbol
/// \return true if m_eSymbol == s

bool CExpression::expect(const eLexSymbol s){
  if(accept(s))return true;
  error(CERR_UNEXPECTEDSYMBOL);
  return false;
} //expect

/// Recursive descent function to process a factor.
/// \return true if there was an error

bool CExpression::factor(ETreeNode*& tree){
  bool bError = false;

  if(accept(eNumberSymbol))
    tree = new ETreeNode(m_nNumber);
  else if(accept(eLParenSymbol))
    bError = expression(tree) || !expect(eRParenSymbol);
  else{
    error(CERR_SYNTAX);
    bError = true;
    getsym();
  } //else
  
  return bError;
} //factor

/// Recursive descent function to process a term.
/// \return true if there was an error

bool CExpression::term(ETreeNode*& tree){
  ETreeNode* lchild = NULL;
  ETreeNode* rchild = NULL;
  bool bError = factor(lchild);
  tree = lchild;

  while(!bError && (m_eSymbol == eMultSymbol || m_eSymbol == eDivSymbol)){

    char opchar='\0';
    switch(m_eSymbol){
      case eMultSymbol: opchar = '*'; break;
      case eDivSymbol:  opchar = '/'; break;
      default: printf("Operator error %d\n", m_eSymbol);
    } //switch
    
    bError = getsym();
    if(!bError){
      bError = factor(rchild);
      lchild = tree = new ETreeNode(opchar, lchild, rchild);
    } //if
  } //while
  
  return bError;
} //term

/// Recursive descent function to process an expression.
/// \return true if there was an error

bool CExpression::expression(ETreeNode*& tree){
  ETreeNode* lchild = NULL;
  ETreeNode* rchild = NULL;
  bool bError = false;

  if(m_eSymbol == eAddSymbol || m_eSymbol == eSubtractSymbol)
    bError = getsym();

  if(!bError){
    bError = term(lchild);
    tree = lchild;
  } //if

  while(!bError && (m_eSymbol == eAddSymbol || m_eSymbol == eSubtractSymbol)){
    eLexSymbol op = m_eSymbol;
    bError = getsym();
    if(!bError){
      bError = term(rchild);
      if(op == eAddSymbol)
        tree = new ETreeNode('+', lchild, rchild);
      else if(op == eSubtractSymbol)
        tree = new ETreeNode('-', lchild, rchild);
      lchild = tree;
    } //if
  } //while
  
  return bError;
} //expression

/// Parse a string containing an arithmetic expression.
/// \param mathstring String containing the expression
/// \return true if there was an error

bool CExpression::parse(const char* mathstring){
  m_strBuffer = new char[strlen(mathstring) + 1]; //make space for local copy of string
  strcpy(m_strBuffer, mathstring); //copy it over
  m_nCurChar = 0; //start of string
  delete m_pExpressionTree; //get rid of old tree
  getsym(); //get the first symbol to prime the pump

  bool bError = expression(m_pExpressionTree); //parse the arithmetic expression

  if(m_nCurChar != strlen(m_strBuffer) || m_eSymbol != eNullSymbol){ //check for errors
    error(CERR_MALFORMED);
    bError = true;
  } //if

  delete [] m_strBuffer; //done with the local copy of the string
  return bError;
} //parse

/// \brief Convert expression tree to prefix expression.
/// \param s String to put prefix expression into.
/// \param len Maximum length of that string.
/// \return true if there is an error.

bool CExpression::prefix(char* s, const int len){
  bool error = false;
  int n = 0;
  s[0] = '\0';
  if(m_pExpressionTree)
    error = m_pExpressionTree->preorder(s, n, len);
  return error;
} //prefix

/// \brief Convert expression tree to postfix expression.
/// \param s String to put postfix expression into.
/// \param len Maximum length of that string.
/// \return true if there is an error.

bool CExpression::postfix(char* s, const int len){
  bool error = false;
  int n = 0;
  s[0] = '\0';
  if(m_pExpressionTree)
    error = m_pExpressionTree->postorder(s, n, len);
  return error;
} //postfix

/// \brief Convert expression tree to fully parenthesized infix expression.
/// \param s String to put infix expression into.
/// \param len Maximum length of that string.
/// \return true if there is an error.

bool CExpression::infix(char* s, const int len){
  bool error = false;
  int n = 0;
  s[0] = '\0';
  if(m_pExpressionTree)
    error = m_pExpressionTree->inorder(s, n, len);
  return error;
} //infix

