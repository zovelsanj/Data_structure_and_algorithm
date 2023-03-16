/* 217. CHECK DUPLICACY OF INTERGERS IN A SEQUENCE OF ARRAY
Given an integer array 'nums', return true if any value appears at least twice in the array, 
and return false if every element is distinct.
Eg: Input: nums = [1,2,3,1]
    Output: true
*/

#include<iostream>
#include<vector>
using namespace std;

class Duplicate {
public:
    int duplicate=0;
    bool containsDuplicate(vector<int>& nums) 
    {
        for(int i=0; i<nums.size()-1; i++)
        {
            for(int j=i+1; j<nums.size(); j++)
            {
                if(nums.at(i) == nums.at(j))
                {
                    duplicate+=1;
                }
            }
        }
        if(duplicate>0) 
            return true;
        else 
            return false;
    }
};

int main(){
    Duplicate d;
    vector<int> arr {1, 0, 2, 1, 4, 4};
    cout<<d.containsDuplicate(arr)<<endl;
}