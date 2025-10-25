/*
https://codeforces.com/problemset/problem/1601/A
*/
#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define READ_VEC(a, n) vector<ll> a(n); for (int i = 0; i < (n); i++) cin >> a[i];
#define PRINT_VEC(a, n) for (int i = 0; i < (n); i++) cout << a[i] << " "; cout << endl;

void solve() {
    int n; cin >> n;
    int cnts[30] = {0}; // cnts[0] = cnt of 0th bit as 1
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        for (int b = 0; b <= 29; b++) {
            cnts[b] += ((x >> b) & 1);
        }
    }
    int g = 0;
    for (int i = 0; i < 30; i++) g = gcd(g, cnts[i]);
    if (g == 0) {
        for (int k = 1; k <= n; k++) cout << k << " ";
        cout << endl;
    }
    else {
        for (int i = 1; i <= g; i++) {
            if (g % i == 0) cout << i << " ";
        }
        cout << endl;
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