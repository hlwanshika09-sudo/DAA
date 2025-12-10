#include <stdio.h>
#include <stdbool.h>

#define MAX 100

int N;
int board[MAX][MAX];

void printSolution() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%c ", board[i][j] ? 'Q' : '.');
        }
        printf("\n");
    }
    printf("\n");
}

bool isSafe(int row, int col) {
    int i, j;
    // check this row on left side
    for (i = 0; i < col; i++)
        if (board[row][i])
            return false;

    // check upper diagonal on left side
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return false;

    // check lower diagonal on left side
    for (i = row, j = col; j >= 0 && i < N; i++, j--)
        if (board[i][j])
            return false;

    return true;
}

bool solveNQUtil(int col) {
    if (col >= N) {
        printSolution();
        return true;
    }

    bool res = false;
    for (int i = 0; i < N; i++) {
        if (isSafe(i, col)) {
            board[i][col] = 1;

            // recur to place rest of queens
            res = solveNQUtil(col + 1) || res; // The || res part makes the algorithm accumulate success across all recursive tries: 
                                               //it ensures res remains true if any placement eventually leads to a solution — even if some placements fail later. 
                                               //Without || res, res would just reflect the result of the last recursive call, which would lose information about earlier successes within the same column loop.

            // BACKTRACK
            board[i][col] = 0;
        }
    }

    return res;
}

int main() {
    printf("Enter N: ");
    //In short: that line is a safety-check. It makes sure the user input was exactly one valid integer. 
    //If not — instead of proceeding with an invalid or uninitialized N — the program exits (with error code 1).
    if (scanf("%d", &N) != 1) return 1;

    if (N < 1 || N > MAX) {
        printf("Please choose N between 1 and %d\n", MAX);
        return 0;
    }

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            board[i][j] = 0;

    if (!solveNQUtil(0)) {  //passing 0 as the starting argument tells the recursive function: “Start with the first column.”
        printf("No solution exists for N = %d\n", N);
    }

    return 0;
}
