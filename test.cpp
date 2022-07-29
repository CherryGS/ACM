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

const int mod1 = 1e9+7;
const int mod2 = 998244353;
const int mod3 = 19992147;
const int inf_int = 0x7fffffff;
const int hf_int = 0x3f3f3f3f;
const ll inf_ll = 0x7fffffffffffffff;
const double ept = 1e-9;

const int mx_n = 100;
int siz;
struct matrix {
    ll a[mx_n+1][mx_n+1];
    matrix() { memset(a, 0, sizeof a); for(int i=1; i<=mx_n; i++) a[i][i] = 1; }
    matrix(ll b[mx_n+1][mx_n+1]) { for(int i=1; i<mx_n; i++) for(int j=1; j<=mx_n; j++) a[i][j]=b[i][j]; }
    matrix operator * (const matrix&x) const {
        ll r[mx_n+1][mx_n+1];
        memset(r, 0, sizeof r);
        for(int i=1; i<=siz; i++) 
            for(int j=1; j<=siz; j++)
                for(int k=1; k<=siz; k++)
                    r[i][j] = (r[i][j] + a[i][k]*x.a[k][j]) % mod1;
        return matrix(r);
    }
    void print(int n) {
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=n; j++)
                cout << a[i][j] << ' ';
            cout << endl;
        }
    }
};

matrix ksm(matrix a, ll b) {
    // a.print();
    matrix ans;
    while(b) {
        if(b&1) ans = ans * a;
        a = a*a;
        b >>= 1;
    }
    return ans;
}

int main() {
    //freopen("1.in", "r", stdin);
    //cout.flags(ios::fixed); cout.precision(8);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T_=1;
    // std::cin >> T_;
    int n;
    ll k;
    ll tmp[mx_n+1][mx_n+1];
    memset(tmp, 0, sizeof(tmp));
    for(int _T=1; _T<=T_; _T++) {
        cin >> n >> k;
        for(int i=1; i<=siz; i++)
            for(int j=1; j<=siz; j++)
                cin >> tmp[i][j];
        matrix ans = ksm(matrix(tmp), k);
        ans.print(n);
    }
    return 0;
}