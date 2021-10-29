#include <bits/stdc++.h>
using namespace std;

std::mt19937 rng(std::random_device{}());
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef const int& cint;
typedef pair<int, int> pii;
typedef const ll& cll;

#define ls (loc<<1)
#define rs ((loc<<1)|1)

const int mod = 1e9+7;
const int inf_int = 0x7fffffff;
const int hf_int = 0x3f3f3f3f;
const ll inf_ll = 0x7fffffffffffffff;
const double ept = 1e-9;

int t;
char s[101];


int main() {
    //freopen("1.in", "r", stdin);
    //cout.flags(ios::fixed); cout.precision(8);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> t;
    while(t--) {
        cin >> s;
        int n = strlen(s);
        int r = 0;
        for(int i=0; i<n; i++) {
            if(s[i] < s[r]) r = i;
        }
        cout << s[r] << ' ';
        for(int i=0; i<n; i++)
            if(i != r) cout << s[i];
            cout << endl;
    }
    return 0;
}