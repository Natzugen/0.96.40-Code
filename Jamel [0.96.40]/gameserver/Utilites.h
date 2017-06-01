#include <stdio.h>
#include <windows.h>


void ServerMsgSend(DWORD wId, int Type, char Sender[20], const char* Message, ...);
void gObjGetChar(DWORD gObjId,DWORD Type,DWORD Size, char * nick);
int gObjGetInt(DWORD aIndex, int Type);
void ChatDataSend(DWORD gObjId,LPBYTE Protocol);
void HookThis(DWORD dwMyFuncOffset, DWORD dwJmpOffset);

void gObj_GetNick(DWORD gObjId, char*nick );
void gObj_GetLogin(WORD gObjId, char*login );
DWORD gObj_GetMoney(DWORD gObjId);
WORD gObj_GetLevel(DWORD PlayerID);
void *GetPlayerAddress(unsigned int PlayerID);
bool VerificaGM(DWORD gObjId);