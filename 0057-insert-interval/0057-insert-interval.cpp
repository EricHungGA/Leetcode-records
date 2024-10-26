class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> results;
        int i = 0;
        int size = intervals.size();
        // first go through and add anything that appears totally before out new Interval
        while(i < size && intervals[i][1] < newInterval[0]){
            results.push_back(intervals[i]);
            i++;
        }
        
        // now i is stopped at the first place we have a overlap
        // loop through until we are totally past the overlaps
        while(i < size && intervals[i][0] <= newInterval[1]){
            newInterval[0] = min(intervals[i][0], newInterval[0]);
            newInterval[1] = max(intervals[i][1], newInterval[1]);
            i++;
        }
        results.push_back(newInterval);

        // now i is stopped at right after the overlaps end
        // so just add the remaining legitimate original intervals
        while(i < size){
            results.push_back(intervals[i]);
            i++;
        }
        return results;
    }
};