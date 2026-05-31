class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
    int n = position.size();
    vector<pair<int, double>> cars;
    for (int i = 0; i < n; i++) {
        // Store {position, time_to_target}
        cars.push_back({position[i], (double)(target - position[i]) / speed[i]});
    }

    // Sort by position descending (closest car first)
    sort(cars.rbegin(), cars.rend());

    stack<double> fleets;
    for (auto& car : cars) {
        double currentTime = car.second;
        // If stack is empty or this car takes LONGER than the fleet ahead,
        // it starts a new fleet.
        if (fleets.empty() || currentTime > fleets.top()) {
            fleets.push(currentTime);
        }
        // If currentTime <= fleets.top(), it joins the fleet ahead (do nothing)
    }

    return fleets.size();
}
};
