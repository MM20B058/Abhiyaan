#include <iostream>
using namespace std;

int main()
{
    int m; // no. of rows of matrix
    int n; // no. of columns of matrix
    int k; // number which is to be checked
    cout<<"Enter no. of rows and columns of th matrix\n";
    cin>>m>>n; // getting input of no. of rows and columns of the matrix
    cout<<"Enter the number which is to be checked\n";
    cin>>k; // getting input of the number which is to be checked
    int Matrix[m][n]; // initializing matrix

    // getting input of matrix
    cout<<"Enter data points of the matrix in sorted order\n";
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>Matrix[i][j];
        }
    }

    // checking whether the number is present in the matrix
    int rindex=0; // row index of the number if at all it is present
    int flag=0; // boolean value

    for(int i=0;i<m;i++){
        if(Matrix[i][0] > k){
                rindex=i-1; // the number should be present in the row before the row whose first number is greater than the number itself as the matrix is sorted
        }
    }
    for(int j=0;j<n;j++){
        if(Matrix[rindex][j]==k){
            flag=1; // setting boolean to be 1 if the number is present
            break; // using break as it is sufficient to run the loop till the first instance of the number is found
        }
    }
    if(flag==1){
        cout<<"True\n";
      for(int j=0;j<n;j++){
        if(Matrix[rindex][j]==k){
            cout<<rindex<<" "<<j<<endl; // outputting the row and column index of the number
        }
    }
    }
    else cout<<"False\n";
    return 0;
}
