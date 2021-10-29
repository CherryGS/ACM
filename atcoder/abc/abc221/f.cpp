#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef const ll& cint;
typedef pair<ll, ll> pii;

const ll mod = 998244353;
const ll inf_int = 0x7fffffff;
const ll hf_int = 0x3f3f3f3f;
const ll inf_ll = 0x7fffffffffffffff;
const double ept = 1e-9;

ll n;
vector<ll> to[200200];
ll r[200200];
ll s[200200];
ll mx, id, id1;
ll ans;
ll e[200200], cnt;
ll lim;
bool flag = 1;

void dfs1(cint u, cint fa, cint step) {
    if(step > mx) {
        mx = step;
        id = u;
    }
    for(ll v: to[u])
        if(v != fa) { 
            // cout << u << " --- --- " << step << ' ' << fa << ' ' << v << endl;
            dfs1(v, u, step+1);
        }
}

void init() {
    dfs1(1, 1, 0);
    mx = 0;
    id1 = id;
    // cout << "------" << endl;
    dfs1(id1, id1, 0);
}

ll dfs2(cint loc, cint fa, cint step) {
    ll sum = 0;
    // cout << loc << " ------- " << sum <<  ' '  << step << ' ' << fa << endl;
    for(ll v: to[loc])
        if(v != fa) sum += dfs2(v, loc, step+1);
    if(step == lim) return 1;
    else return sum;
}

void sol(cint x) {
    ll s1 = 0, s2 = 0, s3 = 1, s4 = 0;
    for(ll v: to[x]) {
        if(!(cnt & 1)) {
            lim = cnt / 2;
            ll r = dfs2(v, x, 1);
            // cout << v << " --- " << r << ' ' << lim << endl;
            if(r) s2 += r;
            else {
                lim = (cnt-1) / 2;
                r = dfs2(v, x, 1);
                s1 += r;
            }
            s1 %= mod;
            s2 %= mod;
        }
        else {
            lim = (cnt-1) / 2;
            ll r = dfs2(v, x, 1);
            s3 *= r + 1;
            s4 += r;
            s3 %= mod;
            s4 %= mod;
        }
    }
    s3 -= s4+1 - mod;
    s3 %= mod;
    // cout << x << ' ' << s1 << ' ' << s2 << ' ' << s3 << ' ' << cnt << endl;
    if(s3) cout << s3 << endl;
    else cout << s1 * s2 % mod << endl;
}

void dfs(cint loc, cint fa) {
    e[++cnt] = loc;
    if(loc == id && flag) {
        flag = 0;
        sol(e[(cnt+1)/2]);
        return;
    }
    for(ll v: to[loc]) {
        if(v != fa && flag) {
            dfs(v, loc);
        }
    }
    -- cnt;
}

int main() {
    cin >> n;
    ll u, v;
    for(ll i=1; i<n; i++) {
        cin >> u >> v;
        to[u].push_back(v);
        to[v].push_back(u);
    }
    if(n == 2) cout << 1 << endl;
    else {
        init();
        // cout << id1 << " ----- " << id << endl;
        dfs(id1, id1);
    }
    return 0;
}
/*
9
1 2
2 3
3 4
4 5
3 6
6 7
3 8
8 9
*/