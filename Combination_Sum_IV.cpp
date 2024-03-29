/*
Given an array of distinct integers nums and a target integer target, return the number of possible combinations that add up to target.

The test cases are generated so that the answer can fit in a 32-bit integer.

Example 1:

Input: nums = [1,2,3], target = 4
Output: 7
Explanation:
The possible combination ways are:
(1, 1, 1, 1)
(1, 1, 2)
(1, 2, 1)
(1, 3)
(2, 1, 1)
(2, 2)
(3, 1)
Note that different sequences are counted as different combinations.
*/

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<unsigned int> res(target+1,0);
        res[0]=1;
        for(int i=1;i<res.size();i++){
            for(int j=0;j<nums.size();j++){
                if(i-nums[j]>=0){
                    res[i]+=res[i-nums[j]];
                }
            }
        }
        return res[target];
    }
};
