// Problem Link : https://leetcode.com/problems/valid-anagram/

class Solution {
public:
    bool isAnagram(string s, string t) {
        
        if(s.length() != t.length())
            return false;
        
        int arr[26] = {0};
        
        for(int i=0;i<s.length();i++)
        {
            cout<<s[i]-'a'<<endl;
            arr[s[i]-'a']++;
        }
        
        for(int i=0;i<t.length();i++)
            arr[t[i]-'a']--;
        
        
        for(int i=0;i<26;i++)
        {
            if(arr[i] != 0)
                return false;
        }
        
        return true;
    }
};