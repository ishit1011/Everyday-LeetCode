class Solution {
public:
    // Function to calculate incremental gain when adding one student
    double calculateGain(int pass, int total) {
        double before = (double)pass / total;
        double after = (double)(pass + 1) / (total + 1);
        return after - before;
    }

    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        int n = classes.size();

        // Define a max-heap (priority queue) that prioritizes the incremental gain in the ratio
        priority_queue<pair<double, pair<int, int>>> maxHp;

        // Push initial classes into the max-heap
        for (int i = 0; i < n; i++) {
            double gain = calculateGain(classes[i][0], classes[i][1]);
            maxHp.push({gain, {classes[i][0], classes[i][1]}});
        }

        // Distribute extra students to maximize the average ratio
        while (extraStudents--) {
            auto [_, currClass] = maxHp.top();
            maxHp.pop();

            int pass = currClass.first + 1;
            int total = currClass.second + 1;

            // Recalculate gain and push the updated class back into the heap
            maxHp.push({calculateGain(pass, total), {pass, total}});
        }

        // Calculate the final average ratio
        double sum = 0.0;
        while (!maxHp.empty()) {
            auto currClass = maxHp.top().second;
            maxHp.pop();
            sum += (double)currClass.first / currClass.second;
        }

        return sum / n; // Return the overall average ratio
    }
};