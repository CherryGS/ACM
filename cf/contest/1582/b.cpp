#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef const int& cint;
typedef pair<int, int> pii;
typedef const ll& cll;

#define ls (loc<<1)
#define rs ((loc<<1)|1)

const int mod = 1e9+7;
const int inf_int = 0x7fffffff;
const int hf_int = 0x3f3f3f3f;
const ll inf_ll = 0x7fffffffffffffff;
const double ept = 1e-9;

int t, n;
int a[101];
ll to[101];

int main() {
    //freopen("1.in", "r", stdin);
    //cout.flags(ios::fixed); cout.precision(8);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> t;
    while(t--) {
        cin >> n;
        ll s = 0, ss = 0;
        for(int i=1; i<=n; i++) {
            cin >> a[i];
            if(a[i] == 0) ++s;
            else if(a[i] == 1) ++ ss;
        }
        ll ans = 0;
        cout << (1ll<<s)*ss << endl;
    }
    return 0;
}