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

int t;
int n;
string a, b, c;

void sol(string x, string y, bool st, bool st1) {
    char ch;
    if(st == 0) ch = '1';
    else ch = '0';
    if(st^st1) swap(x, y);
    // cout << x << ' ' << y << endl;
    string ans;
    int s1 = 0, s2 = 0;
    while(s1 < n || s2 < n) {
        // cout << ans << ' ' << s1 << ' ' << s2 << endl;
        if(s1 < n && s2 < n) {
            if(x[s1] == y[s2]) {
                ans += x[s1];
                ++s1; ++s2;
            } else if(x[s1] == ch) {
                ans += ch;
                ++s1;
            } else {
                ans += ch;
                ++s2;
            }
        }
        if(s1 >= n && s2 < n) ans += y[s2++];
        if(s2 >= n && s1 < n) ans += x[s1++];
    }
    cout << ans << endl;
}

int main() {
    cin >> t;
    while(t--) {
        cin >> n;
        n*=2;
        cin >> a >> b >> c;
        int a1 = 0, b1 = 0, c1 = 0;
        for(int i=0; i<n; i++) {
            if(a[i] == '1') ++ a1;
            if(b[i] == '1') ++ b1;
            if(c[i] == '1') ++ c1;
        }
        bool s1 = (a1*2>=n), s2 = (b1*2>=n), s3 = (c1*2>=n);
        if(!(s1^s2)) sol(a, b, s1, a1>=b1);
        else if(!(s1^s3)) sol(a, c, s1, a1>=c1);
        else sol(b, c, s2, b1>=c1);
    }
    return 0;
}
/*
1
2
0000
1111
1100
*/