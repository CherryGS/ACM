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
const int inf_int = 0x7fffffff;
const int hf_int = 0x3f3f3f3f;
const ll inf_ll = 0x7fffffffffffffff;
const double ept = 1e-9;

int m, n, k;
int h[2002];
int g[303];
ll v[2002];
ll dp[303];
ll a[3003];
ll q[303];
ll s[303];

inline char nc(){
    static char buf[100000],*p1=buf,*p2=buf;
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
inline int _read(){
    char ch=nc();int sum=0;
    while(!(ch>='0'&&ch<='9'))ch=nc();
    while(ch>='0'&&ch<='9')sum=sum*10+ch-48,ch=nc();
    return sum;
}

void solve(cint T) {
    cin >> m >> n >> k;
    int tmp;
    for(int i=1; i<=n; i++) {
        cin >> tmp;
        ++ g[tmp];
    }
    for(int i=1; i<=k; i++) { cin >> h[i] >> v[i]; }
    dp[0] = 1;
    for(int i=1; i<=k; i++) {
        for(int j=0; j<=300-h[i]; j++) {
            if(dp[j]) dp[j+h[i]] = max(dp[j+h[i]], dp[j]+v[i]);
        }
    }
    int r = 300;
    for(int i=300; i>0; i--) {
        if(dp[i] == 0) continue;
        while(r >= i) {
            if(g[r]) s[r] = i;
            --r;
        }
    }
    a[0] = 1;
    ll ans = 0;
    for(int i=1; i<=300; i++) {
        if(s[i]) {
            if(g[i] * s[i] >= m) {
                if(dp[s[i]] > 1)
                for(int j=0; j<=m-s[i]; j++) {
                    if(a[j]) a[j+s[i]] = max(a[j+s[i]], a[j] + dp[s[i]] - 1);
                }
            }
            else {
                for(int l=1; l<=g[i]; l++) {
                    for(int j=m-s[i]; j>=0; j--) {
                        if(a[j]) a[j+s[i]] = max(a[j+s[i]], a[j] + dp[s[i]] - 1);                   
                    }
                }
            }
        }
    }
    for(int i=1; i<=m; i++) ans = max(ans, a[i]);
    printf("%lld\n", ans-1);
}

int main() {
    //freopen("1.in", "r", stdin);
    //cout.flags(ios::fixed); cout.precision(8);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    // int T_=1;
    // std::cin >> T_;
    // for(int _T=1; _T<=T_; _T++)
    solve(1);
    return 0;
}