#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;

#define ll long long
#define ull unsigned long long
#define cint const int&
#define Pi acos(-1)

const int mod = 1e9+7;
const int inf_int = 0x7fffffff;
const ll inf_ll = 0x7fffffffffffffff;
const double ept = 1e-9;

int n;
ll ans=0;
ll sum=0;

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    ll tmp=0;
    for(int i=1; i<=n; i++) {
        cin >> tmp;
        ans = (ans+tmp*sum) % mod;
        sum = (sum+tmp) % mod;
    }
    cout << ans << endl;
    return 0;
}