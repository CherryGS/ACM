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
ll n, k;

int main() {
    cin >> t;
    while(t--) {
        cin >> n >> k;
        vector<ll> q;
        ll tmp;
        for(int i=1; i<=k; i++) {
            cin >> tmp;
            q.push_back(n-tmp);
        }
        int ans = 0;
        sort(q.begin(), q.end());
        for(ll x: q) {
            if(x < n) {
                ++ans;
                n -= x;
            }
            else break;
        }
        cout << ans << endl;
    }
    return 0;
}