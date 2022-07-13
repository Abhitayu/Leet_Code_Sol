/*Given an integer x, return true if x is palindrome integer.

An integer is a palindrome when it reads the same backward as forward.

For example, 121 is a palindrome while 123 is not.

Example:  Input: x = -121
Output: false
Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome. */

class Solution {
public:
    bool isPalindrome(int x) {
        int b=x;
        long a=0,rem;
        if(x<0){
            return false;
        }
        while(b>0){
            rem=b%10;
            a=a*10+rem;
            b=b/10;
        }
        if(a==x){
            return true;
        }
        return false;
    }
};
