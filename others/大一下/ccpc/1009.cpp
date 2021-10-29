#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef const int& cint;

const int mod = 1e9+7;
const int inf_int = 0x7fffffff;
const ll inf_ll = 0x7fffffffffffffff;
const double ept = 1e-9;

map<pair<int, int>, int> e;

int t;
int n;
char s[100100];

int main() {
    cin >> t;
    while(t--) {
        cin >> n >> s;
        int s1 = 0, s2 = 0;
        ll ans = 0;
        e.clear();
        e[{0, 0}] = 1;
        for(int i=0; i<n; i++) {
            if(s[i] == 'U') ++ s1;
            else if(s[i] == 'D') -- s1;
            else if(s[i] == 'L') -- s2;
            else if(s[i] == 'R') ++ s2;
            ans += e[{s1, s2}];
            e[{s1,s2}]++;
        }
        cout << ans << endl;
    }
    return 0;
}