#include <stdio.h> /*printf*/
#include <stdlib.h> /*malloc*/
#include <stddef.h> /*size_t*/
#include "listItr.h" /*functions decleration*/
#include "listInternal.h" /*stracts decleration*/
/************************************************/
Node* GetHeadNext(List *_list);
Node* GetTailPrev(List *_list);
Node* GetHeadPrev(List *_list);
Node* GetTailNext(List *_list);
void* GetTail(List* _list);
void* GetHead(List* _list);
void NodeDestroy(void* _item)
{
	free(_item);
}

/*************************************************/
static void TestListItrBeginIfListIsNull(void);
static void TestListItrBeginIfWorkOk(void);

static void TestListItrEndIfListIsNull(void);
static void TestListItrEndIfWorkOk(void);

static void TestListItrEqualsNull(void);
static void TestListItrEqualsFALSE(void);

static void TestListItrNextIfItrIsNull(void);
static void TestListItrNextIfWorkOk(void);

static void TestListItrPrevIfItrIsNull(void);
static void TestListItrPrevIfWorkOk(void);

static void TestListItrGetIfItrIsNull(void);
static void TestListItrGetIfEmpty(void);
static void TestListItrGetIfWorking(void);

static void TestListItrSetIfItrIsNull(void);
static void TestListItrSetIfElementIsNull(void);
static void TestListItrSetIfEmpty(void);
static void TestListItrSetIfWorkOK(void);

static void TestListItrInsertBeforeIfItrIsNull(void);
static void TestListItrInsertBeforeIfElementIsNull(void);
static void TestListItrInsertBeforeIfWorkOK(void); 

static void TestListItrRemoveIfItrIsNull(void);
static void TestListItrRemoveIfEmpty(void);
static void TestListItrRemoveIfWorkOK(void) ;


int main(void)
{
	printf("\n");
	TestListItrBeginIfListIsNull();
	TestListItrBeginIfWorkOk();

	TestListItrEndIfListIsNull();
	TestListItrEndIfWorkOk();

	TestListItrEqualsNull();
	TestListItrEqualsFALSE();

	TestListItrNextIfItrIsNull();
	TestListItrNextIfWorkOk();

	TestListItrPrevIfItrIsNull();
	TestListItrPrevIfWorkOk();

	TestListItrGetIfItrIsNull();
	TestListItrGetIfEmpty();
	TestListItrGetIfWorking();

	TestListItrSetIfItrIsNull();
	TestListItrSetIfElementIsNull();
	TestListItrSetIfEmpty();
	TestListItrSetIfWorkOK();

	TestListItrInsertBeforeIfItrIsNull();
	TestListItrInsertBeforeIfElementIsNull();
	TestListItrInsertBeforeIfWorkOK(); 

	TestListItrRemoveIfItrIsNull();
	TestListItrRemoveIfEmpty();
	TestListItrRemoveIfWorkOK();
	
	
	return 0;
}

static void TestListItrBeginIfListIsNull(void)
{
	if(ListItrBegin(NULL) == NULL)
	{
		printf("TestListItrBeginIfListIsNull **PASS**\n");
	}
	else
	{
		printf("TestListItrBeginIfListIsNull !!**FAIL**!!\n");
	}
	printf("\n");
}

static void TestListItrBeginIfWorkOk(void)
{
	
	int *a, *b;
	List *ptrList;
	a = (int*)malloc(sizeof(int) * 1);
	*a = 5;
	b = (int*)malloc(sizeof(int) * 1);
	*b = 1;
	ptrList = ListCreate();
	ListPushTail(ptrList, a);
	ListPushTail(ptrList, b);
	if(ListItrBegin(ptrList) == ptrList -> m_head.m_next)
	{
		printf("TestListItrBeginIfWorkOk **PASS**\n");
	}
	else
	{
		printf("TestListItrBeginIfWorkOk !!**FAIL**!!\n");
	}
	ListDestroy(&ptrList, NodeDestroy);
	printf("\n");
}

