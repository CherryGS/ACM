#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int n;
int arr[100100];

void quick_sort(const int&l, const int&r) {
    if(r <= l) return;
    int st = arr[l];
    int le = l, ri = r;
    while(le < ri) {
        while(arr[ri] >= st && ri > le) --ri;
        while(arr[le] <= st && le < ri) ++le;
        if(le != ri) swap(arr[le], arr[ri]);
    }
    swap(arr[l], arr[le]);
    quick_sort(l, le-1);
    quick_sort(le+1, r);
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> arr[i];
    quick_sort(1, n);
    for(int i = 1; i <= n; i++) cout << arr[i] << ' ';
    return 0;
}