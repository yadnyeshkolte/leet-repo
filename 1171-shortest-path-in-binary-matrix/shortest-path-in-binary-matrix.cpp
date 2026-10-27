class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if(grid[0][0]==1 || grid[n-1][n-1]==1){
            return -1;
        }
        if(grid[0][0]==0 && grid.size()==1){
            return 1;
        }
        vector<int> dx = {-1, -1, -1, 0, 0, 1, 1, 1};
        vector<int> dy = {-1, 0, 1, -1, 1, -1, 0, 1};
        queue<vector<int>> q;
        q.push({0,0,1});
        grid[0][0]=1;
        while(!q.empty()){
            vector<int> dir = q.front();
            int x = dir[0];
            int y = dir[1];
            int steps = dir[2];
            q.pop();
            for(int i=0;i<8;i++){
                int nx = x+dx[i];
                int ny = y+dy[i];
                if(nx==n-1 && ny==n-1){
                    return steps+1;
                }
                if(nx>=0 && ny>=0 && nx<=n-1 && ny<=n-1){
                    if(grid[nx][ny]==0){
                        if(nx==n-1 && ny==n-1){
                            return steps;
                        }
                        grid[nx][ny]=1;
                        q.push({nx,ny,steps+1});
                    }
                }
            }
        }
        return -1;
    }
}; 