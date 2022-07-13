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

//One More Solution

class Solution {
public:
    bool isPalindrome(int x) {                 //Writing Comments for First Iteration
        long diviser=1;                        //For Example x=121
        if(x<0){
            return false;
        }
        while(x >= diviser*10){
            diviser = diviser*10;              //Diviser will go to 100
        }
        while(x){
            long a = x%10;                     //We'll Get 1
            long b = x/diviser;                //We'll Get b=121/100   (b=1)
            if(a != b){return false;}          //Checking a!=b (Which Means it is not Palindrome because First and Last digit is not Eqaul)
            x = x%diviser;                     //Now 121 Will Become 21
            x = x/10;                          //21/10 (Equal to 2)
            diviser = diviser/100;             //we are dividing by 100 because in every Iteration we are removing 2 digits first and last
        }
        return true;
    }
};
