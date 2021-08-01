#include <iostream>

  /*
    출력 : 첫째 줄부터 N개 줄에 걸쳐 행렬 A를 B제곱한 결과를 출력한다.
  */
using namespace std;
#define MOD 1000

int N;
long long B;
int matrix[5][5];
int answ[5][5];
void Print_arr(){
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      cout << answ[i][j] << " ";
    }
    cout << endl;
  }
}
void matmul(int x[5][5], int y[5][5]){
  int temp[5][5]= {0,};
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      for(int k=0;k<N;k++){
        temp[i][j] += (x[i][k] * y[k][j]) % MOD;
      }
    }
  }

  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      x[i][j] = temp[i][j] % MOD;
    }
  }
}
void Solved(){
  while(1){
    if((B % 2) == 1){
      // B가 홀수 일 경우.
      matmul(answ,matrix);
    }
    matmul(matrix,matrix);
    B /= 2;
    if(B == 0)
      break;
  }
}

int main(){
  cin >> N  >> B;
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      cin >> matrix[i][j];
    }
    answ[i][i] = 1;
  }
  Solved();
  Print_arr();
}