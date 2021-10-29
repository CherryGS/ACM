#include <iostream>
#include <cstdio>
#include <algorithm>

int num[1001000];
int ans;

using namespace std;
int main() {
    int n;
    int a, b;
    cin >> n;
    for(int i = 1; i <= n-1; i++) {
        cin >> a >> b;
        num[a]++;
        num[b]++;
    }
    int cnt = 0;
    for(int i = 1; i <= n; i++) if(num[i] == 1) cnt++;
    cout << ((cnt+1) >> 1);
    return 0;
}