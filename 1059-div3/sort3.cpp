/*
https://codeforces.com/problemset/problem/1704/C
*/
#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define READ_VEC(a, n) vector<ll> a(n); for (int i = 0; i < (n); i++) cin >> a[i];
#define PRINT_VEC(a, n) for (int i = 0; i < (n); i++) cout << a[i] << " "; cout << endl;

void solve() {
    ll n;
    int m;
    cin >> n >> m;
    READ_VEC(a, m);
    if (m == 1) {
        cout << 2 << endl; // n >= 5
        return;
    }
    sort(a.begin(), a.end());
    vector<ll> diff(m);
    for (int i = 0; i < m-1; i++) {
        diff[i] = a[i+1] - a[i] - 1;
    }
    diff[m-1] = n + a[0] - a[m-1] - 1;
    sort(diff.begin(), diff.end());
    ll cnt = m;
    int j = m-1;
    while (j >= 0 && diff[j] >= 2) {
        cnt++;
        for (int i = 0; i < j; i++) {
            cnt += min(4LL, diff[i]);
            diff[i] = max(0LL, diff[i] - 4);
        }
        j--;
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