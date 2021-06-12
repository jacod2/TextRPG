//1.플레이어는 직업과 체력 공격이란 데이터를 갖는다.구조체로 표현하시오
//2. 게임을 시작하면 직업 선택(1.전사2.법사.3도적.외 등등 하고싶음 더 하세요
//	3. 플레이어를 생성하면 플레이어의 정보는 상시 출력 메뉴창이든 사냥터든
//	4.메뉴에서 던전을 고르시고 1.초급, 2.중급.3고급
//	5.각 던전별 난이도에 따른 다른 몬스터들이 나와야 함.
//	6.몬스터도 이름 공격력 체력 이란 데이터를 가져야 함.
//	7. 던전에서는 플레이어 정보 뿐만 아니라 몬스터의 정보도 같이 출력되야 한다.
//	8. 던전에 들어가면 메뉴는 공격과 도망 두개가 있지만 너넨 더하겠지 ?
//	9. 공격을 하면 플레이어의 체력과 몬스터의 체력은 각각 공격력 만큼 깎는다.
//	10. 만약 플레이어의 체력이 0이 되면 사망 띄어주고 HP 풀로 채워주기
//	11. 몬스터의 체력이 0이되면 사냥 성공 띄어주기.물론 레벨업도 심심하면 만들겠지 ?
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
			"개미굴",
			{"병정개미","불개미","장군개미","여왕개미"},
			{10,20,30,40},
			{5,10,15,30},
			{10,20,30,50}
		},
		{
			"버섯왕국",
			{ "초록버섯","주황버섯","뿔버섯","버섯왕" },
			{ 100,150,200,300 },
			{ 50,70,90,140 },
			{ 50,70,90,100 }
		},
		{
			"커닝시티",
			{ "양아치","불량배","깡패","오야붕" },
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
		cout << "1.불러오기 2.새로시작\n";
		cin >> LoadSel;
		switch (LoadSel)
		{
		case 1:
			if (LoadGame(&Player))
			{
				cout << "불러오기 성공!!\n";
				CheckLoad = true;
				system("pause");
				break;
			}
			else
			{
				cout << "불러오기 실패ㅠㅠ\n";
				system("pause");
				continue;
			}
		case 2:
			ChooseJob(&Player);
			CheckLoad = true;
			break;
		default:
			cout << "잘못된 입력입니다.";
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
			cout << "게임을 클리어하셨습니다 축하합니다!!!!\n\n";
			return 0;
		}
		SelDungeon(&DungeonSel, &Player);
		if (DungeonSel == 4)
		{
			if (SaveGame(&Player))
			{
				cout << "저장성공!!\n";
			}
			else
			{
				cout << "저장실패!!\n";
			}
			return 0;
		}
		GoDungeon(Dungeon[DungeonSel - 1], &Player,GameClear);
	}

	return 0;
}

