/*128. Longest Consecutive Sequence
Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.
You must write an algorithm that runs in O(n) time.
Eg:
Input: nums = [0,3,7,2,5,8,4,6,0,1]
Output: 9
*/
#include<iostream>
#include<vector>
#include<unordered_set>
#include<algorithm>

using namespace std;
// ()
class longestConsecutiveSequence
{
public:
    int longestConsSeq(vector<int>& nums)
    {
        int seq_len = 0;
        int length = 0;
        unordered_set<string> s (nums.begin(), nums.end());
        for (auto &i: s)
        {
            if (!s.count(i-1))
            {
                length = 0;
                cout<<nums[i]-1<<" not in vector"<<endl;
                while (s.count(i+length))
                {
                   length ++;
                }
                seq_len = (length>seq_len)?length:seq_len;
            }
        }
        return seq_len;
    }
};

int main()
{
    vector<int> nums = {0,3,7,2,5,8,4,6,0,1};
    int output;
    longestConsecutiveSequence l;
    output = l.longestConsSeq(nums);
    cout<<output<<endl;    
}