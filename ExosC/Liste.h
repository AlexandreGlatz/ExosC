#pragma once
#ifndef LISTE_H
#define LISTE_H

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

void InitList(List* pList);
void AddFirst(List* pList, int iValue);
void AddLast(List* pList, int iValue);
void AddAfterNode(List* pList, Node* pNode, int iValue);
void Insert(List* pList, int iValue, int iIndex);
void Remove(List* pList, int iIndex);
void RemoveNode(List* pList, Node* pNode);
Node* GetNode(List* pList, int iIndex);
void PrintList(List* pList);
void DestroyList(List* pList);


#endif /* TOOLS_H */