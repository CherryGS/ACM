#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef const int& cint;

const int mod = 1e9+7;
const int inf_int = 0x7fffffff;
const ll inf_ll = 0x7fffffffffffffff;
const double ept = 1e-9;

int t, n, q;
char s[300300];
int sum[300300];

void debug(cint l, cint r) {
    int sum = 0;
    for(int i=l-1; i<r; i++) {
        int r = (s[i] == '+' ? 1 : -1 ) * (i&1 ? 1 : -1);
        sum += r;
    }
    cout << "----" <<  sum << endl;
}

int main() {
    cin >> t;
    while(t--) {
        cin >> n >> q;
        cin >> s;
        int l, r;
        for(int i=0; i<=n; i++) sum[i] = 0;
        for(int i=0; i<n; i++) {
            int r = (s[i] == '+' ? 1 : -1 ) * (i&1 ? 1 : -1);
            sum[i] += r;
            if(i) sum[i] += sum[i-1];
        }
        for(int i=1; i<=q; i++) {
            cin >> l >> r;
            // debug(l, r);
            int rr = sum[r-1];
            if(l > 1) rr -= sum[l-2];
            rr = abs(rr);
            if(rr == 0) cout << 0 << endl;
            else if(rr&1) cout << 1 << endl;
            else cout << 2 << endl;
        }
    }
    return 0;
}