static void TestListItrEndIfListIsNull(void)
{
	if(ListItrEnd(NULL) == NULL)
	{
		printf("TestListItrEndIfListIsNull **PASS**\n");
	}
	else
	{
		printf("TestListItrEndIfListIsNull !!**FAIL**!!\n");
	}
	printf("\n");
}

static void TestListItrEndIfWorkOk(void)
{
	List *ptrList = ListCreate();
	int *a, *b;
	a = (int*)malloc(sizeof(int) * 1);
	b = (int*)malloc(sizeof(int) * 1);
	*a = 5;
	*b = 1;
	if(ListItrEnd(ptrList) == ptrList -> m_tail.m_next)
	{
		printf("TestListItrEndIfWorkOk **PASS**\n");
	}
	else
	{
		printf("TestListItrEndIfWorkOk !!**FAIL**!!\n");
	}
	ListDestroy(&ptrList, NodeDestroy);
	printf("\n");
}

static void TestListItrEqualsFALSE(void)
{
	List *ptrList = ListCreate();
	int *a, *b;
	a = (int*)malloc(sizeof(int) * 1);
	b = (int*)malloc(sizeof(int) * 1);
	*a = 5;
	*b = 1;
	ListPushTail(ptrList, a);
	ListPushTail(ptrList, b);
	if(ListItrEquals(ptrList -> m_head.m_next, ptrList -> m_tail.m_prev ->m_prev)) 
	{
		printf("TestListItrEqualsFALSE **PASS**\n");
	}
	else
	{
		printf("TestListItrEqualsFALSE !!**FAIL**!!\n");
	}
	ListDestroy(&ptrList, NodeDestroy);
	printf("\n");
}

static void TestListItrEqualsNull(void)
{
	
	if(ListItrEquals(NULL, NULL))
	{
		printf("TestListItrEqualsNull **PASS**\n");
	}
	else
	{
		printf("TestListItrEqualsNull !!**FAIL**!!\n");
	}
	printf("\n");
}

static void TestListItrNextIfItrIsNull(void)
{
	if(ListItrNext(NULL) == NULL)
	{
		printf("TestListItrNextIfItrIsNull **PASS**\n");
	}
	else
	{
		printf("TestListItrNextIfItrIsNull !!**FAIL**!!\n");
	}
	printf("\n");
}


static void TestListItrNextIfWorkOk(void) 
{
	int *a, *b;
	List *ptrList = ListCreate();
	a = (int*)malloc(sizeof(int) * 1);
	b = (int*)malloc(sizeof(int) * 1);
	*a = 5;
	*b = 1;
	ListPushTail(ptrList, a);
	ListPushTail(ptrList, b);
	if(ListItrNext(ListItrBegin(ptrList)) == ptrList -> m_tail.m_prev)
	{
		printf("TestListItrNextIfWorkOk **PASS**\n");
	}
	else
	{
		printf("TestListItrNextIfWorkOk !!**FAIL**!!\n");
	}
	ListDestroy(&ptrList, NodeDestroy);
	printf("\n");
}

static void TestListItrPrevIfItrIsNull(void)
{
	if(ListItrPrev(NULL) == NULL)
	{
		printf("TestListItrNextIfItrIsNull **PASS**\n");
	}
	else
	{
		printf("TestListItrNextIfItrIsNull !!**FAIL**!!\n");
	}
	printf("\n");
}

static void TestListItrPrevIfWorkOk(void)
{
	int *a, *b;
	List *ptrList = ListCreate();
	a = (int*)malloc(sizeof(int) * 1);
	b = (int*)malloc(sizeof(int) * 1);
	*a = 5;
	*b = 1;
	ListPushTail(ptrList, a);
	ListPushTail(ptrList, b);
	if(ListItrPrev(ListItrEnd(ptrList)) == ptrList -> m_tail.m_prev)
	{
		printf("TestListItrPrevIfWorkOk **PASS**\n");
	}
	else
	{
		printf("TestListItrPrevIfWorkOk !!**FAIL**!!\n");
	}
	ListDestroy(&ptrList, NodeDestroy);
	printf("\n");
}

