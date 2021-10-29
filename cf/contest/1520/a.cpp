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
int n;
int num[27];
string s;

int main() {
    cin >> t;
    while(t--) {
        memset(num, 0, sizeof num);
        cin >> n;
        char a;
        bool flag = 0;
        cin >> s;
        for(int i=0; i<n; i++) if(!i || s[i] != s[i-1]){
            ++num[s[i]-'A'];
            if(num[s[i]-'A'] > 1) flag = 1;
        }
        if(flag) cout << "NO" << endl;
        else cout << "YES" << endl;
    }
    return 0;
}