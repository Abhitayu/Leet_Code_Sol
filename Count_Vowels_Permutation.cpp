/*
Given an integer n, your task is to count how many strings of length n can be formed under the following rules:

Each character is a lower case vowel ('a', 'e', 'i', 'o', 'u')
Each vowel 'a' may only be followed by an 'e'.
Each vowel 'e' may only be followed by an 'a' or an 'i'.
Each vowel 'i' may not be followed by another 'i'.
Each vowel 'o' may only be followed by an 'i' or a 'u'.
Each vowel 'u' may only be followed by an 'a'.
Since the answer may be too large, return it modulo 10^9 + 7.

Example 1:

Input: n = 1
Output: 5
Explanation: All possible strings are: "a", "e", "i" , "o" and "u".

*/

class Solution {
public:
    int countVowelPermutation(int n) {
        vector<vector<long>> dp(n+1, vector<long>(5, 0));
        int mod = 1000000007;
        for(int i=0;i<5;i++){
            dp[1][i]=1;
        }
        for(int i=1;i<n;i++){
            dp[i+1][0] = (dp[i][1] + dp[i][2] + dp[i][4])%mod;
            dp[i+1][1] = (dp[i][0] + dp[i][2])%mod;
            dp[i+1][2] = (dp[i][1] + dp[i][3])%mod;
            dp[i+1][3] = (dp[i][2]);
            dp[i+1][4] = (dp[i][2] + dp[i][3])%mod;
        }
        int ans;
        for(int i=0;i<5;i++){
            ans=(ans+dp[n][i])%mod;
        }
       return ans; 
    }
};
