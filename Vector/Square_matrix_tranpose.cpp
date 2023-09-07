#include<iostream>
#include<vector>
using namespace std;

void transpose(vector<vector<int> > &matrix)
{
	int m = matrix.size();
	for(int i = 0; i<m; i++)
	{
		for(int j = i+1; j<m; j++)
		{
			int temp = matrix[i][j];
			matrix[i][j] = matrix[j][i];
			matrix[j][i] = temp;
		}
	}
	
	return;
}

int main()
{
	int m = 3;
    int n = 3;
    vector<vector<int> > matrix = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };

    for(int i = 0; i<m; i++)
    {
        for(int j = 0; j<n; j++)
        {
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    
    transpose(matrix);
    
    for(int i = 0; i<m; i++)
    {
        for(int j = 0; j<n; j++)
        {
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
    
}