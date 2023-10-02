class Solution {
public:
    bool winnerOfGame(string colors) {
        queue<int> aliceMoves, bobMoves;
        int i, count, n = colors.size();

        count = 1;
        for (i = 1; i < n; ++i) {
            if (colors[i] != colors[i - 1]) {
                if (count > 2) {
                    if (colors[i - 1] == 'A') {
                        aliceMoves.push(count);
                    }
                    else {
                        bobMoves.push(count);
                    }
                }

                count = 1;
            }
            else {
                ++count;
            }
        }

        if (count > 2) {
            if (colors[i - 1] == 'A') {
                aliceMoves.push(count);
            }
            else {
                bobMoves.push(count);
            }
        }

        bool turn = true;
        while(true) {
            if (turn) {
                if (aliceMoves.empty()) {
                    break;
                }
                else {
                    count = aliceMoves.front();
                    aliceMoves.pop();

                    --count;
                    if (count > 2) {
                        aliceMoves.push(count);
                    }
                }
            }
            else {
                if (bobMoves.empty()) {
                    break;
                }
                else {
                    count = bobMoves.front();
                    bobMoves.pop();

                    --count;
                    if (count > 2) {
                        bobMoves.push(count);
                    }
                }
            }


            turn = !turn;
        }

        return !turn;
    }
};