#define MAX_DROP_NUMBER 1000

struct S_DropSystem
{
	unsigned char ItemType;
	unsigned int ItemIndex;
	unsigned char ItemLevel;
	unsigned char ItemOpt;
	unsigned int ItemLuck;
	unsigned char ItemSkill;
	unsigned char ItemDur;
	unsigned int ItemRate;
	unsigned int ItemMinlvl;
	unsigned int ItemMaxlvl;
	unsigned char ItemDropMap;
	unsigned char ItemExc;

	//Arena Event
	unsigned char aItemType;
	unsigned int aItemIndex;
	unsigned char aItemLevel;
	unsigned char aItemOpt;
	unsigned int aItemLuck;
	unsigned char aItemSkill;
	unsigned char aItemDur;
	unsigned int aItemRate;
	unsigned int aItemMinlvl;
	unsigned int aItemMaxlvl;
	unsigned char aItemDropMap;
	unsigned char aItemExc;

};

class C_DropSystem
{
public:
	S_DropSystem t_struct[MAX_DROP_NUMBER];
	unsigned short t_num;
	void t_LoadSystem();
	void t_LoadArenaBag();
	int MygEventMonsterItemDrop(BYTE * b_MonsterDataAddr,BYTE * a_gObjAddr);
private:
	S_DropSystem		Item[120];
	S_DropSystem		HappyItem[120];
	unsigned char		ItemCount;
};

void MonsterDropCall(BYTE * b_MonsterDataAddr,BYTE * a_gObjAddr);
extern C_DropSystem Drop;