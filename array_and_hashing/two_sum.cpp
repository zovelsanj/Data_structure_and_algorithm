/* 1. TWO SUM
Given an array of integers 'nums' and an integer 'target', return indices of the two numbers such that they add up to target.
You may assume that each input would have exactly one solution, and you may not use the same element twice.
Eg: Input: nums = [2,7,11,15], target = 9
    Output: [0,1]
*/

#include<iostream>
#include<vector>
#include<map>
using namespace std;

class twoSum {
public:
    map<int, int> hashMap(vector<int>& nums)
        {
            map<int , int > counter;    //ordered map (as we will need hash map in order)
            for (int i=0; i< nums.size(); i++)
            {
                    counter[i]++;
            }
            return counter;
        }
    vector<int> bruteForce(vector<int>& nums, int target) 
    {
        vector<int> indices;
        for (int i = 0; i < nums.size()-1; i++)
        {
            for (int j = i+1; i < nums.size(); i++)
            {
                if (nums.at(i)+nums.at(j)==target)
                {
                    indices.push_back(i);
                    indices.push_back(j);
                }
            }
        }
        return indices;
    }
    vector<int> onePass(vector<int>& nums, int target) 
    {
        vector<int> indices;
        map<int , int > hash_map;
        vector <int> :: iterator itr;
        hash_map = hashMap(nums);
        for (int i = 0; i < nums.size(); i++)
        {
            if (hash_map.count(target-nums.at(i)))
                itr = find(nums.begin(), nums.end(), target-nums.at(i));
                indices.push_back(i);
                int j = distance(nums.begin(),itr);
                cout<<j<<endl;
                indices.push_back(j);
        }
        return indices;
    }
};

int main()
{
    vector<int> nums {2, 11, 15, 7};
    int target = 9;
    twoSum t;
    // cout<<t.onePass(nums, target)<<endl;
    cout<<t.onePass(nums, target).at(0)<<", "<<t.onePass(nums, target).at(1)<<endl;
}