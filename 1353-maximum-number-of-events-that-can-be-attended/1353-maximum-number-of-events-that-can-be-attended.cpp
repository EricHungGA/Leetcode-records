class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        // first sort events by start time
        sort(events.begin(), events.end());
        // using min heap because we want to take advantage of the sequencing
        // to access the earliest ending event each day
        priority_queue<int, vector<int>, greater<int>> pq;

        int n = events.size(); // i liked using this notation from the previous hmw prob.
        int i = 0; // index for going through events
        int day = 0;
        int count = 0;

        while(i < n || !pq.empty()){
            // check if there are no events happening at the moment
            // if this is the case simply skip ahead in time to the next starting event
            if(pq.empty()){
                day = events[i][0]; // day will be skipped to this start point
            }

            // add all events into our heap that COULD start today
            while(i < n && events[i][0] <= day){
                pq.push(events[i][1]); // pushing end time
                i++;
            }

            // when an event has ended we need to remove it from our heap
            while(!pq.empty() && pq.top() < day){
                pq.pop();
            }

            // now we actually attend a possible event with the earliest end time
            if(!pq.empty()){
                pq.pop();
                count++;
            }

            // finally increment the day
            day++;
        }
        return count;
    }
};