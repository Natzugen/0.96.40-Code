#ifndef SETTINGS_H
#define SETTINGS_H
/*******************/
static int ATIVERESET = GetPrivateProfileInt("- COMANDOS -", "_COMANDO RESETAR - STATUS", 1, CHRISTYAN);
static int LEVELRESET = GetPrivateProfileInt("- COMANDOS -", "_COMANDO RESETAR - LEVEL", 10, CHRISTYAN);
static unsigned int PRICERESET = GetPrivateProfileInt("- COMANDOS -", "_COMANDO RESETAR - PRICE", 10, CHRISTYAN);

static int ATIVEPK = GetPrivateProfileInt("- COMANDOS -", "_COMANDO LIMPAR PK - STATUS", 1, CHRISTYAN);
static int LEVELPK = GetPrivateProfileInt("- COMANDOS -", "_COMANDO LIMPAR PK - LEVEL", 10, CHRISTYAN);
static unsigned int PRICEPK = GetPrivateProfileInt("- COMANDOS -", "_COMANDO LIMPAR PK - PRICE", 10, CHRISTYAN);

static int ATIVEEXIT = GetPrivateProfileInt("- COMANDOS -", "_COMANDO SAIR - STATUS", 1, CHRISTYAN);
static int LEVELEXIT = GetPrivateProfileInt("- COMANDOS -", "_COMANDO SAIR - LEVEL", 10, CHRISTYAN);
static unsigned int PRICEEXIT = GetPrivateProfileInt("- COMANDOS -", "_COMANDO SAIR - PRICE", 10, CHRISTYAN);

static int ATIVETIME = GetPrivateProfileInt("- COMANDOS -", "_COMANDO HORAS - STATUS", 1, CHRISTYAN);
static int LEVELTIME = GetPrivateProfileInt("- COMANDOS -", "_COMANDO HORAS - LEVEL", 10, CHRISTYAN);
static unsigned int PRICETIME = GetPrivateProfileInt("- COMANDOS -", "_COMANDO HORAS - PRICE", 10, CHRISTYAN);

static int ATIVEZEN = GetPrivateProfileInt("- COMANDOS -", "_COMANDO ZEN - STATUS", 1, CHRISTYAN);
static int LEVELZEN = GetPrivateProfileInt("- COMANDOS -", "_COMANDO ZEN - LEVEL", 10, CHRISTYAN);
static unsigned int ZENADD = GetPrivateProfileInt("- COMANDOS -", "_COMANDO ZEN - ZENADD", 10, CHRISTYAN);

void Settings();
/*******************/
#endif//SETTINGS_H