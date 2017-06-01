#include "StdAfx.h"

void HookThis(DWORD dwMyFuncOffset, DWORD dwJmpOffset);
void MsgBox(char * BoxName,char * BoxText, ...);
bool isGM(int aIndex);
short IndexByName(char * Name);
short GetNameAndSize(char * string);
bool checkUserLevel(int aIndex, char minLevelToUse);