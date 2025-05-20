class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int i=0, j=0, rotationCount = 0;
        int size = sandwiches.size();

        while(i < size && rotationCount <= (size-i)) {
            if(j>=size) {
                j=0;
            }

            if (sandwiches[i] == students[j]) {
                i++;
                students[j] = -1;
                rotationCount = 0;
            } else if(students[j] != -1) {
                rotationCount++;
            }
            j++;
        }
        return size - i;
    }
};