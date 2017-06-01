#include "Logger.h"

static FILE * cmdLog = NULL;
static char cmdLogName[256];

static FILE * npcLog = NULL;
static char npcLogName[256];

static SYSTEMTIME t;
static char fName[40];
static char Line[300];

void CreateCmdLog()
{
	GetLocalTime(&t);

	if(cmdLog != NULL)
	{
		fclose(cmdLog);
		cmdLog = NULL;
	}

	sprintf_s(fName,".\\DLL_LOGS\\CMD_LOG_%d_%d_%d.log",t.wDay,t.wMonth,t.wYear);
	cmdLog = fopen(fName, "a+t");
	if(cmdLog == NULL)
	{
		MsgBox("Error","Log File Create Error");
		ExitThread(0);
	}
	strcpy(cmdLogName,fName);
	LogAddExCmd(false,"[%d/%d/%d :: %d : %d] LOG FILE CREATED",t.wDay,t.wMonth,t.wYear,t.wHour,t.wMinute);
}


void CreateNpcLog()
{
	GetLocalTime(&t);
	if(npcLog != NULL)
	{
		fclose(npcLog);
		npcLog = NULL;
	}

	sprintf_s(fName,".\\DLL_LOGS\\NPC_LOG_%d_%d_%d.log",t.wDay,t.wMonth,t.wYear);
	npcLog = fopen(fName,"a+t");
	if(npcLog == NULL)
	{
		MsgBox("Error","Log File Create Error");
		ExitThread(0);
	}
	strcpy(npcLogName,fName);
	LogAddExNpc(false,"[%d/%d/%d :: %d : %d] NPC FILE CREATED",t.wDay,t.wMonth,t.wYear,t.wHour,t.wMinute);
}
void LogAddExCmd(bool AddScreen,char * LogLine,...)
{
	if(configs.isLogAdd[Cmd] == 0)
		return;

	GetLocalTime(&t);

	va_list pArguments;
    va_start(pArguments, LogLine);
    vsprintf(Line, LogLine, pArguments);
    va_end(pArguments);

	strcat(Line,"\n");

	cmdLog = fopen(cmdLogName, "a+t");
	fprintf(cmdLog,"[CMD][%d : %d]: ",t.wHour,t.wMinute);
	fprintf(cmdLog,Line);
	fclose(cmdLog);
	if(AddScreen)LogAddFunc(Verde,Line);
}
void LogAddExNpc(bool AddScreen,char * LogLine,...)
{
	if(configs.isLogAdd[Npc] == 0)
		return;

	GetLocalTime(&t);

	va_list pArguments;
    va_start(pArguments, LogLine);
    vsprintf(Line, LogLine, pArguments);
    va_end(pArguments);

	strcat(Line,"\n");

	npcLog = fopen(npcLogName,"a+t");
	fprintf(npcLog,"[NPC][%d : %d]: ",t.wHour,t.wMinute);
	fprintf(npcLog,Line);
	fclose(npcLog);
	if(AddScreen)LogAddFunc(Azul,Line);

}