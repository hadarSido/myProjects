#include <stdio.h> /*printf*/
#include <stdlib.h> /*malloc*/
#include <stddef.h> /*size_t*/
#include "list.h" /*functions decleration*/
/************************************************/
Node* GetHeadNext(List *_list);
Node* GetTailPrev(List *_list);
Node* GetHeadPrev(List *_list);
Node* GetTailNext(List *_list);
void* GetTail(List* _list);
void* GetHead(List* _list);
/***********************************************/
static void TestListCreateHeadPrev(void);
static void TestListCreateTailNext(void);
static void TestListCreateHeadNext(void);
static void TestListCreateTailPrev(void);
static void TestListCreateAllocation(void);

static void TestListDestroyIfWorking(void);
static void TestListDestroyDouble(void);

static void TestListPushHeadItemNull(void);
static void TestListPushHeadListNull(void);
static void TestListPushHeadWorkOK(void);

static void TestListPushTailItemNull(void);
static void TestListPushTailListNull(void);
static void TestListPushTailWorkOK(void);

static void TestListPopHeadIfWorkOK(void);
static void TestListPopHeadIfListIsNull(void);
static void TestListPopHeadIfItemIsNull(void);
static void TestListPopHeadIsEmpty(void);

static void TestListPopTailIfWorkOK(void);
static void TestListPopTailListIsNull(void);
static void TestListPopTailItemIsNull(void);
static void TestListPopTailIsEmpty(void);

static void TestListSizeListIsNull(void);
static void TestListSizeListSize(void);
static void TestListSizeListPop(void);

int main(void)
{
	printf("\n");
	TestListCreateHeadPrev();
	TestListCreateTailNext();
	TestListCreateHeadNext();
	TestListCreateTailPrev();
	TestListCreateAllocation();

	TestListDestroyIfWorking();
	TestListDestroyDouble();

	TestListPushHeadItemNull();
	TestListPushHeadListNull();
	TestListPushHeadWorkOK();

	TestListPushTailItemNull();
	TestListPushTailListNull();
	TestListPushTailWorkOK();

	TestListPopHeadIfWorkOK();
	TestListPopHeadIfListIsNull();
	TestListPopHeadIfItemIsNull();
	TestListPopHeadIsEmpty();

	TestListPopTailIfWorkOK();
	TestListPopTailListIsNull();
	TestListPopTailItemIsNull();
	TestListPopTailIsEmpty();

	TestListSizeListIsNull();
	TestListSizeListSize();
	TestListSizeListPop();
	
	
	return 0;
}

static void TestListCreateHeadPrev(void)
{
	List *ptrList = ListCreate();
	void* head = GetHead(ptrList);
	if(GetHeadPrev(ptrList) == head)
	{
		printf("TestListCreateHeadPrev **PASS**\n");
	}
	else
	{
		printf("TestListCreateHeadPrev !!**FAIL**!!\n");
	}
	ListDestroy(&ptrList, NULL);
	printf("\n");
}

static void TestListCreateTailNext(void)
{
	List *ptrList = ListCreate();
	void* tail = GetTail(ptrList);
	if(GetTailNext(ptrList) == tail)
	{
		printf("TestListCreateTailNext **PASS**\n");
	}
	else
	{
		printf("TestListCreateTailNext !!**FAIL**!!\n");
	}
	ListDestroy(&ptrList, NULL);
	printf("\n");
}


static void TestListCreateTailPrev(void)
{
	List *ptrList = ListCreate();
	void* head = GetHead(ptrList);
	if(GetTailPrev(ptrList) == head)
	{
		printf("TestListCreateTailPrev **PASS**\n");
	}
	else
	{
		printf("TestListCreateTailPrev !!**FAIL**!!\n");
	}
	ListDestroy(&ptrList, NULL);
	printf("\n");
}

static void TestListCreateHeadNext(void)
{
	List *ptrList = ListCreate();
	void* tail = GetTail(ptrList);
	if(GetHeadNext(ptrList) == tail)
	{
		printf("TestListCreateHeadNext **PASS**\n");
	}
	else
	{
		printf("TestListCreateHeadNext !!**FAIL**!!\n");
	}
	ListDestroy(&ptrList, NULL);
	printf("\n");
}


static void TestListCreateAllocation(void)
{
	List *ptrList = ListCreate();
	if(ptrList != NULL)
	{
		printf("TestListCreateAllocation **PASS**\n");
	}
	else
	{
		printf("TestListCreateAllocation !!**FAIL**!!\n");
	}
	ListDestroy(&ptrList, NULL);
	printf("\n");
}

static void TestListDestroyIfWorking(void)
{
	List *ptrList = ListCreate();
	ListDestroy(&ptrList, NULL);
	if(ptrList == NULL)
	{
		printf("TestListDestroyIfWorking **PASS**\n");
	}
	else
	{
		printf("TestListDestroyIfWorking !!**FAIL**!!\n");
	}
	printf("\n");
}

