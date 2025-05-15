1. Depth First Search (DFS) Problems
1.1. Number of Islands (LeetCode #200)
Problem: Given a 2D grid of '1's (land) and '0's (water), count the number of islands. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically.

Solution: This problem can be solved using DFS. We traverse the grid, and whenever we find a land ('1'), we initiate a DFS to mark all connected lands as visited.
  class Solution {
public:
    void dfs(vector<vector<char>>& grid, int i, int j) {
        // Check if out of bounds or if the cell is water
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == '0') {
            return;
        }
        
        // Mark the current cell as visited
        grid[i][j] = '0'; 
        
        // Visit all 4 adjacent cells (up, down, left, right)
        dfs(grid, i + 1, j);
        dfs(grid, i - 1, j);
        dfs(grid, i, j + 1);
        dfs(grid, i, j - 1);
    }

    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        if (grid.empty()) return 0;
        
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == '1') {
                    // When we find land, perform DFS
                    dfs(grid, i, j);
                    count++;
                }
            }
        }
        
        return count;
    }
};
2.2. Binary Tree Level Order Traversal (LeetCode #102)
Problem: Given a binary tree, return the level order traversal of its nodes' values.

Solution: This is a classic BFS problem where we traverse the tree level by level.
  class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (!root) return result;
        
        queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty()) {
            int size = q.size();
            vector<int> level;
            
            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();
                level.push_back(node->val);
                
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            
            result.push_back(level);
        }
        
        return result;
    }
};
