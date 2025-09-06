class Solution {
public:
    string longestCommonPrefix(vector<string>& arr) {
        if(arr.empty()) return "";
            string prefix = arr[0];
            for(int i=1; i<arr.size(); i++){
                while(arr[i].find(prefix) != 0){
                    if(prefix.empty()) return "";
                    prefix = prefix.substr(0, prefix.size()-1);
                }
            }
        return prefix;
    }
};