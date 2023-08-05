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
string s, t;
int a[200200][2];

int main() {
    cin >> n >> m;
    cin >> s >> t;
    int l = 0;
    for(int i=0; i<m; i++) {
        while(s[l] != t[i]) ++l;
        a[i][0] = l;
        ++l;
    }
    l = n-1;
    for(int i=m-1; i>=0; i--) {
        while(s[l] != t[i]) --l;
        a[i][1] = l;
        --l;
    }
    int ans = 0;
    // for(int i=0; i<m; i++)
    //     cout << a[i][0] << ' ' << a[i][1] << endl;
    for(int i=0; i<m; i++) ans = max(a[i+1][1] - a[i][0], ans);
    cout << ans << endl;

    return 0;
}