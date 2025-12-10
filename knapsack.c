#include <stdio.h>

int main() {
    int n, W;
    
    printf("Enter number of items: ");
    scanf("%d", &n);

    int weight[20], profit[20];   // keeping size fixed for simplicity

    printf("Enter weights of items:\n");
    for(int i=0; i<n; i++)
        scanf("%d", &weight[i]);

    printf("Enter profits of items:\n");
    for(int i=0; i<n; i++)
        scanf("%d", &profit[i]);

    printf("Enter knapsack capacity: ");
    scanf("%d", &W);

    int dp[20][20];  // DP table (kept small and simple)

    // Filling DP table
    for(int i=0; i<=n; i++) {
        for(int w=0; w<=W; w++) {
            
            if(i==0 || w==0)
                dp[i][w] = 0;                // No item OR no capacity → profit = 0
            
            else if(weight[i-1] <= w)
                dp[i][w] = (profit[i-1] + dp[i-1][w - weight[i-1]] > dp[i-1][w])
                           ? profit[i-1] + dp[i-1][w - weight[i-1]]
                           : dp[i-1][w];     // Take max of include/exclude
            
            else
                dp[i][w] = dp[i-1][w];       // Cannot include item
        }
    }

    printf("\nMaximum Profit = %d\n", dp[n][W]);

    return 0;
}
/*
Enter number of items: 4
Enter weights of items:
2 3 4 5
Enter profits of items:
3 4 5 8
Enter knapsack capacity: 5

Maximum Profit = 8
*/