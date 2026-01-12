#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,s;
namespace Graph {
	struct Edge {
		int v,w;
	};
	constexpr int maxn = 1e4+5;
	int dis[maxn],u,v,w;
	vector<Edge> g[maxn];
	bool NC;//hasNegativeCycle
	void add() {
		cin>>u>>v>>w;
		g[u].push_back({v,w});
		return;
	}
	void BF(int n,int x) {
		for(int i=1; i<=n; i++)dis[i] = INT_MAX;
		dis[s] = 0;
		for(int i=0; i<n-1; i++) { //若存在最短路（无可达负环），最短路最多包括n-1条边
			for(int j=1; j<=n; j++) { //遍历所有边
				if(dis[j] == INT_MAX)continue;//inf + const = inf
				for(Edge e:g[j])
					dis[e.v] = min(dis[e.v],dis[j] + e.w);
			}
		}
		//再遍历一次，检测是否有可达负环
		for(int j=1; j<=n; j++) { //遍历所有边
			if(dis[j] == INT_MAX)continue;//inf + const = inf
			for(Edge e:g[j]){
				if(dis[e.v]>dis[j] + e.w){
					NC = true;
					return;
				}
			}
		}
		return;
	}
	void print(int n){
		if(NC){
			cout<<-1<<endl;
			return;
		}
		for(int i=1;i<=n;i++)cout<<dis[i]<<' ';
		cout<<endl;
		return;
	}

}
signed main() {
	cin>>n>>m>>s;
	while(m--)Graph::add();
	Graph::BF(n,s);
	Graph::print(n);
	return 0;
}