#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 110;
int n,m;
int res = 0;
char g[N][N];
bool st[N][N];
int dx[] = {1,1,0,-1,-1,-1,0,1};
int dy[] = {0,-1,-1,-1,0,1,1,1};

void dfs(int x,int y)
{
	for (int i = 0; i < 8; i ++)
	{
		int a = x + dx[i],b = y + dy[i];
		if (a < 0 || a >= n || b < 0 || b >= m) continue;
		if (g[a][b] != 'W') continue;
		if (st[a][b]) continue;
		
		st[a][b] = true;
		dfs(a,b);
	}
}

int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i ++)
	{
		cin >> g[i];
	}
	for (int i = 0; i < n; i ++)
	{
		for (int j = 0; j < m; j ++)
		{
			if (g[i][j] == 'W' && !st[i][j]) 
			{
				dfs(i,j);
				res ++;
			}
		}
	}
	cout << res << endl;
	return 0;
}
