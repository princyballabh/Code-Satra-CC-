#include <bits/stdc++.h>
using namespace std;

bool isSafe(vector<vector<int>>& board, int row, int col, int N) {
    for (int i = 0; i < col; ++i)
        if (board[row][i]) return false;

    for (int i = row, j = col; i >= 0 && j >= 0; --i, --j)
        if (board[i][j]) return false;

    for (int i = row, j = col; i < N && j >= 0; ++i, --j)
        if (board[i][j]) return false;

    return true;
}

bool solveNQueensUtil(vector<vector<int>>& board, int col, int N) {
    if (col >= N) return true;

    for (int i = 0; i < N; ++i) {
        if (isSafe(board, i, col, N)) {
            board[i][col] = 1;

            if (solveNQueensUtil(board, col + 1, N))
                return true;

            board[i][col] = 0;
        }
    }

    return false;
}

vector<vector<int>> solveNQueens(int N) {
    vector<vector<int>> board(N, vector<int>(N, 0));

    if (!solveNQueensUtil(board, 0, N)) {
        cout << "Solution does not exist" << endl;
        return {};
    }

    return board;
}

int main() {
    int N = 4;
    vector<vector<int>> result = solveNQueens(N);

    for (const auto& row : result) {
        for (int cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }

    return 0;
}
