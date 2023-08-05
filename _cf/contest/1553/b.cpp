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

int q;
char s[505], t[1005];
bool flag;
int le1, le2;

void dfs(cint loc, cint st, bool vis) {
    if(st == le2 && !flag) {
        flag = 1;
        return ;
    }
    if(loc < le1-1 && !flag && !vis)
        if(t[st] == s[loc+1]) dfs(loc+1, st+1, 0);
    if(loc && !flag)
        if(t[st] == s[loc-1]) dfs(loc-1, st+1, 1);
}

int main() {
    cin >> q;
    while(q--) {
        flag = 0;
        cin >> s >> t;
        le1 = strlen(s);
        le2 = strlen(t);
        for(int i=0; i<le1 && !flag; i++) {
            if(s[i] == t[0]) dfs(i, 1, 0);
        }
        if(flag) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}
/*
1
aaa
aaaaa
*/