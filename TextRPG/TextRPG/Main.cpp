//1.�÷��̾�� ������ ü�� �����̶� �����͸� ���´�.����ü�� ǥ���Ͻÿ�
//2. ������ �����ϸ� ���� ����(1.����2.����.3����.�� ��� �ϰ���� �� �ϼ���
//	3. �÷��̾ �����ϸ� �÷��̾��� ������ ��� ��� �޴�â�̵� ����͵�
//	4.�޴����� ������ ���ð� 1.�ʱ�, 2.�߱�.3���
//	5.�� ������ ���̵��� ���� �ٸ� ���͵��� ���;� ��.
//	6.���͵� �̸� ���ݷ� ü�� �̶� �����͸� ������ ��.
//	7. ���������� �÷��̾� ���� �Ӹ� �ƴ϶� ������ ������ ���� ��µǾ� �Ѵ�.
//	8. ������ ���� �޴��� ���ݰ� ���� �ΰ��� ������ �ʳ� ���ϰ��� ?
//	9. ������ �ϸ� �÷��̾��� ü�°� ������ ü���� ���� ���ݷ� ��ŭ ��´�.
//	10. ���� �÷��̾��� ü���� 0�� �Ǹ� ��� ����ְ� HP Ǯ�� ä���ֱ�
//	11. ������ ü���� 0�̵Ǹ� ��� ���� ����ֱ�.���� �������� �ɽ��ϸ� ������� ?
//

#include <iostream>
#include <string>
#include "struct.h"
#include "func.h"
using namespace std;


bool GameClear = 0;

int main()
{
	PlayerStat Player;


	tagDungeon Dungeon[3] =
	{
		{
			"���̱�",
			{"��������","�Ұ���","�屺����","���հ���"},
			{10,20,30,40},
			{5,10,15,30},
			{10,20,30,50}
		},
		{
			"�����ձ�",
			{ "�ʷϹ���","��Ȳ����","�Թ���","������" },
			{ 100,150,200,300 },
			{ 50,70,90,140 },
			{ 50,70,90,100 }
		},
		{
			"Ŀ�׽�Ƽ",
			{ "���ġ","�ҷ���","����","���ߺ�" },
			{ 2,3,4,6 },
			{ 1,1,2,3 },
			{ 100,200,300,500 }
		}
	};

	int DungeonSel = 0;

	bool CheckLoad = 0;
	PrintIndex();
	while (CheckLoad != true)
	{
		int LoadSel = 0;
		system("cls");
		cout << "1.�ҷ����� 2.���ν���\n";
		cin >> LoadSel;
		switch (LoadSel)
		{
		case 1:
			if (LoadGame(&Player))
			{
				cout << "�ҷ����� ����!!\n";
				CheckLoad = true;
				system("pause");
				break;
			}
			else
			{
				cout << "�ҷ����� ���ФФ�\n";
				system("pause");
				continue;
			}
		case 2:
			ChooseJob(&Player);
			CheckLoad = true;
			break;
		default:
			cout << "�߸��� �Է��Դϴ�.";
			continue;
		}
	}

	while (1)
	{
		system("cls");
		Player.PlayerHp = Player.PlayerMaxHp;
		PrintPlayerStat(&Player);

		if (GameClear == true)
		{
			cout << "������ Ŭ�����ϼ̽��ϴ� �����մϴ�!!!!\n\n";
			return 0;
		}
		SelDungeon(&DungeonSel, &Player);
		if (DungeonSel == 4)
		{
			if (SaveGame(&Player))
			{
				cout << "���强��!!\n";
			}
			else
			{
				cout << "�������!!\n";
			}
			return 0;
		}
		GoDungeon(Dungeon[DungeonSel - 1], &Player,GameClear);
	}

	return 0;
}

