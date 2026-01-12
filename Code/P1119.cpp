#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int maxn = 205;
int n,m,u,v,w,q,a[maxn],f[maxn][maxn],t,now;
void update(int k){
	for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            f[i][j] = min(f[i][j],f[i][k]+f[k][j]);
        }
    }
	return;
}
signed main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=0;i<n;i++)cin>>a[i];
    memset(f,0x3f,sizeof(f));
	for(int i=0;i<n;i++)f[i][i]=0;
	while(m--){
		cin>>u>>v>>w;
		f[u][v]=f[v][u]=w;
	}
	cin>>q;
	for(int i=1;i<=q;i++){
		cin>>u>>v>>t;
		while(a[now] <= t && now < n)update(now++);//数据保证了t是不降的
		if(a[u] > t || a[v] > t || f[u][v] == f[n+1][n+1])cout<<"-1\n";
		else cout<<f[u][v]<<'\n';
	}
	return 0;
} 