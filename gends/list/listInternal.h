#ifndef __LISTINTERNAL_H__
#define __LISTINTERNAL_H__
#include "list.h"
#include "listItr.h"
#include "listitrfun.h"

struct Node
{
	void* m_data;
	Node* m_next;
	Node* m_prev;
};

struct List
{
	Node m_head;
	Node m_tail;
};

void InsertNode(Node* _p , Node* _t);
void RemoveNode(Node* _t);
Node* CreatNode(void* _item);


#endif /* __LISTINTERNAL_H__*/

