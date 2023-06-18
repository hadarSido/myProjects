#include <stdio.h> /*printf*/
#include <stdlib.h> /*malloc*/
#include <stddef.h> /*size_t*/
#include "vector.h" /*vector functions decleration*/
#include "genHeap.h" /*generic heap functions decleration*/
/*****************************************************************/
static int	HeapPrintInt(const void *_elem, void * _context)
{
	if(NULL == _elem )
	{
		return FALSE;
	}
	printf("%d  ", *(int*)_elem);
	return TRUE;
}

static int HeapFindInt(const void *_elem, void * _context)
{
	if(NULL == _elem )
	{
		return FALSE;
	}
	*(int*)_elem != *(int*)_context; 
	return TRUE;
}

/****************************************************************************/
static int ComperNodes(const void *_left, const void *_right)
{
	if(NULL == _left || NULL == _right)
	{
		return FALSE;
	}
	return (*(int*)_left < *(int*)_right) ? TRUE : FALSE;
}

/*******************************************************************************/
static void TestHeapBuildVectorNull(void);
static void TestHeapBuildLessIsNull(void);
static void TestHeapBuildIfMallocOK(void);

static void TestDestroyHeapIsNull(void);
static void TestDestroyHeapPointerIsNull(void);
static void TestDestroyHeapIfWorkingOK(void);
static void TestDestroyPtrVector(void);

static void TestHeapInsertHeapIsNull_HEAP_NOT_INITIALIZED(void);
static void TestHeapInsertElementIsNull_HEAP_NOT_INITIALIZED(void);
static void TestHeapInsert_HEAP_ALLOCATION_ERROR(void);
static void TestHeapInsert_HEAP_SUCCESS(void);

static void TestHeapPeekHeapNull(void);
static void TestHeapPeekTopItem(void);

static void TestHeapExtractHeapIsNull(void);
static void TestHeapExtractRemoveItem(void);

static void TestHeapSizeIfHeapNull(void);
static void TestHeapSizeIfSizeOK(void);

static void TestHeapForEachHeapIsNull(void);
static void TestHeapForEachActionIsNull(void);
static void TestHeapForEachPrintInt(void);
static void TestHeapForEachFindInt(void);

/********************************************************************************/
int main(void)
{
	printf("\n");
	TestHeapBuildVectorNull();
	TestHeapBuildLessIsNull();
	TestHeapBuildIfMallocOK();
	
	TestDestroyHeapIsNull();
	TestDestroyHeapPointerIsNull();
	TestDestroyHeapIfWorkingOK();
	TestDestroyPtrVector();

	TestHeapInsertHeapIsNull_HEAP_NOT_INITIALIZED();
	TestHeapInsertElementIsNull_HEAP_NOT_INITIALIZED();
	TestHeapInsert_HEAP_ALLOCATION_ERROR();
	TestHeapInsert_HEAP_SUCCESS();

	TestHeapPeekHeapNull();
	TestHeapPeekTopItem();

	TestHeapExtractHeapIsNull();
	TestHeapExtractRemoveItem();
	
	TestHeapSizeIfHeapNull();
	TestHeapSizeIfSizeOK();

	TestHeapForEachHeapIsNull();
	TestHeapForEachActionIsNull();
	TestHeapForEachPrintInt();
	TestHeapForEachFindInt();


	return 0;
	
}
static void TestHeapBuildVectorNull(void)
{
	Heap *ptrHeap;
	ptrHeap = HeapBuild(NULL, ComperNodes );
	if(ptrHeap == NULL)
	{
		printf("TestHeapBuildVectorNull **PASS**\n");
	}
	else
	{
		printf("TestHeapBuildVectorNull**FAIL**\n");
	}
	HeapDestroy(&ptrHeap);
	printf("\n");
}

static void TestHeapBuildLessIsNull(void)
{
	Heap *ptrHeap;
	Vector *addVector = VectorCreate(5,2);
	ptrHeap = HeapBuild(addVector, NULL );
	if(ptrHeap == NULL)
	{
		printf("TestHeapBuildLessIsNull **PASS**\n");
	}
	else
	{
		printf("TestHeapBuildLessIsNull**FAIL**\n");
	}
	HeapDestroy(&ptrHeap);
	VectorDestroy(&addVector, NULL);
	printf("\n");
}

static void TestHeapBuildIfMallocOK(void)
{
	int item1 = 1;
	Heap *ptrHeap;
	Vector *addVector = VectorCreate(5,2);
	ptrHeap = HeapBuild(addVector, ComperNodes);
	if(ptrHeap != NULL)
	{
		printf("TestHeapBuildIfMallocOK **PASS**\n");
	}
	else
	{
		printf("TestHeapBuildIfMallocOK**FAIL**\n");
	}
	HeapDestroy(&ptrHeap);
	VectorDestroy(&addVector, NULL);
	printf("\n");
}


