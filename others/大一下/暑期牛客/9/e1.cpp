#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef const int& cint;

const int mod = 1e9+7;
const int inf_int = 0x7fffffff;
const ll inf_ll = 0x7fffffffffffffff;
const double ept = 1e-9;

int n;
struct query { int x, int l, int r; };
vector<int> e[500500];
vector<query> qe;

int main() {
    cin >> n;
    int u;
    for(int i=2; i<=n; i++) {
        cin >> u;
        e[u].push_back(i);
    }
    int q, x, l, r;
    cin >> q;
    for(int i=1; i<=q; i++) {
        cin >> x >> l >> r;
        
    }
    return 0;
}