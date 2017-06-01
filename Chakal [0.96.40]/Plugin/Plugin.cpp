/******************************************************************
*
*	CRITICAL TEAM - PROJETO MUSERVER 97d+99i PLUGIN PREMIUM
*	PROGRAMADO POR [CLT]CHAKAL © TODOS DIREITOS RESERVADOS
*	
******************************************************************/

/*
OBS: Algumas funções foram pegas na net de alguma source sei lah :D
*/
#include "StdAfx.h"
#include "Include.h"
void CLtDLL(){
	DWORD OldProtect;
	if (VirtualProtect ((LPVOID) 0x00401000, 3543191, PAGE_EXECUTE_READWRITE, &OldProtect))
	{
	mssql_Conn.MSSQLCONNECT();
	gs_func.LerFunc();
	Drop.t_LoadSystem();
	gs_func.GameCustoms();
	gs_cmd.Settings();
	gs_func.HookThis((DWORD)&ProtocolCoreEx,0x00401D5C);
	gs_func.HookThis((DWORD)&MonsterDropCall,0x00401AC8);
	}
	else
	{
		MessageBoxA(NULL,"Injeção de códigos da DLL falhou","Plugin - Fatal Erro",NULL);
	}
}