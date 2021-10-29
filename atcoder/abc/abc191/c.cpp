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

int h, w;
int mv[4][2] = {
    {1, 0}, {0, 1}, {-1, 0}, {0, -1}
};
bool mp[12][12];
bool bk[12][12];

int dfs(cint x, cint y, cint las) {
    bk[x][y] = 1;
    for(int i=0; i<=3; i++) {
        if(!bk[x+mv[i][0]][y+mv[i][1]]) {
            int tmp=1;
            if(i == las) tmp = 0;
            mp[x][y] = 0;
            return tmp + dfs(x+mv[i][0], y+mv[i][1], i);
        }
    }
    return 0;
}

bool check(cint x, cint y) {
    return mp[x-1][y] == 1 && mp[x+1][y] == 1 && mp[x][y-1] == 1 && mp[x][y+1] == 1 && mp[x+1][y+1] == 1 && mp[x+1][y-1] == 1 && mp[x-1][y+1] == 1 && mp[x-1][y-1] == 1;
}

void deal(cint x, cint y) {
    for(int i=0; i<=3; i++) {
        if(mp[x+mv[i][0]][y+mv[i][1]] && !bk[x+mv[i][0]][y+mv[i][1]]) deal(x+mv[i][0], y+mv[i][1]);
    }
    if(check(x, y)) bk[x][y] = 1;
    mp[x][y] = 0;
    return;
}

int main() {
    cin >> h >> w;
    char x;
    for(int i=1; i<=h; i++)
        for(int j=1; j<=w; j++) {
            cin >> x;
            if(x == '#') {
                mp[i][j] = 1;
                mp[i][j+1] = 1;
                mp[i+1][j] = 1;
                mp[i+1][j+1] = 1;
            } else bk[i][j] = 1;
        }
    int ans = h*w;
    for(int i=1; i<=h; i++)
        for(int j=1; j<=w; j++)
            if(mp[i][j] && !bk[i][j]) {
                deal(i, j);
            }
    for(int i=1; i<=h; i++)
        for(int j=1; j<=w; j++)
            if(!bk[i][j]) {
                ans = min(ans, dfs(i, j, 1));
            }
    cout << ans << endl;
    return 0;
}