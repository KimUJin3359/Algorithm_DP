#include <iostream>
using namespace std;

int map[200][200];
int solve[200][200];

void fill_map(int r, int c)
{
	if (r == 0 && c == 0)
		solve[r][c] = map[r][c];
	else
	{
		if (c >= 1 && solve[r][c - 1] == -1)
			fill_map(r, c - 1);
		if (r >= 1 && solve[r - 1][c] == -1)
			fill_map(r - 1, c);
		if (c >= 1)
			solve[r][c] = solve[r][c - 1] + map[r][c];
		if (r >= 1)
			solve[r][c] = (solve[r][c] > solve[r - 1][c] + map[r][c]) ? solve[r][c] : solve[r - 1][c] + map[r][c];
	}
}

int main()
{
	int M, N;

	cin >> M >> N;
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
			cin >> map[i][j];
	}
	//Memoization
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
			solve[i][j] = -1;
	}
	fill_map(M - 1, N - 1);
	cout << solve[M - 1][N - 1] << endl;
}