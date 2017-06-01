#include "Utilidades.h"

void HookThis(DWORD dwMyFuncOffset, DWORD dwJmpOffset)
{
	*(DWORD*)(dwJmpOffset+1) = dwMyFuncOffset -(dwJmpOffset+5);
}

void MsgBox(char * BoxName,char * BoxText, ...)
{
	char szBuffer[512]="";
	va_list pArguments;
	va_start(pArguments, BoxText);
	vsprintf(szBuffer, BoxText, pArguments);
	va_end(pArguments);
	MessageBox(NULL, szBuffer, BoxName, MB_OK|MB_APPLMODAL);
}

bool isGM(int aIndex)
{
	unsigned char x = gObj[aIndex].CtlCodeEx;
	if(x == 8 || x == 10 || x == 32)
		return true;
	else
		return false;
}

bool checkUserLevel(int aIndex, char minLevelToUse)
{
	if(minLevelToUse >= 32)
	{
		if(isGM(aIndex))
			return true;
	}
	else
	{
		if(gObj[aIndex].VipLevel >= minLevelToUse)
			return true;
	}
	return false;
}

short IndexByName(char * Name)
{
	for(int i = OBJECT_START; i < OBJECT_END; i++)
	{
		if(gObj[i].Connected == 3)
		{
			if(gObj[i].Name[0] == Name[0] && gObj[i].Name[1] == Name[1])
			{
				if(!strcmp(Name,gObj[i].Name))
				{
					return i;
				}
			}
		}
	}
	return -1;
}

short GetNameAndSize(char * string)
{
	char StringA[11];
	short Size = 0;
	for(char i = 0; i < 11; i++)
	{
		if(string[i] != ' ')
		{
			Size += 1;
		}
		else
		{
			i = 11;
		}
	}
	memcpy(StringA,string,Size);
	strcpy(string,StringA);
	return Size;
}