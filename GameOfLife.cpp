// Including dependencies
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <thread>
#include <chrono>

// Matrix for grid [Y][X]
std::string matrix[20][100];


std::string aliveCell(int cellX, int cellY) {
    int sum = 0;
    // Scanning cells around it
    for (int y = cellY - 1; y <= cellY + 1; ++y) {
        if (y < 0 || y >= 20) {
            continue;
        }
        for (int x = cellX - 1; x <= cellX + 1; ++x) {
            if (x < 0 || x >= 100) {
                continue;
            }
            if (y == cellY && x == cellX) {
                continue;
            }
            if (matrix[y][x] == "#") {
                ++sum;
            }
        }
    }
    // Return what state the cell should be
    if (sum <= 1) {
        return " ";
    }
    else if (sum >= 4) {
        return " ";
    }
    else {
        return "#";
    }
}


std::string deadCell(int cellX, int cellY) {
    int sum = 0;
    // Scanning cells around it
    for (int y = cellY - 1; y <= cellY + 1; ++y) {
        if (y < 0 || y >= 20) {
            continue;
        }
        for (int x = cellX - 1; x <= cellX + 1; ++x) {
            if (x < 0 || x >= 100) {
                continue;
            }
            if (y == cellY && x == cellX) {
                continue;
            }
            if (matrix[y][x] == "#") {
                ++sum;
            }
        }
    }
    // Return what state the cell should be
    if (sum >= 3) {
        return "#";
    } else {
        return " ";
    }
}

int main()
{   
    // Creating random alive / dead cells
    srand(time(0));
    for (int r = 0; r < 20; r++) {
        for (int i = 0; i < 100; i++) {
            if (rand() % 10== 1) {
                matrix[r][i] = "#";
            } else {
                matrix[r][i] = " ";
            }
        }
    }   
    // Game loop
    while (true) {
        std::cout << "John Conways game of life" << std::endl;
        // Updating cells
        for (int r = 0; r < 20; r++) {
            for (int i = 0; i < 100; i++) {
                if (matrix[r][i] == " ") {
                    matrix[r][i] = deadCell(i, r);
                }
                else {
                    matrix[r][i] = aliveCell(i, r);
                }
            }
        }
        // Printing cells
        for (int r = 0; r < 20; r++) {
            for (int i = 0; i < 100; i++) {
                std::cout << matrix[r][i];
            }
            std::cout << std::endl;
        }
        std::this_thread::sleep_for(std::chrono::seconds(1));
        system("cls");
    }
}