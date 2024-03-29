//欧拉筛法。
//素数存在数组p中。
#include<bits/stdc++.h>
using namespace std;
#define int long long

int n,cnt=0;
int p[10000010];
bool is_prime[10000010];
int sum=0;

signed main()
{
	cin >> n;
	is_prime[1] = 1;
	for(int i=2;i <= n;i++)
	{
		if(is_prime[i] == 0)
		{
			p[++cnt] = i;
		}
		for(int j=1;j <= cnt && p[j] * i <= n;j++)
		{
			is_prime[p[j] * i] = 1;
			if(i % p[j] == 0)
			{
				break;
			}
		}
	}
	return 0;
}
