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

struct stu{
    int x[101];
    bool operator < (const stu&a) const {
        for(int i=1; i<=m; i++)
            if(x[i] != a.x[i]) return x[i] < a.x[i]; 
        return 0;
    }
    void init() {
        for(int i=1; i<=m; i++) cin >> x[i];
    }
    void print() {
        for(int i=1; i<=m; i++) {
            cout << x[i];
            if(i != m) cout << ' ';
        }
    }
} a[10010];

int ans[10010], cnt[10010], cct;
vector<int> e[10010];

bool check(const stu&a, const stu&b) {
    for(int i=1; i<=m; i++)
        if(a.x[i] != b.x[i]) return 1;
    return 0;
}

int main() {
    cin >> n >> m;
    for(int i=1; i<=n; i++) { a[i].init(); }
    sort(a+1, a+1+n);
    for(int i=1; i<=n; i++) {
        if(check(a[i], a[i-1])) {
            ans[++cct] = i;
        }
        ++cnt[cct];
    }
    for(int i=1; i<=cct; i++) e[cnt[i]].push_back(ans[i]);
    cout << cct << endl;
    for(int i=n; i>=1; i--)
        if(!e[i].empty()) {
            for(int j = 0; j<e[i].size(); j++){
                cout << i << ' ';
                a[e[i][j]].print();
                cout << endl;
            }
        }
    return 0;
}