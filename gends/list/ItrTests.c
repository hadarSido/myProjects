#include <stdio.h> /*printf*/
#include <stdlib.h> /*malloc*/
#include <stddef.h> /*size_t*/
#include "listItr.h" /*functions decleration*/
#include "listInternal.h" /*stracts decleration*/
/************************************************/
int PredicateFunctionForInt(void* _element, void* _context)
{
	if(*(int*)_context == *(int*)_element)
	{
		return 1;
	}
	return 0;
}

int ListActionPrintForInt(void* _element, void* _context)
{
	if(0 == _element)
	{
		return 0;
	}
	printf("%d ", *(int*)_element);
	return 1;
}
/***********************************************************/
static void TestListItrFindFirstBeginIsNull(void);
static void TestListItrFindFirstEndIsNull(void);
static void TestListItrFindFirstFuncIsNull(void);
static void TestListItrFindFirstPredicateInt(void);

static void TestListItrCountBeginIsNull(void);
static void TestListItrCountEndIsNull(void);
static void TestListItrCountFuncIsNull(void);
static void TestListItrCountPredicateInt(void);

static void TestListItrForEachBeginIsNull(void);
static void TestListItrForEachEndIsNull(void);
static void TestListItrForEachFuncIsNull(void);
static void TestListItrForEachPrinteInt(void);

/*************************************************/
int main(void)
{
	printf("\n");
	TestListItrFindFirstBeginIsNull();
	TestListItrFindFirstEndIsNull();
	TestListItrFindFirstFuncIsNull();
	TestListItrFindFirstPredicateInt();

	TestListItrCountBeginIsNull();
	TestListItrCountEndIsNull();
	TestListItrCountFuncIsNull();
	TestListItrCountPredicateInt();
	
	TestListItrForEachBeginIsNull();
	TestListItrForEachEndIsNull();
	TestListItrForEachFuncIsNull();
	TestListItrForEachPrinteInt();



	
	return 0;
}
static void TestListItrFindFirstBeginIsNull(void)
{
	List *ptrList = ListCreate();
	if(ListItrFindFirst(NULL, ListItrEnd(ptrList), PredicateFunctionForInt,NULL) == NULL)
	{
		printf("TestListItrFindFirstBeginIsNull **PASS**\n");
	}
	else
	{
		printf("TestListItrFindFirstBeginIsNull !!**FAIL**!!\n");
	}
	ListDestroy(&ptrList, NULL);
	printf("\n");
}

static void TestListItrFindFirstEndIsNull(void)
{
	List *ptrList = ListCreate();
	if(ListItrFindFirst(ListItrBegin(ptrList), NULL , PredicateFunctionForInt,NULL) == NULL)
	{
		printf("TestListItrFindFirstEndIsNull **PASS**\n");
	}
	else
	{
		printf("TestListItrFindFirstEndIsNull !!**FAIL**!!\n");
	}
	ListDestroy(&ptrList, NULL);
	printf("\n");
}

static void TestListItrFindFirstFuncIsNull(void)
{
	List *ptrList = ListCreate();
	if(ListItrFindFirst(ListItrBegin(ptrList), ListItrEnd(ptrList) , NULL ,NULL) == NULL)
	{
		printf("TestListItrFindFirstFuncIsNull **PASS**\n");
	}
	else
	{
		printf("TestListItrFindFirstFuncIsNull !!**FAIL**!!\n");
	}
	ListDestroy(&ptrList, NULL);
	printf("\n");
}


static void TestListItrFindFirstPredicateInt(void)
{
	List *ptrList = ListCreate();
	int *a, *b;
	void* result;
	int item = 4;
	a = (int*)malloc(sizeof(int) * 1);
	*a = 4;
	b = (int*)malloc(sizeof(int) * 1);
	*b = 7;
	ListPushHead(ptrList, a);
	ListPushHead(ptrList, b);
	result = ListItrFindFirst(ListItrBegin(ptrList), ListItrEnd(ptrList) , PredicateFunctionForInt ,&item); /*begin*/
	if(*(int*)ListItrGet(result) == item )
	{
		printf("TestListItrFindFirstPredicateInt **PASS**\n");
	}
	else
	{
		printf("TestListItrFindFirstPredicateInt !!**FAIL**!!\n");
	}
	ListDestroy(&ptrList, NULL);
	printf("\n");
}


static void TestListItrCountBeginIsNull(void)
{
	List *ptrList = ListCreate();
	if(ListItrCountIf(NULL, ListItrEnd(ptrList), PredicateFunctionForInt,NULL) == 0)
	{
		printf("TestListItrCountBeginIsNull **PASS**\n");
	}
	else
	{
		printf("TestListItrCountBeginIsNull !!**FAIL**!!\n");
	}
	ListDestroy(&ptrList, NULL);
	printf("\n");
}

