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
int val[21];

int main() {
    cin >> n;
    int tmp;
    for(int i=1; i<=n; i++) {
        cin >> tmp;
        for(int j=20; j>=0; j--) {
            if((1<<j) & tmp) val[j]++;
        }
    }
    ll ans = 0;
    for(int i=1; i<=n; i++) {
        ll r = 0;
        for(int j=20; j>=0; j--) {
            if(val[j]) {
                r += (1<<j);
                val[j]--;
            }
        }
        ans += r*r;
    }
    cout << ans << endl;
    return 0;
}