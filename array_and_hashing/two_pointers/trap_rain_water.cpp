/*42. Trapping Rain Water
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.
Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. 
In this case, 6 units of rain water (blue section) are being trapped.*/

#include<iostream>
#include<vector>
using namespace std;

class trapWater {
public:
    int trap(vector<int>& height) 
    {
        int ptr1 = 0;
        int ptr2 = height.size()-1;
        int total_water = 0, units_added = 0;
        int Lmax = height[ptr1]; 
        int Rmax = height[ptr2];
        while (ptr1<ptr2)
        {
            if (Lmax<Rmax)
            {
                ++ptr1;
                units_added = (Lmax-height[ptr1])<0?0:Lmax-height[ptr1];
                total_water += units_added;
                if (units_added==0)
                    Lmax = height[ptr1];
            }
            else
            {
                --ptr2;
                units_added = (Rmax-height[ptr2])<0?0:Rmax-height[ptr2];
                total_water += units_added;
                if (units_added==0)
                    Rmax = height[ptr2];
            }
        } 
        return total_water;
    }
};

int main()
{
    vector<int> height {0,1,0,2,1,0,1,3,2,1,2,1};
    trapWater t;
    cout<<"Total trapped water = "<<t.trap(height)<<" units"<<endl;
}
