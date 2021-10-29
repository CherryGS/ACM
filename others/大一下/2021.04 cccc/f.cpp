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
string s, las;
string s1 = "qiandao", s2 = "easy";

bool check1(cint x) {
    for(int i=0; i<s1.length(); i++) {
        if(x+i >= s.length()) return 1;
        if(s[x+i] != s1[i]) return 1;
    }
    return 0;
}

bool check2(cint x) {
    for(int i=0; i<s2.length(); i++) {
        if(x+i >= s.length()) return 1;
        if(s[x+i] != s2[i]) return 1;
    }
    return 0;
}

int main() {
    cin >> n >> m;
    int l = 0;
    for(int i=1; i<=n; i++) {
        bool flag = 0;
        cin >> s;
        for(int j=0; j<s.length(); j++)
            if(s[j] == 'q') flag = flag | check1(j);
            else if(s[j] == 'e') flag = flag | check2(j);
        if(!flag) -- m, l = i, las = s;
        if(m < 0 ) { break; }
    }
    if(m == 0) cout << "Wo AK le" << endl;
    else cout << las << endl;
    return 0;
}