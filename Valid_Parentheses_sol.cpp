/*Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order. */

//Example 1:Input: s = "()"
//Output: true


class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(int i=0;i<s.length();i++){
            if(s[i]=='(' || s[i]=='[' || s[i]=='{'){
                st.push(s[i]);
            }
            if(s[i]==')' || s[i]==']' || s[i]=='}'){
                char x=st.top();
                if(st.empty()){
                    return false;
                }
                else if(x =='(' && s[i]==')'){
                    st.pop();
                }
                else if(x =='[' && s[i]==']'){
                    st.pop();
                }else if(x =='{' && s[i]=='}'){
                    st.pop();
                }
                else{
                    st.push(s[i]);           //If I don't push element here, this type of Test Case will give Error -> "(])"
                }
            }
        }
        return st.empty();
    }
};
