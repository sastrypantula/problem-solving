// copied solution will again visit later

class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        if (heightMap.empty() || heightMap[0].empty()) {
            return 0;
        }

        int m = heightMap.size();
        int n = heightMap[0].size();
        if (m < 3 || n < 3) {
            return 0;
        }

        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> heap;

        vector<vector<bool>> visited(m, vector<bool>(n, false));

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == 0 || i == m - 1 || j == 0 || j == n - 1) {
                    heap.push({heightMap[i][j], {i, j}});
                    visited[i][j] = true;
                }
            }
        }

        int level = 0, res = 0;
        vector<int> dirs = {-1, 0, 1, 0, -1};

        while (!heap.empty()) {
            auto [height, cell] = heap.top();
            heap.pop();
            int x = cell.first, y = cell.second;

            level = max(level, height);

            for (int d = 0; d < 4; ++d) {
                int nx = x + dirs[d];
                int ny = y + dirs[d + 1];

                if (nx >= 0 && nx < m && ny >= 0 && ny < n && !visited[nx][ny]) {
                    if (heightMap[nx][ny] < level) {
                        res += level - heightMap[nx][ny];
                    }
                    heap.push({heightMap[nx][ny], {nx, ny}});
                    visited[nx][ny] = true;
                }
            }
        }

        return res;
    }
};