#include "common.h"

USESTD 

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int rows = image.size();
        if (rows == 0) return image;

        int cols = image[0].size();
        if (cols == 0) return image;

        vector<vector<bool>> records;
        for (int r = 0; r < rows; r++) {
            vector<bool> col;
            for (int c = 0; c < cols; c++) {
                col.push_back(false);
            }
            records.push_back(col);
        }

        fillColor(image, rows, cols, sr, sc, image[sr][sc], image[sr][sc], newColor, records);
        return image;
    }

    void fillColor(vector<vector<int>> &image, int rows, int cols, int r, int c, int lastColor, int originColor, int newColor, vector<vector<bool>> &records) {
        if (r < 0 || r == rows || c < 0 || c == cols || || records[r][c] == true) return;

        int color = image[r][c];
        if (color == originColor && color == lastColor && color != newColor) {
            image[r][c] = newColor;
        }
        
        lastColor = color;
        records[r][c] = true;
        
        fillColor(image, rows, cols, r - 1, c, originColor, lastColor, newColor, records);
        fillColor(image, rows, cols, r + 1, c, originColor, lastColor, newColor, records);
        fillColor(image, rows, cols, r, c - 1, originColor, lastColor, newColor, records);
        fillColor(image, rows, cols, r, c + 1, originColor, lastColor, newColor, records);
    }
};