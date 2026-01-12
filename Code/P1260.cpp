#include <bits/stdc++.h>
#define int long long
using namespace std;
using pii = pair<int,int>;
constexpr int maxn = 1e3+7;
int n,m,u,v,w,M=INT_MAX,dis[maxn],cnt[maxn];
bool inq[maxn];
vector<pii> g[maxn];
queue<int>q;
void in(int x){inq[x] = true,q.push(x),cnt[x]++;};
int out(){int x = q.front();q.pop();return inq[x] = false,x;};
void spfa(int s){
    in(s);
    dis[s] = 0;
    while(!q.empty()){
        u = out();
        for(auto [v,w]:g[u]){
            if(dis[v] > dis[u] + w){
                dis[v] = dis[u] + w;
                if(!inq[v]){
                    in(v);
                    if(cnt[v] == n+1){
                        cout<<"NO SOLUTION";
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
        cin>>u>>v>>w;
        g[v].push_back({u,w});
    }
    for(int i=1;i<=n;i++)dis[i] = INT_MAX,g[0].push_back({i,0});
    spfa(0);
    for(int i=1;i<=n;i++)M = min(M,dis[i]);
    for(int i=1;i<=n;i++)cout<<dis[i] - M<<'\n';
    return 0;
}