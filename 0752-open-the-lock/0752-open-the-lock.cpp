class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
    // store record for deadends to search faster
    unordered_set<string> deadend_set(deadends.begin(),deadends.end());
    
    // edge case for '0000' being deadend
    if(deadend_set.count("0000")) return -1;

    // edge case for '0000' being target
    if(target == "0000") return 0;

    // queue for combinations, pair using {string combo, # of moves to arrive here}
    queue<pair<string, int>>q;
    q.push({"0000", 0}); // starting val with 0 moves 

    // to avoid repeats, keep track of all the combos we've seen
    unordered_set<string> seen;
    seen.insert("0000");

    // BFS so run until our queue is empty
    while(!q.empty()){
        string curr = q.front().first; // ex. current = "0000"
        int moves = q.front().second; // ex. moves = 0 at beginning
        q.pop();

        // run loop for each digit (4 total) on the lock
        for(int i = 0; i < 4; i++){
            // each wheel can only spin in two ways: up (+1) or down(-1)
            for(int diff : {1, -1}){
                string next = curr;
                // ASCII value ex:
                // if next[i] = 4 for example then its ASCII value 52, '0' is ASCII 48
                // next[i] = 52 - 48 + [1 or -1] % 10, then afterwards add back 48 to get
                // the final ASCII value 
                next[i] = ((next[i] - '0' + diff + 10) % 10) + '0';

                //scenario where the move is valid being not in deadset or seen already
                if(!deadend_set.count(next) && !seen.count(next)){
                    if(next == target){
                        // if target has been reached
                        // + 1 for this current move
                        return moves + 1;
                        }
                        // otherwise add into our history log
                        seen.insert(next);
                        // now add into queue
                        q.push({next,moves + 1});
                    }
                }
            }
        }
    // in the scenario where we exited the loop aka no solutions were found
    return -1;
    }
};