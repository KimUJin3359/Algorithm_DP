#include <iostream>
#include <queue>
using namespace std;

int map[100][100];
int len;

struct compare {
	bool operator()(pair<int, int> a, pair<int, int> b)
	{
		if (a.first * a.second > b.first * b.second)
			return (true);
		else if (a.first * a.second < b.first * b.second)
			return (false);
		else
		{
			if (a.first > b.first)
				return (true);
			else
				return (false);
		}
	}
};

priority_queue<pair<int, int>, vector<pair<int, int>>, compare> pq;

int main()
{
	int C;
	int len;

	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> C;
	for (int N = 1; N <= C; N++)
	{
		cin >> len;
		for (int i = 0; i < len; i++)
		{
			for (int j = 0; j < len; j++)
				cin >> map[i][j];
		}
		for (int i = 0; i < len; i++)
		{
			for (int j = 0; j < len; j++)
			{
				int row = 0, col = 0;
				if (map[i][j] != 0)
				{
					while (j + col < len && map[i][j + col] != 0)
						col++;
					while (i + row < len && map[i + row][j] != 0)
						row++;
				}
				if (row != 0 && col != 0)
				{
					pq.push({ row, col });
					for (int k = i; k < row + i; k++)
					{
						for (int t = j; t < col + j; t++)
							map[k][t] = 0;
					}
					j += col - 1;
				}
			}
		}
		cout << "#" << N << " " << pq.size() << " ";
		while (pq.size())
		{
			cout << pq.top().first << " " << pq.top().second << " ";
			pq.pop();
		}
		cout << endl;
	}
}