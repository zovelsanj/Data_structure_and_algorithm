/* 242. ANAGRAM
Given two strings 's' and 't', return true if 't' is an anagram of 's', and false otherwise.
An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once
Eg: Input: s = "anagram", t = "nagaram"
    Output: true
*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Anagram {
public:
    map<char, int> mapping(string& str)
    {
        map<char , int > counter;    //ordered map (as we will need hash map in order)
        for (char i : str)
        {
            if(i != ' ')
                counter[i]++;
        }
        return counter;
    }
    bool isAnagram(string& s, string& t) 
    {
        if(s.length() != t.length())
            return false;
        map<char , int > map1, map2;
        map1 = mapping(s);
        map2 = mapping(t);
        if(map1==map2) 
            return true;
        else 
            return false;
    }
};

int main()
{
    // string s = "anagram";
    // string t = "margana";
    string s, t;
    cout<<"Input first string: "<<endl;
    getline (cin, s);
    cout<<"Input second string: "<<endl;
    getline(cin, t);
    Anagram h;
    cout<<h.isAnagram(s, t)<<endl;
}