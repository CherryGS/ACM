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
int a[101];
int r[101];
int sum[101];

int gcd(cint x, cint y) {
    return y == 0 ? x : gcd(y, x%y);
}

int main() {
    cin >> t;
    while(t--) {
        cin >> n;
        for(int i=1; i<=n; i++) cin >> a[i];
        sort(a+1, a+1+n);
        int st = 1, pre = 0;
        for(int i=1; i<=n; i++) {
            if(a[st] != a[i]) {
                pre = max(pre, i-st);
                st = i;
            }
        }
        if(st != n) pre = max(pre, n-st+1);
        if(pre >= n/2) cout << -1 << endl;
        else {
            for(int i=1; i<=n; i++) sum[i] = 0;
            int ans = 0;
            for(int i=2*int(1e6); i>=1; i--) {
                for(int j=2; j<=n; j++) {
                    
                }
            }
            cout << ans << endl;
        }
    }
    return 0;
}