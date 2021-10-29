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

int k;

ll ans[61];

int main() {
    cin >> k;
    ans[1] = 1;
    for(int i=2; i<=k; i++) {
        ans[i] = ans[i-1] * ans[i-1] % mod * 16 % mod;
    }
    cout << ans[k] * 6 % mod << endl;
    return 0;
}