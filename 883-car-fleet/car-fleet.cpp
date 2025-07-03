class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int size = position.size();
        vector<pair<int, double>> cars;

        for(int i=0; i<size; i++) {
            double time = (double)(target - position[i])/ speed[i];
            cars.push_back({position[i], time});
        }

        sort(cars.rbegin(), cars.rend());

        int fleets = 0;
        double latestTime = 0;

        for(int i=0; i<size; i++) {
            if(cars[i].second > latestTime) {
                fleets++;
                latestTime = cars[i].second;
            }
        }

        return fleets;

    }
};