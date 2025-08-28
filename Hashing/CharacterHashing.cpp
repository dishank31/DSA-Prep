#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    cout << "Enter string: ";
    getline(cin, s);

    int hashh[256] = {0};
    for (int i = 0; i < s.size(); i++) {
        hashh[s[i]]++;
    }

    int q;
    cout << "Enter number of queries: ";
    cin >> q;

    while (q--) {
        char ch;
        cout << "Enter character to query: ";
        cin >> ch;
        cout << hashh[ch] << endl;
    }
    return 0;
}
