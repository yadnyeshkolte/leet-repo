class Solution {
public:
    void reverseString(vector<char>& s) {
        revstring(s, 0, s.size()-1);
    }
private:
    void revstring(vector<char>& s, int i, int j){
        if(i>=j){
            return;
        }
        char k = s[i];
        s[i] = s[j];
        s[j] = k;
        revstring(s, i+1, j-1);
    }
};