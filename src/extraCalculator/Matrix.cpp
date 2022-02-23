#include<iostream>
#include<fstream>

using namespace std;

void addMat(){
    int row, col;
    double mat1[10][10], mat2[10][10], sum[10][10];
    // set size matrix
    cout << "Enter Row and Column Size of Matrix: ";
    cin >> row >> col;

    while(row > 10 || row < 1 || col > 10 || col < 1){
        cout << "Error! please input row and column in range 1-10.\n";
        cout << "Enter Row and Column Size of Matrix: ";
        cin >> row >> col;
    }
    // input
    cout << "\nEnter Elements of Matrix A: \n";
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            cout << "Enter A[" << i + 1 << "][" << j + 1 << "]: ";
            cin >> mat1[i][j];
        }
    }

    cout << "\nEnter Elements of Matrix B: \n";
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            cout << "Enter B[" << i + 1 << "][" << j + 1 << "]: ";
            cin >> mat2[i][j];
        }
    }
    // addition
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            sum[i][j] = mat1[i][j] + mat2[i][j];
        }
    }
    // display
    cout << "\nMatrix A:\n";
    for(int i = 0; i < row; i++) {
        cout << "[ ";
        for(int j = 0; j < col; j++) {
            cout << mat1[i][j] << " ";
        }
        cout << "]\n";
    }

    cout << "\nMatrix B:\n";
    for(int i = 0; i < row; i++) {
        cout << "[ ";
        for(int j = 0; j < col; j++) {
            cout << mat2[i][j] << " ";
        }
        cout << "]\n";
    }
    // ans
    cout << "\nAddition of Matrix A and Matrix B is:\n";
    for(int i = 0; i < row; i++) {
        cout << "[ ";
        for(int j = 0; j < col; j++) {
            cout << sum[i][j] << " ";
        }
        cout << "]\n";
    }
}

void subtractMat(){
    int row, col;
    double mat1[10][10], mat2[10][10], sum[10][10];
    // set size matrix
    cout << "Enter Row and Column Size of Matrix: ";
    cin >> row >> col;

    while(row > 10 || row < 1 || col > 10 || col < 1){
        cout << "Error! please input row and column in range 1-10.\n";
        cout << "Enter Row and Column Size of Matrix: ";
        cin >> row >> col;
    }
    // input
    cout << "\nEnter Elements of Matrix A: \n";
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            cout << "Enter A[" << i + 1 << "][" << j + 1 << "]: ";
            cin >> mat1[i][j];
        }
    }

    cout << "\nEnter Elements of Matrix B: \n";
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            cout << "Enter B[" << i + 1 << "][" << j + 1 << "]: ";
            cin >> mat2[i][j];
        }
    }
    // substraction
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            sum[i][j] = mat1[i][j] - mat2[i][j];
        }
    }
    // display
    cout << "\nMatrix A:\n";
    for(int i = 0; i < row; i++) {
        cout << "[ ";
        for(int j = 0; j < col; j++) {
            cout << mat1[i][j] << " ";
        }
        cout << "]\n";
    }

    cout << "\nMatrix B:\n";
    for(int i = 0; i < row; i++) {
        cout << "[ ";
        for(int j = 0; j < col; j++) {
            cout << mat2[i][j] << " ";
        }
        cout << "]\n";
    }
    // ans
    cout << "\nSubtraction of Matrix A and Matrix B is:\n";
    for(int i = 0; i < row; i++) {
        cout << "[ ";
        for(int j = 0; j < col; j++) {
            cout << sum[i][j] << " ";
        }
        cout << "]\n";
    }
}

