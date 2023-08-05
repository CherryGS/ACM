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

int t;
int n, m;
vector<int> q[100100];
int num[100100];
int ans[100100];


int main() {
    cin >> t;
    while(t--) {
        bool flag = 0;
        cin >> n >> m;
        int k, r;
        for(int i=1; i<=m; i++) q[i].clear();
        for(int i=1; i<=n; i++) num[i] = 0;

        for(int i=1; i<=m; i++) {
            cin >> k;
            for(int j=1; j<=k; j++) {
                cin >> r;
                q[i].push_back(r);
            }
        }

        for(int i=1; i<=m; i++)
            if(q[i].size() == 1) {
                r = q[i][0];
                ++num[r];
                if(num[r] > (m+1)/2) {flag = 1; break;}
                ans[i] = r;
            }
        
        if(!flag)
        for(int i=1; i<=m; i++)
            if(q[i].size() > 1) {
                for(int j=0; j<q[i].size(); j++)
                    if(num[q[i][j]] < (m+1)/2) {
                        ++num[q[i][j]];
                        ans[i] = q[i][j];
                        break;
                    }
            }
        if(flag) cout << "NO" << endl;
        else {
            cout << "YES" << endl;
            for(int i=1; i<=m; i++)
                cout << ans[i] << ' ';
            cout << endl;
        }
    }    
    return 0;
}