class Solution {
public:
    int compress(vector<char>& chars) {
            int idx = 0;
    for(int i=0; i<chars.size(); i++){
        char ch = chars[i];
        int count = 0;
        while(i<chars.size() && chars[i] == ch){
            i++;  count++;
        }
        if (count == 1){
            chars[idx++] = ch;
        }
        else{
            chars[idx++] = ch;
            string str = to_string(count);
            for(char dig: str){
                chars[idx++] = dig;
            }
        }
        i--;
    }
    chars.resize(idx);
    return idx;
    }
};