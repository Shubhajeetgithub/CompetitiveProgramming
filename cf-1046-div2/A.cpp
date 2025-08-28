#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;

bool check_possible(int a, int b) {
    //assuming a <= b
    int max_b = (a + 1) * 2;
    if (b <= max_b) {
        return true;
    }
    else return false;
}

void solve() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if (c < a || d < b) {
        cout << "NO\n";
        return;
    }
    //checking for a, b
    bool check = true;
    if (a == 0 || b == 0) {
        if (max(a, b) >= 3) check = false;
    }
    else {
        if (a <= b && !check_possible(a, b)) check = false;
        else if (a > b && !check_possible(b, a)) check = false;
    }
    if (!check) {
        cout << "NO\n";
        return;
    }
    check = true;
    a = c-a;
    b = d-b;
    if (a == 0 || b == 0) {
        if (max(a, b) >= 3) check = false;
    }
    else {
        if (a <= b && !check_possible(a, b)) check = false;
        else if (a > b && !check_possible(b, a)) check = false;
    }
    if (!check) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    return;

}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int tt;
    cin >> tt;
    cin.ignore();
    while (tt--) {
        solve();
        fflush(stdout);
    }
    return 0;
}