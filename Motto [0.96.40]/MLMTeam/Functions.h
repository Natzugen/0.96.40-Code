#include "StdAfx.h"
#include "Global.h"

void HookThis(DWORD dwMyFuncOffset, DWORD dwJmpOffset);
void SetByte(DWORD dwOffset, BYTE btValue);
int gObjGetInt(DWORD aIndex, int Type);
void ServerMsgSend(DWORD wId, int Type, char Sender[20], const char* Message, ...);
void DataSendAll(unsigned char* Packet, int Length);
void gObjGetChar(DWORD aIndex,DWORD Type,DWORD Size, char * nick);
void ChatDataSend(DWORD aIndex,LPBYTE Protocol);

typedef struct
{
	unsigned char Enc;
	unsigned char Size;
	unsigned char Type;
	unsigned char MsgType;
	char		Notice[256];
} GCSERVERMSGSTRUCT;