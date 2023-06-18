#include <stdio.h> /*printf*/
#include <string.h> /*memcpy*/
#include <stdlib.h> /*malloc*/
#include <stddef.h> /*size_t*/
#include "vector.h" /*vector functions decleration*/

static void TestVectorCreatCheckNumbersBigerThanZero(void);
static void TestVectorCreatCheckNumbersBlockSizeZero(void);
static void TestVectorCreatCheckNumbersSizeZero(void);
static void TestVectorCreatCheckNumbersZeroes(void);
static void TestVectorCreatCheckNumbersSizeMinosTwo(void);

static void TestVectorDestroyWorking(void);
static void TestVectorDestroyVectorNULL(void);

static void VectorAppend_VECTOR_NOT_INITIALIZED(void);
static void VectorAppendItem_VECTOR_NOT_INITIALIZED(void);
static void VectorAppendItem_VECTOR_OVERFLOW(void);
static void VectorAppendItem_VECTOR_SUCCESS(void);
static void VectorAppendItemGetNumOfItems(void);
static void VectorAppendItemGetSize(void);

static void VectorRemoveItem(void);
static void VectorRemoveSize(void);
static void VectorRemoveVectorNULL(void);
static void VectorRemoveValueNULL(void);
static void VectorRemove_VECTOR_SUCCESS(void);
static void TestVectorRemoveItem_VECTOR_UNDERFLOW(void);
static void VectorRemoveOriginalSize(void);

static void TestVectorGetVector_VECTOR_NOT_INITIALIZED(void);
static void TestVectorGetItem_VECTOR_NOT_INITIALIZED(void);
static void TestVectorGet_VECTOR_SUCCESS(void);
static void TestVectorGetCurectItem(void);
static void TestVectorGet_VECTOR_INDEX_OUT_OF_BOUNDS_ERROR(void);

static void TestVectorSetVector_VECTOR_NOT_INITIALIZED(void);
static void TestVectorSetItem_VECTOR_NOT_INITIALIZED(void);
static void TestVectorSet_VECTOR_INDEX_OUT_OF_BOUNDS_ERROR(void);
static void TestVectorSetCurectIndex(void);
static void TestVectorSet_VECTOR_SUCCESS(void);

static void TestVectorSize_NULL(void);
static void TestVectorSizeOK(void);

static void TestVectorCapacity_NULL(void);
static void TestVectorCapacityOK(void);

static void TestVectorForEach_Vector_NULL(void);
static void TestVectorForEach_Action_NULL(void);
static void TestVectorForEach_PrintInt(void);
static void TestVectorForEach_FindInt(void);
/**********************************************************************/

static int VectorPrintInt(void* _element, size_t _index, void* _context)
{
	if(NULL == _element )
	{
		return FALSE;
	}
	printf("m_nOfItems[%ld] = %d\n", _index, *(int*)_element);
	return TRUE;
}
/****************************************************************/
static int VectorFindInt(void* _element, size_t _index, void* _context)
{
	if(NULL == _element )
	{
		return FALSE;
	}
	return *(int*)_element != *(int*)_context ; 
}
/****************************************************************/

