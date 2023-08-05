#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

#define ull unsigned long long

int t, n, a[51], b[51];

int main() {
    cin >> t;
    while(t--) {
        int am = 1e9 + 1, bm = 1e9 + 1;
        ull ans = 0;
        cin >> n;
        for(int i = 1; i <= n; i++) {cin >> a[i]; am = min(a[i], am);}
        for(int i = 1; i <= n; i++) {cin >> b[i]; bm = min(b[i], bm);}
        for(int i = 1; i <= n; i++) {
            ans += a[i] - am + b[i] - bm - min(a[i] - am, b[i] - bm) ;
        }
        cout << ans << endl;
    }
    return 0;
}