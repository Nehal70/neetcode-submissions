class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        //build the graph
        vector<vector<int>> classGraph(numCourses);
        vector<int> inDegree(numCourses);
        queue<int> bfsQueue;
        vector<int> courseOrder;
        for (int i = 0; i < prerequisites.size(); i++) {
            classGraph[prerequisites[i][1]].push_back(prerequisites[i][0]);
            inDegree[prerequisites[i][0]] += 1;
        }
        //we have a graph, and the indegree
        //let's create an initial bfs queue
        for (int i = 0 ; i < numCourses; i++) {
            if (inDegree[i] == 0) {
                bfsQueue.push(i);
            }
        }
        //bfs
        while (bfsQueue.size()) { //queue isn't empty
            int course = bfsQueue.front(); bfsQueue.pop(); courseOrder.push_back(course);
            for (int i = 0; i < classGraph[course].size(); i++) {
                inDegree[classGraph[course][i]] -= 1;
                if (inDegree[classGraph[course][i]] == 0) {
                    //degree = 0;
                    bfsQueue.push(classGraph[course][i]);
                }
            }
        }
        for (int degree: inDegree) {
            if (degree != 0) {
                return {};
            }
        }
        return courseOrder;
    }
};
