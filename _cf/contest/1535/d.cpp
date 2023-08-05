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
#define lson ((loc<<1)|1)
#define rson (loc<<1)

const int mod = 1e9+7;
const int inf_int = 0x7fffffff;
const ll inf_ll = 0x7fffffffffffffff;
const double ept = 1e-9;

int k;
char s[900300];
int q;
int node[900300];

void dfs(cint loc) {
    if(loc > k) {
        node[loc] = 1;
        return;
    }
    dfs(lson);
    dfs(rson);
    if(s[k-loc] == '0') node[loc] = node[lson];
    else if(s[k-loc] == '1') node[loc] = node[rson];
    else node[loc] = node[lson] + node[rson];
}

void change(cint loc) {
    if(!loc) return;
    if(s[k-loc] == '0') node[loc] = node[lson];
    else if(s[k-loc] == '1') node[loc] = node[rson];
    else node[loc] = node[lson] + node[rson];
    change(loc >> 1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> k;
    cin >> s;
    cin >> q;

    k = (1<<k)-1;
    dfs(1);
    int p;
    char c;
    for(int i=1; i<=q; i++) {
        cin >> p >> c;
        s[p-1] = c;
        change(k-p+1);
        cout << node[1] << endl;
    }
    return 0;
}