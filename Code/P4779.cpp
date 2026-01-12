#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,s;
namespace Graph {
    struct Edge {
        int v,w;
    };
    struct PII{
        int dis,k;
        inline friend bool operator < (PII a,PII b){return a.dis>b.dis;} //注意不要把大于号写成小于号
    };
    constexpr int maxn = 1e5+5;
    int dis[maxn],u,v,w,mind,cnt[maxn];
    vector<Edge> g[maxn];
    priority_queue< PII > pq;
    bool vis[maxn];
    void add() {
        cin>>u>>v>>w;
        g[u].push_back({v,w});
        return;
    }
    void Dijkstra(int n,int s){
        for(int i=1;i<=n;i++)dis[i] = INT_MAX;
        dis[s] = 0;
        pq.push({0,s});
        while(!pq.empty()){
            u = pq.top().k;
            pq.pop();
            if(vis[u])continue;
            vis[u] = true;
            for(Edge e:g[u]){
                v = e.v,w = e.w;
                if(dis[v] > dis[u] + w){
                    dis[v] = dis[u] + w;
                    pq.push({dis[v],v});
                }
            }
        }
    }
    void print(int n){
        for(int i=1;i<=n;i++)cout<<dis[i]<<' ';
        return;
    }
    
}
signed main() {
    cin>>n>>m>>s;
    while(m--)Graph::add();
    Graph::Dijkstra(n,s);
    Graph::print(n);
    return 0;
}