static void TestDestroyHeapIsNull(void)
{
	int item1 = 1;
	Heap *ptrHeap;
	Vector *addVector = VectorCreate(5,2);
	ptrHeap = NULL;
	if(HeapDestroy(&ptrHeap) == NULL)
	{
		printf("TestDestroyHeapIsNull **PASS**\n");
	}
	else
	{
		printf("TestDestroyHeapIsNull**FAIL**\n");
	};
	VectorDestroy(&addVector, NULL);
	printf("\n");
}
static void TestDestroyHeapPointerIsNull(void)
{
	int item1 = 1;
	Heap *ptrHeap;
	Vector *addVector = VectorCreate(5,2);
	if(HeapDestroy(NULL) == NULL)
	{
		printf("TestDestroyHeapPointerIsNull **PASS**\n");
	}
	else
	{
		printf("TestDestroyHeapPointerIsNull**FAIL**\n");
	};
	VectorDestroy(&addVector, NULL);
	printf("\n");
}

static void TestDestroyHeapIfWorkingOK(void)
{
	int item1 = 1;
	Heap *ptrHeap;
	Vector *addVector = VectorCreate(5,2);
	ptrHeap = HeapBuild(addVector, ComperNodes);
	if(HeapDestroy(&ptrHeap) != NULL)
	{
		printf("TestDestroyHeapIfWorkingOK **PASS**\n");
	}
	else
	{
		printf("TestDestroyHeapIfWorkingOK**FAIL**\n");
	}
	VectorDestroy(&addVector, NULL);
	printf("\n");
}

static void TestDestroyPtrVector(void)
{
	int item1 = 1;
	Heap *ptrHeap;
	Vector *addVector = VectorCreate(5,2);
	ptrHeap = HeapBuild(addVector, ComperNodes);
	if(HeapDestroy(&ptrHeap) == addVector)
	{
		printf("TestDestroyPtrVector **PASS**\n");
	}
	else
	{
		printf("TestDestroyPtrVector**FAIL**\n");
	}
	VectorDestroy(&addVector, NULL);
	printf("\n");
}

static void TestHeapInsertHeapIsNull_HEAP_NOT_INITIALIZED(void)
{
	int item1 = 1;
	Heap *ptrHeap;
	Vector *addVector = VectorCreate(5,2);
	ptrHeap = HeapBuild(addVector, ComperNodes);
	if( HeapInsert(NULL, &item1) == HEAP_NOT_INITIALIZED)
	{
		printf("TestHeapInsertHeapIsNull_HEAP_NOT_INITIALIZED **PASS**\n");
	}
	else
	{
		printf("TestHeapInsertHeapIsNull_HEAP_NOT_INITIALIZED**FAIL**\n");
	}
	HeapDestroy(&ptrHeap);
	VectorDestroy(&addVector, NULL);
	printf("\n");
}

static void TestHeapInsertElementIsNull_HEAP_NOT_INITIALIZED(void)
{
	int item1 = 1;
	Heap *ptrHeap;
	Vector *addVector = VectorCreate(5,2);
	ptrHeap = HeapBuild(addVector, ComperNodes);
	if( HeapInsert(ptrHeap, NULL) == HEAP_NOT_INITIALIZED)
	{
		printf("TestHeapInsertElementIsNull_HEAP_NOT_INITIALIZED **PASS**\n");
	}
	else
	{
		printf("TestHeapInsertElementIsNull_HEAP_NOT_INITIALIZED**FAIL**\n");
	}
	HeapDestroy(&ptrHeap);
	VectorDestroy(&addVector, NULL);
	printf("\n");
}

static void TestHeapInsert_HEAP_ALLOCATION_ERROR(void) /*do a ail in vector append*/
{
	int item1 = 1;
	Heap *ptrHeap;
	Vector *addVector =  VectorCreate(5,2);
	ptrHeap = HeapBuild(addVector, ComperNodes);
	if( HeapInsert(ptrHeap,  &item1) == HEAP_VECTOR_APPEND_ERROR)
	{
		printf("TestHeapInsert_HEAP_ALLOCATION_ERROR **PASS**\n");
	}
	else
	{
		printf("TestHeapInsert_HEAP_ALLOCATION_ERROR**FAIL**\n");
	}
	HeapDestroy(&ptrHeap);
	VectorDestroy(&addVector, NULL);
	printf("\n");
}

