/// \file LinkedList.h

#pragma once

#include "LinkedListElement.h"

/// \brief Linked list of integers.
///
/// This linked list chains together a collection of ListElements.
/// In addition to some of the traditional list operations,
/// it also includes functions that can be used to implement an iterator,
/// that is, a thing that can be used to iterate through all of the
/// members of the list.

class LinkedList{
  private:
    LinkedListElement* m_pHead; ///< Pointer to head element.
    LinkedListElement* m_pCurrent; ///< Pointer to current element for iterator.

    bool Find(const int n, LinkedListElement*& prev); ///< Find previous item in list.

  public:
    LinkedList(); ///< Constructor.
    ~LinkedList(); ///< Destructor.

    bool Find(const int n); ///< Find an item.
    void Insert(const int n); ///< Insert item in list.
    bool Delete(const int n); ///< Delete item from list.
    bool isEmpty(); ///< Check for empty list.
    int Length(); ///< Number of items in list.

    //Iterator functions
    bool Head(); ///< Reset iterator to head of list.
    bool Next(); ///< Advance iterator to next item in list.
    bool Get(int& n); ///< Get item from current iterator.
    bool Last(); ///< Check whether iterator is at last item.
}; //LinkedList