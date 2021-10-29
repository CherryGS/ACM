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

int n;
int mp[2002][2002];
vector<int> ans;

int sol(cint x) {
    if(x <= 0) return x + n;
    if(x > n) return x - n;
    return x;
}

int main() {
    cin >> n;
    for(int i=1; i<=n/2; i++) {
        for(int j=1; j<=n; j++) {
            if(mp[sol(j-i)][i+1] < 2 && mp[sol(j+i)][i+1] < 2 && sol(j+i) != sol(j-i)) {
                if(!mp[j][i] && !mp[sol(j+i)][i] && !mp[sol(j-i)][i]) {
                    if(!mp[sol(j-i)][sol(j+i-j+i)] && !mp[sol(j+i)][sol(j+i-j+i)]) {
                        mp[sol(j-i)][i+1]++;
                        mp[sol(j+i)][i+1]++;
                        mp[j][i]++;
                        mp[sol(j+i)][i]++;
                        mp[sol(j-i)][i]++;
                        mp[sol(j-i)][sol(j+i-j+i)]++;
                        mp[sol(j+i)][sol(j+i-j+i)]++;
                        ans.push_back(j);
                        ans.push_back(sol(j-i));
                        ans.push_back(sol(j+i));

                    }
                    // cout << j << ' ' << sol(j-i) << ' ' << sol(j+i) << ' ' << i << endl;
                }
            }
        }
    }
    cout << ans.size() / 3 << endl;
    for(int i=0; i<ans.size(); i++) {
        cout << ans[i] << ' ';
        if(!((i+1)%3)) cout << endl;
    }
    return 0;
}