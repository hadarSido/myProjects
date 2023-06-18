#include <stdio.h> /*printf*/
#include <stdlib.h> /*malloc*/
#include <stddef.h> /*size_t*/
#include "list.h" /*functions decleration*/
#include "listInternal.h" /*stracts decleration*/

/*********************help Functions*****************************/
void InsertNode(Node* _p , Node* _t);
void RemoveNode(Node* _t);
Node* CreatNode(void* _item);
int ListIsEmpty(List* _list);
/*******************************************************************/
List* ListCreate(void)
{
	List *ptrList;
	if(NULL == (ptrList = (List*)malloc(sizeof(List))))
	{
		return NULL;
	}
	(ptrList -> m_head).m_next = &(ptrList -> m_tail);
	(ptrList -> m_head).m_prev = &(ptrList -> m_head);
	(ptrList -> m_tail).m_next = &(ptrList -> m_tail);
	(ptrList -> m_tail).m_prev = &(ptrList -> m_head);
	return ptrList;
}

void ListDestroy(List** _pList, void (*_elementDestroy)(void* _item))
{
	Node* node;
	register Node* tail;
	if (NULL == _pList || NULL == *_pList )
	{
		return;
	}
	node = (*_pList) -> m_head.m_next;
	tail =  &((*_pList) -> m_tail);
	while(node != tail)
	{
		if(NULL != _elementDestroy)
		{
			_elementDestroy(node ->  m_data);
		}
		node = node -> m_next;
		free(node -> m_prev);
	}
	free(*_pList);
	*_pList = NULL;
}

ListResult ListPushHead(List* _list, void* _item)
{
	Node* ptrNode = NULL;
	if(NULL == _item)
	{
		return LIST_NULL_ELEMENT_ERROR;
	}
	if(NULL == _list)
	{
		return LIST_UNINITIALIZED_ERROR;
	}
	ptrNode = CreatNode(_item);
	if(NULL == ptrNode)
	{
		return LIST_ALLOCATION_ERROR;
	}
	InsertNode(ptrNode, (_list -> m_head).m_next);
	return LIST_SUCCESS;
}

ListResult ListPushTail(List* _list, void* _item)
{
	Node* ptrNode = NULL;
	if(NULL == _item)
	{
		return LIST_NULL_ELEMENT_ERROR;
	}
	if(NULL == _list)
	{
		return LIST_UNINITIALIZED_ERROR;
	}
	ptrNode = CreatNode(_item);
	if(NULL == ptrNode)
	{
		return LIST_ALLOCATION_ERROR;
	}
	InsertNode(ptrNode, &(_list -> m_tail));
	return LIST_SUCCESS;
}

ListResult ListPopHead(List* _list, void** _pItem)
{
	Node* ptrNode = NULL;
	if(NULL == _pItem)
	{
		return LIST_NULL_ELEMENT_ERROR;
	}
	if(NULL == _list)
	{
		return LIST_UNINITIALIZED_ERROR;
	}
	if(ListIsEmpty(_list) == TRUE)
	{
		return LIST_IS_EMPTY_ERROR;
	}
	*_pItem = (_list -> m_head).m_next -> m_data;
	RemoveNode((_list -> m_head).m_next);
	return LIST_SUCCESS;
}


ListResult ListPopTail(List* _list, void** _pItem)
{
	Node* ptrNode = NULL;
	if(NULL == _pItem)
	{
		return LIST_NULL_ELEMENT_ERROR;
	}
	if(NULL == _list)
	{
		return LIST_UNINITIALIZED_ERROR;
	}
	if(ListIsEmpty(_list) == TRUE)
	{
		return LIST_IS_EMPTY_ERROR;
	}
	*_pItem = (_list -> m_tail).m_prev -> m_data;
	RemoveNode((_list -> m_tail).m_prev);
	return LIST_SUCCESS;
}

size_t ListSize(const List* _list)
{
	Node* i;
	size_t count = 0;
	if(NULL == _list)
	{
		return 0;
	}
	for(i = _list -> m_head.m_next ; i !=  &(_list -> m_tail) ; i = i -> m_next)
	{
		count+=1;
	}
	return count;
}

/***********************help Push functions***********************/
Node* CreatNode(void* _item)
{
	Node* ptrNode = NULL;
	if(NULL == (ptrNode = (Node*)malloc(sizeof(Node))))
	{
		return NULL;
	}
	ptrNode -> m_data = _item;
	return ptrNode;
}

void InsertNode(Node* _p , Node* _t)
{
	_p-> m_prev = _t -> m_prev;
	_p -> m_next = _t ;
	_t-> m_prev -> m_next = _p;
	_t-> m_prev = _p;
}

/***********************help Pop functions***********************/

void RemoveNode(Node* _t)
{
	_t -> m_next -> m_prev = _t -> m_prev;
	_t -> m_prev -> m_next = _t -> m_next;
	free(_t);
}

int ListIsEmpty(List* _list)
{
	if(_list == NULL)
	{
		return TRUE;
	}
	if(_list -> m_head.m_next == &(_list -> m_tail))
	{
		return TRUE;
	}
	return FALSE;
}

/******************get functions****************************
Node* GetHeadNext(List *_list)
{
	return _list -> m_head.m_next;
}
Node* GetTailPrev(List *_list)
{
	return _list -> m_tail.m_prev;
}
Node* GetHeadPrev(List *_list)
{
	return _list -> m_head.m_prev;
}
Node* GetTailNext(List *_list)
{
	return _list -> m_tail.m_next;
}
void* GetTail(List* _list)
{
	return &_list -> m_tail;
}
void* GetHead(List* _list)
{
	return &_list -> m_head;
}
/*****************************************************************/