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

int t, n;
char s[202];
int r[202];

int main() {
    cin >> t;
    while(t--) {
        cin >> n;
        cin >> s;
        bool flag = 0;
        for(int i=0; i<n-1; i++) {
            if(s[i] != s[i+1]) {
                cout << i+1 << ' ' << i+2 << endl;
                flag = 1;
                break;
            }
        }
        if(!flag) cout << -1 << ' ' << -1 << endl;
    }
    return 0;
}