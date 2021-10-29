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

int n, a, b, c;

struct stu {
    int val;
    int id;
    string ans;
    void init(cint x, cint y) {
        id = x;
        val = y;
    }
    bool operator < (const stu&a) const {
        return val < a.val;
    }
} s[3];

string ans[3];

int main() {
    cin >> a >> b >> c >> n;
    s[0].init(0, a);
    s[1].init(1, b);
    s[2].init(2, c);
    sort(s, s+3);
    cout << s[0].id << endl;
    if(s[1].val - (n-s[2].val) > s[0].val) {
        cout << "NO" << endl;
    } else {
        for(int i=1; i<=n; i++) ans[0] += 'a';
        for(int i=1; i<=n; i++) {
            if(i <= s[2].val) ans[1] += 'a';
            else ans[1] += 'b';
        }
        for(int i=1; i<=n; i++) {
            if(i <= s[0].val) ans[2] += 'a';
            else if(i <= s[1].val) ans[2] += 'b';
            else ans[2] += 'c';
        }
        
    }
    return 0;
}