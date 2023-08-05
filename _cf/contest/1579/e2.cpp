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
int n;
int a[200200];
int b[200200];
map<int, int> e;
int cnt;
int node[200200];

int lowbit(cint x) {
    return x&-x;
}

ll query(int x) {
    ll ans = 0;
    while(x) {
        ans += node[x];
        x -= lowbit(x);
    }
    return ans;
}

void add(int x) {
    while(x <= n) {
        ++node[x];
        x += lowbit(x);
    }
}

int main() {
    cin >> t;
    while(t--) {
        e.clear();
        cnt = 0;
        cin >> n;
        for(int i=1; i<=n; i++) node[i] = 0;
        for(int i=1; i<=n; i++) cin >> a[i], b[i] = a[i];
        sort(a+1, a+1+n);
        for(int i=1; i<=n; i++) if(e.find(a[i]) == e.end()) e[a[i]] = ++cnt;
        for(int i=1; i<=n; i++) b[i] = e[b[i]];
        ll ans = 0;
        for(int i=1; i<=n; i++) {
            ans += min(query(b[i]-1), i-query(b[i])-1);
            add(b[i]);
        }
        cout << ans << endl;
    }
    return 0;
}