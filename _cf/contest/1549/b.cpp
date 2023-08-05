#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef const int& cint;

const int mod = 1e9+7;
const int inf_int = 0x7fffffff;
const ll inf_ll = 0x7fffffffffffffff;
const double ept = 1e-9;

int t, n;
char a[200200], b[200200];
bool vis[200200];

int main() {
    cin >> t;
    while(t--) {
        cin >> n;
        cin >> a >> b;
        int ans = 0;
        int le = 0;
        for(int i=0; i<n; i++) vis[i] = 0;
        for(int i=0; i<n; i++) {
            if(b[i] == '1' && a[i] == '0') ++ans;
            else if(b[i] == '1' && a[i] == '1') {
                if(i && a[i-1] == '1' && !vis[i-1]) {
                    vis[i-1] = 1;
                    ++ans;
                }
                else if(i < n-1 && a[i+1] == '1' && !vis[i+1]) {
                    vis[i+1] = 1;
                    ++ans;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}