/*
	joon - #1260
	DFS와 BFS - DFS/BFS
	Coded by yimo22
*/
#include <iostream>
#include <queue>
#include <vector>
#define MAX 1000
using namespace  std;
vector<int> v;
queue<int> q;
void DFS(int matrix[MAX+1][MAX+1],int cur_city, int Max_city, int* visted_ptr){
	for(int i=1;i<=Max_city;i++){
		// cur_city -> i 로 경로가 있을경우 , 방문하지 않는 도시 일경우
		if((matrix[cur_city][i] == 1 || matrix[i][cur_city]==1) && visted_ptr[i]!=1){
			visted_ptr[i] = 1;
			v.push_back(i);
			DFS(matrix,i,Max_city,visted_ptr);
		}
	}
}
void BFS(int matrix[MAX+1][MAX+1], int Max_city, int* visted_ptr){
	while(!q.empty()){
		int cur_city = q.front();
		q.pop();
		// 가능한 도시들을 Que에 push
		for(int i=1;i<=Max_city;i++){
		// cur_city -> i 로 경로가 있을경우 , 방문하지 않는 도시 일경우
			if((matrix[cur_city][i] == 1 || matrix[i][cur_city]==1)&& visted_ptr[i]!=1){
				visted_ptr[i] = 1;
		
				q.push(i);
			}
		}
		// 방문한 도시 저장
		v.push_back(cur_city);
	}
}
void Print_Arry(){
	for(int i=0;i<v.size();i++)
		cout << v[i]<<" ";
	cout << "\n";
}
int main(){
	int N,M,V;
	cin >> N >> M >> V;
	
	// 인접행렬
	int matrix[MAX+1][MAX+1]={0};

	for(int i=0;i<M;i++){
		int start,end;
		cin >> start >> end;
		matrix[start][end] = 1;
	}
	// 도시의 방문 여부 저장
	int isVisited[MAX+1]={-1};

	// 현재 도시를 방문도시로 추가 및 DFS 탐색
	v.push_back(V);
	isVisited[V]=1;
	DFS(matrix,V,N,isVisited);
	Print_Arry();

	// visited[] 초기화 , vector 초기화
	for(int i=0;i<=MAX;i++)
		isVisited[i]=-1;
	v.clear();

	//BFS 탐색 시작
	q.push(V);
	isVisited[V]=1;
	BFS(matrix,N,isVisited);
	Print_Arry();
	
	return 0;
}