static void TestListItrGetIfItrIsNull(void)
{
	if(ListItrGet(NULL) == NULL)
	{
		printf("TestListItrGetIfItrIsNull **PASS**\n");
	}
	else
	{
		printf("TestListItrGetIfItrIsNull !!**FAIL**!!\n");
	}
	printf("\n");
}

static void TestListItrGetIfEmpty(void)
{
	
	List *ptrList = ListCreate();
	ListItr ptrItr = ListItrBegin(ptrList);
	if(ListItrGet(ptrItr) == NULL)
	{
		printf("TestListItrGetIfEmpty **PASS**\n");
	}
	else
	{
		printf("TestListItrGetIfEmpty !!**FAIL**!!\n");
	}
	ListDestroy(&ptrList, NULL);
	printf("\n");
}

static void TestListItrGetIfWorking(void)
{
	int *a, *b;
	List *ptrList = ListCreate();
	a = (int*)malloc(sizeof(int) * 1);
	b = (int*)malloc(sizeof(int) * 1);
	*a = 5;
	*b = 1;
	ListPushTail(ptrList, a);
	ListPushTail(ptrList, b);
	if(*(int*)ListItrGet(ListItrBegin(ptrList)) == 5)
	{
		printf("TestListItrGetIfWorking **PASS**\n");
	}
	else
	{
		printf("TestListItrGetIfWorking !!**FAIL**!!\n");
	}
	ListDestroy(&ptrList, NodeDestroy);
	printf("\n");
}

static void TestListItrSetIfItrIsNull(void)
{
	
	List *ptrList = ListCreate();
	void* element1;
	if(ListItrSet(NULL, element1) == NULL)
	{
		printf("TestListItrSetIfItrIsNull **PASS**\n");
	}
	else
	{
		printf("TestListItrSetIfItrIsNull !!**FAIL**!!\n");
	}
	ListDestroy(&ptrList, NULL);
	printf("\n");
}

static void TestListItrSetIfElementIsNull(void)
{
	
	List *ptrList = ListCreate();
	ListItr ptrItr = ListItrBegin(ptrList);
	void* element1;
	if(ListItrSet(ptrItr, NULL) == NULL)
	{
		printf("TestListItrSetIfElementIsNull **PASS**\n");
	}
	else
	{
		printf("TestListItrSetIfElementIsNull !!**FAIL**!!\n");
	}
	ListDestroy(&ptrList, NULL);
	printf("\n");
}
static void TestListItrSetIfEmpty(void)
{
	
	List *ptrList = ListCreate();
	ListItr ptrItr = ListItrBegin(ptrList);
	void* element1;
	if(ListItrSet(ptrItr, element1) == NULL)
	{
		printf("TestListItrSetIfEmpty **PASS**\n");
	}
	else
	{
		printf("TestListItrSetIfEmpty !!**FAIL**!!\n");
	}
	ListDestroy(&ptrList, NULL);
	printf("\n");
}

static void TestListItrSetIfWorkOK(void)
{
	
	int *a, *b, *c;
	List *ptrList = ListCreate();
	a = (int*)malloc(sizeof(int) * 1);
	b = (int*)malloc(sizeof(int) * 1);
	c = (int*)malloc(sizeof(int) * 1);
	*a = 5;
	*b = 1;
	ListPushTail(ptrList, a);
	ListPushTail(ptrList, b);
	if(*(int*)ListItrSet(ListItrBegin(ptrList), c) == 5)
	{
		printf("TestListItrSetIfWorkOK **PASS**\n");
	}
	else
	{
		printf("TestListItrSetIfWorkOK !!**FAIL**!!\n");
	}
	ListDestroy(&ptrList, NodeDestroy);
	printf("\n");
}

