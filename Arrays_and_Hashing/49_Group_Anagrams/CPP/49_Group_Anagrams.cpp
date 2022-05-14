// Problem Link : https://leetcode.com/problems/group-anagrams/

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        unordered_map<string,vector<string>> anagrams;
        vector<vector<string>> ans;
        
        for(int i=0;i<strs.size();i++)
        {
            string tempStr = strs[i];
            sort(tempStr.begin(),tempStr.end());
            
            if(anagrams.find(tempStr) != anagrams.end())
                anagrams[tempStr].push_back(strs[i]);
            else
            {
                vector<string> tempVec;
                tempVec.push_back(strs[i]);
                anagrams[tempStr] = tempVec;
            }
        }
        
        for(auto it : anagrams)
            ans.push_back(anagrams[it.first]);
        
        return ans;
       
    }
};