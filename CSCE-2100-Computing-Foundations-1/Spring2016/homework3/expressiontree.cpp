/// \file expressiontree.cpp

#include <stdio.h>
#include <string.h>

#include "expressiontree.h"
#include "defines.h"

/////////////////////////////////////////////////////////////////////////////////////////////////////////
//Constructors and destructors

ETreeNode::ETreeNode(char op, ETreeNode* lchild, ETreeNode* rchild):
  m_bIsOperator(true), m_chOp(op), m_pLeftChild(lchild), m_pRightChild(rchild){
} //constructor

ETreeNode::ETreeNode(unsigned int val):
  m_bIsOperator(false), m_nValue(val), m_pLeftChild(NULL), m_pRightChild(NULL){
} //constructor

ETreeNode::~ETreeNode(){
  delete m_pLeftChild;
  delete m_pRightChild;
} //destructor

/////////////////////////////////////////////////////////////////////////////////////////////////////////
//Tree traversal functions

/// \brief Preorder traversal.
/// Perform a preorder traversal starting at the current node
/// and append the result to a string.
/// \param s String to append result of traversal to.
/// \param n Length of s.
/// \param len Maximum length of s.
/// \return false if the postfix expression fits into s, otherwise true.

bool ETreeNode::preorder(char* s, int& n, const int len){
  bool error = false;

  //YOUR CODE GOES HERE
	//BEGIN HINT  
  if(m_bIsOperator){ //operator node
    s[n++] = m_chOp; //append operator character to s
    s[n++] = '\0'; //zero terminator
  } //if
  else{ //number node
    char buffer[32]; //temporary character buffer
    sprintf(buffer, "%d", m_nValue); //print number into buffer
    strcat((char*)(s + n), buffer); //append buffer to s
  } //else
  //END HINT

/*  string c[s+n];
  c = s;*/
  printf("%s", s);
  s = s -> m_pLeftChild();
  while(s != NULL){
    preorder(s, n, len);
    s = s -> m_pRightChild();
  return error;
} //preorder

/// \brief Postorder traversal.
/// Perform a postorder traversal starting at the current node
/// and append the result to a string.
/// \param s String to append result of traversal to.
/// \param n Length of s.
/// \param len Maximum length of s.
/// \return false if the postfix expression fits into s, otherwise true

bool ETreeNode::postorder(char* s, int& n, const int len){
  bool error = false;

  //YOUR CODE GOES HERE
        //BEGIN HINT
  if(m_bIsOperator){ //operator node
    s[n++] = m_chOp; //append operator character to s
    s[n++] = '\0'; //zero terminator
  } //if
  else{ //number node
    char buffer[32]; //temporary character buffer
    sprintf(buffer, "%d", m_nValue); //print number into buffer
    strcat((char*)(s + n), buffer); //append buffer to s
  } //else
  //END HINT

  return error;
} //postorder

/// \brief Inorder traversal.
/// Perform a inorder traversal starting at the current node
/// and append the result to a string. Fully parenthesize while you're doing it.
/// \param s String to append result of traversal to.
/// \param n Length of s.
/// \param len Maximum length of s.
/// \return false if the postfix expression fits into s, otherwise true.

bool ETreeNode::inorder(char* s, int& n, const int len){
  bool error = false;

  //YOUR CODE GOES HERE
  
  return error;
} //inorder
