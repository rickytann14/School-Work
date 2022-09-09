/// \file LinkedListElement.cpp

#include "LinkedListElement.h"

/// Construct a list element with a given data value and
/// a NULL pointer to the next list element.
/// \param n Value to be stored in the data field m_nData.

LinkedListElement::LinkedListElement(const int n): m_nData(n), m_pNext(NULL){
} //constructor

/// Calling this destructor on the head of a list will
/// cascade through the whole list.

LinkedListElement::~LinkedListElement(){
  delete m_pNext;
} //destructor
