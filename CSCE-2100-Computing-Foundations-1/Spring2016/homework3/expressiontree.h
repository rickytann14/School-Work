/// \file expressiontree.h
/// \brief Header file for expression tree.

#pragma once

/// \brief Structure for a node in an expression tree.
/// Each node can represent an operator or a number.
/// If it is an operator, m_bIsOperator is true, m_chOp is
/// a character representing an operator, and m_pLeftChild and
/// m_pRightChild point to the operands. If it is a number,
/// m_bIsOperator is false and m_nValue contains the value.

class ETreeNode{
  private:
    char m_chOp; ///< Character representing an operator.
    unsigned int m_nValue; ///< A number.
    bool m_bIsOperator; ///< Whether this node represents an operator.

    ETreeNode* m_pLeftChild; ///< Pointer to left child.
    ETreeNode* m_pRightChild; ///< Pointer to right child.

  public:
    ETreeNode(char op, ETreeNode* lchild, ETreeNode* rchild); ///< Constructor for operator node.
    ETreeNode(unsigned int val); ///< Constructor for number node.
    ~ETreeNode(); ///< Destructor.

    bool preorder(char* s, int& n, const int len); ///< Preorder traversal.
    bool postorder(char* s, int& n, const int len); ///< Postorder traversal.
    bool inorder(char* s, int& n, const int len); ///< Inorder traversal.
}; //ETreeNode