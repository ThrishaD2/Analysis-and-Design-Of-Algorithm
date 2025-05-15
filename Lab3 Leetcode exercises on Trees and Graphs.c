1. Tree Problems
1.1. Maximum Depth of Binary Tree
Problem: Given a binary tree, return its maximum depth.
  #include <stdio.h>
#include <stdlib.h>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Function to find the maximum depth of the binary tree
int maxDepth(struct TreeNode* root) {
    if (root == NULL) return 0;
    int left_depth = maxDepth(root->left);
    int right_depth = maxDepth(root->right);
    return (left_depth > right_depth ? left_depth : right_depth) + 1;
}

// Helper function to create a new TreeNode
struct TreeNode* newNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

int main() {
    // Create a simple tree: 1 -> 2, 3
    struct TreeNode* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    
    printf("Maximum Depth of the Tree: %d\n", maxDepth(root));
    return 0;
}
2. Graph Problems
2.1. Number of Connected Components in an Undirected Graph
Problem: You are given n nodes and a list of edges. Return the number of connected components in the graph.
  #include <stdio.h>
#include <stdlib.h>

void dfs(int node, int n, int graph[n][n], int visited[n]) {
    visited[node] = 1;
    for (int i = 0; i < n; i++) {
        if (graph[node][i] == 1 && !visited[i]) {
            dfs(i, n, graph, visited);
        }
    }
}

int countComponents(int n, int edges[][2], int edgesCount) {
    int graph[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            graph[i][j] = 0;
        }
    }
    
    // Build the graph
    for (int i = 0; i < edgesCount; i++) {
        graph[edges[i][0]][edges[i][1]] = 1;
        graph[edges[i][1]][edges[i][0]] = 1;
    }
    
    int visited[n];
    for (int i = 0; i < n; i++) visited[i] = 0;
    
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i, n, graph, visited);
            count++;
        }
    }
    
    return count;
}

int main() {
    int edges[][2] = {{0, 1}, {1, 2}, {3, 4}};
    int n = 5; // Number of nodes
    int edgesCount = sizeof(edges) / sizeof(edges[0]);
    
    printf("Number of connected components: %d\n", countComponents(n, edges, edgesCount));
    return 0;
}
