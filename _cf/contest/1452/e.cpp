#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;

#define ll long long
#define ull unsigned long long
#define cint const int&
#define Pi acos(-1)

const int mod = 998244353;
const int inf_int = 0x7fffffff;
const ll inf_ll = 0x7fffffffffffffff;
const double ept = 1e-9;

struct stu {
    int l, r;
    bool operator < (const stu&a) const {
        if(l == a.l) return r < a.r;
        return l < a.l;
    }
}a[100100];

int n, m, k;
int arr[100100][2];

int main() {
    int aa, bb;
    cin >> n >> m >> k;
    for(int i=1; i<=m; i++) cin >> a[i].l >> a[i].r;
    sort(a+1, a+1+m);
    ll ans=0;
    for(int i=1; i<=m; i++)
    for(int i=0; i<=n; i++) {
        ll tmp=0;
        for(int j=1; j<=n; j++) {
            tmp += arr[j][0];
            if(j-k > 0) tmp -= arr[j][0];
        }
        for(int j=1; j<=n; j++) {
            tmp += arr[j][1];
            if(j-k > 0) tmp -= arr[j][1];
        }
        ++arr[a[i+1].l][0];
        ++arr[a[i+1].r+1][1];
        ans = max(ans, tmp);
    }
    cout << ans << endl;
    return 0;
}