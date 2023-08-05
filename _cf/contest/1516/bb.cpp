#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef const int& cint;

const int mod = 1e9+7;
const int inf_int = 0x7fffffff;
const ll inf_ll = 0x7fffffffffffffff;
const double ept = 1e-9;

int t, n;
int a[2020];

int main() {
    cin >> t;
    while(t--) {
        cin >> n;
        int pre = 0;
        for(int i=1; i<=n; i++) cin >> a[i], pre ^= a[i];
        int l = n, r = 0, tmp = 0;
        for(int i=1; i<=n; i++) {
            tmp ^= a[i];
            if(!tmp) r = i;
        }
        tmp = 0;
        for(int i=n; i>=1; i--) {
            tmp ^= a[i];
            if(!tmp) l = i;
        }
        if(!pre || l <= r) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}