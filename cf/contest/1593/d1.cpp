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

int gcd(cint x, cint y) {
    return y == 0 ? x : gcd(y, x%y);
}

int main() {
    cin >> t;
    while(t--) {
        cin >> n;
        for(int i=1; i<=n; i++) cin >> a[i];
        ll ans = 0;
        for(int i=1; i<n; i++) {
            ans = gcd(abs(a[i]-a[i+1]), ans);
        }
        bool st = 0;
        for(int i=1; i<n; i++) {
            if(a[i] != a[i+1]) {
                st = 1;
                break;
            }
        }
        if(!st) cout << -1 << endl;
        else cout << ans << endl;
    }
    return 0;
}