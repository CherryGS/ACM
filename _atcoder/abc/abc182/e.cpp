#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>
using namespace std;

#define ll long long
#define ull unsigned long long
#define cint const int&
#define Pi acos(-1)

const int mod = 998244353;
const int inf_int = 0x7fffffff;
const ll inf_ll = 0x7fffffffffffffff;
const double ept = 1e-9;

int h, w, n, m, ans;
int mp[1501][1501];
int x[500500], y[500500];

void sol_2(int X, int Y) {
    int i=X-1, j=Y;
    if(i && mp[i][j] != 10 && mp[i][j] != 2 && mp[i][j] != 3) {
        if(!mp[i][j]) ++ans;
        mp[i][j] += 2;
        sol_2(i, j);
    }
    i = X+1;
    if(i<=h && mp[i][j] != 10 && mp[i][j] != 2 && mp[i][j] != 3) {
        if(!mp[i][j]) ++ans;
        mp[i][j] += 2;
        sol_2(i, j);
    }
}

void sol_1(int X, int Y) {
    int i=X, j=Y-1;
    if(Y-1 && mp[i][j] != 10 && mp[i][j] != 1 && mp[i][j] != 3) {
        if(!mp[i][j]) ++ans;
        mp[i][j] += 1;
        sol_1(i, j);
    }
    j=Y+1;
    if(j<=w && mp[i][j] != 10 && mp[i][j] != 1 && mp[i][j] != 3) {
        if(!mp[i][j]) ++ans;
        mp[i][j] += 1;
        sol_1(i, j);
    }
}

//10 blocks 1 row 2 column 3 all
int main() {
    cin >> h >> w >> n >> m;
    for(int i=1; i<=n; i++) cin >> x[i] >> y[i];
    int x_, y_;
    for(int i=1; i<=m; i++) {
        cin >> x_ >> y_;
        mp[x_][y_] = 10;
    }
    for(int i=1; i<=n; i++) if(mp[x[i]][y[i]] != 3){
        if(!mp[x[i]][y[i]])++ans;
        mp[x[i]][y[i]] = 3;
        sol_1(x[i], y[i]);
        sol_2(x[i], y[i]);
    }
    cout << ans;
    return 0;
}