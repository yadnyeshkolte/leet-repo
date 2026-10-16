class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> sideone(numCourses);

        vector<int> ind(numCourses,0);
        for(auto &p: prerequisites) {
            sideone[p[1]].push_back(p[0]);
            ind[p[0]]++;
        }
        queue<int> qu;
        for(int i=0;i<numCourses;i++){
            if(ind[i]==0){
                qu.push(i);
            }
        }
        int count = 0;
        while (!qu.empty()) {
            int node = qu.front();
            qu.pop();
            count++;

            for (int neighbor: sideone[node]) {
                ind[neighbor]--;
                if (ind[neighbor] == 0) {
                    qu.push(neighbor);
                }
            }
        }

        return (count == numCourses);


    }
};