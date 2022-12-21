#include <bits/stdc++.h>
using namespace std;

const int N=5000;

int n,m,t;
int dis[N][N];//i~j为0

int main()
{
    cin >> n >> m >> t;//查询次数
    memset(dis,63,sizeof(dis));//初值为无穷大
    for (int i=0;i <= N;i++) dis[i][i] = 0;//自己到自己为0
    for (int i=1;i <= m;i++)//读图
    {
        int a,b,w;
        cin >> a >> b >> w;
        dis[a][b] = w;
        dis[a][b] = w;//双向图
    }
    for (int k=1;k <= n;k++)//中间点
    for (int i=1;i <= n;n++)//起始点
    for (int j=1;j <= n;j++)//结束点
    {
        dis[i][j] = min(dis[i][j],dis[i][k]+dis[k][j]);
    }
    for (int i=1;i <= t;i++)//查询
    {
        int a,b;
        cin >> a >> b;
        cout << dis[a][b] << endl;
    }
    return 0;
}