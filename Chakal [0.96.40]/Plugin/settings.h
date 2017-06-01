#ifndef SETTINGS_H
#define SETTINGS_H

class MSSQL_FUNC
{
public:
	void RUNMSSQL();
	void MSSQLCONFIG();
	void MSSQLCONNECT();
	void CLtGetSQL(int aIndex);

	char SQL_Server[256];
	char SQL_DBName[256];
	char SQL_User[256];
	char SQL_Pass[255];
	char SQL_Resets[64];
	char SQL_Vip[64];
};

extern MSSQL_FUNC mssql_Conn;

#endif