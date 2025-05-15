#include <stdio.h>

int n, a[10][10], res[10], s[10], top = 0;


void dfs(int, int, int[][10]);


void dfs_top(int, int[][10]);

int main() {
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    int i, j;

  
    printf("Enter the adjacency matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }

   
    dfs_top(n, a);

   
    printf("Solution: ");
    for (i = n - 1; i >= 0; i--) {
        printf("%d ", res[i]);
    }

    return 0;
}

void dfs_top(int n, int a[][10]) {
    int i;
 
    for (i = 0; i < n; i++) {
        s[i] = 0;
    }
    
    for (i = 0; i < n; i++) {
        if (s[i] == 0) {
            dfs(i, n, a);
        }
    }
}

void dfs(int j, int n, int a[][10]) {
    s[j] = 1;  
    int i;
    for (i = 0; i < n; i++) {
        if (a[j][i] == 1 && s[i] == 0) {
            dfs(i, n, a);
        }
    }
    res[top++] = j;  
}

##############OUTPUT###########
Enter the no. of nodes6
0 0 1 1 0 0
0 0 0 1 1 0
0 0 0 1 0 1
0 0 0 0 0 1
0 0 0 0 0 1
0 0 0 0 0 0
Solution: 1 4 0 2 3 5
  


  
#include <stdio.h>

int a[10][10], n, t[10], indegree[10];
int stack[10], top = -1;


void computeIndegree(int, int[][10]);


void tps_SourceRemoval(int, int[][10]);

int main() {
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    int i, j;

    
    printf("Enter the adjacency matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }

   
    computeIndegree(n, a);

 
    tps_SourceRemoval(n, a);

   
    printf("Solution: ");
    for (i = 0; i < n; i++) {
        printf("%d ", t[i]);
    }

    return 0;
}

void computeIndegree(int n, int a[][10]) {
    int i, j, sum;
    for (i = 0; i < n; i++) {
        sum = 0;
        for (j = 0; j < n; j++) {
            sum += a[j][i];  
        }
        indegree[i] = sum;  
    }
}

void tps_SourceRemoval(int n, int a[][10]) {
    int i, j, v;

 
    for (i = 0; i < n; i++) {
        if (indegree[i] == 0) {
            stack[++top] = i;
        }
    }

    int k = 0;
   
    while (top != -1) {
        v = stack[top--];  // Pop a node from the stack
        t[k++] = v;  // Add the node to the topological order

        // For each neighbor, reduce its in-degree
        for (i = 0; i < n; i++) {
            if (a[v][i] != 0) {
                indegree[i]--;
                if (indegree[i] == 0) {
                    stack[++top] = i;  // Push nodes with in-degree 0 onto the stack
                }
            }
        }
    }
}



OUTPUT:
Enter the no. of nodes: 5
0 0 1 0 0
1 0 0 1 0
0 0 0 0 1
0 0 1 0 1
0 0 0 0 0
Solution:1 3 0 2 4
