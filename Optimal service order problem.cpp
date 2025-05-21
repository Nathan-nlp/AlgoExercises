#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	cin >> n;
	int a[n];
	double sum = 0;
	for (int i = 1; i <= n; i ++)
	cin >> a[i];
	
	sort(a + 1, a + 1 + n);
	
	for (int i = 2; i <= n ;i ++)
	sum += a[i-1]*(n-i+1);
	
	double ans;
	ans = sum / n;
	printf("%.2lf",ans);
	return 0;
 } 
