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

int n, m;
int nx[400200], to[400200], he[100100], w[400200], cnt;

void add(cint f, cint t, cint co) {
    nx[++cnt] = he[f];
    he[f] = cnt;
    to[cnt] = t;
    w[cnt] = co;
}

ll dis[100100];
bool mp[100100];

bool dfs(cint loc) {
    bool key=0;
    for(int i=he[loc]; i; i = nx[i])
        if(mp[to[i]]) {if(dis[loc]+w[i] != dis[to[i]]) return 1;}
        else {
            mp[to[i]]=1;
            dis[to[i]] = dis[loc]+w[i];
            key |= dfs(to[i]);
        }
    return key;
}

int main() {
    cin >> n >> m;
    int a, b, c;
    for(int i=1; i<=m; i++) {
        cin >> a >> b >> c;
        add(a,b,c);
        add(b,a,-c);
    }
    for(int i=1; i<=n; i++)
        if(!mp[i]) {
            mp[i]=1;
            dis[i]=0;
            if(dfs(i)) {cout << "No"; return 0;}
        }
    cout << "Yes";
    return 0;
}