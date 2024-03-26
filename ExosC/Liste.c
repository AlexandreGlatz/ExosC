#include <stdio.h>
#include <stdlib.h>
#include "Liste.h"

void AddNode(Node* pNode, int iValue)
{
    pNode->iValue = iValue;
    pNode->pNext->iValue = NULL;
}

void InitList(List* pList)
{
    pList->iCount = 0;
    pList->pFirst->iValue = NULL;
    pList->pFirst->pNext->iValue = NULL;
}

void AddFirst(List* pList, int iValue)
{
    AddNode(pList->pFirst->pNext, pList->pFirst->iValue);
    pList->pFirst->iValue = iValue;
    pList->iCount++;
}

void AddLast(List* pList, int iValue)
{
    
}

void AddAfterNode(List* pList, Node* pNode, int iValue)
{
    //
}

void Insert(List* pList, int iValue, int iIndex)
{
    //
}

void Remove(List* pList, int iIndex)
{
    //
}

void RemoveNode(List* pList, Node* pNode)
{
    //
}

Node* GetNode(List* pList, int iIndex)
{
    //
}

void PrintList(List* pList)
{
    //
}

void DestroyList(List* pList)
{
    //
}

