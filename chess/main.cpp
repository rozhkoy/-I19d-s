#include <iostream>
#include <fstream>
#include <clocale>


int main() {
    std::fstream file("test.txt");
    int boards = 9;
    int countBoardsWithFullFreeRow = 0;
    int count = 0;
    int countMaxRow = 0;
    int countMaxRowInOneBoard = 0;


    struct board {
        char square[8][8];
    };
    board t[boards];

    for (int i = 0; i < boards; i++) {
        for (int l = 0; l < 8; l++) {
            for (int c = 0; c < 8; c++) {
                file >> t[i].square[l][c];
            }
        }
    }

    for (int i = 0; i < boards; i++) {
        countMaxRow = 0;
        for (int column = 0; column < 8; column++) {
            count = 0;
            for (int line = 0; line < 8; line++) {
                std::cout << t[i].square[line][column];
                if(t[i].square[line][column] == '.') {
                    count++;
                }
            }
            if(count == 8) {
                countMaxRow++;
            }
            std::cout << '|' << count << '|' << countMaxRow << std::endl;
        }
        std::cout << std::endl;
        if(countMaxRow > 0) {
            countBoardsWithFullFreeRow++;
        }

        if(countMaxRow > countMaxRowInOneBoard) {
            countMaxRowInOneBoard = countMaxRow;
        }
    }
    std::cout << countMaxRowInOneBoard << "|" << countBoardsWithFullFreeRow;

    return 0;
}
