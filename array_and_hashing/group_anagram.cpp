/* 49. GROUP ANAGRAM
Given an array of strings strs, group the anagrams together. You can return the answer in any order.
Eg: Input: strs = ["eat","tea","tan","ate","nat","bat"]
    Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
*/

#include<iostream>
#include<bits/stdc++.h>
#include<string>
using namespace std;

class groupAnagram
{
private:
    string getKey(string s)
    {
        vector<int > alphabet_count(26); //container for storing alphabets a...z
        for (int i = 0; i < s.size(); i++)
            alphabet_count[s[i]-'a']++;   //map a->0, b->1, ...

        string key = "";
        for (int i = 0; i < 26; i++)
            key.append(to_string(alphabet_count[i]+'a'));   //return a-z mapped from ascii values
        
        return key;
    }
public:
    vector<vector<string>> getAnagrams(vector<string>& strs) 
    {
        map <string , vector<string> > counter;  //hash map to store counts of alhabets in a string
        string key;
        vector<vector<string>> group_anagrams;
        for (int i = 0; i < strs.size(); i++)
        {
            key = getKey(strs[i]);
            counter[key].push_back(strs[i]);
        }
        for (auto it = counter.begin(); it != counter.end(); it++)
            group_anagrams.push_back(it->second); //push values of each keys in the map

        return group_anagrams;
    }
};

int main()
{
    vector<string > str {"ant", "tan", "sat", "tas", "ats"};
    vector<vector<string>> anagram;
    groupAnagram ga;
    anagram = ga.getAnagrams(str);
    for (auto i: anagram)
    {
        for (auto v: i)
            cout<<v<<endl;
    }
    
}