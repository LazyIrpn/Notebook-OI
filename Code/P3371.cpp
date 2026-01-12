#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,s;
namespace Graph {
	struct Edge {
		int v,w;
	};
	constexpr int maxn = 1e4+5;
	int dis[maxn],u,v,w,cnt[maxn];
	vector<Edge> g[maxn];
	queue<int> q;
	bool inq[maxn],NC;//NegativeCycle
	void add() {
		cin>>u>>v>>w;
		g[u].push_back({v,w});
		return;
	}
	void qin(int x){
		q.push(x);
		inq[x] = true;
		cnt[x]++;
	}
	int qout(){
		register int x;
		x = q.front();
		inq[x] = false;
		q.pop();
		return x;
	}
	void BF(int n,int s) {
		for(int i=1;i<=n;i++)dis[i] = INT_MAX;
		dis[s] = 0;
		qin(s);
		while(!q.empty()){
			u = qout();
			if(dis[u]==INT_MAX)continue;
			for(Edge e:g[u]){
				v = e.v,w = e.w;
				if(dis[v] > dis[u]+w){//产生更新
					dis[v] = dis[u]+w;
					if(!inq[v]){
						qin(v);
						if(cnt[v]>n){
							NC = true;
							return;
						}
					}
				}
			}
		}
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