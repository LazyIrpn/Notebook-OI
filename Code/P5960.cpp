#include <bits/stdc++.h>
#define int long long
using namespace std;
using pii = pair<int,int>;
constexpr int maxn = 5e3+7;
int n,u,v,w,m,dis[maxn],cnt[maxn];
vector<pii> g[maxn];
queue<int> q;
bool ins[maxn];
void SPFA(int s){
    q.push(s);
    cnt[s]++,ins[s] = true;
    dis[s] = 0;
    while(!q.empty()){
        u = q.front();
        q.pop();
        ins[u] = false;
        for(auto [v,w]:g[u]){
            if(dis[v] > dis[u] + w){
                dis[v] = dis[u] + w;
                if(!ins[v]){
                    q.push(v);
                    cnt[v]++,ins[v] = true;
                    if(cnt[v] == n+1){//注意加了一个超级源点
                        cout<<"NO\n";
                        exit(0);
                    }
                }
            }
        }
    }
}
signed main(){
    cin.tie(0)->sync_with_stdio(0);
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        cin>>u>>v>>w;//u-v<=w -> u <= v + w
        g[v].push_back({u,w});
    }
    for(int i=1;i<=n;i++)dis[i] = INT_MAX,g[0].push_back({i,0});
    SPFA(0);
    for(int i=1;i<=n;i++)cout<<dis[i]<<' ';
    return 0;
}