#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 1e9+7,maxn = 3; 
struct Matrix {
	int size_x,size_y,res[maxn][maxn];
	inline void clear() {memset(res, 0, sizeof(res)); }
	Matrix creatM(int size_x,int size_y){//普通Matrix 
		register Matrix ep;
		ep.size_x = size_x;
		ep.size_y = size_y;
		ep.clear();
		return ep;
	}
	Matrix creatI(int size_y){//单位Matrix 
		register Matrix x= x.creatM(size_y,size_y);
		for(int i=0;i<size_y;i++)x.res[i][i] = 1;
		return x;
	}
	friend Matrix operator * (Matrix A, Matrix B) {
		register Matrix ans=ans.creatM(A.size_x,B.size_y);
		if(A.size_y != B.size_x)return ans;
		for (int i = 0; i < A.size_x; i++)
			for (int j = 0; j < B.size_y; j++)
				for (int k = 0; k < A.size_y; k++)
					ans.res[i][j] = (ans.res[i][j] + (A.res[i][k] % mod) * (B.res[k][j] % mod)) % mod;
		return ans;
	}
	friend istream& operator >> (istream& stream,Matrix& A){
		for(int i=0;i<A.size_x;i++)
			for(int j=0;j<A.size_y;j++)
				stream>>A.res[i][j];
		return stream;
		
	}
	friend ostream& operator << (ostream& stream,Matrix A){
		for(int i=0;i<A.size_x;i++){
			for(int j=0;j<A.size_y;j++){
				stream<<A.res[i][j]<<' ';
			}
			stream<<'\n';
		}
		return stream;
	}
} bas,arr;
Matrix quickpow(Matrix A,int k){
	register Matrix ret = ret.creatI(A.size_y);
	for(;k;k>>=1,A=A*A){
		if(k & 1)ret = ret * A;
	}
	return ret;
}
int n,k,qry;
signed main(){
	cin>>n;
	bas = bas.creatM(3,1);
	bas.res[0][0] = bas.res[1][0] = bas.res[2][0] = 1;
	arr = arr.creatM(3,3);
	arr.res[0][0] = arr.res[0][2] = arr.res[1][0] = arr.res[2][1] = 1;
	while(n--){
		cin>>qry;
		if(1<=qry && qry<=3)cout<<1<<endl;
		else cout<<(quickpow(arr,qry-3) * bas).res[0][0]<<endl;
	}
	return 0;
}