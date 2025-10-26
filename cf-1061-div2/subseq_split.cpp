/*
https://codeforces.com/problemset/problem/1919/C
when we are asked to obtimally split into two disjoint subsequences 
and the greedy choice depends on the last element in that subsequence, 
use two stacks to store the splits.
*/
#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define READ_VEC(a, n) vector<ll> a(n); for (int i = 0; i < (n); i++) cin >> a[i];
#define PRINT_VEC(a, n) for (int i = 0; i < (n); i++) cout << a[i] << " "; cout << endl;

void solve() {
    int n; cin >> n;
    READ_VEC(a, n);
    if (n <= 2) {
        cout << 0 << endl;
        return;
    }
    vector<int> b, c;
    c.push_back(INT_MAX);
    b.push_back(a[0]);
    if (a[1] <= a[0]) {
        b.push_back(a[1]);
    }
    else c.push_back(a[1]);
    int pen = 0;
    for (int i = 2; i < n; i++) {
        int b_last = b.back();
        int c_last = c.back();
        if (b_last > c_last) {
            if (a[i] <= c_last) c.push_back(a[i]);
            else if (a[i] <= b_last) b.push_back(a[i]);
            else {
                c.push_back(a[i]);
                pen++;
            }
        }
        else {
            if (a[i] <= b_last) b.push_back(a[i]);
            else if (a[i] <= c_last) c.push_back(a[i]);
            else {
                b.push_back(a[i]);
                pen++;
            }
        }
    }
    cout << pen << endl;
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int tt;
    cin >> tt;
    cin.ignore();
    while (tt--) {
        solve();
    }
    return 0;
}