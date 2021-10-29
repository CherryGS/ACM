#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <set>
using namespace std;

#define ll long long
#define ull unsigned long long
#define cint const int&
#define Pi acos(-1)

const int mod = 998244353;
const int inf_int = 0x7fffffff;
const ll inf_ll = 0x7fffffffffffffff;
const double ept = 1e-9;

set<int> e;
int n;

int main() {
    ios::sync_with_stdio(false);
    int a;
    cin >> n;
    int ans=0;
    e.insert(inf_int/2);
    e.insert(-inf_int/2);
    for(int i=1; i<=n; i++) {
        cin >> a;
        if(i==1) ans = a;
        else {
            auto k = e.lower_bound(a);
            if(*k != a) {
                auto k1 = k;
                k1--;
                ans += min(abs(*k1-a),abs(*k-a));
            }
        }
        e.insert(a);
    }
    cout << ans;
    return 0;
}