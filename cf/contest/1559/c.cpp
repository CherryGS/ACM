#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef const int& cint;

const int mod = 1e9+7;
const int inf_int = 0x7fffffff;
const ll inf_ll = 0x7fffffffffffffff;
const double ept = 1e-9;

int t, n;
bool a[10010];

void sol(cint x) {
    for(int i=1; i<=n; i++) {
        cout << i << ' ';
        if(i == x) cout << n+1 << ' ';
    }
    cout << endl;
}

void sol1() {
    cout << n+1 << ' ';
    for(int i=1; i<=n; i++) {
        cout << i << ' ';
    }
    cout << endl;
}

int main() {
    cin >> t;
    while(t--) {
        cin >> n;
        for(int i=1; i<=n; i++) cin >> a[i];
        bool flag = 0;
        for(int i=1; i<=n; i++) {
            if(a[i] == 0 && (i == n || a[i+1] == 1)) {
                sol(i);
                flag = 1;
                break;
            }
            if(a[1] == 1) {
                sol1();
                flag = 1;
                break;
            }
        }
        if(!flag) cout << -1 << endl;
    }
    return 0;
}