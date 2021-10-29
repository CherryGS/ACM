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

int n;
int mp[505][505];

void dfs(cint x, cint y, cint val, cint num) {
    // cout << x << ' ' << y << ' ' << val << endl;
    if(!num) return;
    if(x<n && !mp[x+1][y]) {
        mp[x+1][y] = val;
        dfs(x+1, y, val, num-1);
    } else {
        mp[x][y-1] = val;
        dfs(x, y-1, val, num-1);
    }
}

int main() {
    cin >> n;
    for(int i=1; i<=n; i++) cin >> mp[i][i];
    for(int i=n; i>=1; i--) {
        dfs(i, i, mp[i][i], mp[i][i]-1);
    }
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++)
            if(i >= j)
            cout << mp[i][j] << ' ';
            cout << endl;
    }
    return 0;
}