int main(void)
{
	
	TestVectorCreatCheckNumbersBigerThanZero();
	TestVectorCreatCheckNumbersBlockSizeZero();
	TestVectorCreatCheckNumbersSizeZero();
	TestVectorCreatCheckNumbersZeroes();
	TestVectorCreatCheckNumbersSizeMinosTwo();

	TestVectorDestroyWorking();
	TestVectorDestroyVectorNULL();

	VectorAppend_VECTOR_NOT_INITIALIZED();
	VectorAppendItem_VECTOR_NOT_INITIALIZED();
	VectorAppendItem_VECTOR_OVERFLOW();
	VectorAppendItem_VECTOR_SUCCESS();
	VectorAppendItemGetNumOfItems();
	VectorAppendItemGetSize();

	VectorRemoveItem();
	VectorRemoveSize();
	VectorRemoveVectorNULL();
	VectorRemoveValueNULL();
	VectorRemove_VECTOR_SUCCESS();
	TestVectorRemoveItem_VECTOR_UNDERFLOW();
	VectorRemoveOriginalSize();

	TestVectorGetVector_VECTOR_NOT_INITIALIZED();
	TestVectorGetItem_VECTOR_NOT_INITIALIZED();
	TestVectorGet_VECTOR_SUCCESS();
	TestVectorGetCurectItem();
	TestVectorGet_VECTOR_INDEX_OUT_OF_BOUNDS_ERROR();

	TestVectorSetVector_VECTOR_NOT_INITIALIZED();
	TestVectorSetItem_VECTOR_NOT_INITIALIZED();
	TestVectorSet_VECTOR_INDEX_OUT_OF_BOUNDS_ERROR();
	TestVectorSetCurectIndex();
	TestVectorSet_VECTOR_SUCCESS();

	TestVectorSize_NULL();
	TestVectorSizeOK();

	TestVectorCapacity_NULL();
	TestVectorCapacityOK();

	TestVectorForEach_Vector_NULL();
	TestVectorForEach_Action_NULL();
	TestVectorForEach_PrintInt();
	TestVectorForEach_FindInt();

	
	return 0;
	
}

static void TestVectorCreatCheckNumbersBigerThanZero(void)
{
	Vector *addVector;
	addVector = VectorCreate(5,2);
	if(NULL != addVector)
	{
		printf("TestVectorCreatCheckNumbersBigerThanZero **PASS**\n");
	}
	else
	{
		printf("TestVectorCreatCheckNumbersBigerThanZero **FAIL**\n");
	}
	VectorDestroy(&addVector, NULL);
	printf("\n");
}

static void TestVectorCreatCheckNumbersBlockSizeZero(void)
{
	Vector *addVector;
	addVector = VectorCreate(2,0);
	if(addVector != NULL)
	{
		printf("TestVectorCreatCheckNumbersBlockSizeZero **PASS**\n");
	}
	else
	{
		printf("TestVectorCreatCheckNumbersBlockSizeZero **FAIL**\n");
	}
	VectorDestroy(&addVector, NULL);
	printf("\n");
}

static void TestVectorCreatCheckNumbersSizeZero(void)
{
	Vector *addVector;
	addVector = VectorCreate(0,2);
	if(addVector != NULL)
	{
		printf("TestVectorCreatCheckNumbersSizeZero **PASS**\n");
	}
	else
	{
		printf("TestVectorCreatCheckNumbersSizeZero **FAIL**\n");
	}
	VectorDestroy(&addVector, NULL);
	printf("\n");
}

static void TestVectorCreatCheckNumbersZeroes(void)
{
	Vector *addVector;
	addVector = VectorCreate(0,0);
	if(addVector == NULL)
	{
		printf("TestVectorCreatCheckNumbersZeroes **PASS**\n");
	}
	else
	{
		printf("TestVectorCreatCheckNumbersZeroes **FAIL**\n");
	}
	printf("\n");
}

static void TestVectorCreatCheckNumbersSizeMinosTwo(void)
{
	Vector *addVector;
	addVector = VectorCreate(-2,0);
	if(addVector == NULL)
	{
		printf("TestVectorCreatCheckNumbersSizeMinosTwo **PASS**\n");
	}
	else
	{
		printf("TestVectorCreatCheckNumbersSizeMinosTwo **FAIL**\n");
	}
	printf("\n");
}
static void TestVectorDestroyWorking(void)
{
	Vector *addVector = VectorCreate(5,2);
	VectorDestroy(&addVector, NULL);
	if(addVector == NULL)
	{
		printf("TestVectorDestroyWorking **PASS**\n");
	}
	else
	{
		printf("TestVectorDestroyWorking **FAIL**\n");
	}
	printf("\n");
}

static void TestVectorDestroyVectorNULL(void)
{
	Vector *addVector = VectorCreate(5,2);
	VectorDestroy(NULL, NULL);
	if(addVector != NULL)
	{
		printf("TestVectorDestroyWorking **PASS**\n");
	}
	else
	{
		printf("TestVectorDestroyWorking **FAIL**\n");
	}
	printf("\n");
}

