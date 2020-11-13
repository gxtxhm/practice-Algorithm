#include<iostream>
#include<string.h>
using namespace std;

char board[5][5];//5x5 판
char word[10];//최대 길이가 10인 단어를 10개까지 저장가능한 배열
int endSearch = 0;// 마지막 알파벳을 찾았는지 체크

float cashe[5][5][10] = { 0, };//메모이제이션 기법 적용
int dx[8] = { -1,0,1,1,1,0,-1,-1 };
int dy[8] = { 1,1,1,0,-1,-1,-1,0 };
int nextX, nextY;

void hasword(int x, int y, int wordNum)
{
	
	
	
	if ((x > 4 || x < 0) || (y > 4 || y < 0))return;//x,y값이 범위를 벗어나면 종료

	

	if (endSearch == 1)return;//마지막 알파벳찾았으면 모든 재귀함수 종료


	if (board[x][y] == word[wordNum])//해당 알파벳을 찾았다면
	{
		cashe[x][y][wordNum] = 1;

		if (wordNum == strlen(word) -1)//마지막 알파벳이면 종료
		{
			endSearch = 1;
			return;
		}

		else //알파벳을 더 찾아야 한다면 
		{

			for (int i = 0; i < 8; i++)
			{
				nextX = x + dx[i];
				nextY = y + dy[i];
				if (cashe[nextX][nextY][wordNum + 1] == 1)continue;
				hasword(nextX, nextY, wordNum + 1);
			}
			
		}
	}
	//알파벳을 못찾았다면
	else
	{

		return;
	}
}

int main()
{
	int i, j, n, caseNum;

	cin >> caseNum;
	

	while (caseNum > 0)//테스트 케이스만큼 보드 입력 받기
	{
		for (i = 0; i < 5; i++)// 케이스 하나의 보드 입력
		{
			for (j = 0; j < 5; j++)
			{

				cin >> board[i][j];
				//마지막 열이 입력이 안되어서 계속 PRETTY가 NO가 나와서 한참을 해맸다.
											//저 밑에 있는 getchar 가 마지막 입력을 먹어서 이런 일이 발생했다.
											//잘 모르겠다. 엔터를 저거로 없애려는 거였는데 

			}
		}

		cin >> n;
		
		

		
		while (n>0)//n개의 단어를 검색한다.
		{
			endSearch = 0;
			memset(cashe, 0, sizeof(cashe));

			cin >> word;

			for (i = 0; i < 5; i++)// 보드에서 첫번째 글자 위치 찾기
			{
				for (j = 0; j < 5; j++)
				{
					if (word[0] == board[i][j])
					{
						if (endSearch == 1)//단어를 찾았다면
							goto outFor;

						hasword(i, j, 0);

					}
				}

			}
		outFor:
			if (endSearch == 1)//단어를 찾았다면
			{
				cout << word <<" "<<"YES";
				cout << '\n';
			}
			else//단어를 못찾았다면
			{
				cout << word<<" " << "NO"; cout << '\n';
			}
				
			n--;
		}
		caseNum--;
	}
	
	return 0;
}