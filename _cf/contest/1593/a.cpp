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

ll a, b, c;
int t;

ll mx(ll x, ll y, ll z) {
    if(x > y) return max(x, z);
    return max(y, z);
}

int main() {
    cin >> t;
    while(t--) {
        cin >> a >> b >> c;
        if(a > b && a > c) cout << 0;
        else cout << max(b, c) + 1 - a;
        cout << ' ';
        if(b > c && b > a) cout << 0;
        else cout << max(a, c) + 1 - b;
        cout << ' ';
        if(c > a && c > b) cout << 0;
        else cout << max(a, b) + 1 - c;
        cout << endl;
    }
    return 0;
}