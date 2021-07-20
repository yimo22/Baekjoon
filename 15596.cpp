#include <vector>
#include <iostream>

long long sum(std::vector<int> &a){
  int len = a.size();
  long long sum = 0;
  for(int i=0;i<len;i++){
    sum += a[i];
  }

  return sum;
}