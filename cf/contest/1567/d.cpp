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

int t;
ll s;
int n;

int main() {
    cin >> t;
    while(t--) {
        cin >> s >> n;
        vector<ll> ans;
        --n;
        for(ll i = (ll)1e9; i; i/=10) {
            while(n && (s-i) >= n) {
                s -= i;
                --n;
                ans.push_back(i);
            }
            if(!n) break;
        }
        ans.push_back(s);
        for(ll u: ans) {
            cout << u << ' ';
        }
        cout << endl;
    }
    return 0;
}