static void TestHeapInsert_HEAP_SUCCESS(void)
{
	int item1 = 19;
	int item2 = 11;
	int item3 = 20;
	Heap *ptrHeap;
	Vector *addVector =  VectorCreate(5,2);
	ptrHeap = HeapBuild(addVector, ComperNodes);
	HeapInsert(ptrHeap, &item1);
	HeapInsert(ptrHeap, &item2);
	if( HeapInsert(ptrHeap,  &item3) == HEAP_SUCCESS)
	{
		printf("TestHeapInsert_HEAP_SUCCESS **PASS**\n");
	}
	else
	{
		printf("TestHeapInsert_HEAP_SUCCESS**FAIL**\n");
	}
	HeapDestroy(&ptrHeap);
	VectorDestroy(&addVector, NULL);
	printf("\n");
}

static void TestHeapPeekHeapNull(void)
{
	int item1 = 19;
	Heap *ptrHeap;
	Vector *addVector =  VectorCreate(5,2);
	ptrHeap = HeapBuild(addVector, ComperNodes);
	if(HeapPeek(NULL) == NULL)
	{
		printf("TestHeapPeekHeapNull **PASS**\n");
	}
	else
	{
		printf("TestHeapPeekHeapNull**FAIL**\n");
	}
	HeapDestroy(&ptrHeap);
	VectorDestroy(&addVector, NULL);
	printf("\n");
}

static void TestHeapPeekTopItem(void)
{
	int item1 = 19;
	int item2 = 11;
	int item3 = 20;
	int* item= &item3;
	const void* topItem;
	Heap *ptrHeap;
	Vector *addVector =  VectorCreate(5,2);
	ptrHeap = HeapBuild(addVector, ComperNodes);
	HeapInsert(ptrHeap, &item1);
	HeapInsert(ptrHeap, &item2);
	HeapInsert(ptrHeap, &item3);
	topItem = HeapPeek(ptrHeap);
	if(item == topItem )
	{
		printf("TestHeapPeekTopItem **PASS**\n");
	}
	else
	{
		printf("TestHeapPeekTopItem**FAIL**\n");
	}
	HeapDestroy(&ptrHeap);
	VectorDestroy(&addVector, NULL);
	printf("\n");
}

static void TestHeapExtractHeapIsNull(void)
{
	int item1 = 19;
	int item2 = 11;
	int item3 = 20;
	int* item= &item3;
	const void* topItem;
	Heap *ptrHeap;
	Vector *addVector =  VectorCreate(5,2);
	ptrHeap = HeapBuild(addVector, ComperNodes);
	HeapInsert(ptrHeap, &item1);
	HeapInsert(ptrHeap, &item2);
	HeapInsert(ptrHeap, &item3);
	topItem = HeapPeek(ptrHeap);
	if(HeapExtract(NULL) == NULL )
	{
		printf("TestHeapExtractHeapIsNull **PASS**\n");
	}
	else
	{
		printf("TestHeapExtractHeapIsNull**FAIL**\n");
	}
	HeapDestroy(&ptrHeap);
	VectorDestroy(&addVector, NULL);
	printf("\n");
}


static void TestHeapExtractRemoveItem(void)
{
	int item1 = 19;
	int item2 = 11;
	int item3 = 20;
	int* item = &item3;
	void* topItem;
	Heap *ptrHeap;
	Vector *addVector =  VectorCreate(5,2);
	ptrHeap = HeapBuild(addVector, ComperNodes);
	HeapInsert(ptrHeap, &item1);
	HeapInsert(ptrHeap, &item2);
	HeapInsert(ptrHeap, &item3);
	topItem = HeapExtract(ptrHeap);
	if(topItem == item)
	{
		printf("TestHeapExtractRemoveItem **PASS**\n");
	}
	else
	{
		printf("TestHeapExtractRemoveItem**FAIL**\n");
	}
	HeapDestroy(&ptrHeap);
	VectorDestroy(&addVector, NULL);
	printf("\n");
}

static void TestHeapSizeIfHeapNull(void)
{
	int item1 = 19;
	void* topItem;
	Heap *ptrHeap;
	Vector *addVector =  VectorCreate(5,2);
	ptrHeap = HeapBuild(addVector, ComperNodes);
	HeapInsert(ptrHeap, &item1);
	if(HeapSize(NULL) == 0)
	{
		printf("TestHeapSizeIfHeapNull **PASS**\n");
	}
	else
	{
		printf("TestHeapSizeIfHeapNull**FAIL**\n");
	}
	HeapDestroy(&ptrHeap);
	VectorDestroy(&addVector, NULL);
	printf("\n");
}