static void VectorAppend_VECTOR_NOT_INITIALIZED(void)
{

	int* item;
	Vector *addVector = VectorCreate(5,2);
	if(VectorAppend(NULL, &item) == VECTOR_NOT_INITIALIZED)
	{
		printf("VectorAppend_VECTOR_NOT_INITIALIZED **PASS**\n");
	}
	else
	{
		printf("VectorAppend_VECTOR_NOT_INITIALIZED **FAIL**\n");
	}
	VectorDestroy(&addVector, NULL);
	printf("\n");
}

static void VectorAppendItem_VECTOR_NOT_INITIALIZED(void)
{
	Vector *addVector = VectorCreate(5,2);
	if(VectorAppend(addVector, NULL) == VECTOR_NOT_INITIALIZED)
	{
		printf("VectorAppendItem_VECTOR_NOT_INITIALIZED **PASS**\n");
	}
	else
	{
		printf("VectorAppendItem_VECTOR_NOT_INITIALIZED **FAIL**\n");
	}
	VectorDestroy(&addVector, NULL);
	printf("\n");
}
static void VectorAppendItem_VECTOR_OVERFLOW(void)
{
	int item = 3;
	Vector *addVector;
	addVector = VectorCreate(2,0);
	VectorAppend(addVector, &item);
	VectorAppend(addVector, &item);
	if(VectorAppend(addVector, &item) == VECTOR_OVERFLOW)
	{
		printf("VectorAppendItem_VECTOR_OVERFLOW **PASS**\n");
	}
	else
	{
		printf("VectorAppendItem_VECTOR_OVERFLOW **FAIL**\n");
	}
	
	VectorDestroy(&addVector, NULL);
	printf("\n");
}

static void VectorAppendItem_VECTOR_SUCCESS(void)
{
	int item = 3;
	Vector *addVector;
	addVector = VectorCreate(5,0);
	VectorAppend(addVector, &item);
	VectorAppend(addVector, &item);
	if(VectorAppend(addVector, &item) == VECTOR_SUCCESS)
	{
		printf("VectorAppendItem_VECTOR_SUCCESS **PASS**\n");
	}
	else
	{
		printf("VectorAppendItem_VECTOR_SUCCESS **FAIL**\n");
	}
	
	VectorDestroy(&addVector, NULL);
	printf("\n");
}

static void VectorAppendItemGetSize(void)
{
	int item = 3;
	Vector *addVector;
	addVector = VectorCreate(2,2);
	VectorAppend(addVector, &item);
	VectorAppend(addVector, &item);
	VectorAppend(addVector, &item);
	if(GetSize(addVector) == 4)
	{
		printf("VectorAppendItemGetSize **PASS**\n");
	}
	else
	{
		printf("VectorAppendItemGetSize **FAIL**\n");
	}
	VectorDestroy(&addVector, NULL);
	printf("\n");
}

static void VectorAppendItemGetNumOfItems(void)
{
	int item = 3;
	Vector *addVector;
	addVector = VectorCreate(2,2);
	VectorAppend(addVector, &item);
	VectorAppend(addVector, &item);
	VectorAppend(addVector, &item);
	if(GetnItems(addVector) == 3)
	{
		printf("VectorAppendItemGetNumOfItems **PASS**\n");
	}
	else
	{
		printf("VectorAppendItemGetNumOfItems **FAIL**\n");
	}
	VectorDestroy(&addVector, NULL);
	printf("\n");
}

static void VectorRemoveVectorNULL(void)
{
	int item=3;
	Vector *addVector;
	void* itemRemov;
	addVector = VectorCreate(5,2);
	VectorAppend(addVector, &item);
	VectorAppend(addVector, &item);
	VectorAppend(addVector, &item);
	if(VectorRemove(NULL, &itemRemov) == VECTOR_NOT_INITIALIZED)
	{
		printf("VectorRemoveVectorNULL **PASS**\n");
	}
	else
	{
		printf("VectorRemoveVectorNULL **FAIL**\n");
	}
	VectorDestroy(&addVector, NULL);
	printf("\n");
}

