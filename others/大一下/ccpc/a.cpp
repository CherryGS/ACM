#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef const int& cint;

const int mod = 1e9+7;
const int inf_int = 0x7fffffff;
const ll inf_ll = 0x7fffffffffffffff;
const double ept = 1e-9;

ll n, x;
char s[100100];
string ans;

int main() {
    cin >> n >> x;
    x %= n;
    cin >> s;
    for(int i=0; i<n; i++) {
        int to = (i+x)%n;
        ans += s[to];
    }
    cout << ans << endl;
    return 0;
}