class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        st.push(-1); // base marker
        int longest = 0;

        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(') {
                st.push(i);
            } else {
                st.pop();
                if (st.empty()) {
                    st.push(i);
                } else {
                    longest = max(longest, i - st.top());
                }
            }
        }
        return longest;
    }
};