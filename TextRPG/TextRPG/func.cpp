#include "func.h"
#include <iostream>
#include "struct.h"
using namespace std;

void ChooseJob(PlayerStat* Player)
{
	int PlayerSelect;
	while (1)
	{
		system("cls");
		cout << "플레이어 이름을 입력해주세요 : ";
		cin >> Player->PlayerName;
		cout << "직업을 선택해주세요\n";
		cout << "1. 전사 (공격력 : 낮음 | 체력 : 높음)\n";
		cout << "2. 법사 (공격력 : 높음 | 체력 : 낮음)\n";
		cout << "3. 도적 (공격력 : 보통 | 체력 : 보통)\n";


		cin >> PlayerSelect;
		Job job = (Job)(PlayerSelect - 1);
		switch (job)
		{
		case Warrior:
			Player->PlayerAttack = 10;
			Player->PlayerHp = 200;
			Player->PlayerMaxHp = 200;
			Player->PlayerMp = 0;
			Player->PlayerJob = "전사";
			Player->PlayerExp = 0;
			Player->PlayerLV = 1;
			return;
		case Mage:
			Player->PlayerAttack = 30;
			Player->PlayerHp = 100;
			Player->PlayerMaxHp = 100;
			Player->PlayerMp = 20;
			Player->PlayerJob = "법사";
			Player->PlayerExp = 0;
			Player->PlayerLV = 1;
			return;
		case Rogue:
			Player->PlayerAttack = 20;
			Player->PlayerHp = 150;
			Player->PlayerMaxHp = 150;
			Player->PlayerJob = "도적";
			Player->PlayerMp = 10;
			Player->PlayerExp = 0;
			Player->PlayerLV = 1;
			return;
		default:
			cout << "잘못된 입력입니다.\n";
			break;
		}
	}
}

void PrintIndex()
{
	cout << "TextRPG를 시작합니다! \n\n";
	cout << "$플레이어는 이름과 직업을 입력하고 던전을 탐험하게 됩니다! \n\n";
	cout << "$던전에서 몬스터를 사냥할경우 경험치를얻게되고 경험치 100을모아 레벨업을 할수있습니다!	\n\n";
	cout << "$만약 사냥중 플레이어가 사망할경우 체력을 회복하고 메인메뉴로 돌아갑니다.\n\n";
	cout << "$난이도 3의 최종던전을 정복시 게임을 클리어하게됩니다 힘들겠지만 노력해보세요!	\n\n";
	system("pause");
}


void PrintPlayerStat(PlayerStat* Player)
{
	cout << "$------플레이어 스탯------$\n";
	cout << "이름	:	" << Player->PlayerName << '\n';
	cout << "직업	:	" << Player->PlayerJob << '\n';
	cout << "레벨	:	" << Player->PlayerLV << '\n';
	cout << "경험치	:	" << Player->PlayerExp << '\n';
	cout << "공격력	:	" << Player->PlayerAttack << '\n';
	cout << "체력	:	" << Player->PlayerHp << '\n';
	cout << "마력	:	" << Player->PlayerMp << '\n';
	cout << "$-------------------------$\n";
}

void SelDungeon(int* DungeonSel, PlayerStat* Player)
{
	while (1)
	{
		system("cls");
		PrintPlayerStat(Player);
		cout << "\n\n------던전 선택-------\n";
		cout << "1.	개미굴\n";
		cout << "2.	버섯왕국\n";
		cout << "3.	커닝시티\n";
		cout << "4.	저장하고 나가기\n";
		cin >> *DungeonSel;
		switch (*DungeonSel)
		{
		case 1:
		case 2:
		case 3:
		case 4:
			return;
		default:
			cout << "잘못된 입력입니다.\n";
			break;
		}
	}
}

