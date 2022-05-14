// Problem Link : https://leetcode.com/problems/top-k-frequent-elements/

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        unordered_map<int,int> mp;
        priority_queue<pair<int,int>> maxHeap;
        
        vector<int> ans;
        
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]]++;
        }
        
        for(auto it:mp)
        {
            maxHeap.push({it.second,it.first});
        }
        
        while(k--)
        {
            ans.push_back(maxHeap.top().second);
            maxHeap.pop();
        }
        
        return ans;
    }
};