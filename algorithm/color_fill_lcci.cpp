#include "common.h"

USESTD 

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int rows = image.size();
        if (rows == 0) return image;

        int cols = image[0].size();
        if (cols == 0) return image;

        fillColor(image, rows, cols, sr, sc, image[sr][sc], newColor);
        return image;
    }

    void fillColor(vector<vector<int>> &image, int rows, int cols, int r, int c, int originColor, int newColor) {
        if (r < 0 || r == rows || c < 0 || c == cols) return;

        if (image[r][c] == originColor && image[r][c] != newColor) {
            image[r][c] = newColor;
            fillColor(image, rows, cols, r - 1, c, originColor, newColor);
            fillColor(image, rows, cols, r + 1, c, originColor, newColor);
            fillColor(image, rows, cols, r, c - 1, originColor, newColor);
            fillColor(image, rows, cols, r, c + 1, originColor, newColor);
        }
    }
};