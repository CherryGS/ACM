#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int t = 0, n = 0;
int a[501];
int main() {
    cin >> t;
    while(t--) {
        int ans = 0, p;
        cin >> n;
        memset(a, 0, sizeof a);
        for(int i = 1; i <= n; i++) {cin >> p; a[p]++;}
        for(int i = 200; i >= 2; i--) {
            int m = 0;
            for(int j = i-1; j >= (i+1) >> 1; j--)   {
                if((j << 1) == i) {
                    m += (a[j]/2);
                }
                else m += min(a[j], a[i-j]);
            }
            ans = max(m, ans);
        }
        cout << ans << endl;
    }
    return 0;
}