class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int total_surplus = 0; // To check if a solution exists at all
        int current_tank = 0;  // To find the actual starting point
        int start_index = 0;

        for (int i = 0; i < gas.size(); i++) {
            int net_gain = gas[i] - cost[i];
            total_surplus += net_gain;
            current_tank += net_gain;

            // If we run out of gas at this stretch
            if (current_tank < 0) {
                // Pick the next station as the start
                start_index = i + 1;
                // Reset our tank for the new start
                current_tank = 0;
            }
        }

        // Rule 1: If total gas is less than total cost, return -1
        // Otherwise, start_index is guaranteed to be the answer
        return (total_surplus < 0) ? -1 : start_index;
    }
};