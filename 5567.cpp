#include <iostream>
#include <queue>
#include <vector>

using namespace std;
int relation[500+1][500+1]={0};
int isFriend[500+1]={0};
int main(){
  int n, m;
  cin >> n;
  cin >> m;
  for(int i=0;i<m;i++){
    int a,b;
    cin >> a >> b;
    relation[a][b] = 1;
    relation[b][a] = 1;
  }
  for(int i=2;i<=n;i++){
    if(relation[1][i]){
      isFriend[i] = 1;
      for(int j=2;j<=n;j++){
        if(relation[i][j])
          isFriend[j]=1;
      }
    }
  }
  int result=0;
  for(int i=2;i<=n;i++){
    if(isFriend[i]== 1 )
      result++;
  }
  cout << result << endl;
}
