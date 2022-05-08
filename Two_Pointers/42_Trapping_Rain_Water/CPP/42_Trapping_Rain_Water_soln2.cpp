// Problem Link : https://leetcode.com/problems/trapping-rain-water/

// Two pointers method used.
// Time Complexity : O(n)
// Space Complexity : O(1)

class Solution {
public:
    int trap(vector<int>& arr) {
        
        int L = 0, R = arr.size()-1, arrSize = arr.size(), leftMax, rightMax, totalWater = 0;
        leftMax = arr[0];
        rightMax = arr[arrSize-1];
            
        while(L < R)
        {
            if(leftMax < rightMax)
            {
                L++;
                leftMax = max(leftMax,arr[L]);
                
                // No need to check if substraction -ve as we know it will always be +ve.
                totalWater += leftMax - arr[L];
            }
            else
            {
                R--;
                rightMax = max(rightMax,arr[R]);
                
                // No need to check if substraction -ve as we know it will always be +ve.
                totalWater += rightMax - arr[R];
            }
            
        }
        
        return totalWater;
    }
};
