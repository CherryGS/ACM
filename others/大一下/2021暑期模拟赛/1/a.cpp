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


int main() {
    char s;
    cin >> n >> m;
    int up, dn, lf, rt;
    up = dn = lf = rt = 0;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            cin >> s;
            if(s == 'B') {
                if(up == 0) up = i;
                dn = i;
                if(lf == 0) lf = j;
                rt = j;
            }
        }
    }
    cout << (up+dn)/2 << ' ' << (lf+rt)/2 << endl;
    return 0;
}