/* Given a string, find the longest substring which is palindrome. For example, if the given string is
  “forgeeksskeegfor”, the output should be “geeksskeeg”.
  The time complexity of the Dynamic Programming based solution is O(n^2) and it requires O(n^2) extra space. We can
  find the   longest palindrome substring in (n^2) time with O(1) extra space with this iterative method. The idea is to        generate all even length and odd length palindromes and keep track of the longest palindrome seen so far.

Step to generate odd length palindrome:
Fix a centre and expand in both directions for longer palindromes.

Step to generate even length palindrome
Fix two centre ( low and high ) and expand in both directions for longer palindromes.

 */

/**
 * Author: Tanmay Jha
 * Date: 04/07/2018
 * Email: tanmay.jha1@gmail.com
 */

#include<bits/stdc++.h>

using namespace std;

void maxSubstringPallindrome(string x){
    int max_length=1;
    int start=0;
    int low=0,high=0;
    for(int i=1;i<x.length();i++)
    {
        //for even length
        low=i-1;
        high=i;
        while(low>=0&&high<=x.length()&&x[low]==x[high])
        {
            if(high-low+1>max_length)
            {
                start=low;
                max_length=high-low+1;
            }
            high++;
            low--;
        }
        //for odd length
        low=i-1;
        high=i+1;
        while(low>=0&&high<=x.length()&&x[low]==x[high])
        {
            if(high-low+1>max_length)
            {
                start=low;
                max_length=high-low+1;
            }
            high++;
            low--;
        }
    }
    cout<<"Longest Length pallindrome is: ";
    cout<<x.substr(start,max_length);
    cout<<endl<<"Length:"<<max_length;
}
                
                

int main()
{
    string x;
    getline(cin,x);
    maxSubstringPallindrome(x);
    cout<<endl;
    return 0;
} 