void multiplyMat(){
    int row1, col1, row2, col2;
    double mat1[10][10], mat2[10][10], mult[10][10];
    // set size matrix
    cout << "Enter Row and Column Size of First Matrix: ";
    cin >> row1 >> col1;

    cout << "Enter Row and Column Size of Second Matrix: ";
    cin >> row2 >> col2;

    while(col1 != row2){
        cout << "Error! column of first matrix not equal to row of second.\n";

        cout << "Enter Row and Column Size of First Matrix: ";
        cin >> row1 >> col1;

        cout << "Enter Row and Column Size of Second Matrix: ";
        cin >> row2 >> col2;
    }
    // input
    cout << "\nEnter Elements of Matrix A: \n";
    for(int i = 0; i < row1; i++){
        for(int j = 0; j < col1; j++){
            cout << "Enter A[" << i + 1 << "][" << j + 1 << "]: ";
            cin >> mat1[i][j];
        }
    }

    cout << "\nEnter Elements of Matrix B: \n";
    for(int i = 0; i < row2; i++){
        for(int j = 0; j < col2; j++){
            cout << "Enter B[" << i + 1 << "][" << j + 1 << "]: ";
            cin >> mat2[i][j];
        }
    }
    // multiplication
    for(int i = 0; i < row1; i++){
        for(int j = 0; j < col2; j++){
            mult[i][j] = 0;
        }
    }

     for(int i = 0; i < row1; i++){
         for(int j = 0; j < col2; j++){
             for(int k = 0; k < col1; ++k){
                mult[i][j] += mat1[i][k] * mat2[k][j];
            }
         }     
     }
    // display
    cout << "\nMatrix A:\n";
    for(int i = 0; i < row1; i++) {
        cout << "[ ";
        for(int j = 0; j < col1; j++) {
            cout << mat1[i][j] << " ";
        }
        cout << "]\n";
    }

    cout << "\nMatrix B:\n";
    for(int i = 0; i < row2; i++) {
        cout << "[ ";
        for(int j = 0; j < col2; j++) {
            cout << mat2[i][j] << " ";
        }
        cout << "]\n";
    }
    // ans
    cout << "\nMultiplication of Matrix A and Matrix B is:\n";
    for(int i = 0; i < row1; i++) {
        cout << "[ ";
        for(int j = 0; j < col2; j++) {
            cout << mult[i][j] << " ";
        }
        cout << "]\n";
    }      
}

void subMat(double mat[10][10], double temp[10][10], int p, int q, int n){
    int i = 0, j = 0;
    for(int row = 0; row < n; row++){
        for(int col = 0; col < n; col++){
            if(row != p && col != q){
                temp[i][j++] = mat[row][col];
                if(j == n - 1){
                j = 0;
                i++;
                }
            }
        }
    }
}

double determinant2(double matrix[10][10], int n){
    double det = 0;
    if(n == 1){
        return matrix[0][0];
    }else if(n == 2){
        return ((matrix[0][0] * matrix[1][1]) - (matrix[0][1] * matrix[1][0]));
    }
    double temp[10][10], sign = 1;
    for(int i = 0; i < n; i++){
        subMat(matrix, temp, 0, i, n);
        det += sign * matrix[0][i] * determinant2(temp, n - 1);
        sign = -sign;
    }
    return det;
}

void detMat(){
    int size;
    double mat[10][10];
    // set size matrix
    cout << "Enter Size of Matrix: ";
    cin >> size;
    
    while(size > 10 || size < 1){
        cout << "Error! please input size in range 1-10.\n";
        cout << "Enter Size of Matrix: ";
        cin >> size;
    }
    // input
    cout << "\nEnter Elements of Matrix: \n";
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            cout << "Enter A[" << i + 1 << "][" << j + 1 << "]: ";
            cin >> mat[i][j];
        }
    }
    // display
    cout << "\nMatrix:\n";
    for(int i = 0; i < size; i++) {
        cout << "[ ";
        for(int j = 0; j < size; j++) {
            cout << mat[i][j] << " ";
        }
        cout << "]\n";
    }
    // ans
    cout << "\nDeterminant of Matrix is: " << determinant2(mat, size) << endl;
}

void mainMatrix(){
    while(true){
        cout << "---------------------------------------------------------------------------" << endl;
        cout << "                                    MATRIX                                 " << endl;
        cout << "---------------------------------------------------------------------------" << endl;
        ifstream srcMat;
        srcMat.open("utils/matrix.txt");
        string textline;
        while(getline(srcMat,textline)){
            cout << textline << endl;
        }
        srcMat.close();

        char x;
        cout << "Input: ";
        cin >> x;
        if(x == '1')
            addMat();
        else if(x == '2')
            subtractMat();
        else if(x == '3')
            multiplyMat();
        else if(x =='4')
            detMat();
        else if(x== '5')
            break;
        else
            cout << "Invalid input!!\n";
    }
}