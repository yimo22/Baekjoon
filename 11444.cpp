#include <iostream>

using namespace std;
#define MOD 1000000007
long long matrix[2][2] = {{1,1} , {1,0}};
long long N;
long long answ[2][2]={{1,0},{0,1}}; // 전치행렬
void matmul_matrix(long long data[2][2], long long operand[2][2]){
  long long temp[2][2]={0};
  for(int i=0;i<2;i++){
    for(int k=0;k<2;k++){
      for(int j=0;j<2;j++)
        temp[i][k] = (data[i][j] * operand[j][k] + temp[i][k]) % MOD;
        
    }
  }
  for(int i=0;i<2;i++)
    for(int j=0;j<2;j++)
      data[i][j] = temp[i][j];
}
void Solved(){
  if(N <= 0 )
    return ;
  
  while(1){
    if(N%2){
      // N 이 홀수 일 경우
      matmul_matrix(answ,matrix);
    }
    matmul_matrix(matrix,matrix);
    N /= 2;
    if(N == 0)
      break;
  }
}
int main(){
  cin >> N;

  Solved();
  cout << answ[0][1] << "\n";

  return 0;
}