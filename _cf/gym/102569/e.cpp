#include <iostream>
#include <cstdio>
#include <algorithm>

#define ll long long
ll n;
ll sum;
ll ans;
using namespace std;

int main() {
    cin >> n;
    ll t;
    for(int i = 1; i <= n; i++) {
        cin >> t;
        sum += t;
        ans = min(ans, sum);
    }
    if(ans >= 0) cout << 0;
    else cout << -ans;
    return 0;
}