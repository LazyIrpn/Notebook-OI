#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int maxn = 3e3 + 5, inf = 1e9;
int ans;
namespace G {
	struct Edge {
		int v, w;
	};
	struct PII{
		int dis,k;
		inline friend bool operator < (PII a,PII b){return a.dis>b.dis;}
	};
	vector<Edge>g[maxn];
	int n, m, u, v, w;
	void add_edge() {
		for (int i = 1; i <= m; i++) {
			cin >> u >> v >> w;
			g[u].push_back({v, w});
		}
		for (int i = 1; i <= n; i++) {
			g[0].push_back({i, w});
		}
	}
	int h[maxn], dis[maxn], cnt[maxn];
	bool inq[maxn], vis[maxn], nc = false;
	queue<int>q;
	priority_queue<PII>pq;
	void qin(int p) {
		q.push(p);
		inq[p] = true;
		cnt[p]++;
	}
	int qout() {
		int p = q.front();
		q.pop();
		inq[p] = false;
		return p;
	}
	void SPFA() {
		for (int i = 1; i <= n; i++)h[i] = inf;
		h[0] = 0;
		qin(0);
		while (!q.empty() && !nc) {
			u = qout();
			if (h[u] == inf)continue;
			for (auto [v, w] : g[u]) {
				if (h[v] > h[u] + w) { //find an update
					h[v] = h[u] + w;
					if (!inq[v]) {
						qin(v);
						if (cnt[v] > n)nc = true;
					}
				}
			}
		}
	}
	void remake() {
		for (int u = 1; u <= n; u++)
			for (auto& [v, w] : g[u])
				w += h[u] - h[v];
	}
	void Dijkstra(int s) {
		for (int i = 1; i <= n; i++)dis[i] = inf,vis[i] = false;
		pq.push({dis[s] = 0,s});
		while(!pq.empty()){
			u = pq.top().k;pq.pop();
			if(vis[u])continue;
			vis[u] = true;
			for(auto [v,w]:g[u]){
				if(dis[v] > dis[u] + w)pq.push({dis[v] = dis[u] + w,v});
			}
		}
	}
	void undo(int u){
		for(int v=1;v<=n;v++)if(dis[v] != inf)dis[v] -= h[u] - h[v];//记得特判dis = inf的情况
	}
}
using namespace G;
signed main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	add_edge();
	SPFA();
	if (nc) {
		cout << -1;
		return 0;
	}
	remake();
	for(int i=1;i<=n;i++){
		ans = 0;
		Dijkstra(i);
		undo(i);
		for(int j=1;j<=n;j++)ans+=1LL * j * dis[j];
		cout<<ans<<endl;
	}
	return 0;
}