#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

typedef struct String
{
	char* pContent;
	int iLength;
}String;

String Create(const char* str)
{
	String string;
	string.pContent = str;
	string.iLength = strlen(str);
	return string;
}

void PrintString(const String* pStr)
{
	printf("%s\n", pStr->pContent);
}

String Concatenate1(const String* pStr1, const String* pStr2)
{
	String concatenatedStr;

	concatenatedStr.pContent = pStr1->pContent;
	concatenatedStr.iLength = pStr1->iLength;

	for (int i = 0; i < pStr2->iLength; i++)
	{
		concatenatedStr.pContent[concatenatedStr.iLength] = pStr2->pContent[i];
		concatenatedStr.iLength++;
	}
	return concatenatedStr;
}

String Concatenate2(const char* str1, const char* str2)
{
	String newChar; 
	newChar.iLength = 0;
	for (int i = 0; str1[i] != NULL; i++)
	{
		newChar.pContent[i] = str1[i];
		newChar.iLength++;
	}
	for (int i = 0; str2[i] != NULL; i++)
	{
		newChar.pContent[i] = str2[i];
		newChar.iLength++;
	}
}

String SubString(const String* pStr1, int iStartIndex, int iLength)
{
	String subString;
	subString.iLength = 0;
	for (int i = 0; i < iLength; i++)
	{
		subString.pContent[i] = pStr1->pContent[iStartIndex + i];
		subString.iLength++;
	}
}

String InsertString(const String* pStr1, const String* Pstr2, int iIndex)
{

}

int AreEquals(const String* pStr1, const String* pStr2)
{

}

int TryCastToInt(const String* pStr, int* pResult)
{

}

void DestroyString(String* pStr)
{

}
