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
int a[3], d, e;
string s;
bool flag;

void NO() {
    flag = 1;
    cout << "NO" << endl;
}

int main() {
    cin >> t;
    while(t--) {
        a[0] = a[1] = a[2] = flag = 0;
        cin >> s;
        for(int i=0; i<s.length(); i++) {
            if(s[i] == 'A') ++ a[0];
            else if(s[i] == 'B') ++ a[1];
            else ++ a[2];
        }
        d = s[0] - 'A';
        e = s[s.length()-1] - 'A';
        int h = 3-d-e;
        if(d == e) NO();
        else if(abs(a[d] - a[e]) != a[h]) NO();
        else {
            int st = 1;
            int r = 0;
            if(a[d] > a[e]) st = -1;
            for(int i=0; i<s.length(); i++) {
                if(s[i] - 'A' == d) ++ r;
                else if(s[i] - 'A' == e) -- r;
                else r += st;
                if(r < 0) {NO(); break;}
            }
            if(!flag) cout << "YES" << endl;
        }
    }
    return 0;
}