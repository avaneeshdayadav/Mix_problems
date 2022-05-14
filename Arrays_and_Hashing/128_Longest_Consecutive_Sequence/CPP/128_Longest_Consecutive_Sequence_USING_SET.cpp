// Problem Link : https://leetcode.com/problems/longest-consecutive-sequence/

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        if(nums.size() == 0)
            return 0;
        else if (nums.size() == 1)
            return 1;
        
        set<int> s;
        int maxConsLen = 1, prevElm = 0, count = 0;
        
        for(int i=0;i<nums.size();i++)
            s.insert(nums[i]);
        
        for(auto it : s)
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