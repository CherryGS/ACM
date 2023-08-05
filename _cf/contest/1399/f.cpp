#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int t;

struct stu {
    int l, r;
    bool operator < (stu a) const {
        if(l == a.l) return r < a.r;
        return l < a.l;
    }  
}a[10010];

int dp[3030];

int main() {
    int n;
    cin >> t;
    while(t--) {
        cin >> n;
        for(int i = 1; i <= n; i++) cin >> a[i].l >> a[i].r;
        sort(a+1, a+1+n);
        memset(dp, 0x3f, sizeof dp);
        dp[0] = 0;
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++) if(a[j].l <= dp[i-1]){
                dp[i] = min(dp[i], a[j].r);
            }
        for(int i = 1; i <= n; i++) cout << i << "---" << dp[i] << endl;
        for(int i = n; i >= 1; i--) if(dp[i] < 2e5) {
            cout << " ans: " ;
            cout << i << endl;
            break;
        }
    }
    return 0;
}