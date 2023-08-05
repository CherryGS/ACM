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

int t;
string c;

int main() {
    cin >> t;
    while(t--) {
        cin >> c;
        int ans = inf_int;
        for(int i=c.size()-1; i>=0; i--) {
            for(int j=i+1; j<c.size(); j++) {
                if(c[i] == '5' && c[j] == '0') ans = min(ans, int(c.size()-2-i));
                if((c[i] == '7' || c[i] == '2') && c[j] == '5') ans = min(ans, int(c.size()-2-i));
                if(c[i] == '0' && c[j] == '0') ans = min(ans, int(c.size()-2-i));
            }
        }
        cout << ans << endl;
    }
    return 0;
}