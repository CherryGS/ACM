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

int n, q;
int a[200200];
int b[200200];

struct query {
    int c;
    int id;
    ll ans;
    void init(cint x) {
        cin >> c;
        id = x;
    }
    bool operator < (const query&a) const {
        return c < a.c;
    }
} d[200020];

bool vis[200200];
int prim[200200];
int mobius[200200];
int cnt;

void liner_sieve(cint x) {
    int rt = 0;
    mobius[1] = 1;
    for(int i=2; i<=x; i++) {
        if(!vis[i]) {
            prim[++cnt] = i;
            mobius[i] = -1;
        }
        for(int j=1; j<=cnt; j++) {
            if(1ll*prim[j]*i > x) break;
            vis[prim[j]*i] = 1;
            if(!(i%prim[j])) {
                mobius[i*prim[j]] = 0; // 3
                break;
            }
            mobius[i*prim[j]] = -mobius[i]; // 2
        }
    }
}

bool cmp(const query&a, const query&b) { return a.id < b.id; }

int main() {
    //freopen("1.in", "r", stdin);
    //cout.flags(ios::fixed); cout.precision(8);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T_=1;
    // std::cin >> T_;
    for(int _T=1; _T<=T_; _T++) {
        cin >> n;
        for(int i=1; i<=n; i++) cin >> a[i];
        for(int i=1; i<=n; i++) cin >> b[i];
        cin >> q;
        for(int i=1; i<=q; i++) d[i].init(i);
        sort(d+1, d+1+q);
        liner_sieve(200200);
        ll ans = 0, sum = 0;
        vector<ll> pre[2];
        b[1] = d[1].c;
        for(int i=1; i<=n; i++) b[i] -= a[i];
        for(int i=1; i<=n; i++) cout << b[i] << ' ';
        cout << endl;
        for(int i=1; i<=n; i++) {
            int rss = b[i];
            ans += abs(b[i]);
            if(mobius[i] == 1 && b[i] < 0) pre[0].push_back(-b[i]);
            else if(mobius[i] == -1 && b[i] > 0) pre[1].push_back(b[i]);
            else if(mobius[i] != 0) ++sum;
            for(int j=i; j<=n; j+=i) {
                b[j] -= rss;
            }
        }
        sort(pre[0].begin(), pre[0].end());
        sort(pre[1].begin(), pre[1].end());
        cout << pre[0].size() << " ---- " << pre[1].size() << endl;
        for(int u: pre[0]) cout << u << ' ';
        cout << endl;
        for(int u: pre[1]) cout << u << ' ';
        cout << endl;
        d[1].ans = ans;
        int l = 0, r = 0;
        ll sd = 0;
        for(int i=2; i<=q; i++) {
            ll dd = d[i].c - d[i-1].c;
            sd += dd;
            ans += sum * dd - dd*((pre[0].size()-l)+(pre[1].size()-r));
            while(l < pre[0].size() && -pre[0][l]+sd >= 0) {
                ++sum;
                ans += (-pre[0][l] + sd)*2;
                ++l;
            }
            while(r < pre[1].size() && pre[1][r]-sd<=0) { 
                ++sum;
                ans += (pre[1][r] - sd)*2;
                ++r;
            }
            d[i].ans = ans;
        }
        sort(d+1, d+1+q, cmp);
        for(int i=1; i<=q; i++) {
            cout << d[i].ans << '\n';
        }
    }
    return 0;
}