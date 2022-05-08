// Problem Link : https://leetcode.com/problems/trapping-rain-water/

// No two pointers method used.
// Can be optimized further by using two pointer method reducing space complexity to O(1).
// Time Complexity : O(n)
// Space Complexity : O(n)

class Solution {
public:
    int trap(vector<int>& arr) {
        
        int arrSize = arr.size(), leftMax = INT_MIN, rightMax = INT_MIN;
        int leftMaxArr[arrSize], rightMaxArr[arrSize], totalWater = 0;
        
        leftMaxArr[0] = rightMaxArr[arrSize-1] = 0;
        
        for(int i=1;i<arrSize;i++)
            leftMaxArr[i] = leftMax = max(leftMax,arr[i-1]);
            
        
        for(int i=arrSize-2;i>=0;i--)
            rightMaxArr[i] = rightMax = max(rightMax,arr[i+1]);
        
        
        for(int i=0;i<arrSize;i++)
        {
            int amtOfWaterAtThisElm = min(leftMaxArr[i], rightMaxArr[i]) - arr[i];
            if(amtOfWaterAtThisElm > 0)
                totalWater += amtOfWaterAtThisElm;
        }
        
        return totalWater;
    }
};
