#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int n, t;
int sum[108];
int a;

int main() {
    cin >> t;
    int m;
    while(t--) {
        int st = 0;
        a = 0;
        cin >> n;
        memset(sum, 0 ,sizeof sum);
        for(int i = 1; i <= n; i++) {
            cin >> m;
            sum[m]++;
            a = max(a, m);
        }
        for(int i = 1; i < a; i++) if(sum[i] && (!sum[i+1])) {cout << "NO" << endl; st = 1; break;}
        if(!st) cout << "YES" << endl;
    }

    return 0;
}