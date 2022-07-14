/*Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes the value to go outside the signed 32-bit integer range [-231, 231 - 1], then return 0.

Assume the environment does not allow you to store 64-bit integers (signed or unsigned). 

Example 1:

Input: x = 123
Output: 321
*/

class Solution {
public:
    int reverse(int x) {
        int reverse=0;
        while(x!=0){
            int rem = x%10;
            if((reverse > INT_MAX/10) || (reverse < INT_MIN/10)){         //checking if the value has not crossed INT Max or INT Min
                return 0;
            }
            reverse = reverse*10+rem;
            x = x/10;
        }
        return reverse;
    }
};
