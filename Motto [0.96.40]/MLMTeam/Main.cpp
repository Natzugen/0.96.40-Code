//===========================================================
// Development : MLM Team
// Coded : By Motto & MLM Team
// Versão : 0.97.04
// Protocol : Chs/Kor
// Projeto : MLM Silver/Gold
//===========================================================

#include "Main.h"
#include <windows.h>

void MLMTimer();
extern "C" __declspec(dllexport) void MLMT()
{
	DWORD OldProtect;
	if(VirtualProtect(LPVOID(0x401000),3543191,PAGE_EXECUTE_READWRITE,&OldProtect))
	{
		MLMini();	//carrega o arquivo MLMCustoms.ini
		Carrega();	//carrega as structs
		char SQLConnectionBuffer[2048];
		sprintf_s(SQLConnectionBuffer,"%s@%s",configs.sql.server,configs.sql.dbname);
		GSSQL->Connect(SQLConnectionBuffer,configs.sql.access,configs.sql.dbpass);
		HookThis((DWORD)&MLMProtocolCore,0x00401d5c);
		HookThis((DWORD)&NPCTalk, 0x00401B27);
		//LoadMaps 100%
		SetByte(0x00489424,0x15);
		SetByte(0x0048948F,0x15);
		SetByte(0x0047C7D4,0x15);
		SetByte(0x0047334E,0x15);
		SetByte(0x0047C499,0x15);
		SetByte(0x0047C7D4,0x15);
		SetByte(0x0047C7FE,0x15);
		SetByte(0x0045D153,0x15);
		SetByte(0x00443782,0x14);
		SetByte(0x00497B30,0x14);
		SetByte(0x00497C00,0x14);
		SetByte(0x0045C620,0x14);
		SetByte(0x0045C77B,0x14);
		SetByte(0x0045BA63,0x14);
		*(DWORD*)(0x004D0A00) = (DWORD)&MapLoad;
		/*
		*(BYTE*)(0x0048A309) = 0xFF;
		*(BYTE*)(0x0048A30A) = 0x15;
		*(DWORD*)(0x0048A30B) = 0x004D0A00;
		*(BYTE*)(0x0048A30F) = 0xE9;
		*(BYTE*)(0x0048A310) = 0xC2;
		*(BYTE*)(0x0048A311) = 0x08;
		*(BYTE*)(0x0048A312) = 0x00;
		*(BYTE*)(0x0048A313) = 0x00;
		SetByte(0x0048A663,0xE9); */
	}
	MessageBoxA(NULL, "ABACAXI ,Conexão 100%","Sucesso",MB_OK);
	MessageBoxA(NULL, "Se você comprou esse MuServer foi vítima de roubo porque ele é FREE","Sucesso",MB_OK);
}
bool MLMProtocolCore(BYTE protoNum,unsigned char* aRecv, DWORD aLen, short aIndex, DWORD Encrypt, int Serial)
{
	OBJECTSTRUCT * gObj = (OBJECTSTRUCT*)OBJECT_POINTER(aIndex);

	switch ( protoNum )
	{
	case 0x00:
		ChatDataSend(aIndex,aRecv);
		break;
	case 0x03:
		SetConnection(aIndex);
		break;
	/*case 0x30:
		GCServerMsgStringSend(configs.c_Notice1.ConnectNotice,aIndex,0);
		break;
	}*/
	DataRecv(protoNum,aRecv,aLen,aIndex,Encrypt,Serial);
	return true;
}