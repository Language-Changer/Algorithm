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

vector<edge> e[N];
int dis[N], vis[N], cnt[N];

bool spfa(int n, int s) 
{
	queue<int> q;
	memset(dis, 63, sizeof(dis));
	memset(vis, 0, sizeof(vis));
	memset(cnt, 0, sizeof(cnt));
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
				cnt[v] = cnt[u] + 1;
				if(cnt[v] >= n+2)//防止有超级原点
				{
					return false;//有负环
				}
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
    int n,m,end;
    cin >> n >> m >> end;//How many Points and Sides? end:End
    //for(int i=1;i <= n;i++) e[i].clear();//Use when querying multiple times.
    for (int i = 1; i <= m; i++)
    {
        int u,v,w;
        cin >> u >> v >> w;
        //Two-way Graph
        e[u].push_back({v,w});//u to v
        e[v].push_back({u,w});//v to u
    }
    if(spfa(n,1)) cout << dis[end] << endl;
    else cout << "Had negative ring" << endl;//Negative ring
    return 0;
}