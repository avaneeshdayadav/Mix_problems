// Problem Link : https://leetcode.com/problems/valid-palindrome/

class Solution {
public:
    bool isPalindrome(string s) {
        
        string ret = conversion(s);
        int flag = 1;
        
        for(int i=0,j=ret.length()-1;i<=j;i++,j--)
        {
            if(ret[i] != ret[j])
            {
                flag=0;
                break;
            }
                
        }
        
        if(flag)
            return true;
        return false;
    }
    
    string conversion(string s)
    {
        string ans = "";
        
        for(int i=0;i<s.length();i++)
        {
            if((s[i]>='A' && s[i]<='Z') || (s[i]>='0' && s[i]<='9') || (s[i]>='a' && s[i]<='z'))
            {
                ans += (char)tolower(s[i]);
            }
        }
        
        return ans;
    }
};