static void VectorRemoveValueNULL(void)
{
	int item=3;
	Vector *addVector;
	addVector = VectorCreate(5,2);
	VectorAppend(addVector, &item);
	VectorAppend(addVector, &item);
	VectorAppend(addVector, &item);
	if(VectorRemove(addVector, NULL) == VECTOR_NOT_INITIALIZED)
	{
		printf("VectorRemoveValueNULL **PASS**\n");
	}
	else
	{
		printf("VectorRemoveValueNULL **FAIL**\n");
	}
	VectorDestroy(&addVector, NULL);
	printf("\n");
}

static void VectorRemoveItem(void)
{
	int item=3;
	void* itemRemov;
	Vector *addVector;
	addVector = VectorCreate(2,2);
	VectorAppend(addVector, &item);
	VectorAppend(addVector, &item);
	VectorRemove(addVector, &itemRemov);
	if(GetnItems(addVector) == 1)
	{
		printf("VectorRemoveItem **PASS**\n");
	}
	else
	{
		printf("VectorRemoveItem **FAIL**\n");
	}
	VectorDestroy(&addVector, NULL);
	printf("\n");
}
static void VectorRemoveSize(void)
{
	int item=3;
	void* itemRemov;
	Vector *addVector;
	addVector = VectorCreate(2,2);
	VectorAppend(addVector, &item);
	VectorAppend(addVector, &item);
	VectorRemove(addVector, &itemRemov);
	if(GetSize(addVector) == 2)
	{
		printf("VectorRemoveSize **PASS**\n");
	}
	else
	{
		printf("VectorRemoveSize **FAIL**\n");
	}
	VectorDestroy(&addVector, NULL);
	printf("\n");
}

static void VectorRemoveOriginalSize(void)
{
	int item=3;
	void* itemRemov;
	Vector *addVector;
	addVector = VectorCreate(2,2);
	VectorAppend(addVector, &item);
	VectorAppend(addVector, &item);
	VectorRemove(addVector, &itemRemov);
	if(GetOriginalSize(addVector) == 2)
	{
		printf("VectorRemoveOriginalSize **PASS**\n");
	}
	else
	{
		printf("VectorRemoveOriginalSize **FAIL**\n");
	}
	VectorDestroy(&addVector, NULL);
	printf("\n");
}

static void VectorRemove_VECTOR_SUCCESS(void)
{
	int item=3;
	void* itemRemov;
	Vector *addVector = VectorCreate(2,2);
	VectorAppend(addVector, &item);
	VectorAppend(addVector, &item);
	VectorAppend(addVector, &item);
	if(VectorRemove(addVector, &itemRemov) == VECTOR_SUCCESS)
	{
		printf("VectorRemove_VECTOR_SUCCESS **PASS**\n");
	}
	else
	{
		printf("VectorRemove_VECTOR_SUCCESS **FAIL**\n");
	}
	VectorDestroy(&addVector, NULL);
	printf("\n");
}

static void TestVectorRemoveItem_VECTOR_UNDERFLOW(void)
{
	int item=3;
	void* itemRemov;
	Vector *addVector;
	addVector = VectorCreate(2,2);
	VectorAppend(addVector, &item);
	VectorAppend(addVector, &item);
	VectorRemove(addVector, &itemRemov);
	VectorRemove(addVector, &itemRemov);
	VectorRemove(addVector, &itemRemov);
	if(VectorRemove(addVector, &itemRemov) == VECTOR_UNDERFLOW)
	{
		printf("TestVectorRemoveItem_VECTOR_UNDERFLOW **PASS**\n");
	}
	else
	{
		printf("TestVectorRemoveItem_VECTOR_UNDERFLOW **FAIL**\n");
	}
	VectorDestroy(&addVector, NULL);
	printf("\n");
}

