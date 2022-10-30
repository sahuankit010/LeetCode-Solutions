class Solution {
public:
    bool rotateString(string s, string goal) {
        s += s;
        int found = s.find(goal);
        return found != string::npos && s.size()/2 == goal.size();
    }
};