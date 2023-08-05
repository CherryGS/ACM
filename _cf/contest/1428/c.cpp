#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;

#define ll long long
#define ull unsigned long long
#define cint const int&
#define Pi acos(-1)

char a[2000001];
int ri[2000001];

int main() {
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--) {
        cin >> a;
        int l = strlen(a);
        for(int i = 0; i <= l; i++) ri[i] = i+1;
        int num = 1, it = ri[0], its = 0;
        while(num) {
            num = 0;
            its = 0;
            it = ri[0];
            while(ri[it] != l+1) {
                if(a[ri[it]-1] == 'B') {
                    ri[its] = ri[ri[it]];
                    num++;
                    it = ri[it];
                } else its = it;
                it = ri[it];
            }
        }
        int ans = 0, tmp = 0;
        while(tmp != l + 1) tmp = ri[tmp], ans++;
        cout << ans - 1 << endl;
    }    
    return 0;
}