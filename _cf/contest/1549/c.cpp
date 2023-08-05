#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef const int& cint;

const int mod = 1e9+7;
const int inf_int = 0x7fffffff;
const ll inf_ll = 0x7fffffffffffffff;
const double ept = 1e-9;

int n, m;
int num[200200];
int ans;

int main() {
    cin >> n >> m;
    ans = n;
    int u, v;
    for(int i=1; i<=m; i++) {
        cin >> u >> v;
        if(u > v) swap(u, v);
        num[u]++;
        if(num[u] == 1) -- ans;
    }
    int q, a, b, c;
    cin >> q;
    for(int i=1; i<=q; i++) {
        cin >> a;
        if(a == 1) {
            cin >> b >> c;
            if(b > c) swap(b, c);
            num[b]++;
            if(num[b] == 1) -- ans;
        }
        else if(a == 2) {
            cin >> b >> c;
            if(b > c) swap(b, c);
            num[b]--;
            if(num[b] == 0) ++ ans;
        }
        else if (a == 3) cout << ans << endl;
    }
    return 0;
}