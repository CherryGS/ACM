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
ll a[100100];

int main() {
    cin >> t;
    while(t--) {
        bool flag = 0;
        cin >> n;
        for(int i=1; i<=n; i++) cin >> a[i];
        ll c = -1, dt = -1, mx = -1;
        for(int i=1; i<n; i++) {
            if(a[i+1] >= a[i]) {
                if(c == -1) c = a[i+1] - a[i];
                else if(c != a[i+1] - a[i]) {flag = 1;}
            }
            if(a[i+1] <= a[i]) {
                if(dt == -1) dt = a[i] - a[i+1];
                else if(dt != a[i] - a[i+1]) {flag = 1;}
            }
            mx = max(mx, a[i]);
        }
        mx = max(mx, a[n]);
        if(flag) cout << -1 << endl;
        else if(dt == 0 || c == -1 || dt == -1) cout << 0 << endl;
        else {
            if(mx >= dt+c) cout << -1 << endl;
            else cout << dt+c << ' ' << c << endl;
        }
    }
    return 0;
}