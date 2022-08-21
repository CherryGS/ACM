#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+1e4;
const int P=998244353;
int n,q;
bitset<64000001> s[11];
int v[401][401][401];
int pre[2000200];
int rd(){
	int s=0,ff=1;
	char w=getchar();
	while(!isdigit(w))
		ff^=w=='-',w=getchar();
	while(isdigit(w))
		s=s*10+w-'0',w=getchar();
	return ff?s:-s;
}
int Pow(int x,int y){
	int s=1;
	while(y)
	{
		if(y&1) s=(ll)s*x%P;
		x=(ll)x*x%P; y>>=1;
	}
	return s;
}

int solve(int x, int y, int z) {
    // cout << x << ' ' << y << ' ' << z << endl;
    int ans = 0;
    for(int i=1; i<=n; i++) { if(s[i][v[x][y][z]] == 1) { ++ans; } }
    return ans;
}

int main() {
    freopen("1.in", "r", stdin);
	n=rd(); q=rd();
	int x,y,z,m;
    for(int i=1; i<=400; i++) {
        for(int j=1; j<=400; j++) {
            for(int k=1; k<=400; k++) {
                v[i][j][k] = (i-1) * 160000 + (j-1) * 400 + (k-1);
            }
        }
    }
	for(int i=1;i<=n;i++){
		m=rd();
		for(int j=1;j<=m;j++){
			x=rd(); y=rd(); z=rd();
			s[i][v[x][y][z]] = 1;
        }
	}
    for(int l=1; l<=n; l++) {
        for(int i=1; i<=400; i++) {
            for(int j=1; j<=400; j++) {
                for(int k=1; k<=400; k++) {
                    if(i > 1 && s[l][v[i-1][j][k]] == 1) { s[l][v[i][j][k]] = 1; }
                    else if(j > 1 && s[l][v[i][j-1][k]] == 1) { s[l][v[i][j][k]] = 1; }
                    else if(k > 1 && s[l][v[i][j][k-1]] == 1) { s[l][v[i][j][k]] = 1; }
                }
            }
        }
    }
	int seed=rd();
	std::mt19937 rng(seed);
	std::uniform_int_distribution<> u(1,400);
	
	ll Q=1, ans = 0;
    pre[0] = 1;
    for(int i=1; i<q; i++) { pre[i] = 1ll * pre[i-1] * seed % P; }
	int lastans=0;
	for(int i=1;i<=q;i++){
	    int IQ=(u(rng)^lastans)%400+1;  // The IQ of the i-th friend
	    int EQ=(u(rng)^lastans)%400+1;  // The EQ of the i-th friend
	    int AQ=(u(rng)^lastans)%400+1;  // The AQ of the i-th friend
	    lastans=solve(IQ,EQ,AQ);  // The answer to the i-th friend
	    ans=(ans+(ll)lastans*pre[q-i]%P)%P;
	}
	printf("%d\n",ans);
    return 0;
}