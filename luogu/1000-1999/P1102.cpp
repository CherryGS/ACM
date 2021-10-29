#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int n,c;
int arr[200010];

int sq(int st) {
    // >= st
    int l = 1, r = n, mid;
    while(l <= r) {
        mid = (l+r) >> 1;
        if(arr[mid] < st) l = mid + 1;
        else r = mid - 1;
    }
    return l;
}

int sq2(int st) {
    // > st
    int l = 1, r = n, mid;
    while(l <= r) {
        mid = (l+r) >> 1;
        if(arr[mid] <= st) l = mid + 1;
        else r = mid - 1;
    }
    return l;
}

int main() {
    unsigned long long ans = 0;
    cin >> n >> c;
    for(int i = 1; i <= n; i++) cin >> arr[i];
    sort(arr + 1, arr + 1 + n);
    for(int i = 1; i <= n; i++) ans += sq2(arr[i]-c) - sq(arr[i]-c);
    cout << ans;
    return 0;
}