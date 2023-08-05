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
int sum[1<<20][2];

int main() {
    int tmp = 0, s = 0;
    cin >> n;
    ll ans = 0;
    sum[0][0] = 1;
    for(int i=1; i<=n; i++) {
        cin >> tmp;
        s ^= tmp;
        ans += sum[s][i&1];
        sum[s][i&1]++;
    }
    cout << ans << endl;
    return 0;
}