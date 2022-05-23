class Solution {
public:
    int countSubstrings(string s)
    {
        int cnt = 0, n = s.length();
        
        for(int i=0;i<n;i++)
        {
            int L, R;
            L = R = i;
            
            while(L >= 0 && R < n && s[L] == s[R])
            {
                cnt++;
                L--;
                R++;
            }
                
        }
        
        for(int i=0;i<n;i++)
        {
            int L, R;
            L = i;
            R = i + 1;
            
            while(L >= 0 && R < n && s[L] == s[R])
            {
                cnt++;
                L--;
                R++;
            }
                
        }
        
        return cnt;
        
    }
};