static void TestVectorGetVector_VECTOR_NOT_INITIALIZED(void)
{
	int item=3;
	int index=1;
	void* itemGet;
	Vector *addVector;
	VectorAppend(addVector, &item);
	if(VectorGet(NULL,index, &itemGet) == VECTOR_NOT_INITIALIZED)
	{
		printf("TestVectorGetVector_VECTOR_NOT_INITIALIZED **PASS**\n");
	}
	else
	{
		printf("TestVectorGetVector_VECTOR_NOT_INITIALIZED **FAIL**\n");
	}
	VectorDestroy(&addVector, NULL);
	printf("\n");
}

static void TestVectorGetItem_VECTOR_NOT_INITIALIZED(void)
{
	int item=3;
	int index=1;
	void* itemGet;
	Vector *addVector;
	addVector = VectorCreate(2,2);
	VectorAppend(addVector, &item);
	if(VectorGet(addVector,index, NULL) == VECTOR_NOT_INITIALIZED)
	{
		printf("TestVectorGetItem_VECTOR_NOT_INITIALIZED **PASS**\n");
	}
	else
	{
		printf("TestVectorGetItem_VECTOR_NOT_INITIALIZED **FAIL**\n");
	}
	VectorDestroy(&addVector, NULL);
	printf("\n");
}

static void TestVectorGet_VECTOR_SUCCESS(void)
{
	int item1=3;
	int item2=4;
	int item3=5;
	int index=1;
	void* itemGet;
	Vector *addVector;
	addVector = VectorCreate(2,2);
	VectorAppend(addVector, &item1);
	VectorAppend(addVector, &item2);
	VectorAppend(addVector, &item3);
	if(VectorGet(addVector,index, &itemGet) == VECTOR_SUCCESS)
	{
		printf("TestVectorGet_VECTOR_SUCCESS **PASS**\n");
	}
	else
	{
		printf("TestVectorGet_VECTOR_SUCCESS **FAIL**\n");
	}
	VectorDestroy(&addVector, NULL);
	printf("\n");
}


static void TestVectorGetCurectItem(void)
{
	int item1=3;
	int item2=4;
	int item3=5;
	int index=1;
	void* itemGet;
	Vector *addVector;
	addVector = VectorCreate(2,2);
	VectorAppend(addVector, &item1);
	VectorAppend(addVector, &item2);
	VectorAppend(addVector, &item3);
	VectorGet(addVector,index, &itemGet);
	if(*(int*)itemGet == 4)
	{
		printf("TestVectorGetCurectItem **PASS**\n");
	}
	else
	{
		printf("TestVectorGetCurectItem **FAIL**\n");
	}
	VectorDestroy(&addVector, NULL);
	printf("\n");
}


static void TestVectorGet_VECTOR_INDEX_OUT_OF_BOUNDS_ERROR(void)
{
	int item1=3;
	int item2=4;
	int item3=5;
	int index=5;
	void* itemGet;
	Vector *addVector;
	addVector = VectorCreate(2,2);
	VectorAppend(addVector, &item1);
	VectorAppend(addVector, &item2);
	VectorAppend(addVector, &item3);
	if(VectorGet(addVector,index, &itemGet) == VECTOR_INDEX_OUT_OF_BOUNDS_ERROR)
	{
		printf("TestVectorGet_VECTOR_INDEX_OUT_OF_BOUNDS_ERROR **PASS**\n");
	}
	else
	{
		printf("TestVectorGet_VECTOR_INDEX_OUT_OF_BOUNDS_ERROR **FAIL**\n");
	}
	VectorDestroy(&addVector, NULL);
	printf("\n");
}

static void TestVectorSetVector_VECTOR_NOT_INITIALIZED(void)
{
	int item=3;
	int index=1;
	void* itemGet;
	Vector *addVector = VectorCreate(2,2);
	VectorAppend(addVector, &item);
	if(VectorSet(NULL,index, &itemGet) == VECTOR_NOT_INITIALIZED)
	{
		printf("TestVectorSetVector_VECTOR_NOT_INITIALIZED **PASS**\n");
	}
	else
	{
		printf("TestVectorSetVector_VECTOR_NOT_INITIALIZED **FAIL**\n");
	}
	VectorDestroy(&addVector, NULL);
	printf("\n");
}

