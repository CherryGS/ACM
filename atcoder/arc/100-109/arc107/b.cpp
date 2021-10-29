#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

#define ll long long
#define ull unsigned long long
#define cint const int&
#define Pi acos(-1)

int n, k;

ll sol(cint x) {
    if(x <= n+1) return (x-1);
    return n-(x-n)+1;
}

int main() {
    cin >> n >> k;
    ll ans = 0;
    for(int i = 2; i <= n*2 && i+k <= n*2; i++)
        if(i+k >= 2) {
            ans += sol(i+k) * sol(i);
        }
    cout << ans << endl;
    return 0;
}