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

int n;

int main() {
    ll t1, t2;
    ll ans = 0;
    cin >> n;
    for(int i=1; i<=n; i++) {
        cin >> t1 >> t2;
        ans += (t1+t2)*(t2-t1+1)/2;
    }
    cout << ans;

    return 0;
}