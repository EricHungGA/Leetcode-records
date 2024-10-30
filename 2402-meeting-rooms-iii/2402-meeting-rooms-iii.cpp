class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        // track when each room is available or will become available based on time
        vector<long long> room_open_time(n,0); // 0 == available
        // track how many meetings each room has
        vector<int> meeting_count(n,0); // index represents room #

        // first we sort meetings by start time
        sort(meetings.begin(), meetings.end());

        for(const auto& meeting : meetings){
            int start = meeting[0]; 
            int end = meeting[1];
            bool room_found = false;

            // at the start of our loop we find the earliest a room is available
            long long earliest = LLONG_MAX;
            for(int i = 0; i < n; i++){
                earliest = min(earliest, room_open_time[i]);
            }

            int chosen_room = -1; // if it stays -1, then no room was available at requested start
            long long actual_start = start; // this will be modified to represent literal start time

            // next check if a room is free at our requested start time
            for(int i = 0; i < n; i++){
                if(room_open_time[i] <= start){
                    chosen_room = i;
                    break;
                }
            }

            if(chosen_room == -1){
                actual_start = earliest; 
                // need to make sure we use the lowest # room thats available if there are multiple
                // hence the break after we find the lowest
                for(int i = 0; i < n; i++){
                    if(room_open_time[i] == earliest){
                        chosen_room = i;
                        break;
                    }
                }
            }

            // now update our vectors per loop
            room_open_time[chosen_room] = actual_start + (end - start); // end - start is the length
            // so we increment our timer by the length (starting from the real start time)
            meeting_count[chosen_room]++;
        }

        // now we go through meeting count to find max
        // make sure to use the lowest room # for ties
        int max_meetings = 0;
        int result_room_index = 0;

        for(int i = 0; i < n; i++){
            if(meeting_count[i] > max_meetings){ // using only > so that it doesn't update on tie
                max_meetings = meeting_count[i];
                result_room_index = i;
            }
        }
        return result_room_index;

    }
};