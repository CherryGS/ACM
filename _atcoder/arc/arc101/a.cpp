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
int a[100100];

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> k;
    for(int i = 1; i <= n; i++) cin >> a[i];
    int ans = 0x7fffffff;
    for(int i = 1; i+k-1 <= n; i++) 
        ans = min(ans, min(abs(a[i]), abs(a[i+k-1])) + abs(a[i]-a[i+k-1]));
    cout << ans << endl;

    return 0;
}