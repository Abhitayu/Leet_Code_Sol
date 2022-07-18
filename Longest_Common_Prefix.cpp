/*Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

Example 1:

Input: strs = ["flower","flow","flight"]
Output: "fl"

*/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans;
        for(int i=0;i<strs[0].length();i++){
            char c = strs[0][i];
            bool flag = true;
            for(int j=1;j<strs.size();j++){
                if(c != strs[j][i]){
                    flag = false;
                    break;
                }
                flag = true;
            }
            if(flag){
                ans.push_back(c);
            }
            else{
                break;
            }
        }
        return ans;
    }
};
