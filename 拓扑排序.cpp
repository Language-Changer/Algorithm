/*
题目描述
由于无敌的凡凡在2005年世界英俊帅气男总决选中胜出，Yali Company总经理Mr.Z心情好，决定给每位员工发奖金。公司决定以每个人本年在公司的贡献为标准来计算他们得到奖金的多少。
于是Mr.Z下令召开m方会谈。每位参加会谈的代表提出了自己的意见：“我认为员工a的奖金应该比b高！”Mr.Z决定要找出一种奖金方案，满足各位代表的意见，且同时使得总奖金数最少。每位员工奖金最少为100100元。
输入格式
第一行两个整数n,m，表示员工总数和代表数；
以下m行，每行2个整数a,b，表示某个代表认为第a号员工奖金应该比第b号员工高。
输出格式
若无法找到合理方案，则输出“Poor Xed”；否则输出一个数表示最少总奖金。
*/

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

const int N = 100005;
const int mod = 80112002;
int n, m, eat[N], cnt;
long long ans, num[N];
vector<int> g[N];
queue<int> q;

void tpsort()
{
	while(q.size())
	{
		int t=q.front();
		q.pop();
		for(auto next: g[t])
		{
			eat[next]--;
			num[next] = max(num[next],num[t]+1);
			if(!eat[next])
			{
				cnt++;
				q.push(next);
			}
		}
	}
}
int main()
{
    cin >> n >> m;
    for(int i = 1; i <= m; i++)
    {
		int u, v;
        cin >> u >> v;
        g[v].push_back(u);
        eat[u]++;
    }
    for(int i = 1; i <= n; i++)
    {
		if (eat[i]==0)
		{
			q.push(i);
			num[i]=100;
			cnt++;
		}
    }
    tpsort();
    for(int i = 1; i <= n; i++)
    {
    	ans+=num[i];
    }
    if (cnt==n)
    {
    	cout << ans;
    }
    else
    {
    	cout << "Poor Xed";
    }
    return 0;
}