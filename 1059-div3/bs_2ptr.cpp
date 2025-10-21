/*
https://codeforces.com/problemset/problem/1692/E
min deletions => max length of subarray
prefix array is sorted by default => apply binary search
*/
#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define READ_VEC(a, n) vector<ll> a(n); for (int i = 0; i < (n); i++) cin >> a[i];
#define PRINT_VEC(a, n) for (int i = 0; i < (n); i++) cout << a[i] << " "; cout << endl;

void solve() {
    int n, s; cin >> n >> s;
    READ_VEC(a, n);
    vector<int> pref(n+1);
    pref[0] = 0;
    for (int i = 1; i <= n; i++) {
        pref[i] = pref[i-1] + a[i-1];
    }
    int max_len = -1;
    int i = 0;
    while (i <= n) {
        int target = s + pref[i];
        int j = lower_bound(pref.begin(), pref.end(), target+1) - pref.begin();
        if (pref[j-1] == target) max_len = max(max_len, j - i);
        i++;
    }

    if (max_len == -1) {
        cout << -1 << endl;
    }
    else {
        cout << n + 1 - max_len << endl;
    }
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