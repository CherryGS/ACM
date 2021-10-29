#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef const int& cint;

const int mod = 1e9+7;
const int inf_int = 0x7fffffff;
const ll inf_ll = 0x7fffffffffffffff;
const double ept = 1e-9;

int t;
ll n;
int a[1001];

int main() {
    cin >> t;
    while(t--) {
        cin >> n;
        ll ans = 0;
        for(int i=1; i<=n; i++) cin >> a[i];
        for(int i=0; i<32; i++) {
            for(int j=1; j<=n; j++)
                if(!(a[j]&(1<<i))) { break; }
                else if(j == n) {
                    ans += (1ll<<i);
                }
        }
        cout << ans << endl;
    }
    return 0;
}