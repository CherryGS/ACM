#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

#define ll long long
#define ull unsigned long long
#define cint const int&
#define Pi acos(-1)

int n;
int a[200100];

int main() {
    cin >> n;
    for(int i = 1; i <= n; i++) {cin >> a[i]; a[i] -= i;}
    sort(a+1, a+1+n);
    int x = a[(n+1)/2];
    ll ans = 0;
    for(int i = 1; i <= n; i++) ans += abs(a[i] - x);
    cout << ans << endl;
    return 0;
}