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
char s[100100];

int main() {
    cin >> t;
    while(t--) {
        cin >> s;
        int le = strlen(s);
        int ans = 0;
        int la = 0;
        for(int i=0; i<le; i++) {
            if(s[i] == '0') {
                if(la && la != i) ans = max(ans, 2);
                la = i+1;
            }
        }
        if(la) ans = max(ans, 1);
        cout << ans << endl;
    }
    return 0;
}