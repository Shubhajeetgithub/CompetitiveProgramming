/*
https://codeforces.com/problemset/problem/1729/D
*/
#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define READ_VEC(a, n) vector<ll> a(n); for (int i = 0; i < (n); i++) cin >> a[i];
#define PRINT_VEC(a, n) for (int i = 0; i < (n); i++) cout << a[i] << " "; cout << endl;

void solve() {
    int n; cin >> n;
    READ_VEC(x, n);
    READ_VEC(y, n);
    vector<ll> diff(n);
    for (int i = 0; i < n; i++) diff[i] = y[i] - x[i];
    sort(diff.begin(), diff.end());
    int cnt = 0;
    int i = 0, j = n-1;
    while (i < j) {
        if (diff[j] + diff[i] >= 0) {
            cnt++;
            i++;
            j--;
        }
        else i++;
    }
    cout << cnt << endl;
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