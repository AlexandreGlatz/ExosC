#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

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

int main()
{
    IntArray oArray;
    Init(&oArray);
    TestBattery(&oArray);
    Destroy(&oArray);

    return 0;
}