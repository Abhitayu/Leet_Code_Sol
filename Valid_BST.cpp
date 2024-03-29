/*
Given the root of a binary tree, determine if it is a valid binary search tree (BST).

A valid BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.

Example 1:


Input: root = [2,1,3]
Output: true
*/

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if(root == NULL){
            return true;
        }
        TreeNode* prev = NULL;
        stack<TreeNode*> st;
        while(root!=NULL || !st.empty()){
            while(root!=NULL){
                st.push(root);
                root=root->left;
            }
            root=st.top();
            st.pop();
            if(prev!=NULL && root->val <= prev->val){
                return false;
            }
            prev=root;
            root=root->right;
        }
        return true;
    }
};
