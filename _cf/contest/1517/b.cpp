#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

#define ll long long
#define ull unsigned long long
#define cint const int&
#define Pi acos(-1)

const int mod = 1e9+7;
const int inf_int = 0x7fffffff;
const ll inf_ll = 0x7fffffffffffffff;
const double ept = 1e-9;

int t;
int n, m;
int mp[101][101];
bool vis[101][101];
int ans[101][101];

struct stu{
    int line, num;
    int val;
    bool operator < (const stu&a) const {
        return val < a.val;
    }
    void init(cint x, cint y, cint z) {
        line = x;
        num = y;
        val = z;
    }
} s[100100];
int cnt;

int main() {
    cin >> t;
    while(t--) {
        cnt = 0;
        cin >> n >> m;
        for(int i=1; i<=n; i++)
            for(int j=1; j<=m; j++) {
                vis[i][j] = 0;
                ans[i][j] = 0;
                cin >> mp[i][j];
                s[++cnt].init(i, j, mp[i][j]);
            }
        sort(s+1, s+1+cnt);
        for(int i=1; i<=m; i++) {
            int x = s[i].line;
            int y = s[i].num;
            vis[x][y] = 1;
            ans[x][i] = s[i].val;
        }
        for(int i=1; i<=n; i++) {
            int l = 1;
            for(int j=1; j<=m; j++)
                if(!vis[i][j]) {
                    while(ans[i][l]) { ++l; }
                    ans[i][l] = mp[i][j];
                }
        }
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=m; j++)
                cout << ans[i][j] << ' ';
                cout << endl;
        }
    }
    return 0;
}