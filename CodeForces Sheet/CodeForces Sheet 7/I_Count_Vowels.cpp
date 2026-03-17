#include<bits/stdc++.h>
using namespace std;
#define int long long

int vowels(string S, int i, int count)
{
    if(i == S.size()) return count;  // base case

    //Induction
    if(tolower(S[i]) == 'a' || tolower(S[i]) == 'e' || tolower(S[i]) == 'i' || tolower(S[i]) == 'o' || tolower(S[i]) == 'u') count++;
    return vowels(S, i+1, count);

    /*
        Also can be written as
        if(string("aeiouAEIOU").find(S[i]) != string::npos) count++;        npos (special character) = not found 
    */
}

signed main()
{
    string S;
    getline(cin, S);

    int count = vowels(S, 0, 0);
    cout << count;
}