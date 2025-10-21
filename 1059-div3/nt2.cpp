/*
https://codeforces.com/problemset/problem/1594/C

Observe that here TC is O(nlgn) not O(n^2)
n/i iterations for each i.
sum(n/i) = O(nlgn)
*/
#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define READ_VEC(a, n) vector<ll> a(n); for (int i = 0; i < (n); i++) cin >> a[i];
#define PRINT_VEC(a, n) for (int i = 0; i < (n); i++) cout << a[i] << " "; cout << endl;

void solve() {
    int n; cin >> n;
    char c; cin >> c;
    string s; cin >> s;
    int j = n-1;
    while (j >= 0 && s[j] == c) j--;
    if (j < 0) {
        cout << 0 << endl;
        return;
    }
    for (int i = 1; i <= n; i++) {
        bool good = true;
        for (int j = i; j <= n; j += i) {
            if (s[j - 1] != c) {
                good = false;
                break;
            }
        }
        if (good) {
            cout << 1 << endl;
            cout << i << endl;
            return;
        }
    }
    cout << 2 << endl;
    cout << n << " " << n-1 << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int tt = 1;
    cin >> tt;
    cin.ignore();
    while (tt--) {
        solve();
    }
    return 0;
}