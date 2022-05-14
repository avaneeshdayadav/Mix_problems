// Prolem Link : https://leetcode.com/problems/top-k-frequent-elements/

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        unordered_map<int,int> mp;
        vector<pair<int,int>> vec;
        vector<int> ans;
        
        for(int i=0;i<nums.size();i++)
        {
            if(mp.find(nums[i]) == mp.end())
                mp[nums[i]] = 1;
            else
                mp[nums[i]]++;
        }
        
        for(auto it : mp)
            vec.push_back({it.second,it.first});
        
        sort(vec.begin(),vec.end());
        
        for(int i=vec.size()-1,j=0;j<k;i--,j++)
            ans.push_back(vec[i].second);
        
        return ans;
    }
};