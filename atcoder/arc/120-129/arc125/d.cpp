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

int n;
int vis[200200];
int s[200200];
int a[200200];
ll to[200200];

void init() {
    to[0] = 1;
    for(int i=1; i<=n; i++) {
        to[i] = (to[i-1]*2) % mod;
    }
}

int main() {
    cin >> n;
    init();
    for(int i=1; i<=n; i++) cin >> a[i];
    ll ans = 0;
    for(int i=1; i<=n; i++) {
        ans = ans*2 % mod;
        if(vis[a[i]]) {
            if(vis[a[i]] == 1) ans = (ans + to[s[a[i]]-1]) % mod;
            ans = (ans + to[s[a[i]]-1]) % mod;
        }
        vis[a[i]]++;
        s[a[i]] = i;
        pr2(ans);
    }
    cout << (to[n]-ans+mod-1) % mod << endl;
    return 0;
}