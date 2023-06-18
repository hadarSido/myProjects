#include <stdio.h> /*printf*/
#include <stdlib.h> /*malloc*/
#include <stddef.h> /*size_t*/
#include "listInternal.h" /*stracts decleration*/
#include "listitrfun.h" /*functions decleration*/

typedef int (*genericFunc)(void* _element, void* _context);
typedef int (*InternalFunc)(int _data, void* _counter);

static ListItr InternalForEach(ListItr _begin, ListItr _end, genericFunc _genericFun, void* _context, InternalFunc inerCount, void* _counter);
static int InnerFindFirst(int _result, void* _counter);
static int InnerCount(int _result, void* _counter);
static int InnerForEach(int _result, void* _counter);
/*******************************************************************************************************/
ListItr ListItrFindFirst(ListItr _begin, ListItr _end, PredicateFunction _predicate, void* _context)
{
	if(NULL == _begin || NULL == _end || NULL == _predicate )
	{
		return NULL;
	}
	return InternalForEach(_begin, _end,_predicate, _context, InnerFindFirst, NULL);
}

size_t ListItrCountIf(ListItr _begin, ListItr _end, PredicateFunction _predicate, void* _context)
{
	size_t counter = 0;
	if(NULL == _begin || NULL == _end || NULL == _predicate )
	{
		return 0;
	}
	InternalForEach(_begin, _end,_predicate, _context, InnerCount, &counter);
	return counter;
}

ListItr ListItrForEach(ListItr _begin, ListItr _end, ListActionFunction _action, void* _context)
{
	if(NULL == _begin || NULL == _end || NULL == _action)
	{
		return NULL;
	}
	return InternalForEach(_begin, _end,_action, _context, InnerForEach, NULL);
}

/********************************************help functions********************************************/

static ListItr InternalForEach(ListItr _begin, ListItr _end, genericFunc _genericFun, void* _context, InternalFunc _inerFunc, void* _counter)
{
	int result;
	void* data;
	if(NULL == _begin || NULL == _end)
	{
		return NULL;
	}
	while(_begin != _end)
	{
		data = ListItrGet(_begin);
		result = _genericFun(data, _context);
		result = _inerFunc(result, _counter);
		if(result == 0)
		{
			break;
		}
		_begin = ListItrNext(_begin);
	}
	return _begin;
}
/********************************help- Inner*****************************************/
static int InnerFindFirst(int _result, void* _counter)
{
	if(1 == _result)
	{
		return 0;
	}
	return 1;
}

static int InnerCount(int _result, void* _counter)
{
	if(1 == _result)
	{
		++(*(size_t*)_counter);
	}
	return 1;
}
static int InnerForEach(int _result, void* _counter)
{
	if(0 == _result)
	{
		return 0;
	}
	return 1;
}