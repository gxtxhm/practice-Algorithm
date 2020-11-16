#include<iostream>

using namespace std;

int testCase;
int studentNum, studentPairNum;
bool visited[10];
bool friends[10][10];
int solutionNum; // 방법 수 
int answer[50] = { 0, };
void solution()
{
	int fastStudent= -1;

	for (int i = 0; i < studentNum; i++)// 짝을 찾지 못한 학생을 찾는 함수 , 그 중에서 제일 번호가 빠른 학생을 찾는다.
	{
		if (visited[i] == false) 
		{
			fastStudent = i;
			break;
		}
	}

	if (fastStudent == -1)// 모든 학생이 짝을 찾았다면 
	{
		solutionNum++;
		return;
	}

	for (int i = fastStudent+1; i < studentNum; i++)// fastStudent 번째 학생과 짝이 될 수 있는 친구를 찾는 함수
	{
			if (!visited[i]  && friends[fastStudent][i])//visited[i] 학생이 짝이없고 fastStudent와 둘이 친구라면
			{
				visited[i] = true; visited[fastStudent] = true;
				solution();
				visited[i] = false; visited[fastStudent] = false;
			}
	}

	
	
}







int main()
{
	int n, m;// 한 쌍을 입력 받을 변수들
	int imsitestCase;
	cin >> testCase;
	
	for (int i = 0; i < 10; i++)
	{
		visited[i] = false;
	}
	imsitestCase = testCase;
	while (imsitestCase > 0)
	{
		solutionNum = 0;  
		cin >> studentNum >> studentPairNum;

		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				friends[i][j] = false;
			}
		}

		for (int i = 0; i < studentPairNum; i++)//누가 친구인지 입력받아 friend 배열에 표시
		{
			cin >> n >> m;
			if (n > m)						
				friends[m][n] = true;
			else
				friends[n][m] = true;
			
		}
		solution();
		answer[testCase-imsitestCase] = solutionNum;
		imsitestCase--;
	}
	for (int i=0; i < testCase; i++)
	{
		cout << answer[i];
		cout << '\n';
	}
	return 0; 
}