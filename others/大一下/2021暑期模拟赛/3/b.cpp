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

bool flag;
int t;
char s[300300];
int n, k;
int st;

void dfs(cint loc) {
    if(loc >= n) return;
    if(st != -1) {
        if(s[loc] != '?' && s[loc] != s[st]) {
            flag = 0;
            return;
        }
    }
    if(s[loc] != '?') { st = loc; dfs(loc+k); }
    else dfs(loc+k);
    if(st != -1) s[loc] = s[st];
}

int main() {
    cin >> t;
    while(t--) {
        flag = 1;
        cin >> n >> k;
        cin >> s;
        for(int i=0; i<k; i++){ st=-1; dfs(i); }
        if(!flag) cout << "NO" << endl;
        else {
            int num[3] = {0, 0, 0};
            for(int i=0; i<k; i++) {
                if(s[i] == '?') num[0]++;
                else if(s[i] == '0') num[1]++;
                else num[2]++;
            }
            if(abs(num[1]-num[2])<=num[0]) cout << "YES" << endl;
            else cout << "NO" << endl;
        }
    }
    return 0;
}