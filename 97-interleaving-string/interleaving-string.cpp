class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.length()+s2.length()!=s3.length()){
            return false;
        }
        vector<vector<int>> memo(s1.length()+1, vector<int>(s2.length()+1, -1));
        
        return check(s1, 0 ,s2, 0, s3, 0, memo);
    }
    bool check(string s1, int i, string s2, int j, string s3, int k, vector<vector<int>>& memo){
        if(k==s3.length()){
            return true;
        }
        if(memo[i][j]!=-1){
            return memo[i][j]==1;
        }
        int canform = false;

        if(i<s1.length() && s1[i]==s3[k]){
            canform = check(s1, i+1,s2, j, s3, k+1, memo);
        }

        if(!canform && j<s2.length() && s2[j]==s3[k]){
            canform = check(s1, i,s2, j+1, s3, k+1, memo); 
        }
        memo[i][j] = canform ? 1:0;
        return canform;
    }
};