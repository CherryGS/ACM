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

int n, m, t;
int l, r;
bool a[102][102];
int num[102][102];
int xx[3] = { 0, -1, 1 };

void fil(cint x, cint y) {
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++)
            if(i || j) {
                ++num[x+xx[i]][y+xx[j]];
            }
    }
}

void sol(bool st) {
    if(st)
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            if(num[i][j] > r || num[i][j] < l) {
                a[i][j] = 0;
            } else {
                a[i][j] = 1;
            }
            num[i][j] = 0;
        }
    }
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            if(a[i][j]) fil(i, j);
        }
    }
}

int main() {
    cin >> n >> m;
    cin >> l >> r;
    cin >> t;
    char tmp;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++) {
            cin >> tmp;
            if(tmp == '*') a[i][j] = 1;
        }
    for(int i=1; i<=t; i++) {
        if(i == 1) sol(0);
        else sol(1);
    }
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            if(a[i][j]) cout << '*';
            else cout << '.';
        }
        cout << endl;
    }
    return 0;
}