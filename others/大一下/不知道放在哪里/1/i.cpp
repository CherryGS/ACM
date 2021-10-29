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
int c[200100];

int main() {
    cin >> n;
    for(int i=1; i<=n; i++) cin >> c[i];
    sort(c+1, c+1+n);
    double ans = 1.0;
    bool flag = 0;
    for(int i=1; i<=n; i++) {
        if(i < c[i]) flag = 1;
        ans = min(ans, double(c[i])/i); 
    }
    if(flag) cout << -1 << endl;
    else printf("%.9f\n", ans);
    return 0;
}