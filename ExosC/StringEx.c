#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include "StringEx.h"


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

	concatenatedStr.iLength = pStr1->iLength + pStr2->iLength;

	concatenatedStr.pContent = (char*)malloc((concatenatedStr.iLength+1) * sizeof(char));

	if (concatenatedStr.pContent == NULL) {
		exit(1);
	}

	for (int i = 0; i < pStr1->iLength; i++) {
		concatenatedStr.pContent[i] = pStr1->pContent[i];
	}

	for (int i = 0; i < pStr2->iLength; i++) {
		concatenatedStr.pContent[pStr1->iLength + i] = pStr2->pContent[i];
	}

	concatenatedStr.pContent[concatenatedStr.iLength] = '\0';

	return concatenatedStr;
}

String Concatenate2(const char* str1, const char* str2)
{
	String newChar; 
	newChar.iLength = strlen(str1) + strlen(str2);
	newChar.pContent = (char*)malloc((newChar.iLength+1) * sizeof(char));

	if (newChar.pContent == NULL) {
		exit(1);
	}

	for (int i = 0; i < strlen(str1); i++) {
		newChar.pContent[i] = str1[i];
	}

	for (int i = 0; i < strlen(str2); i++) {
		newChar.pContent[strlen(str1) + i] = str2[i];
	}

	newChar.pContent[newChar.iLength] = '\0';

	return newChar;

}

String SubString(const String* pStr1, int iStartIndex, int iLength)
{
	String subString;
	subString.iLength = iLength;
	subString.pContent = (char*)malloc((subString.iLength + 1) * sizeof(char));

	for (int i = 0; i < iLength; i++)
	{
		subString.pContent[i] = pStr1->pContent[iStartIndex + i];
	}

	subString.pContent[subString.iLength] = '\0';

	return subString;
}

String InsertString(const String* pStr1, const String* pStr2, int iIndex)
{
	String newString;

	newString.iLength = pStr1->iLength + pStr2->iLength;

	newString.pContent = (char*)malloc((newString.iLength +1) * sizeof(char));

	int k = 0;
	int l = 0;
	for (int i = 0; i < newString.iLength; i++)
	{
		if (i >= iIndex && pStr2->pContent[k] != '\0')
		{
			newString.pContent[i] = pStr2->pContent[k];
			k++;
		}

		else
		{
			newString.pContent[i] = pStr1->pContent[l];
			l++;
		}
	}

	newString.pContent[newString.iLength] = '\0';

	return newString;
}

int AreEquals(const String* pStr1, const String* pStr2)
{
	return pStr1->pContent == pStr2->pContent;
}

int TryCastToInt(const String* pStr, int* pResult)
{
	*pResult = (int*)malloc(sizeof(int) * pStr->iLength);

	char tabChar[] = "0123456789";

	for (int i = 0; i < pStr->iLength; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (pStr->pContent[i] == tabChar[j])
			{
				pResult[i] = j;
			}
			else if (pStr->pContent[i]!= tabChar[j] &&  j>9)
			{
				printf("cast failed\n");
				return 0;
			}
			
		}
	}
	return 1;
}

void DestroyString(String* pStr)
{
	free(pStr->pContent);
}
