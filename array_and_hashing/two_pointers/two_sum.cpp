/*167. Two Sum II - Input Array Is Sorted
Given a 1-indexed array of integers numbers that is already sorted in non-decreasing order, find two numbers such that they add up to a specific target number. 
Let these two numbers be numbers[index1] and numbers[index2] where 1 <= index1 < index2 <= numbers.length.
Return the indices of the two numbers, index1 and index2, added by one as an integer array [index1, index2] of length 2.
The tests are generated such that there is exactly one solution. You may not use the same element twice.
Your solution must use only constant extra space.
Eg:
Input: numbers = [2,7,11,15], target = 9
Output: [1,2]
Explanation: The sum of 2 and 7 is 9. Therefore, index1 = 1, index2 = 2. We return [1, 2].
*/
#include<iostream>
#include<vector>
using namespace std;

class TwoSum {
public:
    vector<int> getSumIndices(vector<int>& numbers, int target) 
    {
        int ptr1 = 0;
        int ptr2 = numbers.size()-1;
        while (ptr1<ptr2 && numbers[ptr1]+numbers[ptr2]!=target)
        { 
            if (numbers[ptr1]+numbers[ptr2]>target)
                ptr2--;
            else
                ptr1++;
        }
        return {ptr1+1, ptr2+1};
    }
};

int main()
{
    vector<int> nums {2,7,11,15};
    int target = 9;
    TwoSum t;
    cout<<t.getSumIndices(nums, target).at(0)<<", "<<t.getSumIndices(nums, target).at(1)<<endl;
}