static void TestListDestroyDouble(void)
{
	List *ptrList = ListCreate();
	ListDestroy(&ptrList, NULL);
	ListDestroy(&ptrList, NULL);
	printf("TestListDestroyDouble **PASS**\n");
	printf("\n");
}


static void TestListPushHeadItemNull(void)
{
	List *ptrList = ListCreate();
	
	if(ListPushHead(ptrList, NULL) == LIST_NULL_ELEMENT_ERROR)
	{
		printf("TestListPushHeadItemNull **PASS**\n");
	}
	else
	{
		printf("TestListPushHeadItemNull !!**FAIL**!!\n");
	}
	ListDestroy(&ptrList, NULL);
	printf("\n");
}

static void TestListPushHeadListNull(void)
{
	int item = 5;
	List *ptrList = ListCreate();
	if(ListPushHead(NULL, &item) == LIST_UNINITIALIZED_ERROR)
	{
		printf("TestListPushHeadListNull **PASS**\n");
	}
	else
	{
		printf("TestListPushHeadListNull !!**FAIL**!!\n");
	}
	ListDestroy(&ptrList, NULL);
	printf("\n");
}

static void TestListPushHeadWorkOK(void)
{
	int item = 5;
	List *ptrList = ListCreate();
	if(ListPushHead(ptrList, &item) == LIST_SUCCESS)
	{
		printf("TestListPushHeadWorkOK **PASS**\n");
	}
	else
	{
		printf("TestListPushHeadWorkOK !!**FAIL**!!\n");
	}
	ListDestroy(&ptrList, NULL);
	printf("\n");
}

static void TestListPushTailItemNull(void)
{
	List *ptrList = ListCreate();
	if(ListPushTail(ptrList, NULL) == LIST_NULL_ELEMENT_ERROR)
	{
		printf("TestListPushTailItemNull **PASS**\n");
	}
	else
	{
		printf("TestListPushTailItemNull !!**FAIL**!!\n");
	}
	ListDestroy(&ptrList, NULL);
	printf("\n");
}

static void TestListPushTailListNull(void)
{
	int item = 5;
	List *ptrList = ListCreate();
	if(ListPushTail(NULL, &item) == LIST_UNINITIALIZED_ERROR)
	{
		printf("TestListPushTailListNull **PASS**\n");
	}
	else
	{
		printf("TestListPushTailListNull !!**FAIL**!!\n");
	}
	ListDestroy(&ptrList, NULL);
	printf("\n");
}

static void TestListPushTailWorkOK(void)
{
	int item = 5;
	List *ptrList = ListCreate();
	if(ListPushTail(ptrList, &item) == LIST_SUCCESS)
	{
		printf("TestListPushTailWorkOK **PASS**\n");
	}
	else
	{
		printf("TestListPushTailWorkOK !!**FAIL**!!\n");
	}
	ListDestroy(&ptrList, NULL);
	printf("\n");
}

static void TestListPopHeadIfWorkOK(void)
{
	int item = 3;
	int item2 = 1;
	void *ptrItem;
	List *ptrList = ListCreate();
	ListPushHead(ptrList, &item);
	ListPushHead(ptrList, &item2);
	if(ListPopHead(ptrList, &ptrItem) == LIST_SUCCESS)
	{
		printf("TestListPopHeadIfWorkOK **PASS**\n");
	}
	else
	{
		printf("TestListPopHeadIfWorkOK !!**FAIL**!!\n");
	}
	ListDestroy(&ptrList, NULL);
	printf("\n");
}


static void TestListPopHeadIfListIsNull(void)
{
	int item = 5;
	void *ptrItem;
	List *ptrList = ListCreate();
	if(ListPopHead(NULL, &ptrItem) == LIST_UNINITIALIZED_ERROR)
	{
		printf("TestListPopHeadIfListIsNull **PASS**\n");
	}
	else
	{
		printf("TestListPopHeadIfListIsNull !!**FAIL**!!\n");
	}
	ListDestroy(&ptrList, NULL);
	printf("\n");
}


static void TestListPopHeadIfItemIsNull(void)
{
	int item = 5;
	List *ptrList = ListCreate();
	if(ListPopHead(ptrList, NULL) == LIST_NULL_ELEMENT_ERROR)
	{
		printf("TestListPopHeadIfItemIsNull **PASS**\n");
	}
	else
	{
		printf("TestListPopHeadIfItemIsNull !!**FAIL**!!\n");
	}
	ListDestroy(&ptrList, NULL);
	printf("\n");
}


