/*
	joon - #1931
	회의실 배정 - Greedy
	coded by yimo22
*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef struct Meet{
	int start;
	int end;
}Meet;
bool cmp(Meet s, Meet t){
	if(s.end == t.end){
		return s.start < t.start;
	}else{
		return s.end < t.end;
	}
}
int main(){
	int N;
	cin >> N;

	vector<Meet> t(N);
	for(int i=0;i<N;i++){
		cin >> t[i].start >> t[i].end;
	}

	sort(t.begin(),t.end(),cmp);
	int cnt=0;
	int pre_mt=0;
	for(int i=0;i<t.size();i++){
		if(pre_mt <= t[i].start){
			// reset
			pre_mt = t[i].end;
			cnt++;
		}
	}

	cout << cnt << endl;
}