static void TestListItrCountEndIsNull(void)
{
	List *ptrList = ListCreate();
	if(ListItrCountIf(ListItrBegin(ptrList), NULL , PredicateFunctionForInt,NULL) == 0)
	{
		printf("TestListItrCountEndIsNull **PASS**\n");
	}
	else
	{
		printf("TestListItrCountEndIsNull !!**FAIL**!!\n");
	}
	ListDestroy(&ptrList, NULL);
	printf("\n");
}

static void TestListItrCountFuncIsNull(void)
{
	List *ptrList = ListCreate();
	if(ListItrCountIf(ListItrBegin(ptrList), ListItrEnd(ptrList) , NULL ,NULL) == 0)
	{
		printf("TestListItrCountFuncIsNull **PASS**\n");
	}
	else
	{
		printf("TestListItrCountFuncIsNull !!**FAIL**!!\n");
	}
	ListDestroy(&ptrList, NULL);
	printf("\n");
}

static void TestListItrCountPredicateInt(void)
{
	List *ptrList = ListCreate();
	int *a, *b, *c, *d;
	size_t result;
	int item = 4;
	a = (int*)malloc(sizeof(int) * 1);
	*a = 4;
	b = (int*)malloc(sizeof(int) * 1);
	*b = 4;
	c = (int*)malloc(sizeof(int) * 1);
	*c = 4;
	d = (int*)malloc(sizeof(int) * 1);
	*d = 4;
	ListPushHead(ptrList, a);
	ListPushHead(ptrList, b);
	ListPushHead(ptrList, c);
	ListPushHead(ptrList, d);
	result = ListItrCountIf(ListItrBegin(ptrList), ListItrEnd(ptrList), PredicateFunctionForInt ,&item); /*begin*/
	if(result == 4 )
	{
		printf("TestListItrCountPredicateInt **PASS**\n");
	}
	else
	{
		printf("TestListItrCountPredicateInt !!**FAIL**!!\n");
	}
	ListDestroy(&ptrList, NULL);
	printf("\n");
}


static void TestListItrForEachBeginIsNull(void)
{
	List *ptrList = ListCreate();
	if(ListItrForEach(NULL, ListItrEnd(ptrList), PredicateFunctionForInt,NULL) == NULL)
	{
		printf("TestListItrForEachBeginIsNull **PASS**\n");
	}
	else
	{
		printf("TestListItrForEachBeginIsNull !!**FAIL**!!\n");
	}
	ListDestroy(&ptrList, NULL);
	printf("\n");
}

static void TestListItrForEachEndIsNull(void)
{
	List *ptrList = ListCreate();
	if(ListItrForEach(ListItrBegin(ptrList), NULL , PredicateFunctionForInt,NULL) == NULL)
	{
		printf("TestListItrForEachEndIsNull **PASS**\n");
	}
	else
	{
		printf("TestListItrForEachEndIsNull !!**FAIL**!!\n");
	}
	ListDestroy(&ptrList, NULL);
	printf("\n");
}

static void TestListItrForEachFuncIsNull(void)
{
	List *ptrList = ListCreate();
	if(ListItrForEach(ListItrBegin(ptrList), ListItrEnd(ptrList) , NULL ,NULL) == NULL)
	{
		printf("TestListItrForEachFuncIsNull **PASS**\n");
	}
	else
	{
		printf("TestListItrForEachFuncIsNull !!**FAIL**!!\n");
	}
	ListDestroy(&ptrList, NULL);
	printf("\n");
}

static void TestListItrForEachPrinteInt(void)
{
	List *ptrList = ListCreate();
	int *a, *b, *c, *d, *e, *f, *g , *h;
	int item = 4;
	a = (int*)malloc(sizeof(int) * 1);
	*a = 4;
	b = (int*)malloc(sizeof(int) * 1);
	*b = 2;
	c = (int*)malloc(sizeof(int) * 1);
	*c = 4;
	d = (int*)malloc(sizeof(int) * 1);
	*d = 10;
	e = (int*)malloc(sizeof(int) * 1);
	*e = 5;
	f = (int*)malloc(sizeof(int) * 1);
	*f = 4;
	g = (int*)malloc(sizeof(int) * 1);
	*g = 12;
	h = (int*)malloc(sizeof(int) * 1);
	*h = 3;
	ListPushHead(ptrList, a);
	ListPushHead(ptrList, b);
	ListPushHead(ptrList, c);
	ListPushHead(ptrList, d);
	ListPushHead(ptrList, e);
	ListPushHead(ptrList, f);
	ListPushHead(ptrList, g);
	ListPushHead(ptrList, h);
	ListItrForEach(ListItrBegin(ptrList), ListItrEnd(ptrList), ListActionPrintForInt ,&item); 
	printf("\n");
	printf("TestListItrForEachPrinteInt **PASS**\n");
	ListDestroy(&ptrList, NULL);
	printf("\n");
}
