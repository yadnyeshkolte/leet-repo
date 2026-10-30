class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<int> dx = {1,0,-1,0};
        vector<int> dy = {0,1,0,-1};
        queue<pair<int,int>> q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==0){
                    q.push({i,j});
                }
                if(mat[i][j]==1){
                    mat[i][j] = -1;
                }
            }
        }
        while(!q.empty()){
            auto [x,y] = q.front();
            q.pop();
            for(int i=0;i<4;i++){
                int nx = x+dx[i];
                int ny = y+dy[i];
                if(nx>=0 && ny>=0 && nx<m && ny<n && mat[nx][ny]==-1){
                    mat[nx][ny] = mat[x][y] + 1;
                    q.push({nx,ny});
                }
            }
        }
        return mat;
    }
};