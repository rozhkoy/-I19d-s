#include <iostream>
#include <fstream>

int main() {
    std::fstream file1("przyklad1.txt");
    std::fstream file2("przyklad2.txt");
    int counter = 0;
    int couple = 0;
    bool NumberRow[5];
    int arrayNumber1[5][10];
    int arrayNumber2[5][10];
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 10; ++j) {
            file1 >> arrayNumber1[i][j];
            file2 >> arrayNumber2[i][j];
        }
    }
    for (int i = 0; i < 5; i++) {
        counter = 0;
        for (int j = 0; j < 10; j++) {
            for (int k = 0; k < 10; k++) {
                if (arrayNumber1[i][j] == arrayNumber2[i][k]) {
                    counter++;
                    break;
                }
            }
            if (counter == 10) {
                couple++;
                NumberRow[i] = true;
            }
        }
    }
    std::cout << "result " << couple << std::endl;
    for (int b = 0; b < 5; b++) {
        if (NumberRow[b] == true) {
            if(b == 0) {
                std::cout << b + 1;
            } else {
                std::cout << "," << b + 1;
            }
        }
    }
    return 0;
}