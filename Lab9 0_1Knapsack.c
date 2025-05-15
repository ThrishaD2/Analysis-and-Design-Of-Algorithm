#include <stdio.h>


int knapsack(int W, int weight[], int value[], int n) {
    int dp[n + 1][W + 1];  

   
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (i == 0 || w == 0) {
                dp[i][w] = 0;  
            } else if (weight[i - 1] <= w) {
                
                dp[i][w] = (value[i - 1] + dp[i - 1][w - weight[i - 1]] > dp[i - 1][w]) ?
                            (value[i - 1] + dp[i - 1][w - weight[i - 1]]) : dp[i - 1][w];
            } else {
                
                dp[i][w] = dp[i - 1][w];
            }
        }
    }
    
    return dp[n][W];  

int main() {
    int n, W;

    
    printf("Enter the number of items: ");
    scanf("%d", &n);

    int weight[n], value[n];

  
    for (int i = 0; i < n; i++) {
        printf("Enter weight and value for item %d: ", i + 1);
        scanf("%d %d", &weight[i], &value[i]);
    }

  
    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &W);

    
    int result = knapsack(W, weight, value, n);
    printf("Maximum value in Knapsack = %d\n", result);

    return 0;
}


OUTPUT
Enter the number of items: 4
Enter weight and value for item 1: 2 3
Enter weight and value for item 2: 3 4
Enter weight and value for item 3: 4 5
Enter weight and value for item 4: 5 6
Enter the capacity of the knapsack: 5
Maximum value in Knapsack = 7

