#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef const int& cint;
typedef pair<int, int> pii;

const int mod = 1e9+7;
const int inf_int = 0x7fffffff;
const int hf_int = 0x3f3f3f3f;
const ll inf_ll = 0x7fffffffffffffff;
const double ept = 1e-9;

int t;
ll n, l, r;
ll to[200200];

ll ksm(ll bs, int x) {
    ll ans = 1;
    while(x) {
        if(x&1) ans = ans * bs % mod;
        bs = bs * bs % mod;
        x >>= 1;
    }
    return ans;
}

void init() {
    to[0] = 1;
    for(int i=1; i<=200000; i++)
        to[i] = to[i-1] * i % mod;
}

ll C(cint x, cint y) {
    if(x < y) return 0;
    return to[x] * ksm(to[y]*to[x-y]%mod, mod-2) % mod;
}

vector<int> q;

ll sol(cint x, cint y, cint r) {
    int s1 = r/2;
    int s2 = r-s1;
    ll sum = 0;
    // cout << x << ' ' << y << ' ' << s1 << ' ' << s2 << ' ' << r << endl;
    if(x <= s1 && y <= s2) {
        sum += C(r-x-y, s1-x);
    }
    if(s1 != s2 && x <= s2 && y <= s1) {
        sum += C(r-x-y, s2-x);
    }
    // cout << sum%mod << " ----- " << endl;
    return sum % mod;
}

bool cmp(cint x, cint y) {
    return abs(x) < abs(y);
}

int main() {
    // freopen("1.in", "r", stdin);
    init();
    cin >> t;
    while(t--) {
        cin >> n >> l >> r;
        int s = n;
        int mn = inf_int;
        int s1 = 0, s2 = 0;
        q.clear();
        for(int i=1; i<=n; i++) {
            if(l-i >= 0) -- s, ++ s2;
            else if(r-i <= 0) -- s, ++ s1;
            else {
                q.push_back(l-i);
                q.push_back(r-i);
            }
        }
        sort(q.begin(), q.end(), cmp);
        ll ans = 0;
        for(int i=0; i<=q.size()/2; i++) {
            if(q[i] < 0) {
                if(i == q.size()/2) -- s1;
                ans += sol(s1+1, s2, n) * abs(q[i]);
                ++ s2;
            }
            else {
                if(i == q.size()/2) -- s2;
                ans += sol(s1, s2+1, n) * q[i];
                ++ s1;
            }
            ans %= mod;
        }
        cout << ans << endl;
    }
    return 0;
}