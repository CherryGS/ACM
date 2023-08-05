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

struct node { 
    ll val; 
    vector<int> q; 
    bool operator < (const node&a) const {
        return val < a.val;
    }
};

int n;
vector<int> r[11];
int m;
vector<int> lim[100100];
unordered_map<string, bool> e;

void print(vector<int> r) {
    for(int u: r) cout << u << ' ';
    cout << endl;
}

ll cacu(vector<int> rr) {
    ll ans = 0;
    // print(rr);
    // cout << "-----------" << endl;
    for(int i=0; i<n; i++) {
        // cout << i << ' ' << rr[i] << endl;
        ans += r[i+1][rr[i]-1];
    }
    return ans;
}

bool check(vector<int> r) {
    string tmp;
    for(int u: r) {
        tmp += to_string(u) + ',';
    }
    // print(r);
    // cout << "---" << e[tmp] << ' ' << cacu(r) << endl;
    return !e[tmp];
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    vector<int> mx;
    for(int i=1; i<=n; i++) {
        int s;
        cin >> s;
        mx.push_back(s);
        for(int j=1; j<=s; j++) {
            int tmp;
            cin >> tmp;
            r[i].push_back(tmp);
        }
    }
    cin >> m;
    for(int i=1; i<=m; i++) {
        string tmp1;
        for(int j=1; j<=n; j++) {
            int tmp;
            cin >> tmp;
            lim[i].push_back(tmp);
            tmp1 += to_string(tmp) + ',';
        }
        e[tmp1] = 1;
    }
    ll ans = 0, id = 0, idx;
    if(check(mx)) print(mx);
    else {
        for(int i=1; i<=m; i++) {
            for(int j=0; j<n; j++) {
                if(lim[i][j] > 1) {
                    lim[i][j] -= 1;
                    if(check(lim[i])) {
                        ll r = cacu(lim[i]);
                        if(r > ans) {
                            ans = r;
                            id = i;
                            idx = j;
                        }
                    }
                    lim[i][j] += 1;
                }
            }
        }
        lim[id][idx] -= 1;
        print(lim[id]);
    }
    return 0;
}