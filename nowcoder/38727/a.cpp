#include <bits/stdc++.h>
using namespace std;

std::mt19937 rng(std::random_device{}());
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef const int& cint;
typedef const ll& cll;
typedef pair<int, int> pii;
typedef pair<int, ll> pil;

#define ls (loc<<1)
#define rs ((loc<<1)|1)

const int mod = 1e9+7;
const int inf_int = 0x7fffffff;
const int hf_int = 0x3f3f3f3f;
const ll inf_ll = 0x7fffffffffffffff;
const double ept = 1e-9;

const int mx_n = 3;
struct matrix {
    int a[mx_n][mx_n];
    matrix() { memset(a, 0, sizeof a); for(int i=0; i<mx_n; i++) { a[i][i] = 1; } }
    matrix(int b[mx_n][mx_n]) { for(int i=0; i<mx_n; i++) for(int j=0; j<mx_n; j++) { a[i][j]=b[i][j]; } }
    matrix operator * (const matrix&x) const {
        int r[mx_n][mx_n];
        memset(r, 0, sizeof r);
        for(int i=0; i<mx_n; i++) 
            for(int j=0; j<mx_n; j++)
                for(int k=0; k<mx_n; k++)
                    r[i][j] = (0ll + r[i][j] + 1ll * a[i][k]*x.a[k][j]) % mod;
        return matrix(r);
    }
    void print() {
        for(int i=0; i<mx_n; i++) {
            for(int j=0; j<mx_n; j++)
                cout << a[i][j] << ' ';
            cout << endl;
        }
    }
};

ll qpow(ll x,ll k){
	ll ans=1;
	while(k){
		if(k&1) ans=ans*x%mod;
		x=x*x%mod;
		k>>=1;
	}
	return ans%mod;
}

matrix Gauss_j(matrix &u){	
    auto b = u.a;
    int a[3][6];
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            a[i][j] = b[i][j];
        }
        a[i][i+3] = 1;
    }
	for(int i=0, r; i<3; i++){
		r=i;
		for(int j=i+1; j<3; j++)
			if(a[j][i]>a[r][i]) { r = j; }

		if(r != i) swap(a[i],a[r]);
		
		int kk=qpow(a[i][i],mod-2);	//求逆元 
		for(int k=0; k<3; k++){
			if(k==i) continue;
			int p = 1ll * a[k][i] * kk % mod;
			for(int j=i; j<6; j++) 
				a[k][j] = ((0ll+a[k][j]-1ll*p*a[i][j]) % mod + mod) % mod;
		} 
		
		for(int j=0; j<6; j++) { a[i][j] = (1ll * a[i][j] * kk % mod); }
		//更新当前行 如果放在最后要再求一次逆元,不如直接放在这里
    }
    int c[3][3];
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            c[i][j] = a[i][j+3];
        }
    }
    return matrix(c);
}

int n, q;
char s[5000500];
ll al, bl, ar, br, l, r;
matrix st[5000001];

void solve(cint T) {
    ll ans = 0;
    int u[3][3] = { {1, 1, 1}, {0, 1, 0}, {0, 0, 1} };
    int v[3][3] = { {1, 0, 0}, {1, 1, 1}, {0, 0, 1} };
    int p[3][3] = { {0, 0, 0}, {0, 0, 0}, {1, 0, 0} };
    cin >> n >> q;
    cin >> s;
    cin >> al >> bl >> ar >> br >> l >> r;
    for(int i=0; i<n; i++) {
        if(s[i] == '0') { st[i] = matrix(u); }
        else { st[i] = matrix(v); }
        if(i > 0) { st[i] = st[i-1] * st[i]; }
    }
    for(int i=1; i<=q; i++) {
        l = (l * al + bl) % n + 1;
        r = (r * ar + br) % n + 1;
        if(l > r) { swap(l, r); }
        
    }
}

int main() {
    //freopen("1.in", "r", stdin);
    //cout.flags(ios::fixed); cout.precision(8);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T_=1;
    //std::cin >> T_;
    for(int _T=1; _T<=T_; _T++)
        solve(_T);
    return 0;
}