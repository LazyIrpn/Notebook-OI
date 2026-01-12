#include <bits/stdc++.h>
#define int long long
using namespace std;
using tii = tuple<int,double,int>;
using pii = pair<int,int>;
using pid = pair<int,double>;
constexpr int maxn = 2e2+7,maxm = 1e4+7,inf = 1e9+7;
int n,m,u,v,id;
bool banned[maxm];
double d,w,ans = inf,dis[maxn];
pii points[maxn],fa[maxn];
vector<tii> g[maxn];
vector<int> vec;
void init(){
    for(int i=1;i<=n;i++)dis[i] = inf;
    dis[1] = 0;
}
void dijkstra(){
    init();
    priority_queue<pid> pq;
    pq.push({1,-dis[1]});
    while(!pq.empty()){
        tie(u,d) = pq.top();pq.pop();
        if(-d > dis[u])continue;
        for(auto p:g[u]){
            tie(v,w,id) = p;
            if(banned[id])continue;
            if(dis[v] > dis[u] + w){
                dis[v] = dis[u] + w;
                pq.push({v,-dis[v]});
                fa[v] = {u,id};//v节点由u节点通过边id更新出最短路
            }
        }
    }
}
void dfs(int s){
    if(s == 1)return;
    dfs(fa[s].first);
    vec.push_back(fa[s].second);
}
signed main(){
    cin.tie(0)->sync_with_stdio(0);
    cin>>n>>m;
    for(int i=1,x,y;i<=n;i++){
        cin>>x>>y;
        points[i] = {x,y};
    }
    for(int i=1,xa,xb,ya,yb;i<=m;i++){
        cin>>u>>v;
        tie(xa,ya) = points[u],tie(xb,yb) = points[v];
        w = sqrt(pow(xa-xb,2) + pow(ya-yb,2));
        g[u].push_back({v,w,i}),g[v].push_back({u,w,i});
        banned[i] = false;
    }
    dijkstra();
    dfs(n);
    for(int i:vec){
        banned[i] = true;
        dijkstra();
        ans = min(ans,dis[n]);
        banned[i] = false;
    }
    if(ans == inf)cout<<-1;
    else cout<<fixed<<setprecision(2)<<ans;
    return 0;
}