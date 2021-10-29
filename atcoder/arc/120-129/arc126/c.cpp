#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef const int& cint;
typedef pair<int, int> pii;

const int mod = 1e9+7;
const int inf_int = 0x7fffffff;
const ll inf_ll = 0x7fffffffffffffff;
const double ept = 1e-9;

ll n, k;
ll a[600300];
ll cnt[600300];
ll pre[600300];

int main() {
    ll mx = 0;
    ll sum = 0;
    cin >> n >> k;
    for(int i=1; i<=n; i++) {
        cin >> a[i];
        ++cnt[a[i]];
        mx = max(mx, a[i]);
        sum += a[i];
    }
    for(int i=1; i<=2*mx; i++) {
        cnt[i] += cnt[i-1];
        pre[i] += pre[i-1] + cnt[i-1];
    }
    if(1ll*mx*n-k <= sum) {
        k -= 1ll*mx*n-sum;
        cout << mx + k/n << endl;
    }
    else {
        int ans = 1;
        for(int i=2; i<mx; i++) {
            ll rsum = 0;
            for(int j=i; j<mx+i; j+=i) {
                int l = j-i;
                rsum += pre[j] - pre[l] - 1ll*cnt[l]*i;
            }
            // cout << i << ' ' << rsum << endl;
            if(rsum <= k) ans = i;
        }
        cout << ans << endl;
    }
    return 0;
}