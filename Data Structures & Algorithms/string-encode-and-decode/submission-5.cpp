class Solution {
public:

    string encode(vector<string>& strs) {
        string result;
        for (string str: strs) {
            result += to_string(str.length());
            result += ",";
            result += str;
        }
        return result;
    }

    vector<string> decode(string s) {
        vector<string> result;
        int index = 0;
        while (index < s.size()) {
            //grab number
            string number;
            while (s[index] != ',') {
                number += s[index];
                index++;
            }
            //get length
            int num = stoi(number);
            //skip comma
            index += 1;
            //get new string
            string newstr = s.substr(index, num);
            //add to result vector
            result.push_back(newstr);
            //update index
            index = index + num;
        }
        return result;
    }
};