static void TestVectorSetItem_VECTOR_NOT_INITIALIZED(void)
{
	int item=3;
	int index=1;
	void* itemGet;
	Vector *addVector = VectorCreate(2,2);
	VectorAppend(addVector, &item);
	if(VectorSet(addVector,index, NULL) == VECTOR_NOT_INITIALIZED)
	{
		printf("TestVectorSetItem_VECTOR_NOT_INITIALIZED **PASS**\n");
	}
	else
	{
		printf("TestVectorSetItem_VECTOR_NOT_INITIALIZED **FAIL**\n");
	}
	VectorDestroy(&addVector, NULL);
	printf("\n");
}

static void TestVectorSet_VECTOR_INDEX_OUT_OF_BOUNDS_ERROR(void)
{
	int item=3;
	int index=5;
	void* itemGet;
	Vector *addVector = VectorCreate(2,2);
	VectorAppend(addVector, &item);
	if(VectorSet(addVector,index, &itemGet) == VECTOR_INDEX_OUT_OF_BOUNDS_ERROR)
	{
		printf("TestVectorSet_VECTOR_INDEX_OUT_OF_BOUNDS_ERROR **PASS**\n");
	}
	else
	{
		printf("TestVectorSet_VECTOR_INDEX_OUT_OF_BOUNDS_ERROR **FAIL**\n");
	}
	VectorDestroy(&addVector, NULL);
	printf("\n");
}

static void TestVectorSetCurectIndex(void)
{
	int item1=3;
	int item2=2;
	int item3=1;
	int item4=7;
	int index=2;
	void* itemGet;
	Vector *addVector = VectorCreate(2,2);
	VectorAppend(addVector, &item1);
	VectorAppend(addVector, &item2);
	VectorAppend(addVector, &item3);
	VectorAppend(addVector, &item4);
	VectorGet(addVector,2, &itemGet);
	VectorSet(addVector,2, &itemGet);
	if(*(int*)itemGet == 1 )
	{
		printf("TestVectorSetCurectIndex **PASS**\n");
	}
	else
	{
		printf("TestVectorSetCurectIndex **FAIL**\n");
	}
	VectorDestroy(&addVector, NULL);
	printf("\n");
}
static void TestVectorSet_VECTOR_SUCCESS(void)
{
	int item1=3;
	int item2=2;
	int item3=1;
	int item4=7;
	int index=2;
	void* itemGet;
	Vector *addVector = VectorCreate(2,2);
	VectorAppend(addVector, &item1);
	VectorAppend(addVector, &item2);
	VectorAppend(addVector, &item3);
	VectorAppend(addVector, &item4);
	VectorGet(addVector,2, &itemGet);
	if(VectorSet(addVector,2, &itemGet) == VECTOR_SUCCESS)
	{
		printf("TestVectorSet_VECTOR_SUCCESS **PASS**\n");
	}
	else
	{
		printf("TestVectorSet_VECTOR_SUCCESS **FAIL**\n");
	}
	VectorDestroy(&addVector, NULL);
	printf("\n");
}


static void TestVectorSize_NULL(void)
{
	int item1=3;
	void* itemGet;
	Vector *addVector = VectorCreate(2,2);
	VectorAppend(addVector, &item1);
	if(VectorSize(NULL) == 0)
	{
		printf("TestVectorSize_NULL **PASS**\n");
	}
	else
	{
		printf("TestVectorSize_NULL **FAIL**\n");
	}
	VectorDestroy(&addVector, NULL);
	printf("\n");
}

static void TestVectorSizeOK(void)
{
	int item1=3;
	int item2=2;
	int item3=1;
	int item4=7;
	int index=2;
	void* itemGet;
	Vector *addVector = VectorCreate(2,2);
	VectorAppend(addVector, &item1);
	VectorAppend(addVector, &item2);
	VectorAppend(addVector, &item3);
	VectorAppend(addVector, &item4);
	VectorGet(addVector,2, &itemGet);
	VectorSet(addVector,2, &itemGet);
	if(VectorSize(addVector) == 4)
	{
		printf("TestVectorSizeOK **PASS**\n");
	}
	else
	{
		printf("TestVectorSizeOK **FAIL**\n");
	}
	VectorDestroy(&addVector, NULL);
	printf("\n");
}


