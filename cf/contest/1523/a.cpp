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

ll t, n, m;
char a[1010];
ll le[1010][2];

int main() {
    cin >> t;
    while(t--) {
        cin >> n >> m;
        cin >> a;
        ll st = -inf_int;
        for(int i=1; i<=n; i++) {
            le[i][0] = ++st;
            if(a[i-1] == '1') st = 0;
        }
        st = -inf_int;
        for(int i=n; i>=1; i--) {
            le[i][1] = ++st;
            if(a[i-1] == '1') st = 0;
        }
        for(int i=1; i<=n; i++) {
            if(a[i-1] == '1') cout << '1';
            else {
                if(le[i][1] == le[i][0]) cout << '0';
                else if(min(abs(le[i][0]), abs(le[i][1])) > m) cout << '0';
                else if(le[i][0] < 0 && le[i][1] < 0) cout << '0';
                else cout << '1';
            }
        }
        cout << endl;
    }
    return 0;
}
/*
11 4
01000000001
*/