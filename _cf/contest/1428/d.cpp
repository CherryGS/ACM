#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef const int& cint;

const int mod = 1e9+7;
const int inf_int = 0x7fffffff;
const ll inf_ll = 0x7fffffffffffffff;
const double ept = 1e-9;


typedef pair<int, int> pii;
int n;
int a[100100];
bool mp[101][101];
int r[100100];
vector<pii> e;

void dfs(cint loc, cint las, cint las_loc) {
    if(!loc) return;
    if(!a[loc]) dfs(loc-1, las, las_loc);
    else {
        if(a[loc] == 1) {
            e.push_back( {loc, las-1} );
            dfs(loc-1, las-1, loc);
        } 
        else if(a[loc] == 3){
            e.push_back( {loc, las-1} );
            e.push_back( {las_loc, las-1} );
            dfs(loc-1, las-1, loc);
        }
        else {
            e.push_back( {loc, las} );
            dfs(loc-1, las, loc);
        }
    }
}

void add(cint x, cint y) {
    e.push_back( {x, y} );
}

int main() {
    cin >> n;
    for(int i=1; i<=n; i++) cin >> a[i];
    queue<int> q[2];
    bool flag = 0;
    int st = n;
    for(int i=n; i>=1; i--) {
        if(a[i] == 3) {
            if(q[1].size()) {
                add(st, i);
                add(st, q[1].front());
                q[1].pop();
            } 
            else if(q[0].size()) {
                add(st, i);
                add(st, q[0].front());
                q[0].pop();
            }
            else {
                flag = 1;
                break;
            }
            q[1].push(i);
            --st;
        }
        else if(a[i] == 2) {
            if(q[0].size()) {
                int ss = q[0].front();
                q[0].pop();
                add(r[ss], i);
                q[1].push(i);
            }
            else {
                flag = 1;
                break;
            }
        }
        else if(a[i] == 1) {
            add(st, i);
            q[0].push(i);
            r[i] = st;
            --st;
        }
    }
    if(flag) cout << -1 << endl;
    else {
        cout << e.size() << endl;
        for(auto k: e) {
            cout << k.first << ' ' << k.second << endl;
            // mp[k.first][k.second] = 1;
        }
        // for(int i=1; i<=n; i++) {
        //     for(int j=1; j<=n; j++)
        //         cout << mp[i][j] << ' ';
        //         cout << endl;
        // }
    }
    return 0;
}