#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef const int& cint;

const int mod = 1e9+7;
const int inf_int = 0x7fffffff;
const ll inf_ll = 0x7fffffffffffffff;
const double ept = 1e-9;

int n, k;
ll r[10010];
ll ad[10010];
ll sum[10010];
ll ans[10010];

ll query(cint i, cint j, bool st) {
    cout << (st == 1 ? "or " : "and ");
    cout << i << ' ' << j << endl; 
    cout.flush();
    ll tmp;
    cin >> tmp;
    return tmp;
}

int main() {
    cin >> n >> k;
    for(int i=1; i<n; i++) {
        r[i] = query(i, i+1, 1);
        ad[i] = query(i, i+1, 0);
        sum[i] = r[i]+ad[i];
    }
    ll st = query(1, 3, 1) + query(1, 3, 0);
    ans[2] = (sum[1]+sum[2]-st)/2;
    ans[1] = sum[1] - ans[2];
    for(int i=2; i<n; i++)
        ans[i+1] = sum[i]-ans[i];
    sort(ans+1, ans+1+n);
    cout << "finish " << ans[k] << endl;
    return 0;
}