#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define N 4

int final_cost = INT_MAX;
int final_assignment[N];

int rowMin(int costMatrix[N][N], int row) {
    int min = INT_MAX;
    for (int j = 0; j < N; j++) {
        if (costMatrix[row][j] < min)
            min = costMatrix[row][j];
    }
    return min;
}

int colMin(int costMatrix[N][N], int col) {
    int min = INT_MAX;
    for (int i = 0; i < N; i++) {
        if (costMatrix[i][col] < min)
            min = costMatrix[i][col];
    }
    return min;
}

int reduceMatrix(int costMatrix[N][N], int rowCovered[], int colCovered[]) {
    int reductionCost = 0;

    for (int i = 0; i < N; i++) {
        if (!rowCovered[i]) {
            int minRow = rowMin(costMatrix, i);
            reductionCost += minRow;
            for (int j = 0; j < N; j++) {
                costMatrix[i][j] -= minRow;
            }
        }
    }

    for (int j = 0; j < N; j++) {
        if (!colCovered[j]) {
            int minCol = colMin(costMatrix, j);
            reductionCost += minCol;
            for (int i = 0; i < N; i++) {
                costMatrix[i][j] -= minCol;
            }
        }
    }

    return reductionCost;
}

void branchAndBound(int costMatrix[N][N], int currCost, int rowCovered[], int colCovered[], int assignment[], int level) {
    if (level == N) {
        if (currCost < final_cost) {
            final_cost = currCost;
            for (int i = 0; i < N; i++)
                final_assignment[i] = assignment[i];
        }
        return;
    }

    for (int j = 0; j < N; j++) {
        if (!colCovered[j]) {
            int reducedMatrix[N][N];
            for (int i = 0; i < N; i++)
                for (int k = 0; k < N; k++)
                    reducedMatrix[i][k] = costMatrix[i][k];

            int newRowCovered[N], newColCovered[N];
            for (int i = 0; i < N; i++) {
                newRowCovered[i] = rowCovered[i];
                newColCovered[i] = colCovered[i];
            }
            newRowCovered[level] = 1;
            newColCovered[j] = 1;

            int reductionCost = reduceMatrix(reducedMatrix, newRowCovered, newColCovered);
            int newCost = currCost + costMatrix[level][j] + reductionCost;

            if (newCost < final_cost) {
                assignment[level] = j;
                branchAndBound(reducedMatrix, newCost, newRowCovered, newColCovered, assignment, level + 1);
            }
        }
    }
}

void solveAssignmentProblem(int costMatrix[N][N]) {
    int rowCovered[N] = {0}, colCovered[N] = {0};
    int assignment[N];

    int reducedMatrix[N][N];
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            reducedMatrix[i][j] = costMatrix[i][j];

    int reductionCost = reduceMatrix(reducedMatrix, rowCovered, colCovered);
    branchAndBound(reducedMatrix, reductionCost, rowCovered, colCovered, assignment, 0);

    printf("Minimum cost: %d\n", final_cost);
    printf("Assignment of tasks to agents: \n");
    for (int i = 0; i < N; i++) {
        printf("Agent %d -> Task %d\n", i, final_assignment[i]);
    }
}

int main() {
    int costMatrix[N][N] = {
        {9, 2, 7, 8},
        {6, 4, 3, 7},
        {5, 8, 1, 8},
        {7, 6, 9, 4}
    };

    solveAssignmentProblem(costMatrix);

    return 0;
}
