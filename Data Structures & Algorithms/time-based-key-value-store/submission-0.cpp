class TimeMap {
public:

    unordered_map<string, vector<pair<string, int>>> backMap;

    TimeMap() {
        // unordered_map<string, vector<pair<string, int>>> backMap;
    }
    
    void set(string key, string value, int timestamp) {
        backMap[key].push_back({value, timestamp});
    }
    
    string get(string key, int timestamp) {
        int left = 0;
        int right = backMap[key].size() - 1; //backMap[key].back().second;
        string maxTime = "";
        while (left <= right) {
            int middle = (left + right) / 2;
            if (backMap[key][middle].second < timestamp) {
                //search right half, see if later timestamp possible
                maxTime = backMap[key][middle].first;
                left = middle + 1;
            } else if (backMap[key][middle].second > timestamp) {
                //search left half
                right = middle - 1;
            } else {
                //equal
                return backMap[key][middle].first;
            }
        }
        return maxTime;
    }
};
