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
int n;
char s[300300], c;

int main() {
    cin >> t;
    while(t--) {
        cin >> n >> c;
        cin >> (s+1);
        bool flag = 0;
        int id;
        for(int i=1; i<=n; i++) {
            for(int j=i; j<=n; j+=i) {
                if(s[j] != c) {
                    break;
                }
                else if(j+i > n) {
                    flag = 1;
                    id = i;
                    break;
                }
            }
            if(flag) break;
        }
        bool is = 0;
        for(int i=1; i<=n; i++)
            if(s[i] != c) is = 1;
        if(!is) {
            cout << 0 << endl;
        }
        else if(flag) {
            cout << 1 << endl << id << endl;
        }
        else {
            cout << 2 << endl << n-1 << ' ' << n << endl;
        }
    }
    return 0;
}