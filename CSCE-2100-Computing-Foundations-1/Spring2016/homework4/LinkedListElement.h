/// \file LinkedListElement.h

#pragma once

#include <stddef.h>

/// \brief List element.
///
/// The list element consists of an integer value and
/// a pointer to the next list element. Make sure that the
/// destructor gets run only for the first element of a list.

class LinkedListElement{
  friend class LinkedList;

  private:
    int m_nData; ///< Item in list element.
    LinkedListElement* m_pNext; ///< Pointer to next list element.
  
  public:
    LinkedListElement(const int n); ///< Constructor.
    ~LinkedListElement(); ///< Destructor. 
}; //LinkedListElement
