#include <windows.h>
#include "fixes.h"
#include "defines.h"
#include "utilites.h"
#include "gameserver.h"
#include "global.h"

bool ProtocolHook(BYTE protoNum,unsigned char* aRecv, DWORD aLen, short aIndex, DWORD Encrypt, int Serial);

extern "C" __declspec(dllexport) void GSConfigs()
{
DWORD OldProtect;
if(VirtualProtect(LPVOID(0x401000),3543191,PAGE_EXECUTE_READWRITE,&OldProtect))
{
LoadConfigs();
HookThis((DWORD)&ProtocolHook,0x00401d5c);
}
else
{
MessageBoxA(NULL,"Não foi Possivel Carregar a DLL.","Jamel.dll",MB_OK);
}
}

void HookThis(DWORD dwMyFuncOffset, DWORD dwJmpOffset)
{
	*(DWORD*)(dwJmpOffset+1) = dwMyFuncOffset -(dwJmpOffset+5);
}

bool ProtocolHook(BYTE protoNum,unsigned char* aRecv, DWORD aLen, short aIndex, DWORD Encrypt, int Serial)
{
	switch(BYTE(protoNum))
	{
	case 0x00: // Chat Data Recv 
		ChatDataSend(aIndex,aRecv);
		break;
	case 0x03:
		GCServerMsgStringSend(ConnectNotice,aIndex,0);
		break;
	}
	DataRecv(protoNum,aRecv,aLen,aIndex,Encrypt,Serial);
	return true;
}

void LoadConfigs()
{
	LoadIni();
	Fixes();
	GoIni();
	MessageBoxA(NULL,"A Dll Foi Carregada! Clique em OK","Sucesso",MB_OK);
}