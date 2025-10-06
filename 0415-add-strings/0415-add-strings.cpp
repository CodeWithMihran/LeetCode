class Solution {
public:
    string addStrings(string num1, string num2) {
        int i = num1.size()-1;
        int j = num2.size()-1;
        int carry = 0;
        string res="";

        while(i>=0 || j>=0 || carry){
            int x = 0;
            if(i>=0) x = num1[i--] - '0';
            int y = 0;
            if(j>=0) y = num2[j--] - '0';

            int sum = x + y + carry;
            res.push_back(char('0' + (sum%10)));
            carry = sum/10;
        }
        reverse(res.begin(),res.end());
        return res;
    }
};