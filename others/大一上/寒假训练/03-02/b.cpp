#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
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
int a;
int ans = inf_int;

int main() {
    cin >> n;
    for(int i=1; i<=n; i++) {
        cin >> a;
        if(i == 1 || i == n) ans = min(ans, a/(n-1));
        else ans = min(ans, a/max(i-1, n-i));
    }
    cout << ans << endl;
    return 0;
}