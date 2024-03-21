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

void CheckCapacity(IntArray* pIntArray)
{
    if (pIntArray->iSize >= pIntArray->iCapacity)
    {
        pIntArray->iCapacity *= 2;
        int* temp = realloc(pIntArray->pContent, sizeof(int) * pIntArray->iCapacity);
        free(temp);
    }
    else if (pIntArray->iSize <= pIntArray->iCapacity/4)
    {
        pIntArray->iCapacity /= 2;
        int* temp = realloc(pIntArray->pContent, sizeof(int) * pIntArray->iCapacity);
        pIntArray->pContent = temp;
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

    CheckCapacity(pIntArray);
}

void Insert(IntArray* pIntArray, int iValue, int iIndex)
{
    pIntArray->pContent[pIntArray->iSize] = pIntArray->pContent[iIndex];
    pIntArray->pContent[iIndex] = iValue;
    pIntArray->iSize++;

    CheckCapacity(pIntArray);
}

void Remove(IntArray* pIntArray, int iIndex)
{
    pIntArray->pContent[iIndex] = pIntArray->pContent[pIntArray->iSize-1];
    pIntArray->iSize--;

    CheckCapacity(pIntArray);
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