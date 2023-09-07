#include<iostream>
#include<vector>
using namespace std;


    vector<vector<int> > transpose(vector<vector<int> >& matrix) 
    {
        int m = matrix.size(); // row
        int n = matrix[0].size(); // column

        vector<vector<int> > t(n,vector<int>(m));
        for(int i = 0; i<n; i++)
        {
            for(int j = 0; j<m; j++)
            {
                t[i][j] = matrix[j][i];
            }
        }
        return t;    
    }
    
int main()
{
    vector<vector<int> > v = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };

    // Call the transpose function and store the result in a new variable
    vector<vector<int> > transposed = transpose(v);

    // Print the transpose matrix
    for (int i = 0; i < transposed.size(); i++)
    {
        for (int j = 0; j < transposed[i].size(); j++)
        {
            cout << transposed[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}