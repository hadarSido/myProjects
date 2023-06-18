#ifndef __LISTITR_H__
#define __LISTITR_H__
#include "list.h"
#define TRUE 1
#define FALSE 0
typedef void* ListItr;

/** 
 * @brief Get itertator to the list's beginning
 *
 * @params _list : list to return begin iterator, pointing at first element
 *                 or at the end if list is empty
 * @return iterator pointing at the list's beginning
 * @return null if the list is null
 */
ListItr ListItrBegin(const List* _list);

/** 
 * @brief Get itertator to the list end
 *
 * @params _list : list to return end iterator
 * @return an iterator pointing at the list's end
 * @return null if the list is null
 */
ListItr ListItrEnd(const List* _list);

/** 
 * @brief retruns none zero if _a and _b iterators refer to same node
 * @warning might be implemented as a macro
 * @return 1 if equals
 * @return 0 if not equals

 */
int ListItrEquals(const ListItr _a, const ListItr _b);

/** 
 * @brief Get itertator to the next element from a given iterator
 * @warning if _itr is end iterator it will be returned
 * @return an iterator pointing at the next element
 * @return null if the itr is null
 */
ListItr ListItrNext(ListItr _itr);

/** 
 * @brief Get itertator to the previous element
 * @warning if _itr is begin iterator it will be returned
 * @return an iterator pointing at the previous element
 * @return null if the itr is null
 */
ListItr ListItrPrev(ListItr _itr);

/** 
 * @brief Get data from the list node the iterator is pointing to
 * @params _itr : A list iterator
 * @return the data the iterator is pointing at or NULL if pointing to the end
 * @return null if the itr is null or if we are at the end of the list */
void* ListItrGet(ListItr _itr);

/** 
 * @brief Set data at the node where the iterator is pointing at
 * @params _itr : A list iterator
 * @params _itr : An element pointer
 * @return the data from the node to be changed
 * @return null if the itr is null, if the element pointer is null or if we are at the end of the list 
 */
void* ListItrSet(ListItr _itr, void* _element);

/** 
 * @brief Inserts a new node before node the iterator is pointing at
 * @params _itr : A list iterator
 * @params _itr : An element pointer
 * @return an iterator pointing at the element inserted 
 * @return NULL if itr or element are null or if alocation fail
 */
ListItr ListItrInsertBefore(ListItr _itr, void* _element);

/** 
 * @brief Removes the node the iterator is pointing at
 * @params _itr : A list iterator
 * @return NULL if itr or is null or if alocation fail or if list is empty
 * @return the pointer to the removed data
 */
void* ListItrRemove(ListItr _itr);

#endif /* __LISTITR_H__ */