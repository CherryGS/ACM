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

int t;
int n, m, k;
bool mp[2][101][101];
bool vis[101][101];

bool check(cint x, cint y, bool st) {
    bool flag = 0;
    if(st == 0) {
        if(mp[1][x-1][y] + mp[0][x-1][y] + mp[1][x-1][y+1] == 3 && !vis[x][y]) flag = 1;
        if(mp[1][x][y] + mp[0][x+1][y] + mp[1][x][y+1] == 3 && !vis[x][y]) flag = 1;
    }
    else {
        if(mp[0][x][y-1] + mp[1][x][y-1] + mp[0][x+1][y-1] == 3 && !vis[x][y]) flag = 1;
        if(mp[0][x][y] + mp[1][x][y+1] + mp[0][x+1][y] == 3 && !vis[x][y]) flag = 1;
    }
    return flag;
}

int siz(cint i, cint j) {
    return mp[0][i][j] + mp[1][i][j] + mp[0][i+1][j] + mp[1][i][j+1];
}

struct node{
    int i, j;
};

void change(cint x, cint y) {
    if(!mp[0][x][y]) {
        mp[0][x][y] = 1;
        
    }
    else if(!mp[1][x][y]) {
        mp[1][x][y] = 1;
    }
    else if(!mp[0][x+1][y]) {
        mp[0][x+1][y] = 1;
    }
    else if(!mp[1][x][y+1]) {
        mp[1][x][y+1] = 1;
    }
}

int main() {
    cin >> t;
    while(t--) {
        memset(mp, 0, sizeof mp);
        memset(vis, 0, sizeof vis);
        cin >> n >> m >> k;
        int x, y, o;
        int ans = 0;
        bool st = 0;
        for(int i=1; i<=k; i++) {
            cin >> x >> y >> o;
            mp[o][x][y] = 1;
            if(check(x, y, o)) {
                vis[x][y] = 1;
                if(st == 0) ++ ans;
                else -- ans;
            }
            else st ^= 1;
        }
        queue<node> q1, q2;
        for(int i=1; i<n; i++) {
            for(int j=1; j<m; j++) {
                int st = siz(i, j);
                if(st == 4) {
                    vis[i][j] = 1;
                }
                else if(st == 3) {
                    q1.push( {i, j} );
                }
                else if(st == 2) {
                    q2.push( {i, j} );
                }
            }
        }
        while(!q1.empty()) {
            int x = q1.front().i;
            int y = q1.front().j;
            q1.pop();
            change(i, j);
            if(st == 0) ++ ans;
            else -- ans;
        }
    }
    return 0;
}