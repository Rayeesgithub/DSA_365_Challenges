#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <queue>
#include <utility>

using namespace std;

void dfs(int i, int j, int N, int M, int block_num, const vector<vector<int>>& grid, vector<vector<bool>>& visited, set<pair<int, int>>& block_coords) {
    if (i < 0 || i >= N || j < 0 || j >= M || visited[i][j] || grid[i][j] != block_num) {
        return;
    }

    visited[i][j] = true;
    block_coords.insert({i, j});

    dfs(i + 1, j, N, M, block_num, grid, visited, block_coords);
    dfs(i - 1, j, N, M, block_num, grid, visited, block_coords);
    dfs(i, j + 1, N, M, block_num, grid, visited, block_coords);
    dfs(i, j - 1, N, M, block_num, grid, visited, block_coords);
}

map<int, set<pair<int, int>>> find_connected_blocks(const vector<vector<int>>& grid, int N, int M) {
    map<int, set<pair<int, int>>> blocks;
    vector<vector<bool>> visited(N, vector<bool>(M, false));

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (!visited[i][j]) {
                set<pair<int, int>> block_coords;
                dfs(i, j, N, M, grid[i][j], grid, visited, block_coords);
                blocks[grid[i][j]].insert(block_coords.begin(), block_coords.end());
            }
        }
    }

    return blocks;
}

int find_dependencies(const map<int, set<pair<int, int>>>& blocks, int N, int M, int target) {
    map<int, int> block_tops;

    for (const auto& [block_num, coords] : blocks) {
        int min_row = N;
        for (const auto& [i, j] : coords) {
            min_row = min(min_row, i);
        }
        block_tops[block_num] = min_row;
    }

    if (blocks.find(target) == blocks.end()) {
        return 0; // Target block not found.
    }

    const set<pair<int, int>>& target_coords = blocks.at(target);
    int target_top = block_tops[target];

    set<int> blocks_to_remove;

    for (const auto& [block_num, coords] : blocks) {
        if (block_num == target) continue;

        int block_top = block_tops[block_num];
        if (block_top <= target_top) {
            set<int> target_columns, block_columns;
            for (const auto& [i, j] : target_coords) target_columns.insert(j);
            for (const auto& [i, j] : coords) block_columns.insert(j);

            for (int col : target_columns) {
                if (block_columns.find(col) != block_columns.end()) {
                    blocks_to_remove.insert(block_num);
                    break;
                }
            }
        }
    }

    return blocks_to_remove.size();
}

void solve_block_extraction() {
    int N, M;
    cin >> N >> M;

    vector<vector<int>> grid(N, vector<int>(M));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> grid[i][j];
        }
    }

    int K;
    cin >> K;

    map<int, set<pair<int, int>>> blocks = find_connected_blocks(grid, N, M);
    int result = find_dependencies(blocks, N, M, K);
    cout << result << endl;
}

int main() {
    solve_block_extraction();
    return 0;
}
