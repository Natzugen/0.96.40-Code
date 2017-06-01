#include "StdAfx.h"
#include "Include.h"
static char Message[256];
static char Temp[256];
GS_FUNCTIONS gs_func;

void GS_FUNCTIONS::HookThis(DWORD dwMyFuncOffset, DWORD dwJmpOffset)
{
	*(DWORD*)(dwJmpOffset+1) = dwMyFuncOffset -(dwJmpOffset+5);
}
int GS_FUNCTIONS::gObjGetInt(DWORD aIndex, int Tipo)
{
	DWORD gObj = (aIndex * gObjSize + gObjOffset);
	return *LPWORD(gObj+Tipo);
}

void GS_FUNCTIONS::PluginProcurar(){
	FILE* Pluginini;
	Pluginini = fopen(".//Plugin.ini","rb");
	if (Pluginini!=0)
	{fclose(Pluginini);}
	else{char msg[400];
	sprintf_s(msg,"Plugin.ini não encontrado. O GameServer não pode ser iniciado.",Pluginini);
	MessageBox(NULL,msg,"Plugin.dll",NULL);
	ExitProcess(0);}
}
bool GS_FUNCTIONS::VerificarGM(int aIndex){
	OBJECTSTRUCT * gObj = (OBJECTSTRUCT*) OBJECT_POINTER (aIndex);
	unsigned char x = gObj->CtlCodeEx;
	if(x == 8 || x == 10 || x == 32)
	return true;
	else
	return false;
}

void GS_FUNCTIONS::Reloginho(){
	HANDLE TheTime;
	TheTime = CreateThread(NULL,0,(LPTHREAD_START_ROUTINE)ReplayNocicia,NULL,0,0);
}
void GS_FUNCTIONS::LerFunc(){
	gs_func.IpConnectServ();
	gs_func.PluginProcurar();
	gs_func.Reloginho();
}