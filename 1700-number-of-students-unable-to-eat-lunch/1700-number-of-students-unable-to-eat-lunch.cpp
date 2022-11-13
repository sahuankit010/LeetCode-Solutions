class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int zeros=0, ones=0;
        for(int i=0;i<students.size();i++) {
            if(students[i]) ones++;
            else zeros++;
        }
        for(int i=0;i<sandwiches.size();i++){
            if(sandwiches[i]) ones--;
            else zeros--;
            if(ones==-1 || zeros==-1) return sandwiches.size()-i;
        }
        return 0;
    }
};