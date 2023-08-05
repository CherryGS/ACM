#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <queue>
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

int t, n, m;
char mp[101][101];
int num[103][103];
bool sk[101][101];
int a[2], b[2];
bool ans;
queue<pair<int,int>> q;
queue<pair<pair<int,int>,int>> p;

bool isli(cint x, cint y) {
    return ((x>=1) && (x<=y));
}

void deal(cint x, cint y, cint co) {
    num[x][y] = co;
    q.push(make_pair(x, y));
}


void deal1(cint x, cint y, cint co) {
    sk[x][y]=1;
    p.push(make_pair(make_pair(x,y),co));
}

int main() {
    ios::sync_with_stdio(false);
    cin >> t;
    while(t--) {
        memset(num, 0x3f, sizeof num);
        memset(sk, 0, sizeof sk);
        ans = 0;
        cin >> n >> m;
        for(int i=1; i<=n; i++)
            for(int j=1; j<=m; j++) {
                cin >> mp[i][j];
                if(mp[i][j] == '*') {
                    q.push(make_pair(i, j));
                    num[i][j] = 0;
                } else if(mp[i][j] == 'S') {
                    a[0] = i; a[1] = j;
                } else if(mp[i][j] == 'X') {
                    b[0] = i; b[1] = j;
                }
            }
        while(!q.empty()) {
            auto k = q.front();
            q.pop();
            int x=k.first, y=k.second;
            int co = num[x][y];
            if(isli(x+1, n) && co+1 < num[x+1][y] && mp[x+1][y] != '#') deal(x+1, y, co+1);
            if(isli(x-1, n) && co+1 < num[x-1][y] && mp[x-1][y] != '#') deal(x-1, y, co+1);
            if(isli(y+1, m) && co+1 < num[x][y+1] && mp[x][y+1] != '#') deal(x, y+1, co+1);
            if(isli(y-1, m) && co+1 < num[x][y-1] && mp[x][y-1] != '#') deal(x, y-1, co+1);
        }
        sk[a[0]][a[1]] = 1;
        p.push(make_pair(make_pair(a[0], a[1]),0));
        while(!p.empty()) {
            auto k = p.front();
            p.pop();
            if(ans) continue;
            int co = k.second;
            int x=k.first.first, y=k.first.second;
            if(mp[x][y] == 'X') {
                ans = 1;
                continue;
            }
            if(isli(x+1, n) && co+1 < num[x+1][y] && mp[x+1][y] != '#' && !sk[x+1][y]) deal1(x+1, y, co+1);
            if(isli(x-1, n) && co+1 < num[x-1][y] && mp[x-1][y] != '#' && !sk[x-1][y]) deal1(x-1, y, co+1);
            if(isli(y+1, m) && co+1 < num[x][y+1] && mp[x][y+1] != '#' && !sk[x][y+1]) deal1(x, y+1, co+1);
            if(isli(y-1, m) && co+1 < num[x][y-1] && mp[x][y-1] != '#' && !sk[x][y-1]) deal1(x, y-1, co+1);
        }
        if(ans) cout << "yes" << endl;
        else cout << "no" << endl;
    }
    return 0;
}