#include <bits/stdc++.h>
using namespace std;

#ifdef _DEBUG
#define pr1(x) cout << x << ' ';
#define pr2(x) cout << x << endl;
#else
#define pr1(x)
#define pr2(x)
#endif
typedef long long ll;
typedef unsigned long long ull;
typedef const int& cint;
typedef pair<int, int> pii;

const int mod = 1e9+7;
const int inf_int = 0x7fffffff;
const ll inf_ll = 0x7fffffffffffffff;
const double ept = 1e-9;

ll t, a, b, c, m;

ll mx(ll x, ll y, ll z) {
    return max(max(x, y), z);
}

int main() {
    cin >> t;
    while(t--) {
        cin >> a >> b >> c >> m;
        ll r = mx(a, b, c);
        if(m > a+b+c-3) {
            cout << "NO" << endl;
        } 
        else if(max(0ll, r - (a+b+c-r)-1) > m) {
            cout << "NO" << endl;
        }
        else cout << "YES" << endl;
    }
    return 0;
}