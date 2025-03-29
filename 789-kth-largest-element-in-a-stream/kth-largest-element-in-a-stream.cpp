class KthLargest {
private:
    priority_queue<int, vector<int>, greater<int>> pq;
    int k_; // Member variable
public:
    KthLargest(int k, vector<int>& nums) : k_(k) { // Initialize k_ with the parameter "k"
        for (int num : nums) {
            add(num);
        }
    }
    
    int add(int val) {
        if (pq.size() < k_) {
            pq.push(val);
        } else if (val > pq.top()) {
            pq.push(val);
            pq.pop();
        }
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */