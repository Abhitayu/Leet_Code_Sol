/*
Given an integer array nums where the elements are sorted in ascending order, convert it to a height-balanced binary search tree.

A height-balanced binary tree is a binary tree in which the depth of the two subtrees of every node never differs by more than one.

Example 1:


Input: nums = [-10,-3,0,5,9]
Output: [0,-3,9,-10,null,5]
Explanation: [0,-10,5,null,-3,null,9] is also accepted:

*/

class Solution {
public:
    TreeNode* convert_bst(vector<int>&nums, int l, int r){
        if(l>r){                  //base case
            return nullptr;
        }
        int mid = (l+r)/2;            //finding mid  (l <- mid -> r)
        TreeNode* root = new TreeNode(nums[mid]);   
        root->left = convert_bst(nums,l,mid-1);   //passing the left part of mid (l <- mid)
        root->right = convert_bst(nums,mid+1,r); //passing the right part of mid (mid -> r)
        return root;
        
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n = nums.size();
        return convert_bst(nums,0,n-1);
    }
};
