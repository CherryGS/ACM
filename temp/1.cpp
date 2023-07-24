#include<bits/stdc++.h>
using namespace std;

/*
1000件, 选3件，尽量靠近100元，不行输出 It's too expensive.
*/

int n;
int a[1001];
int dp[101][3];

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    for(int i=1; i<=n; i++) { cin >> a[i]; }
    dp[0][0] = 1;
    for(int i=1; i<=n; i++) {
        for(int j=100-1; j>=0; j--) {
            for(int k=3-1; k>=0; k--) {
                if(dp[j][k] == 1) {
                    if(j+a[i]<=100) { dp[j+a[i]][k+1] = 1; }
                }
            }
        }
    }
    int ans = -1;
    for(int i=100; i>=1; i--) {
        if(dp[i][3] == 1) { ans = i; }
        if(ans != -1) { break; }
    }
    if(ans == -1) { cout << "It's too expensive.\n"; }
    else { cout << ans << '\n'; }
}
/*
8
32 52 13 22 59 42 7 68
*/