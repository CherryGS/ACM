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

int n, m;
bool bk[2020][2020];
int to[4][2] = { {0,1}, {0,-1} , {1,0}, {-1,0} };
queue<pair<int,int>> ans;

void dfs(cint x, cint y, cint dx, cint dy) {
    bk[x][y] = 0;
    if(bk[x+dx][y+dy]) dfs(x+dx, y+dy, dx, dy);
    else ans.push(make_pair(x, y));
}

int main() {
    ios::sync_with_stdio(false);
    char a;
    scanf("%d %d",&n,&m);
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++) {
            a = getchar();
            while(a != '.' && a != '*') a = getchar();
            if(a == '*') bk[i][j] = 1;
        }
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
            if(bk[i][j]) {
                ans.push(make_pair(i, j));
                for(int k=0; k<4; k++)
                    if(bk[i+to[k][0]][j+to[k][1]]) {
                        dfs(i, j, to[k][0], to[k][1]);
                        break;
                    }
            }
    cout << ans.size()/2 << endl;
    while(!ans.empty()) {
        auto k = ans.front();
        ans.pop();
        printf("%d %d ", k.first, k.second);
        k = ans.front();
        ans.pop();
        printf("%d %d \n", k.first, k.second);
    }
    return 0;
}