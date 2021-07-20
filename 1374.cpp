#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <functional>

#define lesson_num 1000000000
using namespace std;
typedef struct lesson{
  int num;
  int start;
  int end;
  int dur;
}lesson;
bool my_sort(lesson p1, lesson p2){
  return p1.start > p2.start;
}
int Duplicated_lesson[lesson_num] = {0};
int main(){
  int N;
  cin >> N;
  vector<lesson> v;
  for(int i=0;i<N;i++){
    lesson temp;
    cin >> temp.num >> temp.start >> temp.end;
    temp.dur = temp.start - temp.end;
    v.push_back(temp);
  }

  sort(v.begin(),v.end(),my_sort);

  for(int i=0;i<lesson_num;i++){
    for(int j=0;j<v.size();j++){
      if(v[j].start < (i+0.5) && (i+0.5) < v[j].end)
        Duplicated_lesson[i]++;
    }
  }
  priority_queue<int> pq;
  pq.
  queue<lesson> q;
  while(!q.empty()){

  }
  

  return 0;
}