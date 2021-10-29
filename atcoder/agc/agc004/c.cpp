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
char mp[505][505];
bool ans[505][505][2];

int main() {
    cin >> h >> w;
    for(int i=1; i<=h; i++) {
        for(int j=1; j<=w; j++) {
            cin >> mp[i][j];
        }
    }
    for(int i=1; i<=w; i++) ans[1][i][0] = ans[h][i][1] = 1;
    for(int i=2; i<h; i++) {
        for(int j=2; j<w; j++) {
            if(j&1) {
                ans[i][j][0] = 1;
                if(mp[i][j] == '#') ans[i][j][1] = 1;
            } else {
                ans[i][j][1] = 1;
                if(mp[i][j] == '#') ans[i][j][0] = 1;
            }
        }
    }
    for(int l=1; l<=2; l++) {
        for(int i=1; i<=h; i++) {
            for(int j=1; j<=w; j++) {
                if(ans[i][j][l-1]) cout << '#';
                else cout << '.';
            }
            cout << endl;
        }
        cout << endl;
    }
    return 0;
}