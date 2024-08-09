/*
https://leetcode.com/problems/magic-squares-in-grid/description/?envType=daily-question&envId=2024-08-09
*/

class Solution {

    public static boolean isInvalid(int[][] grid, int currentRow, int currentColumn) {
        return grid[currentRow][currentColumn] <= 0 || grid[currentRow][currentColumn] > 9;
    }

    public int numMagicSquaresInside(int[][] grid) {
        int rows = grid.length, columns = grid[0].length, resultantMagicSubgrids = 0;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < columns; ++j) {
                if (i + 2 <= rows - 1 && j + 2 <= columns - 1) {
                    HashSet <Integer> seenNumbers = new HashSet<> ();
                    int sumToCheck = 0;
                    boolean isAnySubGridInvalid = false;
                    for (int k = i; k <= i + 2; ++k) {
                        if (isInvalid(grid, k, j)) {
                            isAnySubGridInvalid = true;
                            break;
                        }
                        sumToCheck += grid[k][j];
                    }
                    if (!isAnySubGridInvalid) {
                        for (int l = j; l <= j + 2; ++l) {
                            int anotherSumToCheck = 0;
                            for (int k = i; k <= i + 2; ++k) {
                                if (isInvalid(grid, i, j)) {
                                    isAnySubGridInvalid = true;
                                    break;
                                }
                                anotherSumToCheck += grid[k][l];
                            }
                            if (anotherSumToCheck != sumToCheck) {
                                isAnySubGridInvalid = true;
                                break;
                            }
                        }
                        if (!isAnySubGridInvalid) {
                            int firstDiagnolSumToCheck = 0, secondDiagonalSumToCheck = 0;
                            firstDiagnolSumToCheck += grid[i][j] + grid[i + 1][j + 1] + grid[i + 2][j + 2];
                            secondDiagonalSumToCheck += grid[i][j + 2] + grid[i + 1][j + 1] + grid[i + 2][j];
                            if (firstDiagnolSumToCheck != sumToCheck || secondDiagonalSumToCheck != sumToCheck) {
                                isAnySubGridInvalid = true;
                                continue;
                            }
                            if (!isAnySubGridInvalid) {
                                for (int k = i; k <= i + 2; ++k) {
                                    int currentRowSum = 0;
                                    for (int l = j; l <= j + 2; ++l) {
                                        if (seenNumbers.contains(grid[k][l])||isInvalid(grid, k, l)) {
                                            isAnySubGridInvalid = true;
                                            break;
                                        }
                                        seenNumbers.add(grid[k][l]);
                                        currentRowSum += grid[k][l];
                                    }
                                    if (currentRowSum != sumToCheck) {
                                        isAnySubGridInvalid = true;
                                        break;
                                    }
                                }
                            }
                        }
                    }
                    if (!isAnySubGridInvalid) resultantMagicSubgrids++;
                }
            }
        }
        return resultantMagicSubgrids;
    }
}