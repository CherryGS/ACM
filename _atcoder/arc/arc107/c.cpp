#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

#define ll long long
#define ull unsigned long long
#define cint const int&
#define Pi acos(-1)

const int mod = 998244353;

int n, kk;
int arr[100][100];
int bcj[101][2];
int num[101][2];

int find(cint x, cint y) {
    return bcj[x][y] == x? x: bcj[x][y] = find(bcj[x][y], y);
}

void sol(ll & x, int&m) {
    ll tmp = 1;
    for(; m; m--) {
        tmp *= m;
        tmp %= mod;
    }
    x %= mod;
    x = (x*tmp) % mod;
}

int main() {
    cin >> n >> kk;
    for(int i = 1; i <= n; i++) 
        bcj[i][0] = i, bcj[i][1] = i;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            cin >> arr[i][j];
    for(int i = 1; i < n; i++)
        for(int j = i+1; j <= n; j++) {

            bool f = 1;
            for(int k = 1; k <= n; k++)
                if(arr[i][k] + arr[j][k] > kk) {
                    f = 0; break;
                }
            if(f) bcj[find(bcj[i][0], 0)][0] = find(bcj[j][0], 0);

            f = 1;
            for(int k = 1; k <= n; k++)
                if(arr[k][i] + arr[k][j] > kk) {
                    f = 0; break;
                }
            if(f) bcj[find(bcj[i][1], 1)][1] = find(bcj[j][1], 1);

        }
    for(int i = 1; i <= n; i++) {
        bcj[i][0] = find(bcj[i][0], 0);
        bcj[i][1] = find(bcj[i][1], 1);
    }
    for(int i = 1; i <= n; i++) {
        ++num[bcj[i][0]][0];
        ++num[bcj[i][1]][1];
    }
    ll fra_1 = 1, fra_2 = 1;
    for(int i = 1; i <= n; i++) {
        if(num[i][0]) sol(fra_1, num[i][0]);
        if(num[i][1]) sol(fra_2, num[i][1]);
    }
    cout << (fra_1 * fra_2) % mod;
    return 0;
}