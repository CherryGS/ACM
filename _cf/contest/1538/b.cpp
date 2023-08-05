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

int t;
int n;
int a[200200];

int main() {
    cin >> t;
    while(t--) {
        ll sum = 0;
        cin >> n;
        for(int i=1; i<=n; i++) {
            cin >> a[i];
            sum += a[i];
        }
        if(sum%n) {
            cout << -1 << endl;
            continue;
        }
        int ans = 0;
        for(int i=1; i<=n; i++)
            if(a[i] > sum/n) ++ ans;
        cout << ans << endl;

    }
    return 0;
}