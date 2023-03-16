/* 238. PRODUCT ARRAY EXCEPT SELF
Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].
The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.
You must write an algorithm that runs in O(n) time and without using the division operation.
Eg: Input: nums = [1,2,3,4]
    Output: [24,12,8,6]
*/

#include<iostream>
#include<vector>
using namespace std;

class productExceptSelf {
public:
    vector<int> divisionMethod(vector<int>& nums) 
    {
        vector<int> result;
        int all_product = 1;
        int contains_zero = 0;
        for (int i=0; i<nums.size(); i++)
        {
            if (nums.at(i) != 0)
            {
                all_product *= nums.at(i);
            }
            else
                contains_zero ++;
                continue;            
        }
        for (int i = 0; i < nums.size(); i++)
        {
            if (contains_zero==0)
                result.push_back(all_product/nums[i]);
            else if (contains_zero == 1)
            {
                if (nums.at(i) !=0)
                    result.push_back(0);
                else
                    result.push_back(all_product);
            }
            else
                result.push_back(0);
        }
        return result;
    }
    vector<int> productMethod(vector<int>& nums)
    {
        vector<int> result;
        int pre_product = 1;
        int post_product = 1;
        for (int i = 0; i < nums.size(); i++)
        {
            result.push_back(pre_product);
            pre_product *= nums.at(i);
        }
        for (int i = 0; i < nums.size(); i++)
        {
            result.at(nums.size()-1-i) *= post_product;
            post_product *= nums.at(nums.size()-1-i);
        }
        return result;
    } 
};

int main()
{
    vector<int> input_array {-1,1,0,-3,0};
    vector<int> output_array;
    productExceptSelf p;
    output_array = p.productMethod(input_array);
    for (int i = 0; i < output_array.size(); i++)
    {
        cout<<output_array[i]<<endl;
    }
}