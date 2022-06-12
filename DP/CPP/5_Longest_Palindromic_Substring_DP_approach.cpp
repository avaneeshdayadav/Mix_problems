// For more clarrification on this approach use the video link : https://www.youtube.com/watch?v=UflHuQj6MVA
// I used that video for learning and is not my youtube video neither i am any promoting any channel.

class Solution {
public:
    string longestPalindrome(string s) {
        
        
        // DP soln
        int n = s.length();
        
        
        // If string length is 1 then return string itself.
        if(n == 1)
            return s;
        
        // Matrix of size nxn whose rows represents start indx and col represents end indx of any substring.
        vector<vector<int>> dp(n,vector<int>(n,0));
        
        
        // This arr of size 2 will keep record of i, j index of longest palindrome substring.
        int arr[2] = {-1,-1};
        
        
        // Mark all diagonal elements in matrix as 1. Bcoz single substr of length 1 itself is palindrome
        for(int i=0;i<n;i++)
            dp[i][i] = 1;
        
        
        // Mark all 2 length substr as 1 if their both characters are equal.
        for(int i=0;i<n-1;i++)
        {
            if(s[i] == s[i+1])
            {
                arr[0] = i;
                arr[1] = i+1;
                dp[i][i+1] = 1;
            }
        }
        
        
        int diff = 2;
        
        // Traverse diagonally in each iteration.
        while(diff < n)
        {
            for(int i=0,j=i+diff;j<n;i++,j++)
            {
                if(s[i] == s[j] && dp[i+1][j-1] == 1)
                {
                    dp[i][j] = 1;
                    if(j-i > arr[1]-arr[0])
                    {
                        arr[0] = i;
                        arr[1] = j;
                    }
                }
            }
            diff++;
        }
            
        
        // If index is -1 in arr, it means no palindrome found so return any single length string. Here I returned first character of given string.
        if(arr[0] == -1)
            return s.substr(0,1);
        
        
        // Otherwise return substring between i and j index values stored in arr.
        return s.substr(arr[0],arr[1]-arr[0]+1);
        
    }
};