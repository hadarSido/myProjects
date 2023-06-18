#include <stdio.h> /*printf*/
#include <stdlib.h> /*malloc*/
#include <stddef.h> /*size_t*/
#include "vector.h" /*vector functions decleration*/
#define DECLER_FACTOR 2

static VectorResult ReallocCheckToRaise(Vector* _vector);
static VectorResult ReallocCheckToReduce(Vector* _vector);

struct Vector
{
    void**  m_items;
    size_t  m_originalSize;	
    size_t  m_size;
    size_t  m_nOfItems;
    size_t  m_blockSize;
};

Vector* VectorCreate(size_t _initialCapacity, size_t _blockSize)
{
	void** pItems=NULL;
	Vector* ptrVector=NULL;
	if(0 == _initialCapacity && 0 == _blockSize)
	{
		return NULL;
	}
	if(NULL == (ptrVector = (Vector*)malloc(sizeof(Vector))))
	{
		return NULL;
	}
	if(NULL == (pItems = (void**)malloc(_initialCapacity*sizeof(void*))))
	{
		free(ptrVector);
		return NULL;
	}
	ptrVector -> m_items = pItems ;
	ptrVector -> m_originalSize = _initialCapacity ; /*we do not want to go ender this size so we decler it in the original size and size*/
	ptrVector -> m_size = _initialCapacity ;
	ptrVector -> m_nOfItems = 0;
	ptrVector -> m_blockSize = _blockSize;
	
	return ptrVector; 
}

void VectorDestroy(Vector** _vector, void (*_elementDestroy)(void* _item))
{
	size_t i, size;
	if (NULL == _vector || NULL == *_vector)
	{
		return;
	}
	if(NULL != _elementDestroy)
	{
		size = (*_vector) -> m_nOfItems;
		for(i = 0; i < size ; ++i)
		{
			_elementDestroy((*_vector) -> m_items[i]);
		}
	}
	free((*_vector) -> m_items);
	free(*_vector);
	*_vector = NULL;
}

VectorResult VectorAppend(Vector* _vector, void* _item)
{
	if(NULL == _vector || NULL == _item)
	{
		return VECTOR_NOT_INITIALIZED;
	}
	if (VECTOR_SUCCESS != ReallocCheckToRaise(_vector))
	{
		return VECTOR_OVERFLOW;
	}
	_vector -> m_items [_vector -> m_nOfItems] = _item;
	(_vector -> m_nOfItems) ++;
	
	return VECTOR_SUCCESS;
}

VectorResult VectorRemove(Vector* _vector, void** _pValue)
{
	if(NULL == _vector || NULL == _pValue)
	{
		return VECTOR_NOT_INITIALIZED;
	}
	if(0 == _vector -> m_nOfItems)
	{
		return VECTOR_UNDERFLOW; 
	}
	*_pValue = _vector -> m_items [_vector -> m_nOfItems-1];
	(_vector -> m_nOfItems) -- ;
	ReallocCheckToReduce(_vector);
	return VECTOR_SUCCESS;
}

VectorResult VectorGet(const Vector* _vector, size_t _index, void** _pValue)
{
	if(NULL == _vector || NULL == _pValue)
	{
		return VECTOR_NOT_INITIALIZED;
	}
	if(_index >= (_vector -> m_nOfItems))
	{
		
		return VECTOR_INDEX_OUT_OF_BOUNDS_ERROR;
	}
	*_pValue =  _vector -> m_items [_index];
	return VECTOR_SUCCESS;
}

VectorResult VectorSet(Vector* _vector, size_t _index, void*  _value)
{
	if(NULL == _vector || NULL == _value)
	{
		return VECTOR_NOT_INITIALIZED;
	}
	if(_index >= ( _vector -> m_nOfItems))
	{
		return VECTOR_INDEX_OUT_OF_BOUNDS_ERROR;
	}
	_vector -> m_items[_index] = _value;
	return VECTOR_SUCCESS;
}

size_t VectorSize(const Vector* _vector)
{
	if(NULL == _vector)
	{
		return 0;
	} 
	return _vector -> m_nOfItems;

}

size_t VectorCapacity(const Vector* _vector)
{
	if(NULL == _vector)
	{
		return 0;
	}
	return _vector -> m_size;
}

size_t VectorForEach(const Vector* _vector, VectorElementAction _action, void* _context)
{
	size_t size, i = 0;
	void* data = NULL;
	if(NULL == _vector || NULL == _action)
	{
		return 0;
	}
	size =  _vector -> m_nOfItems;
	for(i = 0; i < size; ++i)
	{
		if(0 == _action(_vector -> m_items[i], i, _context))
		{
			break;
		}	
	}
 	return i;
}

/*************************help functions***************************/

static VectorResult ReallocCheckToRaise(Vector* _vector)
{
	void** pTemp = NULL;
	if((_vector -> m_size) == (_vector -> m_nOfItems))
	{
		if(0 == _vector -> m_blockSize)
		{
			return VECTOR_OVERFLOW;
		}
		pTemp = (void**)realloc(_vector -> m_items, (_vector -> m_blockSize + _vector -> m_size) * sizeof(void*));

		if( NULL == *pTemp)
		{
			return VECTOR_REALLOCATION_FAILED;
		}
		_vector -> m_items = pTemp; 
		_vector -> m_size += (_vector -> m_blockSize);
	}
	return VECTOR_SUCCESS;
}
static VectorResult ReallocCheckToReduce(Vector* _vector)
{
	void** pTemp = NULL;
	if ( (_vector -> m_size > _vector -> m_originalSize) && ((_vector -> m_blockSize) * DECLER_FACTOR) <= (_vector -> m_size - _vector -> m_nOfItems)) 
	{
		pTemp = (void**)realloc(_vector -> m_items, (_vector -> m_blockSize + _vector -> m_size)*sizeof(void*));
		if( NULL == *pTemp )
		{
			return VECTOR_REALLOCATION_FAILED;
		}
		_vector -> m_items = pTemp; 
		_vector -> m_size -= (_vector -> m_blockSize);
		
	}
	return VECTOR_SUCCESS;
}

/******************get functions****************************
size_t GetOriginalSize(Vector *_vector)
{
	return _vector -> m_originalSize;
}

size_t GetSize(Vector *_vector)
{
	return _vector -> m_size;
}
size_t GetnItems(Vector *_vector)
{
	return _vector -> m_nOfItems;
}

size_t GetBlockSize(Vector *_vector)
{
	return _vector -> m_blockSize;
}
/*****************************************************/

