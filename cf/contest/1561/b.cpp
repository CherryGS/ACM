#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef const int& cint;

const int mod = 1e9+7;
const int inf_int = 0x7fffffff;
const ll inf_ll = 0x7fffffffffffffff;
const double ept = 1e-9;

int t, a, b;

int main() {
    cin >> t;
    while(t--) {
        cin >> a >> b;
        int s1 = (a+b) >> 1;
        int s2 = a+b-s1;
        vector<int> ans;
        // cout << s1 << '+' << s2 << endl; 
        for(int i=0; i<=a+b+1; i++) {
            if(!((s1-a+i)&1) && (s1-a+i) >= 0) {
                int r = (s1-a+i)/2;
                if(r <= b && r <= s1 && b-r <= s2) ans.push_back(i);
            }
            // cout << s2-a+i << "---" << i << endl;
            if(!((s2-a+i)&1) && (s2-a+i) >= 0 && s1 != s2){
                int r = (s2-a+i)/2;
                if(r <= b && r <= s2 && b-r <= s1) ans.push_back(i);
            }
        }
        cout << ans.size() << endl;
        for(int v: ans) {
            cout << v << ' ';
        }
        cout << endl;
    }
    return 0;
}