/*
https://codeforces.com/problemset/problem/1879/C
*/
#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define READ_VEC(a, n) vector<ll> a(n); for (int i = 0; i < (n); i++) cin >> a[i];
#define PRINT_VEC(a, n) for (int i = 0; i < (n); i++) cout << a[i] << " "; cout << endl;
const int NUM = 998244353;
void solve() {
    string s;
    cin >> s;
    int n = s.size();
    ll min_len = 0;
    ll min_op = 1;
    int cnt = 1;
    for (int i = 1; i < n; i++) {
        if (s[i] == s[i-1]) {
            cnt++;
        }
        else {
            min_len += (cnt - 1);
            min_op = (min_op * cnt) % NUM;
            cnt = 1;
        }
    }
    min_len += (cnt - 1);
    min_op = (min_op * cnt) % NUM;
    for (int j = min_len; j >= 1; j--) {
        min_op = (min_op * j) % NUM;
    }
    cout << min_len << " " << min_op << endl;
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