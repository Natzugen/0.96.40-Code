//mapas.cpp ->Novos Mapas
//Agradecimentos > DsTeamDev (Chris/Diguinho)

#include "mapas.h"

CHAR MapBuff[21][15] = {
	"Terrain1.att",
	"Terrain2.att",
	"Terrain3.att",
	"Terrain4.att",
	"Terrain5.att",
	"Terrain6.att",
	"Terrain7.att",
	"Terrain8.att",
	"Terrain9.att",
	"Terrain10.att",
	"Terrain11.att",
	"Terrain12.att",
	"Terrain12.att",
	"Terrain12.att",
	"Terrain12.att",
	"Terrain12.att",
	"Terrain12.att",
	"Terrain18.att",
	"Terrain19.att",
	"Terrain20.att",
	"Terrain21.att",
};

void MapLoad()
{
	for(int i=0;i<0x15;i++)
	{
		_asm
		{
			Mov Ecx, i
				Imul Ecx, Ecx, 0x4DB68
				Add Ecx, 0x6354C78
				Mov Eax, 0x00402225
				Call Eax
				Mov Eax, i
				Push Eax
				Mov Ecx, i
				Imul Ecx, Ecx, 0FH
				Add Ecx, offset MapBuff
				Push Ecx
				Mov Ecx, 0x0687DE60
				Mov Eax, 0x00401A7D
				Call Eax
				Push Eax
				Mov Ecx, i
				Imul Ecx, Ecx, 0x4DB68
				Add Ecx, 0x6354C78
				Mov Eax, 0x00401FC3
				Call Eax
		}
	}
}