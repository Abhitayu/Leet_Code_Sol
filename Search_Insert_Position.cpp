/*Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You must write an algorithm with O(log n) runtime complexity.

Example 1:

Input: nums = [1,3,5,6], target = 5
Output: 2
*/

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int begin=0,mid;
        int end=nums.size();
        if(target>nums[end-1]){
            return end;
        }
        if(target<nums[begin]){
            return begin;
        }
        while(begin<=end){
            mid=(end+begin)/2;
            if(target==nums[mid]){
                return mid;
            }
            else if(target>=nums[mid]){
                begin=mid+1;
            }
            else{
                end=mid-1;
            }
        }
        return begin;
    }
};
