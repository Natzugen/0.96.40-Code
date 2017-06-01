#include "StdAfx.h"

extern "C" _declspec(dllexport) void Christyan()
{
	DWORD OldProtect;
	if(VirtualProtect((LPVOID)0x00401000, 3543191, PAGE_EXECUTE_READWRITE, &OldProtect))
	{
		Settings();
		SQLServer();
		Customs();
		HookThis(0x00401D5C, (DWORD)(&ProtocolCore));
		MessageBox(0, "GameServer 0.96.40 ~ v.97D\nPowered By Christyan Barbosa F. Soares\nFassa bom aproveito do servidor", "GameServer v.97D ~ 0.96.40", MB_OK);
		Console();
	}
	else
	{
		MessageBox(0, "IXI, ALGUMA COISA DEU ERRADO, SE VIRA AGORA :O", "GameServer v.97D ~ 0.96.40", MB_OK);
		ExitProcess(0);
	}
}