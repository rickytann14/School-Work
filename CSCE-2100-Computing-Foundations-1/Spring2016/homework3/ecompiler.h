/// \file ecompiler.h
///
/// \brief Header file for class CExpression.

#pragma once

#include "expressiontree.h"

enum eCompilerErrCode{ ///< Compiler error code.
  CERR_SYNTAX, CERR_UNEXPECTEDSYMBOL, CERR_MALFORMED,
  CERR_NUMCODES //MUST BE LAST
}; //eCompilerErrCode

enum eLexSymbol{ ///< Lexicographic symbols for lexical analyzer.
  eNullSymbol, eNumberSymbol, eLParenSymbol, eRParenSymbol, 
  eMultSymbol, eDivSymbol, eAddSymbol, eSubtractSymbol
}; //eLexSymbol

/// \brief Expression class CExpression.
///
/// CExpression includes a lexical analyzer and a recursive descent LL(1)
/// parser for arithmetic expressions.

class CExpression{
  private:
    //Lexical Analysis stuff.
    char* m_strBuffer; ///< Character string containing an arithmetic expression to be parsed.
    int m_nCurChar; ///< Index of current character from m_strBuffer.
    eLexSymbol m_eSymbol; ///< Current lexicographic symbol.
    unsigned int m_nNumber; ///< Current number parsed, if there is one.
    
    bool getsym(); ///< Get next lexicographic symbol into m_eSymbol.
    bool getnumber(); ///< Get next number into m_nNumber.  

    //Parsing stuff.
    void error(const eCompilerErrCode e); ///< Error processing.
    bool accept(const eLexSymbol s); ///< Skip over a particular kind of symbol.
    bool expect(const eLexSymbol s); ///< Verify that a symbol is next.

    bool factor(ETreeNode*& tree); ///< Process a factor of the LL(1) grammar.
    bool term(ETreeNode*& tree);  ///< Process a term of the LL(1) grammar.
    bool expression(ETreeNode*& tree);  ///< Process a expression of the LL(1) grammar.

    //Expression tree stuff
    ETreeNode* m_pExpressionTree; ///< Pointer to the root node of an expression tree.

  public:
    CExpression(); ///< Constructor.
    bool parse(const char* mathstring); ///< Parse the string into an expression tree.
    bool prefix(char* s, const int len); ///< Convert the expression to prefix order.
    bool postfix(char* s, const int len); ///< Convert the expression to postfix order.
    bool infix(char* s, const int len); ///< Convert the expression to fully parenthesized infix order.
}; //CExpression