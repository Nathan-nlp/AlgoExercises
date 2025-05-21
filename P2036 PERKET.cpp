#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 20;
int n;
int st[N];
int s[N],b[N];
int res = 1e9; 

void dfs(int x)
{
	if (x > n)
	{
		bool tl = false;
		int sum1 = 1;
		int sum2 = 0;
		for (int i = 1; i <= n; i ++)
		{
			if (st[i] == 1)
			{
				tl = true;
				sum1 *= s[i];
				sum2 += b[i];
			}
		 } 
		 if (tl)
		 res = min(res,abs(sum1-sum2));
		 return ;
	}
	
	st[x] = 1;
	dfs(x + 1);
	st[x] = 0;
	
	st[x] = 2;
	dfs(x + 1);
	st[x] = 0; 
}

int main()
{
	cin >> n;
	
	for (int i = 1; i <= n; i ++)
	{
		cin >> s[i] >> b[i];
	}
	dfs(1);
	cout << res << endl;
	return 0;
}
