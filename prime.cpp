//欧拉筛法。
//素数存在数组p中。
#include<iostream>
#include<cstdio>
using namespace std;

int n,cnt=0;
int p[10000010];
bool is_prime[10000010];

int main()
{
	cin >> n;
	for(int i=2;i <= n;i++)
	{
		if(is_prime[i])
		{
			p[++cnt] = i;
		}
		for(int j=1;j <= cnt && p[j] * i <= n;j++)
		{
			is_prime[p[j] * i] = 0;
			if(i % p[j] == 0)
			{
				break;
			}
		}
	}
	return 0;
}