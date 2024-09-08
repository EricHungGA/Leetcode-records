class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        // 1. create solution vector to store final outputs
        // 2. add prefix sum values by range, using first and last booking
        // 3. we will calculate prefix sum over each booking range, so only add
        // the positive value to the first element, and then subtract it from
        // one element to the right outside the range so that the prefix sum
        // carrying over for the next range will be accurate.
        // 4. Compute prefix sum simply from first to last element in the solutions vector
        vector<int>solution(n, 0);
        for(const auto& booking : bookings){
            int first = booking[0] - 1; // adjusted for our vector 
            int last = booking[1]; // this represents the one flight outside the range (adjusted by 2)
            int seats = booking[2];

            solution[first] += seats;
            if(last < n){
                solution[last] -= seats;
            }
        }
        for(int i = 1; i < solution.size(); i++){
            solution[i] += solution[i - 1];
        }
        return solution;
    }
};