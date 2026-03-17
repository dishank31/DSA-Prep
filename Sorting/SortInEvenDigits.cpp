/* 
Q) Given an array of integers, sort the array in increasing order of even digits present in number. 
If their is tie sort it based on value.
*/

#include<bits/stdc++.h>

using namespace std;

int EvenDigitCount(int el)
{
    int count = 0;
    int digit = 0;
    while(el > 0)
    {
        digit = el % 10;
        if(digit % 2 == 0) count++;
        el /= 10;
    }

    return count;
}

void solution(vector<int> arr)
{
    int n = arr.size();
    
    for(auto el : arr)
    {
        pair<int,int> nums[] = {{el, EvenDigitCount(el)}};
    }

    

}

int main()
{
    return 0;
}

