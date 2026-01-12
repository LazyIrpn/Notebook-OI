#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 1e9+7,maxn = 105; 
struct Matrix {
	int size_x,size_y,res[maxn][maxn];
	inline void clear() {memset(res, 0, sizeof(res)); }
	Matrix creatM(int size_x,int size_y){//普通Matrix 
		Matrix ep;
		ep.size_x = size_x;
		ep.size_y = size_y;
		ep.clear();
		return ep;
	}
	Matrix creatI(int size_y){//单位Matrix 
		Matrix ep= ep.creatM(size_y,size_y);
		for(int i=1;i<=size_y;i++)ep.res[i][i] = 1;
		return ep;
	}
	friend Matrix operator * (Matrix A, Matrix B) {
		Matrix ans=ans.creatM(A.size_x,B.size_y);
		if(A.size_y != B.size_x)return ans;
		for (int i = 1; i <= A.size_x; i++)
			for (int j = 1; j <= B.size_y; j++)
				for (int k = 1; k <= A.size_y; k++)
					ans.res[i][j] = (ans.res[i][j] + (A.res[i][k] % mod) * (B.res[k][j] % mod)) % mod;
		return ans;
	}
	friend istream& operator >> (istream& stream,Matrix& A){
		for(int i=1;i<=A.size_x;i++)
			for(int j=1;j<=A.size_y;j++)
				stream>>A.res[i][j];
		return stream;
		
	}
	friend ostream& operator << (ostream& stream,Matrix A){
		for(int i=1;i<=A.size_x;i++){
			for(int j=1;j<=A.size_y;j++){
				stream<<A.res[i][j]<<' ';
			}
			stream<<'\n';
		}
		return stream;
	}
} bas;
Matrix quickpow(Matrix A,int k){
	register Matrix ret = ret.creatI(A.size_y);
	for(;k;k>>=1,A=A*A)if(k&1)ret = ret * A;
	return ret;
}
int n,k;
signed main(){
	cin>>n>>k;
	bas = bas.creatM(n,n);
	cin>>bas;
	cout<<quickpow(bas,k);
	return 0;
}