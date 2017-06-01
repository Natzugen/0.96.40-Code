#include "StdAfx.h"

void Settings()
{
	GetPrivateProfileString("- COMANDOS -", "_COMANDO POSTAR - STRING", "POST" , StringPost, 10, CHRISTYAN);
	GetPrivateProfileString("- COMANDOS -", "_COMANDO RESETAR - STRING", "RESETAR", StringReset, 10, CHRISTYAN);
	ATIVERESET = GetPrivateProfileInt("- COMANDOS -", "_COMANDO RESETAR - STATUS", 1, CHRISTYAN);
	LEVELRESET = GetPrivateProfileInt("- COMANDOS -", "_COMANDO RESETAR - LEVEL", 10, CHRISTYAN);
	PRICERESET = GetPrivateProfileInt("- COMANDOS -", "_COMANDO RESETAR - PRICE", 10, CHRISTYAN);
	GetPrivateProfileString("- COMANDOS -", "_COMANDO LIMPAR PK - STRING", "PKCLEAR", StringPk, 10, CHRISTYAN);
	ATIVEPK = GetPrivateProfileInt("- COMANDOS -", "_COMANDO LIMPAR PK - STATUS", 1, CHRISTYAN);
	LEVELPK = GetPrivateProfileInt("- COMANDOS -", "_COMANDO LIMPAR PK - LEVEL", 10, CHRISTYAN);
	PRICEPK = GetPrivateProfileInt("- COMANDOS -", "_COMANDO LIMPAR PK - PRICE", 10, CHRISTYAN);
	GetPrivateProfileString("- COMANDOS -", "_COMANDO SAIR - STRING", "EXIT", StringExit, 10, CHRISTYAN);
	ATIVEEXIT = GetPrivateProfileInt("- COMANDOS -", "_COMANDO SAIR - STATUS", 1, CHRISTYAN);
	LEVELEXIT = GetPrivateProfileInt("- COMANDOS -", "_COMANDO SAIR - LEVEL", 10, CHRISTYAN);
	PRICEEXIT = GetPrivateProfileInt("- COMANDOS -", "_COMANDO SAIR - PRICE", 10, CHRISTYAN);
	GetPrivateProfileString("- COMANDOS -", "_COMANDO HORAS - STRING", "TIME", StringTime, 10, CHRISTYAN);
	ATIVETIME = GetPrivateProfileInt("- COMANDOS -", "_COMANDO HORAS - STATUS", 1, CHRISTYAN);
	LEVELTIME = GetPrivateProfileInt("- COMANDOS -", "_COMANDO HORAS - LEVEL", 10, CHRISTYAN);
	PRICETIME = GetPrivateProfileInt("- COMANDOS -", "_COMANDO HORAS - PRICE", 10, CHRISTYAN);
	GetPrivateProfileString("- COMANDOS -", "_COMANDO ZEN - STRING", "ZEN", StringZen, 10, CHRISTYAN);
	ATIVEZEN = GetPrivateProfileInt("- COMANDOS -", "_COMANDO ZEN - STATUS", 1, CHRISTYAN);
	LEVELZEN = GetPrivateProfileInt("- COMANDOS -", "_COMANDO ZEN - LEVEL", 10, CHRISTYAN);
	ZENADD = GetPrivateProfileInt("- COMANDOS -", "_COMANDO ZEN - ZENADD", 10, CHRISTYAN);
}