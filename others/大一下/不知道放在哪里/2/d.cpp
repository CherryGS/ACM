#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef const int& cint;

const int mod = 1e9+7;
const int inf_int = 0x7fffffff;
const ll inf_ll = 0x7fffffffffffffff;
const double ept = 1e-9;

int n, m;
bool mp[2020][2020];
int up[2020][2020];
int lef[2020][2020];

int main() {
    cin >> n >> m;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++)
            cin >> mp[i][j];
    }
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            up[i][j] = 1;
            if(i>1 && mp[i][j] != mp[i-1][j]) up[i][j] += up[i-1][j];
            // cout << up[i][j] << ' ';
        }
        // cout << endl;
    }
    int ans1 = 0, ans2 = 0;
    stack<int> e;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m+1; j++) {
            lef[i][j] = j;
            bool flag = 0;
            if(mp[i][j] == mp[i][j-1]) flag = 1;
            while(!e.empty() && (up[i][j] < up[i][e.top()] || flag == 1)) {
                ans2 = max(ans2, (j-lef[i][e.top()])*up[i][e.top()]);
                ans1 = max(ans1, int(pow(min((j-lef[i][e.top()]), up[i][e.top()]), 2)));
                if(!flag)lef[i][j] = lef[i][e.top()];
                e.pop();
            }
            e.push(j);
        }
        while(!e.empty()) e.pop();
    }
    cout << ans1 << endl << ans2 << endl;
    return 0;
}
/*
5 5
1 1 1 1 1
1 1 1 1 1
1 1 1 1 1
1 1 1 1 1
1 1 1 1 1

5 5
1 0 1 0 1
0 1 0 1 0
1 0 1 0 1
0 1 0 1 0
1 0 1 0 1
*/