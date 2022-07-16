#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

int n, k, s;
int a[100100], b[100100];
int val[2][303];

int main() {
    freopen("1.in", "r", stdin);
    cin >> n >> k >> s;
    int ans = 0;
    for(int i=1; i<=n; i++) {
        cin >> a[i] >> b[i];
        if(b[i] >= s && a[i] >= 175) {
            ans++;
        }
        else {
            val[0][a[i]]++;
        }
    }
    // cout << ans << endl;
    for(int i=1; i<=k; i++) {
        for(int j=175; j<=300; j++) {
            if(val[0][j]) {
                ++ans;
                val[0][j]--;
            }
        }
    }
    cout << ans << endl;
}