#include <iostream>
#include <deque>
using namespace std;

pair<int, int> *screw;
bool *used;
deque<int> ans;
int len, res;
int res_i;

void assemble(deque<int> dq, int size)
{
	if (size > res)
	{
		ans.clear();
		for (int i = 0; i < dq.size(); i++)
			ans.push_back(dq[i]);
		res = size;
	}
	for (int i = 0; i < len; i++)
	{
		if (screw[dq.back()].second == screw[i].first && used[i] == false)
		{
			dq.push_back(i);
			used[i] = true;
			assemble(dq, size + 1);
			dq.pop_back();
			used[i] = false;
		}
	}
}


int main()
{
	int C;
	deque<int> temp;

	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> C;
	for (int N = 1; N <= C; N++)
	{
		int in, out;

		res = 0;
		cin >> len;
		screw = new pair<int, int>[len];
		used = new bool[len];
		for (int i = 0; i < len; i++)
		{
			cin >> screw[i].first >> screw[i].second;
			used[i] = false;
		}
		for (int i = 0; i < len; i++)
		{
			used[i] = true;
			temp.push_back(i);
			assemble(temp, 1);
			used[i] = false;
			temp.pop_back();
		}
		cout << "#" << N << " ";
		for (int i = 0; i < ans.size(); i++)
			cout << screw[ans[i]].first << " " << screw[ans[i]].second << " ";
		cout << endl;
		delete used;
		delete screw;
	}
}