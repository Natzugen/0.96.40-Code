#ifndef INGAME_H
#define INGAME_H

struct STRUCT_INGAME
{

	void PlayerConnect(int aIndex);
	void GameMasterConn(int aIndex);
	void VipPremium(int aIndex);
	void InGame(int aIndex);

};
	void ReplayNocicia();
extern STRUCT_INGAME in_game;


#endif