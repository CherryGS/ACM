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

int n;

int sol(string tmp) {
    if(tmp[0] == '-') return -1;
    if(tmp.size() > 6) return -1;
    int ans = 0;
    for(int i=0; i<tmp.size(); i++) {
        ans *= 10;
        ans += tmp[i] - '0';
    }
    return ans;
}

int main() {
    vector<int> f;
    string tmp;
    cin >> n;
    for(int i=1; i<=n; i++) {
        cin >> tmp;
        f.push_back(sol(tmp));
    }
    sort(f.begin(), f.end());
    int st = -1;
    for(int u: f) {
        if(u >= 0) {
            if(u > st + 1) break;
            st = u;
        }
    }
    cout << st+1 << endl;
    return 0;
}
/*
5
1 1 2 3 4
*/