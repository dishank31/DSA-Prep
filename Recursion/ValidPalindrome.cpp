#include<bits/stdc++.h>

using namespace std;

bool CheckPalindrome(string s)
{
    int start = 0;
    int end = s.size()-1;

    while(start<=end)
    {
        if(!isalnum(s[start]))
        {
            start++;
            continue;
        }
        else if(!isalnum(s[end]))
        {
            end--;
            continue;  
        }
        else if(tolower(s[start]) != tolower(s[end]))
        {
            return false;
        }
        else 
        {
            start++;
            end--;
        }
    }

    return true;
        
}

int main()
{
    string s;
    cout << "Enter string for palindrome check : ";
    getline(cin, s);
    cout << CheckPalindrome(s) << endl;
    return 0;
}
