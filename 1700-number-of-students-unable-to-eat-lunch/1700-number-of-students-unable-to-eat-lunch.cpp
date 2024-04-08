class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        while(students.size() != 0){
            vector<int> temp;
            temp = students;
            if(students[0] == sandwiches[0]){
                students.erase(students.begin());
                sandwiches.erase(sandwiches.begin());
            }
            else{
                int num = students[0];
                students.erase(students.begin());
                students.push_back(num);
                if(students == temp){
                    return students.size();
                }
            }
        }
        return 0;
    }
};