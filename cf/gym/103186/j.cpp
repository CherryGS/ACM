#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef const int& cint;
typedef pair<int, int> pii;

const int mod = 1e9+7;
const int inf_int = 0x7fffffff;
const int hf_int = 0x3f3f3f3f;
const ll inf_ll = 0x7fffffffffffffff;
const double ept = 1e-9;

int n;
int a[50050];

int main() {
    //freopen("1.in", "r", stdin);
    //cout.flags(ios::fixed); cout.precision(8);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    ll sum = 0;
    for(int i=1; i<=n; i++) cin >> a[i];
    for(int i=1; i<=n; i++) sum += a[i];
    sort(a+1, a+1+n);
    ll ans1 = 0;
    ll ans2 = 0;
    for(int i=1; i<=n; i+=2) ans1 += a[i];
    for(int i=n; i>=1; i-=2) ans2 += a[i];
    // int l = 1, r = n;
    // ll pre1 = 0, pre2 = 0;
    // ll ans3, ans4;
    // for(int i=1; i<=n/2; i++) pre1 += a[i];
    // for(int i=n/2+1; i<=n; i++) pre2 += a[i];
    // ans3 = abs(pre2) - abs(pre1);
    cout << max(abs(ans1)-abs(sum-ans1), abs(ans2)-abs(sum-ans2)) << endl;
    return 0;
}
/*
4
-1 1 1 2
*/