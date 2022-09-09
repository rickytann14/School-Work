#include "LinkedList.h"

LinkedList::LinkedList(): m_pHead(NULL), m_pCurrent(NULL){
} //constructor

LinkedList::~LinkedList(){
  delete m_pNext; //deleting the head will cascade through the whole list
} //destructor

/// Run through the list until we find the list element containing
/// a certain item. If it's there, return a pointer to the previous
/// list element. (If there are duplicates, use the first one.) 
/// \param n [IN] Item to find.
/// \param prev [OUT] Pointer to previous list element. NULL if there is none.
/// \return true if n is in the list.

bool LinkedList::Find(const int n, LinkedListElement*& prev){
  LinkedListElement* p = m_pHead; //start at the head
  if(p == NULL)return false; //bail if the list is empty
  prev = NULL; //pointer to previous item

  while(p->m_nData != n && p->m_pNext != NULL){ //advance until we find n
    prev = p; //maintain the prev pointer
    p = p->m_pNext; //advance p
  } //while

  return p->m_nData == n; //have we found n?
} //Find

/// Find an item using the private Find function to do the heavy lifting.
/// \param n [IN] Item to find.
/// \return true if n is in the list.

bool LinkedList::Find(const int n){

  // YOUR CODE GOES HERE <----------------------------------------------------------------------------------
  LinkedListElement* p;//temp pointer
  return Find(n, p)
} //Find

/// Insert an item at the head of the list. Duplicates are allowed.
/// \param n [IN] Item to insert.

void LinkedList::Insert(const int n){
  
  // YOUR CODE GOES HERE <----------------------------------------------------------------------------------
  LinkedListElement* p = m_pHead;
  m_pHead = new LinkedListElement(n);
  m_pHead->m_pNext = p;

} //Insert

/// To delete an item, first you've got to find it. Then you've
/// got to unlink it. We need a pointer to the previous list element
/// in order to do that. Of course, we've got to do something different
/// for the first element of the list. (If there are duplicates, use the first one.) 
/// \param n [IN] Item to delete.

bool LinkedList::Delete(const int n){
  
  // YOUR CODE GOES HERE <----------------------------------------------------------------------------------
    LinkedListElement* prev; //pointer to previous item
    if(Find(n, prev)){ //if there, grab pointer to prev
         LinkedListElement* trash; //list element to be trashed
         if(prev == nullptr){ //it's at the head of the list
              if(m_pCurrent == m_pHead) //maintain current
                    m_pCurrent = m_pHead->m_pNext;
              trash = m_pHead;
              m_pHead = m_pHead->m_pNext; //advance the head
         } //if
         else{ //it's not at the head of the list
              if(m_pCurrent == prev->m_pNext) //maintain current
                      m_pCurrent = prev->m_pNext->m_pNext;
              LinkedListElement* trash = prev->m_pNext; //trash
              prev->m_pNext = trash->m_pNext; //unlink trash
          } //else
      trash->m_pNext = nullptr; //unlink trash
      delete trash; //delete trash

      found = true;
    } //if
   
    return found;
} //Delete
/// Check if the list is empty by looking at the head pointer to see if it is NULL.
/// \return true if list is empty.

bool LinkedList::isEmpty(){

  // YOUR CODE GOES HERE <----------------------------------------------------------------------------------
  return m_pHead == nullptr
} //isEmpty

/// Find the number of items in the list by going through
/// all of them, counting as we go.
/// \return The number of items in the list.

int LinkedList::Length(){
  int i=0;
  if(!isEmpty())
    for(LinkedListElement* p=m_pHead; p!=NULL; p=p->m_pNext)i++;
  return i; 
} //Length

////////////////////////////////////////////////////////////////////////////////////////////////////
//List iterator functions.

/// \return true if the list is empty.

bool LinkedList::Head(){
  m_pCurrent = m_pHead;
  return m_pCurrent != NULL;
} //Head

/// \return true for success.

bool LinkedList::Next(){
  if(m_pCurrent != NULL){
} //constructor

LinkedList::~LinkedList(){
  delete m_pHead; //deleting the head will cascade through the whole list
} //destructor

/// Run through the list until we find the list element containing
/// a certain item. If it's there, return a pointer to the previous
/// list element. (If there are duplicates, use the first one.) 
/// \param n [IN] Item to find.
/// \param prev [OUT] Pointer to previous list element. NULL if there is none.
/// \return true if n is in the list.

bool LinkedList::Find(const int n, LinkedListElement*& prev){
  LinkedListElement* p = m_pHead; //start at the head
  if(p == NULL)return false; //bail if the list is empty
  prev = NULL; //pointer to previous item

  while(p->m_nData != n && p->m_pNext != NULL){ //advance until we find n
    prev = p; //maintain the prev pointer
    p = p->m_pNext; //advance p
  } //while

  return p->m_nData == n; //have we found n?
} //Find

