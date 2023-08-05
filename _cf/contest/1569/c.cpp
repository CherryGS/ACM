#include <bits/stdc++.h>
using namespace std;

#ifdef _DEBUG
#define pr1(x) cout << x << ' ';
#define pr2(x) cout << x << endl;
#else
#define pr1(x)
#define pr2(x)
#endif
typedef long long ll;
typedef unsigned long long ull;
typedef const int& cint;
typedef pair<int, int> pii;

const int mod = 998244353;
const int inf_int = 0x7fffffff;
const ll inf_ll = 0x7fffffffffffffff;
const double ept = 1e-9;

int t, n;
ll a[200200];
ll to[200200];

bool cmp(cint x, cint y) {
    return a[x] > a[y];
}

void init() {
    to[0] = 1;
    for(ll i=1; i<=200000; i++)
        to[i] = (to[i-1] * i) % mod;
}

ll ksm(ll bs, int x) {
    ll ans = 1;
    while(x) {
        if(x&1) ans = (ans*bs) % mod;
        bs = (bs*bs) % mod;
        x >>= 1;
    }
    return ans;
}

ll C(cint x, cint y) {
    return to[x] * ksm(to[y]*to[x-y]%mod, mod-2) % mod ;
}

int main() {
    init();
    cin >> t;
    while(t--) {
        cin >> n;
        vector<int> e;
        for(int i=1; i<=n; i++) e.push_back(i);
        for(int i=1; i<=n; i++) cin >> a[i];
        sort(e.begin(), e.end(), cmp);
        if(a[e[0]] - a[e[1]] >= 2) {
            cout << 0 << endl;
        }
        else if(a[e[0]] == a[e[1]]) {
            cout << to[n] << endl;
        }
        else {
            int num = 0;
            for(int i=1; i<e.size(); i++)
                if(a[e[i]] == a[e[1]]) ++ num;
            cout << (to[n]*ksm(num+1, mod-2)%mod*(num))%mod << endl;
        }
    }    
    return 0;
}