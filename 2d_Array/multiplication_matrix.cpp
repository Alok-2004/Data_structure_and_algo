#include<iostream>
#include<vector>

using namespace std;

int main()
{
    int m;
    cout<<"Enter rows of 1st matrix: ";
    cin>>m; 

    int n;
    cout<<"Enter colmns of 1st matrix: ";
    cin>>n;

    int p;
    cout<<"Enter rows of 2nd matrix: ";
    cin>>p; 

    int q;
    cout<<"Enter colmns of 2nd matrix: ";
    cin>>q;

    if (n==p)
    {
        int a[m][n];
        cout<<"Enter the element of the 1st matrix: ";
        for(int i = 0; i<m; i++)
        {
            for(int j = 0; j<n; j++)
            {
                cin>>a[i][j];
            }
        }

        int b[p][q];
        cout<<"Enter the element of the 2nd matrix: ";
        for(int i = 0; i<p; i++)
        {
            for(int j = 0; j<q; j++)
            {
                cin>>b[i][j];
            }
        }

        int res[m][q];
        for(int i = 0; i<m; i++)
        {
            for(int j = 0; j<n; j++)
            {
                res[i][j] = 0;
                for(int k = 0; k<p; k++)
                {
                    res[i][j] = res[i][j] + a[i][k] *b[k][i];
                }
            }
        }

        // display
        for(int i = 0; i<m; i++)
        {
            for(int j = 0; j<q; j++)
            {
                cout<<res[i][j]<<"\n";
            }
            cout<<endl;
        }
    }
    else{
        cout<<"Matrices cant be multiplied.";
    }



}


