#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    Node* pNext;
    Node* pPrevious;

    int iValue;
} Node;

typedef struct List
{
    Node* pFirst;

    int iCount;
} List;

void Init(List* pList)
{
    //
}

void AddFirst(List* pList, int iValue)
{
    //
}

void AddLast(List* pList, int iValue)
{
    //
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

void Print(List* pList)
{
    //
}

void Destroy(List* pList)
{
    //
}

int main()
{
    List oList;
    init(&oList);

    AddLast(&oList, 1);
    AddLast(&oList, 2);
    AddLast(&oList, 3);

    AddFirst(&oList, 0);

    Destroy(&oList);
}