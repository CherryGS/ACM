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

char s[100100];
string pt[4] = { "dreamer", "dream", "eraser", "erase"};
bool flag;

void dfs(cint loc, cint ed) {
    // cout << loc << ' ' << ed << endl;
    if(loc > ed) {
        flag = 1;
        return;
    }
    for(int i=0; i<4; i++) {
        if(ed-loc+1 < pt[i].length()) continue;
        for(int j=0; j<=pt[i].length(); j++) {
            if(j == pt[i].length()) {
                dfs(loc+j, ed);
                break;
            }
            if(s[loc+j] != pt[i][j]) break;
        }
    }
}

int main() {
    cin >> s;
    dfs(0, strlen(s)-1);
    if(flag) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}