#include "StdAfx.h"

bool ProtocolCore(BYTE protoNum,LPBYTE aRecv,DWORD aLen,short aIndex,DWORD Encrypt,int Serial);

void ThreadProc();
extern "C" __declspec(dllexport) void Entry()
{
	char Buffer[256];
	DWORD OldProtect;
	if(VirtualProtect(LPVOID(0x401000),3543191,PAGE_EXECUTE_READWRITE,&OldProtect))
	{
		CreateCmdLog();
		CreateNpcLog();
		if(!Load())
		{
			MsgBox("ERRO FATAL","Falha na leitura de arquivos de configuração!");
			ExitThread(0);
		}
		else // Conecta à DataBase
		{
			LoadCmdConfigs();	// Carrega as configs dos comandos
			sprintf_s(Buffer,"%s@%s",configs.sql.Server,configs.sql.DbName);
			GSQL->Connect(Buffer,configs.sql.User,configs.sql.Pass);
			HookNewOBJECTSTRUCT();
			HookThis((DWORD)&ProtocolCore,0x00401D5C);
			HANDLE gThread;
			gThread = CreateThread(NULL,0,(LPTHREAD_START_ROUTINE)ThreadProc,NULL,0,0);
			{
				configs.gTime_Hour = 0;
				configs.gTime_Min = 0;
				configs.gTime_Sec = 0;
			}
			HANDLE Window1;
			Window1 = CreateThread(NULL,0,(LPTHREAD_START_ROUTINE)InitializeWindow,NULL,0,0);
		}
	}
	else
	{
		MsgBox("ERRO FATAL","Falha na injeção de códigos da DLL");
		ExitThread(0);
	}

}

bool ProtocolCore(BYTE protoNum,LPBYTE aRecv,DWORD aLen,short aIndex,DWORD Encrypt,int Serial)
{
	switch ( protoNum )
	{
	case 0x00: // Chat Data Recv
		ChatRecv(aIndex,aRecv);
		break;
	case 0x03: // Player Connect
		SetConnection(aIndex);
		break;
	case 0x30:
		if(NpcTalkEx(aIndex,(aRecv[4] + aRecv[3] * 256)))
		{
			GCSERVERMSGSTRUCT * Chat = (GCSERVERMSGSTRUCT *) aRecv;
			Chat->Enc = 0xC1;
			Chat->Type = 0x0D;
			Chat->MsgType = 0;
			sprintf_s(Chat->Notice,"error");
			Chat->Size = strlen(Chat->Notice);
		}
		break;
	}

	DataRecv(protoNum,aRecv,aLen,aIndex,Encrypt,Serial);
	return true;
}

void ThreadProc()
{
	configs.gTime_Sec++;
	if(configs.gTime_Sec == 60)
	{
		configs.gTime_Sec = 0;
		configs.gTime_Min++;
	}
	if(configs.gTime_Min == 60)
	{
		configs.gTime_Min = 0;
		configs.gTime_Hour++;
	}

	Sleep(1000);
	ThreadProc();
}