// Problem Link : https://leetcode.com/problems/container-with-most-water/

class Solution {
public:
    int maxArea(vector<int>& arr) {
        
        int L = 0, R = arr.size()-1, maxArea = INT_MIN;
        
        while(L < R)
        {
            int minOf_L_R = min(arr[L],arr[R]);
            
            maxArea = max(maxArea,minOf_L_R * (R-L));
            
            if(arr[L] == minOf_L_R)
                L++;
            else
                R--;   
        }
        
        return maxArea;
    }
};
