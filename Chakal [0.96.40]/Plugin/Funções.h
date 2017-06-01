#ifndef FUNÇÕES_H
#define FUNÇÕES_H

class GS_FUNCTIONS
{
public:
	void HookThis(DWORD dwMyFuncOffset, DWORD dwJmpOffset);
	void PluginProcurar();
	void LerFunc();
	void Reloginho();

	bool VerificarGM(int aIndex);

	int gObjGetInt(DWORD PlayerID, int Type);

	void GameCustoms();
};

extern GS_FUNCTIONS gs_func;

#endif