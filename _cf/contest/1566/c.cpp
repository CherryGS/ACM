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
int n;
char s[2][100100];

int main() {
    cin >> t;
    while(t--) {
        cin >> n;
        cin >> s[0];
        cin >> s[1];
        bool f1 = 0, f2 = 0;
        ll ans = 0;
        for(int i=0; i<n; i++) {
            if(s[0][i] != s[1][i]) {
                ans += 2;
                f1 = f2 = 0;
            }
            else {
                if(s[0][i] == '0') {
                    if(f2 == 1) {
                        ans += 2;
                        f1 = f2 = 0;
                    }
                    else {
                        f1 = 1;
                        ans += 1;
                    }
                }
                else {
                    if(f1 == 1) {
                        ans += 1;
                        f1 = f2 = 0;
                    }
                    else {
                        f2 = 1;
                        f1 = 0;
                    }
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}