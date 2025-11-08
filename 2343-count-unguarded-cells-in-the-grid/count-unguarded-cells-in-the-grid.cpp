class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
          vector<vector<char>> graph(m, vector<char>(n, '.'));

    for (auto& g : guards) graph[g[0]][g[1]] = 'G';
    for (auto& w : walls) graph[w[0]][w[1]] = 'W';

   
    for (auto& g : guards) {
        int i = g[0], j = g[1];

for (int y = j - 1; y >= 0; y--) {
    if (graph[i][y] == 'W' || graph[i][y] == 'G') break;
    if (graph[i][y] == '.') graph[i][y] = 'V';
}

for (int y = j + 1; y < n; y++) {
    if (graph[i][y] == 'W' || graph[i][y] == 'G') break;
    if (graph[i][y] == '.') graph[i][y] = 'V';
}

for (int x = i - 1; x >= 0; x--) {
    if (graph[x][j] == 'W' || graph[x][j] == 'G') break;
    if (graph[x][j] == '.') graph[x][j] = 'V';
}
for (int x = i + 1; x < m; x++) {
    if (graph[x][j] == 'W' || graph[x][j] == 'G') break;
    if (graph[x][j] == '.') graph[x][j] = 'V';
}

    }


    int count = 0;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            if (graph[i][j] == '.') count++;

    return count;
    }
};