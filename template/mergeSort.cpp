#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int n;
int arr[1001000];
int brr[1001000];

void merge_sort(const int& l, const int& r) {
    if(l >= r) return;
    int mid = (l+r) >> 1;
    merge_sort(l, mid);
    merge_sort(mid+1, r);
    int t1 = l, t2 = mid+1;
    int st = l;
    while(st <= r) {
        while((arr[t1] <= arr[t2] || t2 > r) && t1 <= mid) {brr[st] = arr[t1]; ++st; ++t1;}
        while((arr[t2] < arr[t1] || t1 > mid) && t2 <= r) {brr[st] = arr[t2]; ++st; ++t2;}
    }
    --st;
    while(st >= l) {arr[st] = brr[st]; st--;}
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> arr[i];
    merge_sort(1, n);
    for(int i = 1; i <= n; i++) cout << arr[i] << ' ';
    return 0;
}