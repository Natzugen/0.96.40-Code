#include "StdAfx.h"

SACommand * cmd = new SACommand();
SAConnection * con = new SAConnection();

TCHAR SQLData[50];
TCHAR SQLHost[50];
TCHAR SQLUser[50];
TCHAR SQLPass[50];

void SQLServer()
{
	char Buffer[2048];
	GetPrivateProfileString("- CUSTOMS -", "_DATABASE", "MuOnline", SQLData, 50, CHRISTYAN);
	GetPrivateProfileString("- CUSTOMS -", "_HOST", "127.0.0.1", SQLHost, 50, CHRISTYAN);
	GetPrivateProfileString("- CUSTOMS -", "_USER", "sa", SQLUser, 50, CHRISTYAN);
	GetPrivateProfileString("- CUSTOMS -", "_PASS", "123456", SQLPass, 50, CHRISTYAN);
	sprintf(Buffer,"%s@%s",SQLHost,SQLData);
	SQLInit(Buffer,SQLUser,SQLPass);
}

void SQLInit(const char* DataBase, const char* User, const char* Password) 
{
	try
	{
		con->Connect(DataBase, User, Password, SA_SQLServer_Client);
		cmd->setConnection(con);
	}
	catch(SAException &x)
	{
		MessageBoxA(NULL, x.ErrText(), "SQLInit() can't connect.", MB_OK);
		::ExitProcess(0);
	}
}

int GetFieldInt(char* Table, char* Field, const char* Optional, ...)
{
	char Buffer[1024];
	va_list pArguments;
    va_start(pArguments, Optional);
    vsprintf(Buffer, Optional, pArguments);
    va_end(pArguments);

    if (Optional)
	    Exec("SELECT %s FROM %s %s;", Field, Table, Buffer);
    else
		Exec("SELECT %s FROM %s;", Field, Table);

    if(cmd->isResultSet()) 
    {
	    cmd->FetchNext();
	    int Result = cmd->Field(Field).asLong();
	    return Result;
    }
	return 0;
}


void Exec(const char* szQuery, ...)
{
	    char szBuffer[1024];
	    va_list pArguments;
	    va_start(pArguments, szQuery);
	    vsprintf(szBuffer, szQuery, pArguments);
	    va_end(pArguments);
	    cmd->setCommandText(szBuffer);
	    cmd->Execute();		
}
