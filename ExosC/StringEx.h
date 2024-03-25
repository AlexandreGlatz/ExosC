#pragma once
#ifndef TOOLS_H
#define TOOLS_H

typedef struct String
{
	char* pContent;
	int iLength;
}String;

String Create(const char* str);
void PrintString(const String* pStr);
String Concatenate1(const String* pStr1, const String* pStr2);
String Concatenate2(const char* str1, const char* str2);
String SubString(const String* pStr1, int iStartIndex, int iLength);
String InsertString(const String* pStr1, const String* pStr2, int iIndex);
int AreEquals(const String* pStr1, const String* pStr2);
int TryCastToInt(const String* pStr, int* pResult);
void DestroyString(String* pStr);

#endif /* TOOLS_H */