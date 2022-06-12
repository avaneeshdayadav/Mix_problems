// Solution without using DP.
// Problem Link : https://leetcode.com/problems/longest-palindromic-substring/

class Solution {
public:
    string longestPalindrome(string s) {
        
        int n = s.length(), maxLen = INT_MIN ;
        int arr[2] = {-1,-1};
        
        if(n == 1)
            return s;
        
        
        for(int i=0;i<n;i++)
        {
            // Odd Len palindromes.
            int start = i-1, end = i+1;

            while(start >= 0 && end < n)
            {
                if(s[start] == s[end])
                {
                    if(end - start > arr[1]-arr[0])
                    {
                        arr[0] = start;
                        arr[1] = end;
                    }
                    start--;
                    end++;
                }
                else
                    break;
            }
            
            
            // Even Len palindrome.
            start = i;
            end = i+1;
            
            while(start >= 0 && end < n)
            {
                if(s[start] == s[end])
                {
                    if(end - start > arr[1]-arr[0])
                    {
                        arr[0] = start;
                        arr[1] = end;
                    }
                    start--;
                    end++;
                }
                else
                    break;
            }
                
        }
        
        if(arr[0] == -1)
            return s.substr(0,1);
        
        return s.substr(arr[0], arr[1] - arr[0] + 1);
    }
};