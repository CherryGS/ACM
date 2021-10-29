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

int n, z;
int x[200200];

int main() {
    cin >> n >> z;
    for(int i=1; i<=n; i++) cin >> x[i];
    sort(x+1, x+1+n);
    int ans = 0;
    int st = 1;
    for(int i=n/2+1; i<=n; i++) {
        if(x[i] - x[st] >= z) ++ans, ++st;
        if(st > n/2) break;
    }
    cout << ans << endl;
    return 0;
}