#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef const int& cint;
typedef pair<int, int> pii;

const int mod = 1e9+7;
const int inf_int = 0x7fffffff;
const int hf_int = 0x3f3f3f3f;
const ll inf_ll = 0x7fffffffffffffff;
const double ept = 1e-9;

int n, m;
bool mp[505][505];
int cnt;

int main() {
    char tmp;
    cin >> n >> m;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            cin >> tmp;
            if(tmp == 'B') mp[i][j] = 1;
            if(mp[i][j]) {
                if(i > 1) mp[i-1][j] ^= 1;
                if(j > 1) mp[i][j-1] ^= 1;
                if(i > 1 && j > 1) mp[i-1][j-1] ^= 1; 
            }
        }
    }
    // for(int i=1; i<=n; i++) {
    //     for(int j=1; j<=m; j++) {
    //         cout << mp[i][j] << ' ';
    //     }
    //     cout << endl;
    // }
    int ans = 0;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            if(i < n && j < m) {
                if(mp[i][m] && mp[n][j] && mp[i][j]) {
                    ans += 3;
                    mp[i][m] = mp[n][j] = mp[i][j] = 0;
                    mp[n][m] ^= 1;
                    ++cnt;
                }
            }
            if(mp[i][j]) {
                ++ans;
            }
        }
    }
    if(mp[n][m]) {
        if(cnt) --ans;
    }
    cout << ans << endl;
    return 0;
}