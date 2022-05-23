class Solution {
    public int countSubstrings(String s) {
        
        int cnt = 0, n = s.length();
        
        for(int i=0;i<n;i++)
        {
            int L = i, R = i;
            
            while(L >= 0 && R < n && s.charAt(R) == s.charAt(L))
            {
                L--;
                R++;
                cnt++;
            }
        }
        
        
        for(int i=0;i<n;i++)
        {
            int L = i, R = i + 1;
            
            while(L >= 0 && R < n && s.charAt(R) == s.charAt(L))
            {
                L--;
                R++;
                cnt++;
            }
        }
        
        
        return cnt;
    }
    
    
}