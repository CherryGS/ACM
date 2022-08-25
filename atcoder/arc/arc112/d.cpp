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
int bcj[2][1010];
int row[1001], col[1001];

int fd(cint x, bool st) {
    return bcj[st][x] == x ? x : bcj[st][x] = fd(bcj[st][x], st);
}

int main() {
    ios::sync_with_stdio(false);
    int s = -1, ss = -1;
    cin >> h >> w;
    char a;
    for(int i=1; i<=h; i++) bcj[0][i] = i;
    for(int i=1; i<=w; i++) bcj[1][i] = i;
    bcj[1][w] = 1; bcj[0][h] = 1;
    for(int i=1; i<=h; i++)
        for(int j=1; j<=w; j++) {
            cin >> a;
            if(a == '#') {
                if(i == 1 || i == h) bcj[1][fd(bcj[1][j], 1)] = fd(bcj[1][1], 1);
                else {
                    if(row[i] != 0) bcj[1][fd(bcj[1][j], 1)] = fd(bcj[1][row[i]], 1);
                    row[i] = j;
                }
                if(j == 1 || j == w) bcj[0][fd(bcj[0][i], 0)] = fd(bcj[0][1], 0);
                else {
                    if(col[j] != 0) bcj[0][fd(bcj[0][i], 0)] = fd(bcj[0][col[j]], 0);
                    col[j] = i;
                }

            }
        }
    int tmp = 0;
    for(int i=1; i<=w; i++)
        if(bcj[1][i] == i) ++tmp;
    int tmp1 = 0;
    for(int i=1; i<=h; i++)
        if(bcj[0][i] == i) ++tmp1;
    cout << min(tmp1, tmp) - 1 << endl;
    return 0;
}