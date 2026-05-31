class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        //build the graph
        vector<vector<int>> courseGraph(numCourses);
        vector<int> inDegree(numCourses);
        queue<int> bfsQueue;
        for (int i = 0; i < prerequisites.size(); i++) {
            //add 1st number to 2nd number's list
            courseGraph[prerequisites[i][1]].push_back(prerequisites[i][0]);
            inDegree[prerequisites[i][0]] += 1;
        }
        //initial bfs queue
        for (int i = 0; i < numCourses; i++) {
            if (!inDegree[i]) {
                bfsQueue.push(i); //push the number of the course with 0 pre-reqs
            }
        }
        //bfs
        while (bfsQueue.size()) { //while queue isn't empty
            //take course and pop it from list
            int course = bfsQueue.front(); bfsQueue.pop();
            //update postreq's indegree
            for (int i = 0; i < courseGraph[course].size(); i++) {
                inDegree[courseGraph[course][i]] -= 1;
                if (inDegree[courseGraph[course][i]] == 0) {
                    bfsQueue.push(courseGraph[course][i]);
                }
            }
        }
        for (int degree: inDegree) {
            if (degree != 0) {
                return false;
            }
        }
        return true;
    }
};
