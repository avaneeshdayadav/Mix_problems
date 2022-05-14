// Problem Link : https://leetcode.com/problems/longest-consecutive-sequence/

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        if(nums.size() == 0)
            return 0;
        else if (nums.size() == 1)
            return 1;
        
        // Sort the nums.
        sort(nums.begin(),nums.end());
        
        // Temp vector to store without any duplicates.
        vector<int> temp;
        temp.push_back(nums[0]);
        
        
        // Storing without duplicates in temp vector.
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i] != nums[i-1])
                temp.push_back(nums[i]);
        }
        
        
        int maxConsLen = 1, prevElm = 0, count = 0;
        
        for(auto it : temp)
        {
            if(it - prevElm == 1)
                count++;
            else
            {
                maxConsLen = max(maxConsLen,count);
                count = 1;
            }
            prevElm = it;
        }
        
        return max(maxConsLen,count);
        
    }
};