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

int n, m;
bool mp[101][101];
bool ans[100100]; // 1 means ->
bool vis[101];
int edge[100100][2];
int c[100];
bool ans1[101][101];

//check
bool vis1[101];
bool mp1[101][101];
int check_num(cint loc) {
    int ret = 0;
    vis1[loc] = 1;
    for(int i=1; i<=n; i++)
        if(i != loc && !vis1[i] && mp1[loc][i]) {
            ret += check_num(i);
        }
    return ret + 1;
}

void print() {
    cout << "__________________" << endl;
    for(int i=1; i<=n; i++)
        if(!vis1[i]) cout << i << ' ';
    cout << endl << endl;;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++)
            cout << mp1[i][j] << ' ';
        cout << endl;
    }
}

void check() {
    for(int i=1; i<=m; i++) {
        int l = edge[i][0], r = edge[i][1];
        if(ans[i]) mp1[l][r] = 1;
        else mp1[r][l] = 1;
    }
    for(int i=1; i<=n; i++) {
        memset(vis1, 0, sizeof vis1);
        int k = check_num(i);
        if(c[i] != k) {
            cout << "Wrong : " << i << endl;
            cout << "Expected c :" << c[i] << "  The result : " << k << endl;
            print();
            exit(0);
        }
    }
}

void dfs(cint loc) {
    vis[loc] = 1;
    for(int i=1; i<=n; i++)
        if(mp[loc][i] && c[i] == c[loc]) {
            ans1[loc][i] = 1;
            mp[loc][i] = mp[i][loc] = 0;
            if(!vis[i]) dfs(i);
        }
}

int main() {
    cin >> n >> m;
    for(int i=1; i<=m; i++) cin >> edge[i][0] >> edge[i][1];
    for(int i=1; i<=m; i++) mp[edge[i][0]][edge[i][1]] = mp[edge[i][1]][edge[i][0]] = 1;
    for(int i=1; i<=n; i++) cin >> c[i];
    for(int i=1; i<=m; i++) {
        int l = edge[i][0], r = edge[i][1];
        if(c[l] != c[r]) ans1[l][r] = c[l] > c[r];
        else if(!vis[r]) dfs(r);
        ans[i] = ans1[l][r];
    }
    check();
    for(int i=1; i<=m; i++)
        if(ans[i]) cout << "->" << endl;
        else cout << "<-" << endl;
    return 0;
}