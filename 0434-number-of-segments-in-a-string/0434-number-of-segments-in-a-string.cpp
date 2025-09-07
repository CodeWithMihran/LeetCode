class Solution {
public:
    int countSegments(string s) {
        int segments = 0;
        int i=0, n=s.size();
        while(i < n){
            while(i<n && s[i] == ' '){
                i++;
            }
            if(i >= n){
                break;
            }
            segments++;
            while(i<n && s[i] != ' '){
                i++;
            }
        }
        return segments;
    }
};