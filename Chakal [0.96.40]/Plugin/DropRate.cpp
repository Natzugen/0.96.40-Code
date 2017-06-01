#include "StdAfx.h"
#include "Include.h"
C_DropSystem Drop;

void C_DropSystem::t_LoadSystem()
{
	this->t_num = 0;
	FILE * hFile;
	fopen_s(&hFile, ".\\Data\\ItemDropRate.txt", "r");
	char Linha[1024];
	int type,index,lvl,opt,luck,skill,dur,rate,minlvl,maxlvl,exc,ancient;

	if(hFile == 0)
	{
		MessageBox(0, "ItemDropRate.txt - Arquivo não encontrado.", "GameServer - Erro 102", MB_OK | MB_ICONSTOP);
		::ExitProcess(0);
		return;
	}

    while(!feof(hFile))
    {
        fgets(Linha, 1024, hFile);
		if(!strcmp(Linha, "end"))
			break;

		if(Linha[strlen(Linha) - 1] == '\n' || Linha[strlen(Linha) - 1] == '\r')
		{
			if(Linha[0] != '/' || Linha[1] != '/')
			{
				if(t_num > MAX_DROP_NUMBER)
				{
					MessageBoxA(NULL,"Erro ao ler o ItemDropRate.txt, numero maximo de items excedido.!","Fatal Error", MB_OK | MB_ICONSTOP);;
					::ExitProcess(0);
				}
				sscanf_s(Linha, "%d %d %d %d %d %d %d %d %d %d %d", &type, &index, &lvl, &opt, &luck, &skill, &dur, &rate, &minlvl, &maxlvl, &exc);
				t_struct[this->t_num].ItemType		= type;
				t_struct[this->t_num].ItemIndex		= index;
				t_struct[this->t_num].ItemLevel		= lvl;	
				t_struct[this->t_num].ItemOpt		= opt;	
				t_struct[this->t_num].ItemLuck		= luck;	
				t_struct[this->t_num].ItemSkill		= skill;
				t_struct[this->t_num].ItemDur		= dur;	
				t_struct[this->t_num].ItemRate		= rate;	
				t_struct[this->t_num].ItemMinlvl	= minlvl;	
				t_struct[this->t_num].ItemMaxlvl	= maxlvl;
				t_struct[this->t_num].ItemExc		= exc;
				t_num++;
			}
		}
	}
	fclose(hFile);
}
int C_DropSystem::MygEventMonsterItemDrop(BYTE * b_MonsterDataAddr,BYTE * a_gObjAddr){
	for(int i = 0; i < t_num; i++){
		WORD wMonsterLv =0;
		WORD wMonsterId =0;
		WORD Player;
		BYTE cMapID,cX,cY;
		PBYTE bDataAddr =0;
		bDataAddr = (PBYTE)b_MonsterDataAddr;

		memcpy(&Player,bDataAddr+0x6A,sizeof(WORD));
		memcpy(&wMonsterLv,bDataAddr+0x86,sizeof(WORD));
		memcpy(&wMonsterId,bDataAddr+0x83,sizeof(WORD));
		memcpy(&cMapID,bDataAddr+0xD9,sizeof(BYTE));
		memcpy(&cX,bDataAddr+0xD4,sizeof(BYTE));
		memcpy(&cY,bDataAddr+0xD6,sizeof(BYTE));

		DWORD Item = t_struct[i].ItemType * 32 + t_struct[i].ItemIndex;
						
		//Valor Item = ItemGetNumberMake(Group,Index);
		DWORD dwPena = ItemGetNumberMake(13, 14);
		DWORD dwBless = ItemGetNumberMake(14, 13);
		DWORD dwSoul = ItemGetNumberMake(14, 14);
		DWORD dwLife = ItemGetNumberMake(14, 16);
		//Inclua aqui os Items

		DWORD dwTopHitUser = gObjMonsterTopHitDamageUser(b_MonsterDataAddr);
		DWORD dwRand = rand();

		if(wMonsterLv >= t_struct[i].ItemMinlvl)
		{
			if(wMonsterLv <= t_struct[i].ItemMaxlvl)
			{
				if(rand() % t_struct[i].ItemRate >= (10000 - t_struct[i].ItemRate))
				{
				ItemSerialCreateSend(b_MonsterDataAddr[0],cMapID,cX,cY,Item,t_struct[i].ItemLevel,t_struct[i].ItemDur,t_struct[i].ItemSkill,t_struct[i].ItemLuck,t_struct[i].ItemOpt,dwTopHitUser,t_struct[i].ItemExc);
				return 1;
				}
			}
		}
	}
	int rValue = gEventMonsterItemDrop(b_MonsterDataAddr, a_gObjAddr);
	return rValue;
}
void MonsterDropCall(BYTE * b_MonsterDataAddr,BYTE * a_gObjAddr)
{
	Drop.MygEventMonsterItemDrop(b_MonsterDataAddr,a_gObjAddr);
}