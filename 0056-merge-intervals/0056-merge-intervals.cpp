class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // edge case
        if(intervals.empty()) return {};
        // assume the input may be out of order
        // first sort the input (could use priority queue)
        // then compare e1 to s2 and so on 
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> results;
        
        results.push_back(intervals[0]);

        for(int i = 0; i < intervals.size(); i++){
            if(intervals[i][0] <= results.back()[1]){
                // using max in case the end of #2 is actually smaller than end of #1
                results.back()[1] = max(results.back()[1], intervals[i][1]);
            } else {
                results.push_back(intervals[i]);
            }
        }
        return results;
    }
};