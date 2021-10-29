#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
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
bool mp[101][101];
queue<int> row, col;
queue<pair<int, int>> ans;

void sol_1(cint x, cint y, cint key) {
    // 0 -> row
    int x1 = x + 1, y1 = y + 1;
    if (x == n) x1 = x - 1;
    if (y == m) y1 = y - 1;
    ans.push(make_pair(x, y));
    mp[x][y] ^= 1;
    if (!key) {
        ans.push(make_pair(x1, y));
        mp[x1][y] ^= 1;
    } else {
        ans.push(make_pair(x, y1));
        mp[x][y1] ^= 1;
    }
    ans.push(make_pair(x1, y1));
    mp[x1][y1] ^= 1;
}

int cnto(cint x, cint y, cint x1, cint y1) {
    return mp[x][y] + mp[x1][y] + mp[x][y1] + mp[x1][y1];
}

void add(cint x, cint y, cint x1, cint y1) {
    ans.push(make_pair(x, y));
    ans.push(make_pair(x1, y));
    ans.push(make_pair(x, y1));
}

void deal_ans(cint x, cint y, cint x1, cint y1) {
    if (mp[x1][y] + mp[x][y1] + mp[x][y] == 3) {
        add(x,y,x1,y1);
        return;
    }
    if (mp[x][y] + mp[x1][y1] + mp[x1][y] == 3) {
        add(x1,y,x,y1);
        return;
    }
    if (mp[x1][y] + mp[x][y1] + mp[x1][y1] == 3) {
        add(x1,y1,x,y);
        return;
    }
    if (mp[x][y] + mp[x1][y1] + mp[x][y1] == 3) {
        add(x,y1,x1,y);
        return;
    }
}

void change(cint x, cint y, cint x1, cint y1) {
    mp[x][y] ^= 1;
    mp[x1][y] ^= 1;
    mp[x][y1] ^= 1;
    add(x,y,x1,y1);
    return;
}

void sol_2(cint x, cint y) {
    int x1 = x + 1, y1 = y + 1;
    while(cnto(x,y,x1,y1)) {
        if (mp[x][y]) {
            if (cnto(x, y, x1, y1) == 3) {
                deal_ans(x, y, x1, y1);
                return;
            }
            change(x, y, x1, y1);
        }
        if (mp[x1][y]) {
            if (cnto(x1, y, x, y1) == 3) {
                deal_ans(x1, y, x, y1);
                return;
            }
            change(x1, y, x, y1);
        }
        if (mp[x][y1]) {
            if (cnto(x, y1, x1, y) == 3) {
                deal_ans(x, y1, x1, y);
                return;
            }
            change(x, y1, x1, y);
        }
        if (mp[x1][y1]) {
            if (cnto(x1, y1, x, y) == 3) {
                deal_ans(x1, y1, x, y);
                return;
            }
            change(x1, y1, x, y);
        }
    }
}

void print() {
    cout << ans.size()/3 << endl;
    while (!ans.empty()) {
        for(int i=1; i<=3; i++) {
            auto k = ans.front();
            ans.pop();
            cout << k.first << ' ' << k.second << ' ';
        }
        cout << endl;
    }
}

int main() {
    cin >> t;
    while (t--) {
        char st;
        cin >> n >> m;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++) {
                cin >> st;
                mp[i][j] = st - '0';
            }
        if (n & 1) {
            for (int i = 1; i <= m; i++) if (mp[n][i]) sol_1(n, i, 0);
            --n;
        }
        if (m & 1) {
            for (int i = 1; i <= n; i++) if (mp[i][m]) sol_1(i, m, 1);
            --m;
        }
        for (int i = 1; i <= n; i += 2)
            for (int j = 1; j <= m; j += 2) sol_2(i, j);
        print();
    }
    return 0;
}