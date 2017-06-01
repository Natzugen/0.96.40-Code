#include "StdAfx.h"
#include "sqlapi.h"
#include "Include.h"
#include "settings.h"
MSSQL_FUNC mssql_Conn;

static char Buffer[1024];

void MSSQL_FUNC::MSSQLCONFIG()
{
	GetPrivateProfileStringA(MSSQLSERVER,"Usuario do sql padrao < sa >","sa",this->SQL_User,strlen(this->SQL_User),CFG_GAMESERVER);
	GetPrivateProfileStringA(MSSQLSERVER,"Senha do sql","chakal",this->SQL_Pass,strlen(this->SQL_Pass),CFG_GAMESERVER);
	GetPrivateProfileStringA(MSSQLSERVER,"DataBase padrao < MuOnline >","MuOnline",this->SQL_DBName,strlen(this->SQL_DBName),CFG_GAMESERVER);
	GetPrivateProfileStringA(MSSQLSERVER,"Host do sql padrao < 127.0.0.1 >","127.0.0.1",this->SQL_Server,strlen(this->SQL_Server),CFG_GAMESERVER);
}
void MSSQL_FUNC::RUNMSSQL()
{
	sprintf_s(Buffer,"%s@%s",this->SQL_Server,this->SQL_DBName);
	MYSQL->Connect(Buffer,this->SQL_User,this->SQL_Pass);
}
void MSSQL_FUNC::CLtGetSQL(int aIndex)
{	OBJECTSTRUCT * gObj = (OBJECTSTRUCT*) OBJECT_POINTER(aIndex);
	gObj->VipLevel = MYSQL->GetFieldInt("MuOnline.dbo.MEMB_INFO","vip","WHERE memb___id = '%s'",gObj->AccountID);
	gObj->Resets = MYSQL->GetFieldInt("MuOnline.dbo.Character","Resets","WHERE Name = '%s'",gObj->Name);
	gObj->CtlCodeEx = MYSQL->GetFieldInt("MuOnline.dbo.Character","CtlCode","WHERE Name = '%s'",gObj->Name);
	gObj->Creditos = MYSQL->GetFieldInt("MuOnline.dbo.MEMB_INFO","Creditos","WHERE memb___id = '%s'",gObj->AccountID);
	gObj->Golds = MYSQL->GetFieldInt("MuOnline.dbo.MEMB_INFO","Golds","WHERE memb___id = '%s'",gObj->AccountID);
	gObj->Resetao = MYSQL->GetFieldInt("MuOnline.dbo.Character","Resetao","WHERE Name = '%s'",gObj->Name);
	gObj->Maxbau = MYSQL->GetFieldInt("MuOnline.dbo.MEMB_INFO","baux","WHERE memb___id = '%s'",gObj->AccountID);
}
void MSSQL_FUNC::MSSQLCONNECT(){
	mssql_Conn.MSSQLCONFIG();
	mssql_Conn.RUNMSSQL();
}