void PrintMonsterStat(tagDungeon dungeon, int MonsterNum)
{
	cout << "$------몬스터 스탯------$\n";
	cout << "이름	:	" << dungeon.MonsterName[MonsterNum] << '\n';
	cout << "체력	:	" << dungeon.MonsterHP[MonsterNum] << '\n';
	cout << "공격력	:	" << dungeon.MonsterAtt[MonsterNum] << '\n';
	cout << "경험치	:	" << dungeon.MonsterXp[MonsterNum] << '\n';
	cout << "$-------------------------$\n";
}

void GoDungeon(tagDungeon Dungeon, PlayerStat* Player,bool GameClear)
{
	system("cls");
	int i = 0;
	int ActionSel = 0;
	while (1)
	{
		system("cls");
		if (i == 4)
		{
			if (Dungeon.DugeonName == "커닝시티")
				GameClear = true;
			cout << "던전을 클리어 하셨습니다 축하합니다!\n\n";
			system("pause");
			return;
		}


		PrintPlayerStat(Player);


		PrintMonsterStat(Dungeon, i);
		cout << "1.	싸운다\n" << "2.	도망간다\n";
		cin >> ActionSel;
		switch (ActionSel)
		{

		case 1:
			cout << "싸움을 시작합니다.\n";
			system("pause");
			if (Fight(Dungeon, i, Player))
				i++;
			else
				return;
			break;
		case 2:
			cout << "도망갑니다.\n";
			system("pause");
			return;
		default:
			cout << "잘못된 입력입니다.\n";
			system("pause");
			break;
		}
	}
}

bool Fight(tagDungeon dungeon, int MonsterNum, PlayerStat* Player)
{
	int FightSel = 0;
	while (1)
	{
		system("cls");
		if (Player->PlayerHp <= 0)
		{
			cout << "플레이어 사망ㅠㅠ\n\n";
			cout << "마을로 되돌아갑니다.\n\n";
			system("pause");
			Player->PlayerHp = Player->PlayerMaxHp;
			return false;
		}
		if (dungeon.MonsterHP[MonsterNum] <= 0)
		{
			cout << "몬스터 처치 성공!!\n";
			Player->PlayerExp += dungeon.MonsterXp[MonsterNum];
			while (100 <= Player->PlayerExp)
			{
				Player->PlayerExp -= 100;
				cout << "레벨업!!!!!\n\n";
				Player->PlayerLV += 1;
				Player->PlayerAttack += 10;
				Player->PlayerMaxHp += 10;
				Player->PlayerHp += 10;
				Player->PlayerMp += 10;
			}
			system("pause");
			return true;
		}
		PrintPlayerStat(Player);
		PrintMonsterStat(dungeon, MonsterNum);
		cout << "1.공격한다 2.스킬사용 (MP 10 소모)\n";
		cin >> FightSel;
		switch (FightSel)
		{
		case 1:
			Player->PlayerHp -= dungeon.MonsterAtt[MonsterNum];
			dungeon.MonsterHP[MonsterNum] -= Player->PlayerAttack;
			break;
		case 2:
			if (Player->PlayerMp >= 10)
			{
				cout << "스킬사용!\n";
				system("pause");
				Player->PlayerMp -= 10;
				Player->PlayerHp -= dungeon.MonsterAtt[MonsterNum];
				dungeon.MonsterHP[MonsterNum] -= 2 * Player->PlayerAttack;
			}
			else
			{
				cout << "마나부족!\n";
				system("pause");
			}
			break;
		default:
			cout << "잘못된 입력입니다.";
			system("pause");
			break;
		}
	}
}


bool LoadGame(PlayerStat* Player)
{
	FILE* fp = nullptr;

	errno_t err = fopen_s(&fp, "../SaveData.txt", "rb");

	if (0 == err)
	{
		fread(Player, sizeof(PlayerStat), 1, fp);
		fclose(fp);
		return true;
	}
	else
		return false;
}

bool SaveGame(PlayerStat* Player)
{
	FILE* fp = nullptr;

	errno_t err = fopen_s(&fp, "../SaveData.txt", "wb");

	if (0 == err)
	{
		fwrite(Player, sizeof(PlayerStat), 1, fp);
		fclose(fp);
		return true;
	}
	else
		return false;
}