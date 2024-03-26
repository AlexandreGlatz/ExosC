#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include "StringEx.h"
#include "Liste.h"

typedef struct IntArray
{
    int* pContent;

    int iSize;
    int iCapacity;
} IntArray;

void IsInRange(IntArray* pIntArray, int iIndex)
{
    if (iIndex < 0 || iIndex > pIntArray->iSize)
    {
        printf("L'index n'est pas dans la liste");
    }
}

void ReallocMem(IntArray* pIntArray, int capacity)
{
    int* temp = (int*)realloc(pIntArray->pContent, sizeof(int) * capacity);

    if (temp == NULL)
    {
        free(pIntArray->pContent);
        exit(1);
    }

    pIntArray->pContent = temp;
}

void UpdateCapacity(IntArray* pIntArray)
{
    if (pIntArray->iSize >= pIntArray->iCapacity)
    {
        pIntArray->iCapacity *= 2;
        ReallocMem(pIntArray, pIntArray->iCapacity);
    }
    else if (pIntArray->iSize < pIntArray->iCapacity/2)
    {
        pIntArray->iCapacity /= 2;
        ReallocMem(pIntArray, pIntArray->iCapacity);
    }

}

void Init(IntArray* pIntArray)
{
    pIntArray->iSize = 0;
    pIntArray->iCapacity = 5;
    pIntArray->pContent = (int*)malloc(sizeof(int) * pIntArray->iCapacity) ;
}

void Add(IntArray* pIntArray, int iValue)
{
    
    pIntArray->pContent[pIntArray->iSize] = iValue;
    pIntArray->iSize ++;

    UpdateCapacity(pIntArray);
}

void Insert(IntArray* pIntArray, int iValue, int iIndex)
{
    for (int i = pIntArray->iSize; i >= iIndex; i--)
    {
        pIntArray->pContent[i] = pIntArray->pContent[i-1];
    }
    pIntArray->pContent[iIndex] = iValue;
    pIntArray->iSize++;

    UpdateCapacity(pIntArray);
}

void Remove(IntArray* pIntArray, int iIndex)
{
    for (int i = iIndex; i < pIntArray->iSize-1; i++)
    {
        pIntArray->pContent[i] = pIntArray->pContent[i + 1];
    }
    pIntArray->iSize--;

    UpdateCapacity(pIntArray);
}

void Get(IntArray* pIntArray, int iIndex)
{
    printf("%d", pIntArray->pContent[iIndex]);
}

void Print(IntArray* pIntArray)
{
    for (int i = 0; i < pIntArray->iSize; i++)
    {
        printf("%d, ", pIntArray->pContent[i]);
    }
    printf("\n");
}

void Destroy(IntArray* pIntArray)
{
    pIntArray->iSize = 0;
    pIntArray->iCapacity = 5;
    free(pIntArray->pContent);
}

void TestBattery(IntArray* pIntArray)
{
    for (int i = 0; i < 10; i++)
    {
        Add(pIntArray, i);
    }
    Print(pIntArray);
    Get(pIntArray, 5);
    Insert(pIntArray, 40, 5);
    Print(pIntArray);
    Remove(pIntArray, 4);
    Print(pIntArray);
}

StringTests()
{
    String str1 = Create("Bonjour");
    PrintString(&str1);

    String str2 = Create("Au revoir");
    PrintString(&str2);

    String concatenated = Concatenate1(&str1, &str2);
    PrintString(&concatenated);

    String concatenated2 = Concatenate2("hello", "olleh");
    PrintString(&concatenated2);

    String subString = SubString(&str1, 2, 5);
    PrintString(&subString);

    String str3 = InsertString(&str1, &str2, 2);
    PrintString(&str3);

    if (AreEquals(&str1, &str2))
    {
        printf("oui\n");
    }
    else
    {
        printf("non\n");
    }
    
    String str4 = Create("1234");
    int result = 0;
    if (TryCastToInt(&str4, &result))
    {
        printf("%d\n", result);

    }

    int result2 = 0;
    if (TryCastToInt(&str1, &result2))
    {
        printf("%d\n", result2);
    }

    Destroy(&str1);
    Destroy(&str1);
    Destroy(&str1);
    Destroy(&str1);

}
void ListTests() {
    List oList;
    InitList(&oList);

    AddLast(&oList, 1);
    AddLast(&oList, 2);
    AddLast(&oList, 3);

    AddFirst(&oList, 0);

    DestroyList(&oList);
}

int main()
{
    IntArray oArray;
    Init(&oArray);

    TestBattery(&oArray);

    StringTests();

    ListTests();
    Destroy(&oArray);

    return 0;
}