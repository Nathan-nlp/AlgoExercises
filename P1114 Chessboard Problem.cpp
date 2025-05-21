#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 10;
int n,k;
char g[N][N];
int res = 0;
bool st[N];

void dfs(int x,int cnt)
{
	if (cnt == k)
	{
		res ++;
		return ;
	}
	
	if (x >= n)
	return;
	
	for (int i = 0; i < n; i ++)
	{
		if (!st[i] && g[x][i] == '#')
		{
			st[i] = true;
			dfs(x + 1,cnt + 1);
			st[i] = false;
		}
	}
	dfs(x + 1,cnt);
	
}

int main()
{
	while (cin >> n >> k && n > 0 && k > 0)
	{
		for (int i = 0; i < n ;i ++ )
		{
			cin >> g[i];
		}
		res = 0;
		dfs(0,0);
		cout << res << endl;
	}
	return 0;
 } 
