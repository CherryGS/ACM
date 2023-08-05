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

const int mod = 998244353;
const int inf_int = 0x7fffffff;
const ll inf_ll = 0x7fffffffffffffff;
const double ept = 1e-9;

int t, n;
ll a[200200];

int main() {
    cin >> t;
    while(t--) {
        cin >> n;
        for(int i=1; i<=n; i++) cin >> a[i];
        ll tmp=0, mx=0;
        for(int i=1; i<=n; i++) {
            if(i!=1) tmp += abs(a[i]-a[i-1]);
            if(i==1) mx = max(mx, abs(a[1]-a[2]));
            else if (i==n) mx = max(mx, abs(a[n]-a[n-1]));
            else mx = max(mx, abs(a[i]-a[i-1])+abs(a[i]-a[i+1])-abs(a[i-1]-a[i+1]));
        }
        cout << tmp-mx << endl;
    }
    return 0;
}