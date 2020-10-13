#include <iostream>

using namespace std;
int main()
{
    cout << "Sparse Matrix : \n";
    int m=5,n=6;
    int matrix[5][6] =
    {
        {0 , 0 , 0 , 0 , 9, 0 },
        {0 , 8 , 0 , 0 , 0, 0 },
        {4 , 0 , 0 , 2 , 0, 0 },
        {0 , 0 , 0 , 0 , 0, 5 },
        {0 , 0 , 2 , 0 , 0, 0 }
    };
    int total_size=0;
    for(int i=0;i<m;i++){
        for(int j = 0;j<n;j++){
            if(matrix[i][j]!=0){
                total_size+=1;
            }
        }
    }
    int sparseMatrix[3][total_size];
    int current_index =0;
    for(int i=0;i<m;i++){
        for(int j = 0;j<n;j++){
            if(matrix[i][j]!=0){
                sparseMatrix[0][current_index] = i;
                sparseMatrix[1][current_index] = j;
                sparseMatrix[2][current_index] = matrix[i][j];
                current_index+=1;
            }
        }
    }
    for(int i=0;i<total_size;i++){
        cout<<sparseMatrix[0][i]<<" ";
        cout<<sparseMatrix[1][i]<<" ";
        cout<<sparseMatrix[2][i]<<"\n";
    }
    int matrix_2[5][6] =
    {
        {0 , 0 , 0 , 0 , 9, 0 },
        {0 , 8 , 0 , 0 , 0, 0 },
        {4 , 0 , 0 , 2 , 0, 0 },
        {0 , 0 , 0 , 0 , 0, 5 },
        {0 , 0 , 2 , 0 , 0, 0 }
    };
    int total_size_2=0;
    for(int i=0;i<m;i++){
        for(int j = 0;j<n;j++){
            if(matrix_2[i][j]!=0){
                total_size_2+=1;
            }
        }
    }
    int sparseMatrix_2[3][total_size_2];
    int current_index_2 =0;
    for(int i=0;i<m;i++){
        for(int j = 0;j<n;j++){
            if(matrix_2[i][j]!=0){
                sparseMatrix_2[0][current_index_2] = i;
                sparseMatrix_2[1][current_index_2] = j;
                sparseMatrix_2[2][current_index_2] = matrix_2[i][j];
                current_index_2+=1;
            }
        }
    }
    for(int i=0;i<total_size_2;i++){
        cout<<sparseMatrix_2[0][i]<<" ";
        cout<<sparseMatrix_2[1][i]<<" ";
        cout<<sparseMatrix_2[2][i]<<"\n";
    }

    return 0;
}
