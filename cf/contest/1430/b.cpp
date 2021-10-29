#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

#define ll long long
#define ull unsigned long long
#define cint const int&
#define Pi acos(-1)

int t, n, k;
ll arr[200002];

int main() {
    ios::sync_with_stdio(false);
    cin >> t;
    while(t--) {
        cin >> n >> k;
        arr[n] = 0;
        if(n == 1) {cout << 0 << endl;continue;}
        if(n == 0) {cout << 0 << endl;continue;}
        for(int i = 1; i <= n; i++) cin >> arr[i];
        sort(arr+1, arr+1+n);
        if(k == 0) {cout << arr[n] - arr[1] << endl;continue;}
        ll ans = 0;
        for(int i = n - 1; k && i > 0; i--, k--) ans += arr[i];
        cout << arr[n] + ans << endl;
    }
    return 0;
}