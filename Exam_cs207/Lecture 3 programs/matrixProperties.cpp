#include <iostream>
using namespace std;

int main()
{
    cout << "This program checks the following properties of square matrices:" << endl;
    cout << "diagonal, symmetric, upper triangular, lower triangular." << endl;
    cout << "First you need to provide a matrix." << endl;
    cout << "What is the dimension of your matrix? " << endl;
    int dim = 0;
    cin >> dim;
    // possible input validation here
    if(dim <= 0)
    {
        cout << "Negative or null matrix dimension. Aborting ..." << endl;
        return 0;
    }
    // matrix allocation
    double** matrix = new double*[dim]{nullptr};
    for(int i = 0; i < dim; i++)
    {
        matrix[i] = new double[dim]{0.0};
    }
    cout << "List the elements of your matrix in a row-wise fashion separated by spaces " << endl;
    //cout << ">> ";
    for(int i = 0; i < dim ; i++)
    {
        for(int j = 0; j < dim; j++)
        {
            cin >> matrix[i][j];
        }
    }
    // printing the matrix
    for(int i = 0; i < dim ; i++)
    {
        for(int j = 0; j < dim; j++)
        {
            cout <<  matrix[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;

    //checking for symmetry, upper triangular, lower triangular, diagonal
    bool symmetric = true;
    bool upTri = true;
    bool lowTri = true;
    bool diagonal = true;
    for(int i = 0; i < dim ; i++)
    {
        for(int j = i+1; j < dim; j++)
        {
            if(matrix[i][j] != matrix[j][i])
                symmetric = false;
            if(matrix[i][j] != 0)
            {
                lowTri = false;
                diagonal = false;
            }
            if(matrix[j][i] != 0)
            {
                upTri = false;
                diagonal = false;
            }
        }
    }

    // printing output
    if(diagonal)
        cout << "Your matrix is diagonal." << endl;
    else if(symmetric)
        cout << "Your matrix is symmetric." << endl;
    else if(upTri)
        cout << "Your matrix is upper triangular." << endl;
    else if(lowTri)
        cout << "Your matrix is lower triangular." << endl;
    else
        cout << "Your matrix does not have any of the properties listed above." << endl;


    // explicit de-allocation is required to avoid memory leaks
    for(int i = 0; i < dim; i++)
    {
        delete[] matrix[i];
    }
    delete[] matrix;
    return 0;
}
