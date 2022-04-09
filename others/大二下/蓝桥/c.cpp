#include <bits/stdc++.h> 
using namespace std;

typedef long long ll;

int n;
ll a[200200];

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    for(int i=1; i<=n; i++) { cin >> a[i]; }
    ll sum = 0, ans = 0;
    for(int i=1; i<=n; i++) { sum += a[i]; }
    for(int i=1; i<=n; i++) {
        ans += a[i] * (sum - a[i]);
    }
    cout << ans / 2;
}