#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>

#define x first
#define y second

using namespace std;
typedef pair<int,int> PII;

const int N = 110;
int n,m;
int g[N][N];
int dist[N][N];
queue<PII> q; 

int dx[] = {1,0,-1,0};
int dy[] = {0,-1,0,1};


int bfs(int x1,int y1)
{
	memset(dist,-1,sizeof dist);
	q.push({x1,y1});
	dist[x1][y1] = 0;//initialization
	
	while(!q.empty()) 
	{
		auto t = q.front();
		q.pop();
		
		for (int i = 0; i < 4; i ++)
		{
			int a = t.x + dx[i];
			int b = t.y + dy[i];
			
			if (a < 1 || a > n || b < 1 || b > m) continue;
			if (dist[a][b] > 0) continue;//Indicates that this point has passed 
			if (g[a][b] != 0) continue;
			
			q.push({a,b});
			dist[a][b] = dist[t.x][t.y] + 1;
			
			if (a == n && b == m) return dist[n][m];
		}
	}
	return dist[n][m];
}

int main()
{
	cin >> n >> m;
	
	for (int i = 1; i <= n; i ++)
	{
		for (int j = 1; j <= m; j ++)
		{
			cin >> g[i][j];
		}
	}
	int res = bfs(1,1);
	cout << res << endl;
	return 0;
 } 
