#include <bits/stdc++.h>
using namespace std;

#ifdef _DEBUG
#define pr1(x) cout << x << ' ';
#define pr2(x) cout << x << endl;
#else
#define pr1(x)
#define pr2(x)
#endif
typedef long long ll;
typedef unsigned long long ull;
typedef const int& cint;
typedef pair<int, int> pii;

const int mod = 1e9+7;
const int inf_int = 0x7fffffff;
const ll inf_ll = 0x7fffffffffffffff;
const double ept = 1e-9;

int n, m;
int a[200200];
int b[200200];
int c[200200];
int mx[200200];

bool cmp(cint x, cint y) {
    return a[x] == a[y] ? b[x] > b[y] : a[x] < a[y];
}

void sol() {
    int r = 0;
    memset(mx, 0x3f, sizeof mx);
    mx[0] = 0;
    for(int i=1; i<=m; i++) {
        int id = lower_bound(mx, mx+r+1, c[i]) - mx;
        mx[id] = c[i];
        r = max(r, id);
    }
    for(int i=m; i>=1; i--)
        if(mx[i] < 0x3f3f3f3f) {
            cout << i << endl;
            return;
        }
}

int main() {
    cin >> n >> m;
    int u, v;
    for(int i=1; i<=m; i++) cin >> a[i] >> b[i];
    vector<int> id;
    for(int i=1; i<=m; i++) id.push_back(i);
    sort(id.begin(), id.end(), cmp);
    for(int i=1; i<=m; i++) c[i] = b[id[i-1]];
    sol();
    return 0;
}