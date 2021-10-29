#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

#define ll long long
#define ull unsigned long long
#define cint const int&
#define Pi acos(-1)

const int mod = 1e9+7;
const int inf_int = 0x7fffffff;
const ll inf_ll = 0x7fffffffffffffff;
const double ept = 1e-9;

int t, n, m;
int a[100100], b[100100], c[100100];
vector<int> ans[100100];
int l[100100], r[100100];
int to[100100];


int main() {
    cin >> t;
    while(t--) {
        cin >> n >> m;
        for(int i=1; i<=n; i++) l[i] = r[i] = 0, ans[i].clear();
        for(int i=1; i<=n; i++) cin >> a[i];
        for(int i=1; i<=n; i++) cin >> b[i];
        for(int i=1; i<=m; i++) cin >> c[i], to[i] = 0;
        for(int i=1; i<=n; i++) {
            if(a[i] != b[i]) {
                ans[b[i]].push_back(i);
                r[b[i]]++;
            }
        }
        for(int i=m; i>=1; i--) {
            if(l[c[i]] != r[c[i]]) {
                to[i] = ans[c[i]][l[c[i]]++];
                b[to[i]] = a[to[i]];
            } else {
                if(i == m) {
                    for(int j=1; j<=n; j++)
                        if(b[j] == c[m]) {to[m] = j; break;}
                } else 
                to[i] = to[m];
            }
            if(!to[m]) {
                break;
            }
        }
        if(!to[m]) {
            cout << "NO" << endl;
            continue;
        }
        bool flag=1;
        for(int i=1; i<=n; i++)
            if(a[i] != b[i]) {
                cout << "NO" << endl;
                flag = 0;
                break;
            }
        if(flag) {
            cout << "YES" << endl;
            for(int i=1; i<=m; i++)
                cout << to[i] << ' ';
            cout << endl;
        }

    }
    return 0;
}