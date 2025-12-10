#include <stdio.h>

int subsetCount = 0;

void printSubset(int subset[], int length) {
    printf("{ ");
    for(int i = 0; i < length; i++)
        printf("%d ", subset[i]);
    printf("}\n");
}

void findSubsets(int arr[], int n, int sum, int subset[], int index) {
    // If required sum becomes 0 → print the subset
    if(sum == 0) {
        subsetCount++;
        printSubset(subset, index);
        return;
    }

    // If no elements or sum < 0 stop
    if(n == 0)
        return;

    // Include current element arr[n-1]
    subset[index] = arr[n-1];
    findSubsets(arr, n-1, sum - arr[n-1], subset, index+1);

    // Exclude current element & move further
    findSubsets(arr, n-1, sum, subset, index);
}

int main() {
    int arr[20], subset[20], n, sum;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements of set:\n");
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Enter required sum: ");
    scanf("%d", &sum);

    printf("\nSubsets with sum = %d are:\n", sum);
    findSubsets(arr, n, sum, subset, 0);

    if(subsetCount == 0)
        printf("No subset exists.\n");
    else
        printf("\nTotal %d subset(s) found.\n", subsetCount);

    return 0;
}

/*
Enter number of elements: 5
Enter elements: 3 4 5 2 1
Enter required sum: 6

Subsets with sum = 6 are:
{ 1 5 }
{ 2 4 }
{ 1 2 3 }

Total 3 subset(s) found.
*/