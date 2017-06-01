#ifndef MSSQL_H
#define MSSQL_H

#include "sqlapi.h"
#include "StdAfx.h"

class SQL
{
public:
	SQL(void);
	virtual ~SQL(void);
	void Connect(char* DataBase,char* Acc,char* Password);
	int GetFieldInt(char* Table, char* Field, const char* Optional, ...);
	void Exec(const char* szQuery, ...);
	int GetBufferQueryInt(char* Query,char* BuffName);
	unsigned char* GetBufferQueryBinary(char* Query,char* BuffName);
};
extern SQL * MYSQL;
#endif