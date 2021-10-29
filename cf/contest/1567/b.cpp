#include <bits/stdc++.h>
using namespace std;

#ifdef _DEBUG
#define pr1(x) cout << x << ' ';
#define pr2(x) cout << x << endl;
#else
#define pr1(x)
#define pr2(x)
#endif
typedef long long ll;
typedef unsigned long long ull;
typedef const int& cint;
typedef pair<int, int> pii;

const int mod = 1e9+7;
const int inf_int = 0x7fffffff;
const ll inf_ll = 0x7fffffffffffffff;
const double ept = 1e-9;

int t;
int a, b;
int s[1000300];
map<int, int> e;
int cnt;

void init() {
    int x = 524288;
    for(int i=1; i<=x; i++) {
        s[i] = s[i-1]^i;
    }
    for(int i=x; i>=1; i--) {
        e[s[i]] = i;
    }
}

int main() {
    init();
    cin >> t;
    while(t--) {
        cin >> a >> b;
        int r = s[a-1];
        b ^= r;
        if(b == 0) cout << a << endl;
        else if(b != a) cout << a+1 << endl;
        else cout << a+2 << endl;

    }
    return 0;
}