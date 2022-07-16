// n^2
#include <bits/stdc++.h>
using namespace std;

int n;
int a[100100];

int gcd(int x, int y) { return y == 0 ? x : gcd(y, x%y); }

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i=1; i<=n; i++) { cin >> a[i]; }
    int mn = n+1;
    for(int i=1; i<=n; i++) {
        int x = a[i];
        for(int j=i; j>=1; j--) {
            x = gcd(x, a[j]);
            if(x == 1) { mn = min(mn, i-j); break; }
        }
    }
    cout << n-1 + mn << '\n';
    return 0;
}