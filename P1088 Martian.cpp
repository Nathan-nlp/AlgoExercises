#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 10010;

int n,m;
int arr[N];
int mars[N];
bool st[N];
bool return0 = false;
int res = 0;

void dfs(int x)
{
	if (return0)
	{
		return ;
	}
	
	if (x > n)
	{
		res ++;
		if (res == m + 1)
		{
		return0 = true;
		for (int i = 1; i <= n; i ++)
		{
			cout << arr[i] << " ";
		}
	}
	return ;
}
	for (int i = 1; i <= n; i ++)
	{
		if (!res)
		{
			i = mars[x];
		}
		if(!st[i])
		{
			arr[x] = i;
			st[i] = true;
			dfs(x + 1);
			st[i] = false;
			arr[x] = 0;
		}
	}
}

int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i ++)
	{
		cin >> mars[i];
	}
	dfs(1);
	return 0;
}
