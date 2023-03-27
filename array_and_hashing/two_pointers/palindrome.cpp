/*125. Valid Palindrome
A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. 
Given a string s, return true if it is a palindrome, or false otherwise.
Eg:
Input: s = "A man, a plan, a canal: Panama"
Output: true
Explanation: "amanaplanacanalpanama" is a palindrome.
*/
#include<iostream>
// #include <ctype>
#include<string>
using namespace std;

class Palindrome {
public:
    bool isPalindrome(string s) 
    {
        int ptr1 = 0;
        int ptr2 = s.size() - 1;
        while (ptr1 < ptr2) {
            if (!isalnum(s[ptr1]) && ptr1 < ptr2) {
                ptr1++;
                continue;
            }
            if (!isalnum(s[ptr2]) && ptr1 < ptr2) {
                ptr2--;
                continue;
            }
            else if (tolower(s[ptr1]) != tolower(s[ptr2])) {
                return false;
            }
            ptr1++;
            ptr2--;
        }
        return true;
    }
};


int main()
{
    string s = "A man, a plan, a canal: Panama";
    string s1 = "race a car";
    Palindrome p;
    cout<<p.isPalindrome(s1)<<endl;
}