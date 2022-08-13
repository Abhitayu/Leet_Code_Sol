/*
You are given a string s and an array of strings words of the same length. Return all starting indices of substring(s) in s that is a concatenation of each word in words exactly once, in any order, and without any intervening characters.

You can return the answer in any order.

Example 1:

Input: s = "barfoothefoobarman", words = ["foo","bar"]
Output: [0,9]
Explanation: Substrings starting at index 0 and 9 are "barfoo" and "foobar" respectively.
The output order does not matter, returning [9,0] is fine too.

*/

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        unordered_map<string,int> um;
        int totalwords = words.size();
        int len = words[0].length();
        int n = s.length();
        vector<int> ans;
        for(int i=0;i<words.size();i++){
            um[words[i]]++;
        }
        for(int i=0;i<n-totalwords*len+1;i++){
            unordered_map<string,int> cp;
            int j=0;
            for(;j<totalwords;j++){
                string word = s.substr(i+j*len,len);
                if(um.find(word)!=um.end()){
                    cp[word]++;
                    if(cp[word]>um[word]){
                        break;
                    }
                }
                else break;
            }
            if(j==totalwords){
                ans.push_back(i);
            }
        }
        return ans;
    }
};
