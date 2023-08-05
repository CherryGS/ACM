#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef const int& cint;
typedef pair<int, int> pii;

const int mod = 1e9+7;
const int inf_int = 0x7fffffff;
const int hf_int = 0x3f3f3f3f;
const ll inf_ll = 0x7fffffffffffffff;
const double ept = 1e-9;

map<string, int> e;
int mx, n;
string ans;

int main() {
    cin >> n;
    string tmp;
    for(int i=1; i<=n; i++) {
        cin >> tmp;
        e[tmp]++;
        if(e[tmp] > mx) {
            mx = e[tmp];
            ans = tmp;
        }
    }
    if(mx*2 > n) cout << ans << endl;
    else cout << "NONE" << endl;
    return 0;
}