/*
733. Flood Fill
You are given an image represented by an m x n grid of integers image, where image[i][j] represents the pixel value of the image. 
You are also given three integers sr, sc, and color. Your task is to perform a flood fill on the image starting from the pixel image[sr][sc].
To perform a flood fill:
Begin with the starting pixel and change its color to color.
Perform the same process for each pixel that is directly adjacent (pixels that share a side with the original pixel, 
either horizontally or vertically) and shares the same color as the starting pixel.
Keep repeating this process by checking neighboring pixels of the updated pixels and modifying their color 
if it matches the original color of the starting pixel.
The process stops when there are no more adjacent pixels of the original color to update.
Return the modified image after performing the flood fill.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    set<pair<int , int>>visited;
    void solve(vector<vector<int>>& image, int sr, int sc, int color, int flag){
        if(sr >= image.size() or sr < 0) return;
        if(sc >= image[0].size() or sc < 0) return;
        if( visited.count({sr,sc}) ) return;
        if(image[sr][sc] == flag){
            visited.insert({sr , sc});  
            image[sr][sc] = color;
            solve(image , sr+1 ,sc , color , flag);
            solve(image , sr ,sc+1 , color , flag);
            solve(image , sr ,sc-1 , color , flag);
            solve(image , sr-1 ,sc , color , flag);
        }
        return;
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(image[sr][sc] == color) return image;
        solve(image , sr , sc , color , image[sr][sc]);
        return image;
    }

};

int main() {
    Solution sol;
    vector<vector<int>> image = {
        {1, 1, 1},
        {1, 1, 0},
        {1, 0, 1}
    };
    int sr = 1, sc = 1, color = 2;
    
    vector<vector<int>> result = sol.floodFill(image, sr, sc, color);
    
    for(const auto& row : result) {
        for(const auto& pixel : row) {
            cout << pixel << " ";
        }
        cout << endl;
    }
    
    return 0;
}