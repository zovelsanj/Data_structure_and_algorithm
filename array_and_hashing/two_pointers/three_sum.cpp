/*15. 3Sum
Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.
Notice that the solution set must not contain duplicate triplets.
Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]
Explanation: 
nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
The distinct triplets are [-1,0,1] and [-1,-1,2]. Notice that the order of the output and the order of the triplets does not matter.*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution 
{
public:
    vector<vector<int>> threeSum(vector<int>& nums) 
    {
        int ptr1 = 0;
        int ptr2 = nums.size()-1;
        sort(nums.begin(), nums.end());
        vector<vector<int>> triplets;
        for (int i = 1; i < nums.size()-1; i++)
        {
            int sum = nums[ptr1]+nums[ptr2]+nums[i];
                if (sum>0)
                    --ptr2;
                else if (sum<0)
                    ++ptr1;
                else
                {
                    vector<int> v = {nums[ptr1], nums[ptr2], nums[i]};
                    triplets.push_back(v);
                    ++ptr1;
                    --ptr2;
                }
        }
        return triplets;
    }
};

int main()
{
    vector<int> nums {0,0,0,0};
    Solution s;
    vector<vector<int>> triplets = s.threeSum(nums);
    for (int i = 0; i < triplets.size(); i++)
    {
        for (int j = 0; j < triplets[i].size(); j++)
        {
            cout<< triplets[i][j]<<",";
        }
        cout<<endl;
    }
}