static void TestListPopHeadIsEmpty(void) 
{
	int item1 = 3;
	int item2 = 1;
	void *ptrItem;
	List *ptrList = ListCreate();
	ListPushHead(ptrList, &item1);
	ListPushHead(ptrList, &item2);
	ListPopHead(ptrList, &ptrItem);
	ListPopHead(ptrList, &ptrItem);
	if(ListPopHead(ptrList, &ptrItem) == LIST_IS_EMPTY_ERROR)
	{
		printf("TestListPopHeadIsEmpty **PASS**\n");
	}
	else
	{
		printf("TestListPopHeadIsEmpty !!**FAIL**!!\n");
	}
	ListDestroy(&ptrList, NULL);
	printf("\n");
}

static void TestListPopTailIfWorkOK(void)
{
	int item1 = 3;
	int item2 = 1;
	void *ptrItem;
	List *ptrList = ListCreate();
	ListPushHead(ptrList, &item1);
	ListPushHead(ptrList, &item2);
	if(ListPopTail(ptrList, &ptrItem) == LIST_SUCCESS)
	{
		printf("TestListPopTailIfWorkOK **PASS**\n");
	}
	else
	{
		printf("TestListPopTailIfWorkOK !!**FAIL**!!\n");
	}
	ListDestroy(&ptrList, NULL);
	printf("\n");
}

static void TestListPopTailListIsNull(void)
{
	void *ptrItem;
	List *ptrList = ListCreate();
	if(ListPopTail(NULL, &ptrItem) == LIST_UNINITIALIZED_ERROR)
	{
		printf("TestListPopTailListIsNull **PASS**\n");
	}
	else
	{
		printf("TestListPopTailListIsNull !!**FAIL**!!\n");
	}
	ListDestroy(&ptrList, NULL);
	printf("\n");
}

static void TestListPopTailItemIsNull(void)
{
	void *ptrItem;
	List *ptrList = ListCreate();
	if(ListPopTail(ptrList, NULL) == LIST_NULL_ELEMENT_ERROR)
	{
		printf("TestListPopTailItemIsNull **PASS**\n");
	}
	else
	{
		printf("TestListPopTailItemIsNull !!**FAIL**!!\n");
	}
	ListDestroy(&ptrList, NULL);
	printf("\n");
}


static void TestListPopTailIsEmpty(void) 
{
	int item1 = 3;
	int item2 = 1;
	void *ptrItem;
	List *ptrList = ListCreate();
	ListPushHead(ptrList, &item1);
	ListPushHead(ptrList, &item2);
	ListPopHead(ptrList, &ptrItem); 
	ListPopHead(ptrList, &ptrItem);
	if(ListPopHead(ptrList, &ptrItem) == LIST_IS_EMPTY_ERROR)
	{
		printf("TestListPopTailIsEmpty **PASS**\n");
	}
	else
	{
		printf("TestListPopTailIsEmpty !!**FAIL**!!\n");
	}
	ListDestroy(&ptrList, NULL);
	printf("\n");
}

static void TestListSizeListIsNull(void) 
{
	List *ptrList = ListCreate();
	if(ListSize(NULL) == 0)
	{
		printf("TestListSizeListIsNull **PASS**\n");
	}
	else
	{
		printf("TestListSizeListIsNull !!**FAIL**!!\n");
	}
	ListDestroy(&ptrList, NULL);
	printf("\n");
}


static void TestListSizeListSize(void) 
{
	int item1 = 3;
	int item2 = 6;
	int item3 = 1;
	int item4 = 8;
	int item5 = 1;
	int item6 = 9;
	int item7 = 10;
	List *ptrList = ListCreate();
	ListPushHead(ptrList, &item1);
	ListPushHead(ptrList, &item2);
	ListPushHead(ptrList, &item3);
	ListPushTail(ptrList, &item7);
	ListPushTail(ptrList, &item6);
	ListPushTail(ptrList, &item5);
	ListPushHead(ptrList, &item4);
	if(ListSize(ptrList) == 7)
	{
		printf("TestListSizeListSize **PASS**\n");
	}
	else
	{
		printf("TestListSizeListSize !!**FAIL**!!\n");
	}
	ListDestroy(&ptrList, NULL);
	printf("\n");
}

static void TestListSizeListPop(void) 
{
	int item1 = 3;
	int item2 = 6;
	int item3 = 1;
	int item4 = 8;
	int item5 = 1;
	int item6 = 9;
	int item7 = 10;
	void *ptrItem1;
	void *ptrItem2;
	List *ptrList = ListCreate();
	ListPushHead(ptrList, &item1);
	ListPushHead(ptrList, &item2);
	ListPushHead(ptrList, &item3);
	ListPushTail(ptrList, &item7);
	ListPushTail(ptrList, &item6);
	ListPushTail(ptrList, &item5);
	ListPushHead(ptrList, &item4);
	ListPopTail(ptrList, &ptrItem1);
	ListPopHead(ptrList, &ptrItem2);
	if(ListSize(ptrList) == 5)
	{
		printf("TestListSizeListPop **PASS**\n");
	}
	else
	{
		printf("TestListSizeListPop !!**FAIL**!!\n");
	}
	ListDestroy(&ptrList, NULL);
	printf("\n");
}





