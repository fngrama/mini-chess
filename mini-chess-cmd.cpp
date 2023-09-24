#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// Define the initial chess board
vector<vector<char>> board = {
    {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'},
    {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
    {'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'}
};

// Function to evaluate king safety
double evaluateKingSafety(const vector<vector<char>>& board) {
    pair<int, int> whiteKingPosition = {-1, -1};
    pair<int, int> blackKingPosition = {-1, -1};

    // Find the positions of white and black kings
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (board[i][j] == 'K') {
                whiteKingPosition = {i, j};
            } else if (board[i][j] == 'k') {
                blackKingPosition = {i, j};
            }
        }
    }

    if (whiteKingPosition.first == -1 || blackKingPosition.first == -1) {
        // Kings are missing from the board; return neutral value
        return 0.0;
    }

    // Calculate the distance of kings from the center
    double centerRow = 3.5;
    double centerCol = 3.5;
    double whiteKingDistance = sqrt(pow(whiteKingPosition.first - centerRow, 2) +
                                     pow(whiteKingPosition.second - centerCol, 2));
    double blackKingDistance = sqrt(pow(blackKingPosition.first - centerRow, 2) +
                                     pow(blackKingPosition.second - centerCol, 2));

    // You can adjust these coefficients as needed
    double distanceFactor = 0.1;
    
    // Return the king safety evaluation score
    return (blackKingDistance - whiteKingDistance) * distanceFactor;
}

int main() {
    // Example usage:
    double kingSafetyScore = evaluateKingSafety(board);
    cout << "King Safety Score: " << kingSafetyScore << endl;

    return 0;
}