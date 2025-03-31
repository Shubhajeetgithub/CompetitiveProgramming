#include <bits/stdc++.h>
using namespace std;

void concatWord() {
    string s;
    cin >> s;
    string t;
    if (s.size() <= 10) {
        t = s;
    }
    else {
        t += s[0];
        t += to_string(s.size() - 2);
        t += s[s.size() - 1];
    }
    cout << t << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tt; //number of lines of test cases
    cin >> tt;
    while (tt--) concatWord();
}