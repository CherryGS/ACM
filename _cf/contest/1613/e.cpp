#include <bits/stdc++.h>
using namespace std;

std::mt19937 rng(std::random_device{}());
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef const int& cint;
typedef const ll& cll;
typedef pair<int, int> pii;
typedef pair<int, ll> pil;

#define ls (loc<<1)
#define rs ((loc<<1)|1)

const int mod1 = 1e9+7;
const int mod2 = 998244353;
const int inf_int = 0x7fffffff;
const int hf_int = 0x3f3f3f3f;
const ll inf_ll = 0x7fffffffffffffff;
const double ept = 1e-9;

int n, m;
vector<char> s[1000100];

struct node {
    int x, y;
};

bool isfree(cint x, cint y) {
    if(x < 0 || x >= n || y < 0 || y >= m) return 0;
    return s[x][y] == '.';
}

bool check(cint x, cint y) {
    return (isfree(x-1, y) + isfree(x, y-1) + isfree(x+1, y) + isfree(x, y+1)) < 2;
}

void solve(cint T) {
    cin >> n >> m;
    char ss;
    queue<node> q;
    for(int i=0; i<n; i++) {
        s[i].clear();
        for(int j=0; j<m; j++) {
            cin >> ss;
            s[i].push_back(ss);
            if(ss == 'L') q.push({i, j});
        }
    }
    while(!q.empty()) {
        node k = q.front();
        q.pop();
        if(s[k.x][k.y] != 'L' && !check(k.x, k.y)) continue;
        if(s[k.x][k.y] != 'L') s[k.x][k.y] = '+';
        if(isfree(k.x-1, k.y)) q.push({k.x-1, k.y});
        if(isfree(k.x, k.y-1)) q.push({k.x, k.y-1});
        if(isfree(k.x+1, k.y)) q.push({k.x+1, k.y});
        if(isfree(k.x, k.y+1)) q.push({k.x, k.y+1});
    }
    for(int i=0; i<n; i++) {
        for(char r: s[i]) cout << r;
        cout << '\n';
    }
}

int main() {
    //freopen("1.in", "r", stdin);
    //cout.flags(ios::fixed); cout.precision(8);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T_=1;
    std::cin >> T_;
    for(int _T=1; _T<=T_; _T++)
        solve(_T);
    return 0;
}