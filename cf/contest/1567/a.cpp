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
char s[1010];

int main() {
    cin >> t;
    while(t--) {
        cin >> n;
        cin >> s;
        string ans;
        for(int i=0; i<n; i++) {
            if(s[i] == 'U') ans += 'D';
            else if(s[i] == 'D') ans += 'U';
            else ans += s[i];
        }
        cout << ans << endl;
    }
    return 0;
}