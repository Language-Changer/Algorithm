#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;

const int N = 100005;
const int inf = 0x3f3f3f3f;

struct edge {
  int v, w;
};

struct node {
	int dis, u;
	bool operator>(const node& a) const {return dis > a.dis;}//符号重定向。为优先队列的堆排序准备的。
};

vector<edge> e[N];
int dis[N], vis[N];
priority_queue<node, vector<node>, greater<node> > q;//优先队列。

void dijkstra(int n, int s) 
{
	memset(dis, 63, sizeof(dis));
	dis[s] = 0;
	q.push({0, s});
	while (!q.empty()) 
	{
    	int u = q.top().u;
    	q.pop();
    	if (vis[u])
    	{
    		continue;
    	}
    	vis[u] = 1;
    	for (auto ed : e[u]) 
    	{
    		int v = ed.v;
    		int w = ed.w;
    		if (dis[v] > dis[u] + w) 
    		{
        		dis[v] = dis[u] + w;
        		q.push({dis[v], v});
    		}
    	}
	}
}

int main()
{
    int n,m;//n点的总数;m边的总数.
    cin >> n >> m;
    int s=1,end=n;//s:start;end:end.
    for (int i = 1;i <= m;i++)
    {
    	int u,v,w;
    	cin >> u >> v >> w;
		e[u].push_back({v,w});//双向图,单向图请保留这行.
		e[v].push_back({u,w});
    }
    dijkstra(n,s);
    if (dis[n] != 0x3f3f3f3f)
    {
        cout << dis[end];//s到end长度.
    }
    else cout << -1;//走不通.
    return 0;
}