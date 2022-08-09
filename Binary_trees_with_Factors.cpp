/*
Given an array of unique integers, arr, where each integer arr[i] is strictly greater than 1.

We make a binary tree using these integers, and each number may be used for any number of times. Each non-leaf node's value should be equal to the product of the values of its children.

Return the number of binary trees we can make. The answer may be too large so return the answer modulo 109 + 7.

Example 1:

Input: arr = [2,4]
Output: 3
Explanation: We can make these trees: [2], [4], [4, 2, 2]
*/

class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        unordered_map<int,long long int> um;
        long long int ans=0;
        sort(arr.begin(),arr.end());
        for(int i=0;i<arr.size();i++){
            um[arr[i]]=1;
        }
        for(int i=1;i<arr.size();i++){
            long long int count=0;
            auto it = um.find(arr[i]);
            for(int j=0;j<i;j++){
                if(arr[i]%arr[j]==0){
                    auto it2 = um.find(arr[j]);
                    auto it3 = um.find(arr[i]/arr[j]);
                    if(it3!=um.end()){
                        count+=(it2->second)*(it3->second);
                    }
                }
            }
            it->second+=count;
        }
        for(auto it:um){
            ans+= it.second;
        }
        ans=ans%1000000007;
        return ans;
    }
};
