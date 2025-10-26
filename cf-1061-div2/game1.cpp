/*
https://codeforces.com/problemset/problem/1931/E

A -> S -> A -> S -> ... -> A (1 number (p) left := end)
A :- reduce number of digits
S :- increase number of digits, but remove one number
num_digits(p) >= (m+1) -> S wins
num_digits(p) <= m -> A wins

sort a in terms of increasing number of trailing zeros
A chooses from the last (j), and S  concatenates ajai ->
*/
#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define READ_VEC(a, n) vector<ll> a(n); for (int i = 0; i < (n); i++) cin >> a[i];
#define PRINT_VEC(a, n) for (int i = 0; i < (n); i++) cout << a[i] << " "; cout << endl;

struct MyObject {
    string value;
    MyObject(string v = "") : value(v) {} // allow implicit construction from string and default construction
 
    bool operator<(const MyObject& other) const {
        int cnta = 0, cntb = 0;
        for (int i = value.size() - 1; i >= 0; i--) {
            if (value[i] != '0') break;
            cnta++;
        }
        for (int i = other.value.size() - 1; i >= 0; i--) {
            if (other.value[i] != '0') break;
            cntb++;
        }
        return cnta < cntb;
    }
};

void clean(string& s) {
    // remove starting zeros
    int i = 0;
    while (i < s.size() && s[i] == '0') i++;
    s = s.substr(i);
    if (s.empty()) s = "0";
}

void solve() {
    int n, m; cin >> n >> m;
    vector<MyObject> a;
    for (int k = 0; k < n; k++) {
        string x; cin >> x;
        a.emplace_back(x);
    }
    sort(a.begin(), a.end());
    int j = n-1;
    int len = 0;
    while (j >= 0) {
        string t = a[j].value;
        reverse(t.begin(), t.end());
        clean(t);
        len += t.size();
        if (j >= 1) len += a[j-1].value.size();
        j -= 2;
    }
    if (len <= m) {
        cout << "Anna" << endl;
        return;
    }
    else {
        cout << "Sasha" << endl;
        return;
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