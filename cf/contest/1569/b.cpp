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
char s[505];
char ans[501][501];

int main() {
    cin >> t;
    while(t--) {
        cin >> n;
        cin >> s;
        for(int i=1; i<=n; i++)
            for(int j=1; j<=n; j++)
                ans[i][j] = (i == j ? 'X' : '+');
        vector<int> win, los;
        for(int i=0; i<n; i++) {
            if(s[i] == '1') win.push_back(i+1);
            else los.push_back(i+1);
        }
        for(int i1: win) {
            for(int i2: win) {
                if(i1 != i2)
                ans[i1][i2] = ans[i2][i1] = '=';
            }
        }
        if(los.size() < 3 && los.size() > 0) {
            cout << "NO" << endl;
            continue;
        }
        for(int i: los) {
            for(int j=1; j<=n; j++)
                if(i != j) ans[i][j] = '-';
        }
        if(los.size())
        for(int i=1; i<los.size(); i++) {
            ans[los[i-1]][los[i]] = '+';
        }
        if(los.size()) ans[los[los.size()-1]][los[0]] = '+';
        cout << "YES" << endl; 
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=n; j++) {
                if(ans[i][j] == '-' && ans[j][i] == '-') ans[i][j] = '+';
                cout << ans[i][j];
            }
            cout << endl;
        }

    }    
    return 0;
}