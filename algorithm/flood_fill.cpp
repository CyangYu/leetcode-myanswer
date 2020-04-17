#include "common.h"

USESTD


int main(int argc, char *argv[]) {
    vector<vector<int>> image = {
        {0, 1, 0, 1},
        {1, 0, 1, 0},
        {1, 1, 1, 1},
        {0, 1, 1, 0}
    };

    Solution solution;
    solution.floodFill(image, 0, 0, 1);

    printf("HelloWorld");

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cout << image[i][j] << ", ";
        }
        cout << endl;
    }
}