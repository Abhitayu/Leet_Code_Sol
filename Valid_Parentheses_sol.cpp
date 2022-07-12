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
