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
		cout << "�÷��̾� �̸��� �Է����ּ��� : ";
		cin >> Player->PlayerName;
		cout << "������ �������ּ���\n";
		cout << "1. ���� (���ݷ� : ���� | ü�� : ����)\n";
		cout << "2. ���� (���ݷ� : ���� | ü�� : ����)\n";
		cout << "3. ���� (���ݷ� : ���� | ü�� : ����)\n";


		cin >> PlayerSelect;
		Job job = (Job)(PlayerSelect - 1);
		switch (job)
		{
		case Warrior:
			Player->PlayerAttack = 10;
			Player->PlayerHp = 200;
			Player->PlayerMaxHp = 200;
			Player->PlayerMp = 0;
			Player->PlayerJob = "����";
			Player->PlayerExp = 0;
			Player->PlayerLV = 1;
			return;
		case Mage:
			Player->PlayerAttack = 30;
			Player->PlayerHp = 100;
			Player->PlayerMaxHp = 100;
			Player->PlayerMp = 20;
			Player->PlayerJob = "����";
			Player->PlayerExp = 0;
			Player->PlayerLV = 1;
			return;
		case Rogue:
			Player->PlayerAttack = 20;
			Player->PlayerHp = 150;
			Player->PlayerMaxHp = 150;
			Player->PlayerJob = "����";
			Player->PlayerMp = 10;
			Player->PlayerExp = 0;
			Player->PlayerLV = 1;
			return;
		default:
			cout << "�߸��� �Է��Դϴ�.\n";
			break;
		}
	}
}

void PrintIndex()
{
	cout << "TextRPG�� �����մϴ�! \n\n";
	cout << "$�÷��̾�� �̸��� ������ �Է��ϰ� ������ Ž���ϰ� �˴ϴ�! \n\n";
	cout << "$�������� ���͸� ����Ұ�� ����ġ����Եǰ� ����ġ 100����� �������� �Ҽ��ֽ��ϴ�!	\n\n";
	cout << "$���� ����� �÷��̾ ����Ұ�� ü���� ȸ���ϰ� ���θ޴��� ���ư��ϴ�.\n\n";
	cout << "$���̵� 3�� ���������� ������ ������ Ŭ�����ϰԵ˴ϴ� ��������� ����غ�����!	\n\n";
	system("pause");
}


void PrintPlayerStat(PlayerStat* Player)
{
	cout << "$------�÷��̾� ����------$\n";
	cout << "�̸�	:	" << Player->PlayerName << '\n';
	cout << "����	:	" << Player->PlayerJob << '\n';
	cout << "����	:	" << Player->PlayerLV << '\n';
	cout << "����ġ	:	" << Player->PlayerExp << '\n';
	cout << "���ݷ�	:	" << Player->PlayerAttack << '\n';
	cout << "ü��	:	" << Player->PlayerHp << '\n';
	cout << "����	:	" << Player->PlayerMp << '\n';
	cout << "$-------------------------$\n";
}

void SelDungeon(int* DungeonSel, PlayerStat* Player)
{
	while (1)
	{
		system("cls");
		PrintPlayerStat(Player);
		cout << "\n\n------���� ����-------\n";
		cout << "1.	���̱�\n";
		cout << "2.	�����ձ�\n";
		cout << "3.	Ŀ�׽�Ƽ\n";
		cout << "4.	�����ϰ� ������\n";
		cin >> *DungeonSel;
		switch (*DungeonSel)
		{
		case 1:
		case 2:
		case 3:
		case 4:
			return;
		default:
			cout << "�߸��� �Է��Դϴ�.\n";
			break;
		}
	}
}

void PrintMonsterStat(tagDungeon dungeon, int MonsterNum)
{
	cout << "$------���� ����------$\n";
	cout << "�̸�	:	" << dungeon.MonsterName[MonsterNum] << '\n';
	cout << "ü��	:	" << dungeon.MonsterHP[MonsterNum] << '\n';
	cout << "���ݷ�	:	" << dungeon.MonsterAtt[MonsterNum] << '\n';
	cout << "����ġ	:	" << dungeon.MonsterXp[MonsterNum] << '\n';
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
			if (Dungeon.DugeonName == "Ŀ�׽�Ƽ")
				GameClear = true;
			cout << "������ Ŭ���� �ϼ̽��ϴ� �����մϴ�!\n\n";
			system("pause");
			return;
		}


		PrintPlayerStat(Player);


		PrintMonsterStat(Dungeon, i);
		cout << "1.	�ο��\n" << "2.	��������\n";
		cin >> ActionSel;
		switch (ActionSel)
		{

		case 1:
			cout << "�ο��� �����մϴ�.\n";
			system("pause");
			if (Fight(Dungeon, i, Player))
				i++;
			else
				return;
			break;
		case 2:
			cout << "�������ϴ�.\n";
			system("pause");
			return;
		default:
			cout << "�߸��� �Է��Դϴ�.\n";
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
			cout << "�÷��̾� ����Ф�\n\n";
			cout << "������ �ǵ��ư��ϴ�.\n\n";
			system("pause");
			Player->PlayerHp = Player->PlayerMaxHp;
			return false;
		}
		if (dungeon.MonsterHP[MonsterNum] <= 0)
		{
			cout << "���� óġ ����!!\n";
			Player->PlayerExp += dungeon.MonsterXp[MonsterNum];
			while (100 <= Player->PlayerExp)
			{
				Player->PlayerExp -= 100;
				cout << "������!!!!!\n\n";
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
		cout << "1.�����Ѵ� 2.��ų��� (MP 10 �Ҹ�)\n";
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
				cout << "��ų���!\n";
				system("pause");
				Player->PlayerMp -= 10;
				Player->PlayerHp -= dungeon.MonsterAtt[MonsterNum];
				dungeon.MonsterHP[MonsterNum] -= 2 * Player->PlayerAttack;
			}
			else
			{
				cout << "��������!\n";
				system("pause");
			}
			break;
		default:
			cout << "�߸��� �Է��Դϴ�.";
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