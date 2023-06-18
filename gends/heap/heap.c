#include <stdio.h> /*printf, NULL*/
#include <stdlib.h> /*malloc*/
#include <stddef.h> /*size_t*/
#include "vector.h" /*vector functions decleration*/
#include "genHeap.h" /*generic heap functions decleration*/
#define LEFT_SON(_index)(_index *2+1) 
#define IS_LEAF(_heap, _index)(LEFT_SON(_index) >=_heap -> m_heapSize)
#define RIGHT_SON(_index)(_index *2+2) 
#define HAS_RIGHT(heap,i)((2*(i)+2)<heap->m_heapSize)
#define FATHER(heap)((heap->m_heapSize-1)/2)

struct Heap
{
	Vector* m_vec;
	size_t m_heapSize;
	LessThanComparator m_cFunc;
};

/*********************help Functions*****************************/ 
static size_t FindNewHead(Heap* _heap ,size_t  _index);
static void Heapify(Heap* _heap , int _index);
static void Swap(Heap* _heap, void* _father, void* _son, size_t _ifather, size_t _iSon);
static void BubbleUp(Heap* _heap, size_t _index);
/*****************************************************************/

Heap* HeapBuild(Vector* _vector, LessThanComparator _pfLess)
{
	Heap* ptrHeap;
	size_t i, heapSize, smallFather;
	if (NULL == _vector || NULL == _pfLess )
	{
		return NULL;
	}
	if(NULL == (ptrHeap = (Heap*)malloc(sizeof(Heap))))
	{
		return NULL;
	}
	ptrHeap -> m_vec = _vector;
	ptrHeap -> m_heapSize = VectorSize(_vector);
	ptrHeap -> m_cFunc = _pfLess;

	if(ptrHeap -> m_heapSize > 1)
	{
		smallFather = (ptrHeap -> m_heapSize -1)/2; /*add marco function to father*/
		for(i = smallFather ; i > 0 ; --i)
		{
			Heapify(ptrHeap, smallFather);
		}
		Heapify(ptrHeap, 0);
	}
	return ptrHeap;
}

/********************************************************************************/
Vector* HeapDestroy(Heap** _heap)
{
	Vector* ptrVec;
	if (NULL == _heap || NULL == *_heap )
	{
		return NULL;
	}
	ptrVec = (*_heap) -> m_vec;
	free(*_heap);
	return ptrVec;
}
/*********************************************************************************/
HeapResultCode HeapInsert(Heap* _heap, void* _element)
{
	size_t index;
	size_t vectorSize;
	if (NULL == _heap || NULL == _element)
	{
		return HEAP_NOT_INITIALIZED;
	}
	if(VECTOR_SUCCESS != VectorAppend(_heap -> m_vec, _element)) 
	{
		return HEAP_VECTOR_APPEND_ERROR;
	}
	BubbleUp(_heap, _heap -> m_heapSize);
	(_heap -> m_heapSize)++;
	return HEAP_SUCCESS;
}
/****************************************************************************/
const void* HeapPeek(const Heap* _heap) /*const hear meen to protect the value not the pointer*/
{
	void* topElement;
	if (NULL ==_heap || 0 == _heap -> m_heapSize)
	{
		return NULL;
	}
	VectorGet(_heap -> m_vec, 0, &topElement);
	return topElement;
}
/***************************************************************************/

void* HeapExtract(Heap* _heap)
{
	void* extractElement;
	void* topElement;
	if (NULL == _heap || 0 == _heap -> m_heapSize)
	{
		return NULL;
	}
	VectorGet(_heap -> m_vec, 0, &topElement); /*save the first element*/
	VectorRemove(_heap -> m_vec, &extractElement); /*delet the last elemant and save it in 'extractElement'*/
	(_heap -> m_heapSize)--;
	if(_heap -> m_heapSize > 0 )
	{
		VectorSet(_heap -> m_vec, 0, extractElement); /*put the last element in the head of the list*/
		Heapify(_heap , 0);
	}
	return topElement;
}
/**************************************************************************/
size_t HeapSize(const Heap* _heap)
{
	if (NULL == _heap )
	{
		return 0;
	}
	return _heap -> m_heapSize; 
}
/**********************************************************************************/
size_t HeapForEach(const Heap* _heap, ActionFunction _act, void* _context)
{
	size_t size, i = 0;
	void* data = NULL;
	if(NULL == _heap || NULL == _act)
	{
		return 0;
	}
	size = HeapSize(_heap);
	for(i = 0; i < size -1 ; ++i)
	{
		VectorGet(_heap -> m_vec, i, &data);
		if(0 == _act(data , _context))
		{
			break;
		}
	}
	return i;	
}

/**************************************hepify -help*****************************************/
static void Heapify(Heap* _heap , int _index)
{
	void* fatherVal;
	void* sonVal;
	size_t newHead;
	if(IS_LEAF(_heap, _index))
	{
		return;
	}
	newHead = FindNewHead(_heap, _index);
	if(newHead == _index)
	{
		return;
	}
	VectorGet(_heap -> m_vec, newHead, &sonVal);
	VectorGet(_heap -> m_vec, _index, &fatherVal);
	Swap(_heap, fatherVal, sonVal, _index, newHead);
	Heapify(_heap, newHead);
}

static void Swap(Heap* _heap, void* _father, void* _son, size_t _ifather, size_t _iSon)
{
	VectorSet(_heap -> m_vec, _iSon, _father);
	VectorSet(_heap -> m_vec, _ifather, _son);
}

static size_t FindNewHead(Heap* _heap ,size_t  _index)
{
	void* rightVal;
	void* leftVal;
	void* fatherVal;
	void* newHeadVal; 
	size_t newHead = _index;
	VectorGet(_heap -> m_vec, _index, &fatherVal);
	VectorGet(_heap -> m_vec, LEFT_SON(_index), &leftVal);
	newHeadVal = fatherVal;
	if(TRUE == _heap -> m_cFunc(fatherVal, leftVal)) /*TRUE- the father is smaller than the left - need to swap left and right*/
	{
		newHead = LEFT_SON(_index); /*left son index*/
	}
	if(HAS_RIGHT(_heap, _index))
	{
		VectorGet(_heap -> m_vec, newHead, &newHeadVal);
		VectorGet(_heap -> m_vec, RIGHT_SON(_index), &rightVal);
		if(_heap -> m_cFunc(newHeadVal, rightVal) == TRUE)
		{
			newHead = RIGHT_SON(_index);
		}
	}
	return newHead;
}
/****************************************************************************************/

static void BubbleUp(Heap* _heap, size_t _index)
{
	void* father;
	void* son;
	size_t iFather;
	if (_index == 0)
	{
		return;
	}
	iFather = (_index - 1)/2;
	VectorGet(_heap -> m_vec, iFather, &father);
	VectorGet(_heap -> m_vec, _index, &son);
	if(TRUE == _heap -> m_cFunc(father, son))
	{
		Swap(_heap, father, son, iFather, _index);
		BubbleUp(_heap, iFather);
	}
}

/*****************************************************************************************/