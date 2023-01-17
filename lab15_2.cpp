#include<iostream>
using namespace std;

const int N = 5;

void inputMatrix(double [][N]);

void findLocalMax(const double [][N], bool [][N]);

void showMatrix(const bool [][N]);

int main(){
	double A[N][N]; 
	bool B[N][N]; 
	cout << "Input the matrix.....\n";
	inputMatrix(A);
	findLocalMax(A,B);
	cout << "Result is \n";
	showMatrix(B);
	return 0;
}
void showMatrix(const bool A[N][N]){
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(A[i][j]){
                cout << 1 << " ";
            }
            else cout << 0 << " "; 
        }
        cout << "\n";
    }
}
void inputMatrix(double A[N][N]){
    for(int r=0; r<N; r++){
    cout << "Row " << r+1 <<": ";    
    for(int c=0; c<N;c++){
            cin >> A[r][c];
        }
    }
}
void findLocalMax(const double A[N][N], bool B[N][N]){
    for(int r=0; r<N; r++){
        for(int c=0; c<N;c++){
            if(r==0||c==0||r==N-1||c==N-1){
                B[r][c] = false;
            }
            else if(A[r][c]>=A[r-1][c] && A[r][c]>=A[r][c-1] && A[r][c]>=A[r+1][c] && A[r][c]>=A[r][c+1]){
                B[r][c] = true;
            }
            else B[r][c] = false; 
        }
    }
}