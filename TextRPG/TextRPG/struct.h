#pragma once
#include <string>
using namespace std;

struct PlayerStat
{
	string PlayerName;
	string PlayerJob;
	int PlayerAttack;
	int PlayerHp;
	int PlayerMp;
	int PlayerMaxHp;
	int PlayerExp;
	int PlayerLV;
};

struct tagDungeon
{
	string DugeonName;
	string MonsterName[4];
	int MonsterHP[4];
	int MonsterAtt[4];
	int MonsterXp[4];
};

enum Job
{
	Warrior = 0,
	Mage = 1,
	Rogue = 2
};
