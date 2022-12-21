/*
[题目描述]本题测试数据为随机数据,在考试中可能会出现构造数据让SPFA不通过。如题,给出一个有向图,请输出从某一点出发到所有点的最短路径长度。
[输入格式]第一行包含三个整数n,m,s,分别表示点的个数、有向边的个数、出发点的编号。接下来m行每行包含三个整数u,v,w,表示一条u to v的,长度为w的边。
[输出格式]输出一行n个整数,第i个表示s到第i个点的最短路径,若不能到达则输出 2^31-1.
*/
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;

const int N=10005;
const int inf=0x3f3f3f3f;

struct edge 
{
  int v, w;
};

queue<int> q;
vector<edge> e[N];
int dis[N], vis[N];

bool spfa(int n, int s) 
{
    memset(dis, 63, sizeof(dis));
    dis[s] = 0;
    vis[s] = 1;
    q.push(s);
    while (!q.empty()) 
    {
        int u = q.front();
        q.pop();
        vis[u] = 0;
        for (auto ed:e[u]) 
        {
            int v = ed.v,w = ed.w;
            if (dis[v] > dis[u] + w) 
            {
                dis[v] = dis[u] + w;
                if (!vis[v])
                {
                    q.push(v);
                    vis[v] = 1;
                }
            }
        }
    }
    return true;
}

int main()
{
    int n,m,s;
    cin >> n >> m >> s;
    for (int i = 1; i <= m; i++)
    {
        int u,v,w;
        cin >> u >> v >> w;
        e[u].push_back({v,w});
    }
    spfa(n,s);
    for (int i = 1; i <= n; i++)
    {
        if (dis[i] != inf)
        {
            cout << dis[i] << ' ';
        }
        else
        {
            cout << 0x7fffffff << ' ';
        }
    }
    return 0;
}