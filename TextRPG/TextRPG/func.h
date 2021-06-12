#pragma once
#include "struct.h"

void ChooseJob(PlayerStat* Player);
void PrintIndex();
void PrintPlayerStat(PlayerStat* Player);
void SelDungeon(int* DungeonSel, PlayerStat* Player);
void GoDungeon(tagDungeon Dungeon, PlayerStat* Player, bool GameClear);
void PrintMonsterStat(tagDungeon dungeon, int MonsterNum);
bool Fight(tagDungeon dungeon, int MonsterNum, PlayerStat* Player);
bool LoadGame(PlayerStat* Player);
bool SaveGame(PlayerStat* Player);