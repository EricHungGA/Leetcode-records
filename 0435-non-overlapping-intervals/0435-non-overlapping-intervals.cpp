class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        // sort by END time instead of start time 
        // remove overlapping intervals
        sort(intervals.begin(),intervals.end(), [](const vector<int>& a, const vector<int>& b){
            return a[1] < b[1];
        });
        int count = 0;
        // this prev represents the most recent "non-removed" pair
        int prev = intervals[0][1];
        for(int i = 1; i < intervals.size(); i++){
            if(intervals[i][0] < prev){
                cout << "removing " << intervals[i][0] << "," << intervals[i][1] << endl;
                count++;
            } else {
                prev = intervals[i][1];
            }
        }
        return count;
    }
};