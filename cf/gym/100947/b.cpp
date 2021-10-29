#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;

#define ll long long
#define ull unsigned long long
#define cint const int&
#define Pi acos(-1)

const int mod = 998244353;
const int inf_int = 0x7fffffff;
const ll inf_ll = 0x7fffffffffffffff;
const double ept = 1e-9;

int t;
int mp[9][9];

bool sol(char a, cint b) {
    int x = a - 'A' + 1;
    int y = b;
    if(mp[x][y]) {
        return 1;
    }
    for(int i=1; i<=8; i++)
        mp[i][y] = 1, mp[x][i] = 1;
    for(int i=1; i<=8; i++) {
        if(x-i >=1 && y-i >=1) mp[x-i][y-i] = 1;
        if(x+i <=8 && y+i <=8) mp[x+i][y+i] = 1;
        if(x-i >=1 && y+i <=8) mp[x-i][y+i] = 1;
        if(x+i <=8 && y-i >=1) mp[x+i][y-i] = 1;
    }
    return 0;
}

int main() {
    char a;
    int b;
    cin >> t;
    while(t--) {
        bool key=0;
        memset(mp, 0, sizeof mp);
        for(int i=1; i<=8; i++) {
            cin >> a >> b;
            key |= sol(a, b);
        }
        if(!key) cout << "Valid" << endl;
        else cout << "Invalid" << endl;
    }
    return 0;
}