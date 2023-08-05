#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef const int& cint;
typedef pair<int, int> pii;

const int mod = 1e9+7;
const int inf_int = 0x7fffffff;
const int hf_int = 0x3f3f3f3f;
const ll inf_ll = 0x7fffffffffffffff;
const double ept = 1e-9;

int n, m, qq;
int dp[1000100];
string s[1001000];

struct node {
    int l, r;
    bool ans;
    int id;
    void init(cint x) {
        id = x;
        cin >> l >> r;
    }
}q[200200];

bool cmp1(const node&a, const node&b) {
    return a.r < b.r;
}

bool cmp2(const node&a, const node&b) {
    return a.id < b.id;
}



int main() {
    cin >> n >> m;
    for(int i=0; i<n; i++) cin >> s[i];
    cin >> qq;
    for(int i=1; i<=qq; i++) q[i].init(i);
    sort(q+1, q+1+qq, cmp1);
    int r = 1;
    dp[0] = m+1;
    for(int j=1; j<=m; j++) {
        int mx = 0;
        for(int i=1; i<=n; i++) {
            if(s[i-1][j-1] == 'X') dp[i] = j+1;
            else { dp[i] = min(dp[i], dp[i-1]); mx = max(mx, dp[i]); }
        }
        while(q[r].r <= j && r <= qq) {
            if(q[r].l >= mx) q[r].ans = 1;
            ++r;
        }
    }
    sort(q+1, q+1+qq, cmp2);
    for(int i=1; i<=qq; i++)
        if(q[i].ans) cout << "YES" << endl;
        else cout << "NO" << endl;
    return 0;
}
/*
1 1
.
1
1 1
*/