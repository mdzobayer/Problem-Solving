#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void initDeck(int arr[][13], int rows) {
    for(int r = 0; r < rows; ++r)
        for(int c = 0; c < 13; ++c)
            arr[r][c] = 0;
}

void displayDeck(int arr[][13], int rows) {
    for(int r = 0; r < rows; ++r) {
        for(int c = 0; c < 13; ++c)
            cout << arr[r][c] << " ";
        cout << endl;
    }
}

void shuffleDeck(int arr[][13], int rows) {
    int row, col;
    srand(time(NULL));
    for(int card = 1; card <= 52; ++card) {
        row = rand() % 4;
        col = rand() % 13;
        if (arr[row][col] == 0)
            arr[row][col] = card;
        else {
            while (arr[row][col] != 0) {
                row = rand() % 4;
                col = rand() % 13;
            }
            arr[row][col] = card;
        }
    }
}

int main()
{
    const int rows = 4;
    const int cols = 13;
    int deck[rows][cols];
    initDeck(deck, rows);
    shuffleDeck(deck, rows);
    displayDeck(deck, rows);
    cout << endl;
    return 0;
}
