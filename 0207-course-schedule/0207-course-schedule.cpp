class Solution {
private:
    // add function for checking for cycles
    bool hasCycle(int course, vector<vector<int>>&adj, vector<bool>&visited, vector<bool>&cur_path){
        // check for cycle meaning our course we are checking is already on the current path
        if(cur_path[course]) return true;
        // if we already visited this course then skip
        if(visited[course]) return false;

        // now update so that we've visited this course and added it into path
        cur_path[course] = true;
        visited[course] = true;

        // check the pre-reqs for the current course
        for(const auto& c : adj[course]){
            // run cycle check and if theres a cycle for the pre-req, then it is true here too
            if(hasCycle(c, adj, visited, cur_path)){
                return true;
            }
        }

        // if there were no cycles and no more pre-reqs for this course then backtrack
        cur_path[course] = false;
        return false;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // we need to lookout for cycles because its impossible to do the courses involved
        // first lets build an adjacency list to view all the requirements for a single course
        // more easily then having to search through the entire pre-reqs

        // example of how this looks after we add all pre-reqs
        // searchup course 1: returns
        // adj[0] = [3,4,7]
        // meaning for course 1 you need to take courses 3, 4, 7 first
        vector<vector<int>>adj(numCourses);
        for(const auto& course: prerequisites){
            // course[0] = course to take
            // course[1] = requirements
            adj[course[0]].push_back(course[1]);
        }


        // keep track of our current run through to make sure we don't hit a cycle
        vector<bool> cur_path(numCourses, false);
        // keep track of paths we've visited alr so we don't recalculate
        vector<bool> visited(numCourses, false);

        // now check every course
        for(int course = 0; course < numCourses; course++){
            if(!visited[course] && hasCycle(course, adj, visited, cur_path)){
                // meaning there is a cycle so finishing is impossible
                return false;
            }
        }
        
        // if none of them had a cycle we are good to go
        return true;
    }
};