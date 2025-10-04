class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        unordered_map<int, int> freq;
        for (int b : barcodes) freq[b]++;

        priority_queue<pair<int, int>> pq;
        for (auto& [val, count] : freq) {
            pq.push({count, val});
        }

        vector<int> result;
        while (!pq.empty()) {
            auto [count1, val1] = pq.top(); pq.pop();

            if (!result.empty() && result.back() == val1) {
                if (pq.empty()) break; 
                auto [count2, val2] = pq.top(); pq.pop();

                result.push_back(val2);
                if (--count2 > 0) pq.push({count2, val2});
                pq.push({count1, val1});
            } else {
                result.push_back(val1);
                if (--count1 > 0) pq.push({count1, val1});
            }
        }

        return result;
    }
};