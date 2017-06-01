#ifndef SQLSERVER_H
#define SQLSERVER_H

extern TCHAR SQLData[50];
extern TCHAR SQLHost[50];
extern TCHAR SQLUser[50];
extern TCHAR SQLPass[50];

void SQLServer();
void SQLInit(const char* DataBase, const char* User, const char* Password);
void Exec(const char* szQuery, ...);
int GetFieldInt(char* Table, char* Field, const char* Optional, ...);

#endif//SQLSERVER_H