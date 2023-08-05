#include <iostream>
#include <cstdio>
#include <algorithm>

#define ll long long

using namespace std;
int main() {
    int n;
    ll ans = 0;
    ll a,b;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a >> b;
        if(a >= ans) ans = a;
        ans += b;
    }    
    cout << ans;
    return 0;
}