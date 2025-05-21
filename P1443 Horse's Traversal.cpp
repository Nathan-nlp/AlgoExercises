#include <iostream>
#include <algorithm>
#include <cstring>

#define x first
#define y second 

using namespace std;

typedef pair<int,int> PII;

const int N = 410;
int n,m;
int dist[N][N];
PII q[N * N];

int dx[] = {2,2,1,1,-1,-1,-2,-2};
int dy[] = {1,-1,2,-2,2,-2,1,-1};

void bfs(int x1,int y1)
{
	memset(dist,-1,sizeof dist);
	
	q[0] = {x1,y1};
	dist[x1][y1] = 0;
	int hh = 0,tt = 0;
	
	while(hh <= tt)
	{
		auto t = q[hh++];
		for (int i = 0; i < 8; i ++)
		{
			int a = t.x + dx[i],b = t.y + dy[i];
			
			if (a < 1 || a > n || b < 1 || b > m) continue;
			if (dist[a][b] >= 0) continue;
			
			dist[a][b] = dist[t.x][t.y] + 1;
			q[++tt] = {a,b};
		}
	}
}

int main()
{
	int x1,y1;
	cin >> n >> m >> x1 >> y1;
	
	bfs(x1,y1);
	
	for (int i = 1; i <= n; i ++)
	{
		for (int j = 1; j <= m; j ++)
			printf("%-5d",dist[i][j]);
		cout << endl;
	}
	
	return 0;
 } 
