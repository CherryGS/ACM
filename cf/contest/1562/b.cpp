#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef const int& cint;

const int mod = 1e9+7;
const int inf_int = 0x7fffffff;
const ll inf_ll = 0x7fffffffffffffff;
const double ept = 1e-9;

int t, k;
char s[51];

bool check(cint x) {
    if(x == 1) return 1;
    for(int i=2; i<=sqrt(x); i++) {
        if(!(x%i)) return 1;
    }
    return 0;
}

int main() {
    cin >> t;
    while(t--) {
        cin >> k;
        cin >> s;
        bool flag = 0;
        vector<int> ans;
        for(int i=0; i<k; i++) {
                if(check(s[i]-'0')) {
                    ans.push_back(i);
                    flag = 1;
                    break;
                }
        }
        if(!flag)
        for(int i=0; i<k && !flag; i++) {
            for(int j=i+1; j<k; j++) {
                if(check((s[i]-'0')*10+s[j]-'0')) {
                    ans.push_back(i);
                    ans.push_back(j);
                    flag = 1;
                    break;
                }
            }
            if(flag) break;
        }
        // cout << "------" << endl;
        cout << ans.size() << endl;
        for(int v: ans) {
            cout << s[v];
        }
        cout << endl;
        // cout << "-----" << endl;
    }
    return 0;
}