static void TestVectorCapacity_NULL(void)
{
	int item1=3;
	void* itemGet;
	Vector *addVector = VectorCreate(2,2);
	VectorAppend(addVector, &item1);
	if(VectorCapacity(NULL) == 0)
	{
		printf("TestVectorCapacity_NULL **PASS**\n");
	}
	else
	{
		printf("TestVectorCapacity_NULL **FAIL**\n");
	}
	VectorDestroy(&addVector, NULL);
	printf("\n");
}

static void TestVectorCapacityOK(void)
{
	int item1=3;
	int item2=2;
	int item3=1;
	int item4=7;
	int index=2;
	void* itemGet;
	Vector *addVector = VectorCreate(2,2);
	VectorAppend(addVector, &item1);
	VectorAppend(addVector, &item2);
	VectorAppend(addVector, &item3);
	VectorAppend(addVector, &item4);
	VectorGet(addVector,2, &itemGet);
	VectorSet(addVector,2, &itemGet);
	if(VectorCapacity(addVector) == 4)
	{
		printf("TestVectorCapacityOK **PASS**\n");
	}
	else
	{
		printf("TestVectorCapacityOK **FAIL**\n");
	}
	VectorDestroy(&addVector, NULL);
	printf("\n");
}

static void TestVectorForEach_Vector_NULL(void)
{
	int item=3 , num = 50;
	int index=5;
	void* itemGet;
	Vector *addVector = VectorCreate(2,2);
	VectorAppend(addVector, &item);
	if(VectorForEach(NULL, VectorPrintInt, &num) == 0)
	{
		printf("TestVectorForEach_Vector_NULL **PASS**\n");
	}
	else
	{
		printf("TestVectorForEach_Vector_NULL **FAIL**\n");
	}
	VectorDestroy(&addVector, NULL);
	printf("\n");
}


static void TestVectorForEach_Action_NULL(void)
{
	int item=3 , num = 50;
	int index=5;
	void* itemGet;
	Vector *addVector = VectorCreate(2,2);
	VectorAppend(addVector, &item);
	if(VectorForEach(addVector, NULL, &num) == 0)
	{
		printf("TestVectorForEach_Action_NULL **PASS**\n");
	}
	else
	{
		printf("TestVectorForEach_Action_NULL **FAIL**\n");
	}
	VectorDestroy(&addVector, NULL);
	printf("\n");
}


static void TestVectorForEach_PrintInt(void)
{
	int item1=3;
	int item2=2;
	int item3=1;
	int item4=7;
	int item5=10;
	void* itemGet;
	Vector *addVector = VectorCreate(2,2);
	VectorAppend(addVector, &item1);
	VectorAppend(addVector, &item2);
	VectorAppend(addVector, &item3);
	VectorAppend(addVector, &item4);
	VectorAppend(addVector, &item5);
	if(VectorForEach(addVector, VectorPrintInt, NULL) == 5)
	{
		printf("TestVectorForEach_PrintInt **PASS**\n");
	}
	else
	{
		printf("TestVectorForEach_PrintInt **FAIL**\n");
	}
	VectorDestroy(&addVector, NULL);
	printf("\n");
}

static void TestVectorForEach_FindInt(void)
{
	int item1=3;
	int item2=2;
	int item3=1;
	int item4=7;
	int item5=10;
	int find = 1;
	void* itemGet;
	Vector *addVector = VectorCreate(2,2);
	VectorAppend(addVector, &item1);
	VectorAppend(addVector, &item2);
	VectorAppend(addVector, &item3);
	VectorAppend(addVector, &item4);
	VectorAppend(addVector, &item5);
	if(VectorForEach(addVector, VectorFindInt, &find) == 2)
	{
		printf("TestVectorForEach_FindInt **PASS**\n");
	}
	else
	{
		printf("TestVectorForEach_FindInt **FAIL**\n");
	}
	VectorDestroy(&addVector, NULL);
	printf("\n");
}





