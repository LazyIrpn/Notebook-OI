#include <bits/stdc++.h>
#define int long long
using namespace std;
using pii = pair<int,int>;
constexpr int maxn = 5e3+7,inf = INT_MAX;
int n,m,u,v,w,dis[maxn][2],nd;
vector<pii> g[maxn];
struct Node{
    int ver,dis;
    bool type;
    friend bool operator <(const Node &a,const Node &b){return a.dis > b.dis;}
};
void dijkstra(int s){
    for(int i=1;i<=n;i++) dis[i][0] = dis[i][1] = inf;
    dis[s][0] = 0,dis[s][1] = inf;
    priority_queue<Node> pq;
    pq.push({s,0,0});
    while(!pq.empty()){
        auto [u,d,type] = pq.top();pq.pop();
        if(d > dis[u][type]) continue;
        for(auto [v,w]:g[u]){
            nd = d + w;
            if(nd < dis[v][0]){
                //swap(dis[v][0],dis[v][1] = nd);
                dis[v][1] = dis[v][0],dis[v][0] = nd;
                pq.push({v,dis[v][0],0}),pq.push({v,dis[v][1],1});
            }else if(nd < dis[v][1] && nd != dis[v][0]){
                dis[v][1] = nd;
                pq.push({v,dis[v][1],1});
            }
        }
    }
}
signed main(){
    cin.tie(0)->sync_with_stdio(0);
    cin>>n>>m;
    while(m--){
        cin>>u>>v>>w;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }
    dijkstra(1);
    cout<<dis[n][1];
    return 0;
}