static void TestListItrInsertBeforeIfItrIsNull(void)
{
	List *ptrList = ListCreate();
	ListItr ptrItr = ListItrBegin(ptrList);
	void* element1;
	if(ListItrInsertBefore(NULL, element1) == NULL)
	{
		printf("TestListItrInsertBeforeIfItrIsNull **PASS**\n");
	}
	else
	{
		printf("TestListItrInsertBeforeIfItrIsNull !!**FAIL**!!\n");
	}
	ListDestroy(&ptrList, NULL);
	printf("\n");
}

static void TestListItrInsertBeforeIfElementIsNull(void)
{
	List *ptrList = ListCreate();
	ListItr ptrItr = ListItrBegin(ptrList);
	void* element1;
	if(ListItrInsertBefore(ptrItr, NULL) == NULL)
	{
		printf("TestListItrInsertBeforeIfElementIsNull **PASS**\n");
	}
	else
	{
		printf("TestListItrInsertBeforeIfElementIsNull !!**FAIL**!!\n");
	}
	ListDestroy(&ptrList, NULL);
	printf("\n");
}

static void TestListItrInsertBeforeIfWorkOK(void) /********/
{
	int *a, *b, *c;
	List *ptrList = ListCreate();
	a = (int*)malloc(sizeof(int) * 1);
	b = (int*)malloc(sizeof(int) * 1);
	c = (int*)malloc(sizeof(int) * 1);
	*a = 5;
	*b = 1;
	*c = 12;
	ListPushTail(ptrList, a);
	ListPushTail(ptrList, b);
	if(*(int*)(((Node*)ListItrInsertBefore(ListItrBegin(ptrList), c))-> m_data) == 12)
	{
		printf("TestListItrInsertBeforeIfWorkOK **PASS**\n");
	}
	else
	{
		printf("TestListItrInsertBeforeIfWorkOK !!**FAIL**!!\n");
	}
	ListDestroy(&ptrList, NodeDestroy);
	printf("\n");
}


static void TestListItrRemoveIfItrIsNull(void)
{
	List *ptrList = ListCreate();
	ListItr ptrItr = ListItrBegin(ptrList);
	void* element1;
	if(ListItrRemove(NULL) == NULL)
	{
		printf("TestListItrRemoveIfItrIsNull **PASS**\n");
	}
	else
	{
		printf("TestListItrRemoveIfItrIsNull !!**FAIL**!!\n");
	}
	ListDestroy(&ptrList, NULL);
	printf("\n");
}

static void TestListItrRemoveIfEmpty(void)
{
	List *ptrList = ListCreate();
	ListItr ptrItr = ListItrBegin(ptrList);
	if(ListItrRemove(ptrItr) == NULL)
	{
		printf("TestListItrRemoveIfEmpty **PASS**\n");
	}
	else
	{
		printf("TestListItrRemoveIfEmpty !!**FAIL**!!\n");
	}
	ListDestroy(&ptrList, NULL);
	printf("\n");
}


static void TestListItrRemoveIfWorkOK(void) 
{
	int *a, *b, *c;
	List *ptrList = ListCreate();
	a = (int*)malloc(sizeof(int) * 1);
	b = (int*)malloc(sizeof(int) * 1);
	c = (int*)malloc(sizeof(int) * 1);
	*a = 5;
	*b = 1;
	*c = 12;
	ListPushTail(ptrList, a);
	ListPushTail(ptrList, b);
	if(*(int*)ListItrRemove(ListItrBegin(ptrList)) == 5)
	{
		printf("TestListItrRemoveIfWorkOK **PASS**\n");
	}
	else
	{
		printf("TestListItrRemoveIfWorkOK !!**FAIL**!!\n");
	}
	ListDestroy(&ptrList, NodeDestroy);
	printf("\n");
}
