#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef const int& cint;

const int mod = 1e9+7;
const int inf_int = 0x7fffffff;
const ll inf_ll = 0x7fffffffffffffff;
const double ept = 1e-9;

struct node { 
    int x; int id; 
    bool operator < (const node&a) const { return x > a.x; } 
};
int n;
char s[2000200];
int col[1001000];
int num[1001000];
int mx[1000100];
int sum[1000100];
int ans[2001000];
vector<int> q[1000100];
vector<node> r, u;

struct lis {
    int l, r;
    void init(cint x) {
        l = x-1;
        r = x+1;
    }
} ls[1000100];

void del(cint x) {
    ls[ls[x].l].r = ls[x].r;
    ls[ls[x].r].l = ls[x].l;
}

int main() {
    cin >> n;
    cin >> s;
    for(int i=1; i<=n; i++) cin >> col[i], num[col[i]]++;
    for(int i=1; i<=n; i++)
        if(num[i]) u.push_back( {num[i], i} );
    sort(u.begin(), u.end());
    for(int i=1; i<=u.size(); i++)
        ls[i].init(i);
    ls[0].r = 1;
    ls[u.size()+1].l = u.size();
    int ss = 0;
    for(int i=0; i<2*n; i++) {
        if(s[i] == '(') ++ ss;
        else -- ss;
        if(s[i] == '(') q[ss].push_back(i);
    }
    bool flag = 0;
    for(int i=1; i<=n; i++) {
        int r = 0;
        for(int k: q[i]) {
            r = ls[r].r;
            // cout << r << ' ' << endl;
            if(r == u.size()+1) { flag = 1; break; }
            ans[k] = u[r-1].id;
            u[r-1].x--;
            if(!u[r-1].x) del(r);
        }
        if(flag) break;
    }
    if(flag == 1) cout << "NO" << endl;
    else {
        cout << "YES" << endl;
        for(int i=0; i<2*n; i++)
            if(ans[i]) cout << ans[i] << ' ';
        cout << endl;
    }
    return 0;
}
/*
4
(())(())
2 1 1 2
*/