static void TestHeapSizeIfSizeOK(void)
{
	int item1 = 19;
	int item2 = 11;
	int item3 = 20;
	int* item = &item3;
	Vector *addVector =  VectorCreate(5,2);
	Heap* ptrHeap = HeapBuild(addVector, ComperNodes);
	HeapInsert(ptrHeap, &item1);
	HeapInsert(ptrHeap, &item2);
	HeapInsert(ptrHeap, &item3);
	if(HeapSize(ptrHeap) == 3)
	{
		printf("TestHeapSizeIfSizeOK **PASS**\n");
	}
	else
	{
		printf("TestHeapSizeIfSizeOK**FAIL**\n");
	}
	HeapDestroy(&ptrHeap);
	VectorDestroy(&addVector, NULL);
	printf("\n");
}

static void TestHeapForEachHeapIsNull(void)
{
	int item1=3;
	int item2=2;
	int item3=1;
	int num = 5;
	Vector *addVector = VectorCreate(2,2);
	Heap* ptrHeap = HeapBuild(addVector, ComperNodes);
	HeapInsert(ptrHeap, &item1);
	HeapInsert(ptrHeap, &item2);
	HeapInsert(ptrHeap, &item3);
	if(HeapForEach(NULL, HeapPrintInt, &num) == 0)
	{
		printf("TestHeapForEachHeapIsNull **PASS**\n");
	}
	else
	{
		printf("TestHeapForEachHeapIsNull **FAIL**\n");
	}
	HeapDestroy(&ptrHeap);
	VectorDestroy(&addVector, NULL);
	printf("\n");
}

static void TestHeapForEachActionIsNull(void)
{
	int item1=3;
	int item2=2;
	int item3=1;
	int num = 5;
	Vector *addVector = VectorCreate(2,2);
	Heap* ptrHeap = HeapBuild(addVector, ComperNodes);
	HeapInsert(ptrHeap, &item1);
	HeapInsert(ptrHeap, &item2);
	HeapInsert(ptrHeap, &item3);
	if(HeapForEach(ptrHeap, NULL, &num) == 0)
	{
		printf("TestHeapForEachActionIsNull **PASS**\n");
	}
	else
	{
		printf("TestHeapForEachActionIsNull **FAIL**\n");
	}
	HeapDestroy(&ptrHeap);
	VectorDestroy(&addVector, NULL);
	printf("\n");
}

static void TestHeapForEachPrintInt(void)
{
	int item1=3;
	int item2=20;
	int item3=1;
	int item4=3;
	int item5=11;
	int item6=5;
	int item7=3;
	int item8=10;
	int item9=7;
	int num = 20;
	size_t index;
	Vector *addVector = VectorCreate(10,2);
	Heap* ptrHeap = HeapBuild(addVector, ComperNodes);
	HeapInsert(ptrHeap, &item1);
	HeapInsert(ptrHeap, &item2);
	HeapInsert(ptrHeap, &item3);
	HeapInsert(ptrHeap, &item4);
	HeapInsert(ptrHeap, &item5);
	HeapInsert(ptrHeap, &item6);
	HeapInsert(ptrHeap, &item7);
	HeapInsert(ptrHeap, &item8);
	HeapInsert(ptrHeap, &item9);
	index = HeapForEach(ptrHeap, HeapPrintInt, NULL);
	if(index = 8)
	{
		printf("\n");
		printf("TestHeapForEachPrintInt **PASS**\n");
	}
	else
	{
		printf("\n");
		printf("TestHeapForEachPrintInt **FAIL**\n");
	}
	HeapDestroy(&ptrHeap);
	VectorDestroy(&addVector, NULL);
	printf("\n");
}

static void TestHeapForEachFindInt(void)
{
	int item1=3;
	int item2=20;
	int item3=1;
	int item4=3;
	int item5=11;
	int item6=5;
	int item7=3;
	int item8=10;
	int item9=7;
	int num = 20;
	size_t index;
	Vector *addVector = VectorCreate(10,2);
	Heap* ptrHeap = HeapBuild(addVector, ComperNodes);
	HeapInsert(ptrHeap, &item1);
	HeapInsert(ptrHeap, &item2);
	HeapInsert(ptrHeap, &item3);
	HeapInsert(ptrHeap, &item4);
	HeapInsert(ptrHeap, &item5);
	HeapInsert(ptrHeap, &item6);
	HeapInsert(ptrHeap, &item7);
	HeapInsert(ptrHeap, &item8);
	HeapInsert(ptrHeap, &item9);
	index = HeapForEach(ptrHeap, HeapFindInt, &num);
	if(index = 1)
	{
		printf("\n");
		printf("TestHeapForEachPrintInt **PASS**\n");
	}
	else
	{
		printf("\n");
		printf("TestHeapForEachPrintInt **FAIL**\n");
	}
	HeapDestroy(&ptrHeap);
	VectorDestroy(&addVector, NULL);
	printf("\n");
}

