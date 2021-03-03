#include <iostream>
using namespace std;

int map[200][200];
int solve[200][200];

int main()
{
	int M, N;

	cin >> M >> N;
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
			cin >> map[i][j];
	}
	//DP
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (i == 0 && j == 0)
				solve[i][j] = map[i][j];
			else
			{
				if (j >= 1)
					solve[i][j] = solve[i][j - 1] + map[i][j];
				if (i >= 1)
					solve[i][j] = (solve[i][j] < solve[i - 1][j] + map[i][j]) ? solve[i - 1][j] + map[i][j] : solve[i][j];
			}
		}
	}
	cout << solve[M - 1][N - 1] << endl;
}