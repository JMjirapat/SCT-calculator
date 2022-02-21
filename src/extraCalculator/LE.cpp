#include<iostream>
#include<cmath>
using namespace std;

double determinant(double matrix[10][10], int n){ // Calculate determinant of matrix
   double det = 0;
   double submatrix[10][10];
   if(n == 2)
   return ((matrix[0][0] * matrix[1][1]) - (matrix[1][0] * matrix[0][1]));
   else{
      for(int x = 0; x < n; x++){
         int subi = 0;
         for(int i = 1; i < n; i++){
            int subj = 0;
            for(int j = 0; j < n; j++){
               if(j == x)
               continue;
               submatrix[subi][subj] = matrix[i][j];
               subj++;
            }
            subi++;
         }
         det = det + (pow(-1, x) * matrix[0][x] * determinant(submatrix, n - 1 ));
      }
   }
   return det;
}

void shiftdet(double coeff[10][10],double val[10],double ph[10],int n){ // Get the sub det. of each variable then store it in ph[] 
    double shift[10][10];
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            shift[i][j] = coeff[i][j];
        }
    }
    for (int k = 0; k < n; k++){
        for (int l = 0; l < n; l++){
            shift[l][k] = val[l];
        }
        ph[k] = determinant(shift, n);
        for (int i = 0; i < n; i++){
           for (int j = 0; j < n; j++){
              shift[i][j] = coeff[i][j];
            }
        }
    }
}

void solve(double coeff[10][10],double val[10],double ans[10],int n){ // main solving part
    double maindet = determinant(coeff,n);
    double ph[10];
    shiftdet(coeff,val,ph,n);
    for(int i = 0; i < n; i++){
       ans[i] = (ph[i]/maindet);
    }
    if(maindet != 0){ // have solution
        cout << "\nThere is the solution to the equation! :D\n";
        for(int i = 0; i < n; i++){
           cout << "The value of variable[" << i+1 << "] is " << ph[i] << "/" << maindet << " or " << ans[i] << "\n";
        }
    }
    else{ // no value
        bool nosolcheck = false;
        for(int i = 0; i < n; i++){
           if(ph[i] != 0) nosolcheck = true;
        }
        if (nosolcheck == true) cout << "\nUnfortunately,The equation have no solutions.\n";
        else cout << "\nUnfortunately,There is an infinite solution for the value of variable.\n";
    }
}

void LE(){ // main running part
   int n,i,j;
   cout << "[Linear equation solver!]\n";
   cout << "If the amount of variable is [n] then [n] must be [2 <= n <= 10]\n";
   cout << "Example of the variable coeffient: \n";
   cout << "|a(x)+b(y)+c(z)    a b c |\n";
   cout << "|d(x)+e(y)+f(z) -> d e f |\n";
   cout << "|g(x)+h(y)+i(z)    g h i |\n";
   cout << "Example of the equation value: \n";
   cout << "a(x)+b(y)+c(z)= [1]    \n";
   cout << "d(x)+e(y)+f(z)= [2] -> [1] [2] [3]\n";
   cout << "g(x)+h(y)+i(z)= [3]    \n";
   cout << "Enter the amount of the variable: ";
   cin >> n;
   while(n > 10 || n < 2){
       cout << "Please input [n] in scope of range! >:(\n";
       cout << "Enter the amount of the variable: ";
       cin >> n;
   }
   double coeff[10][10];
   double val[10];
   double ans[10];
   cout << "Enter the coeffient of the equation:\n";
   for(i = 0; i < n; i++)
   for(j = 0; j < n; j++)
   cin >> coeff[i][j];
   cout << "Enter the value of each equation:\n";
   for(i = 0; i < n; i++) cin >> val[i];
   solve(coeff,val,ans,n);
}

void mainLE(){
   bool next = 1;
   while(next){
      cout << "---------------------------------------------------------------------------" << endl;
      cout << "                                 LINEAR EQUATION                           " << endl;
      cout << "---------------------------------------------------------------------------" << endl;
      LE();
      cout << "Do you want calculate more? 0: No, 1: Yes" << endl << ">> ";
      cin >> next;
   }
}
