#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
typedef double db;
#define IL inline

const int MOD = 998244353;
const int N = 2097152;
const int G = 3;

IL int ksm(int a,int b,int m) {
	int res = 1;
	while(b) {
		if(b&1) res = 1LL * res * a % m;
		a = 1LL * a * a % m;
		b >>= 1;
	}
	return res;
}
IL int inv(int x) { return ksm(x,MOD-2,MOD);}

int rev[N];
int eps[N], ieps[N];
IL void initeps() {
	int g = ksm(G, (MOD-1) / N, MOD), ig = inv(g);
	ieps[0] = eps[0] = 1;
	for(int i=1;i<N;i++) eps[i] = 1LL * eps[i-1] * g % MOD;
	for(int i=1;i<N;i++) ieps[i] = 1LL * ieps[i-1] * ig % MOD;
}
IL void cal_rev(int degA, int degB, int& lim, int& p) {
	lim = 1; p = 0;
	while(lim <= (degA+degB)) {lim <<= 1; ++p;}
	for(int i=0;i<lim;i++) rev[i] = (rev[i>>1]>>1) | ((i&1)<<(p-1));
}
IL void trans(int *x, int* w, int n) {
	for(int i=0; i<n; i++) if(i < rev[i]) swap(x[i],x[rev[i]]);
	for(int i=2;i<=n;i<<=1) {
		int l = i>>1, d = N / i;
		for(int j=0;j<n;j+=i) {
			for(int k=0;k<l;k++) {
				int t = 1LL * x[j+k+l] * w[d*k] % MOD;
				x[j+k+l] = (1LL * x[j+k] - t + MOD) % MOD;
				x[j+k] = (x[j+k] + t) % MOD;
			}
		}
	}
}
IL void dft(int* x, int n) { trans(x,eps,n);}
IL void idft(int* x, int n) { 
	trans(x,ieps,n); 
	int in = inv(n);
	for(int i=0;i<n;i++) x[i] = 1LL * x[i] * in % MOD;
}

int ntt_a[N], ntt_b[N];
IL int mul_normal(int *C, int *A, int *B, int degA, int degB) {
	int lim, p;
	cal_rev(degA, degB, lim, p); // if length is the same, u can write it in the main. 
	for(int i=0;i<=degA;i++) ntt_a[i] = A[i];
    for(int i=degA+1;i<lim;i++) ntt_a[i] = 0;
	for(int i=0;i<=degB;i++) ntt_b[i] = B[i];
    for(int i=degB+1;i<lim;i++) ntt_b[i] = 0;
	dft(ntt_a, lim); dft(ntt_b, lim);
	for(int i=0;i<lim;i++) ntt_a[i] = 1LL * ntt_a[i] * ntt_b[i] % MOD;
	idft(ntt_a, lim);
	for(int i=0;i<=degA+degB;i++) C[i] = ntt_a[i];
	return degA + degB; // return length of the poly.
}

int f[N], g[N], ans[N];

int main() {
	initeps();
	int n,m; scanf("%d%d",&n,&m);
	for(int i=0;i<=n;i++) scanf("%d",&f[i]);
	for(int i=0;i<=m;i++) scanf("%d",&g[i]);
	mul_normal(ans,f,g,n,m);
	for(int i=0;i<=n+m;i++) printf("%d%c",ans[i]," \n"[i==n+m]);
	return 0;
} 