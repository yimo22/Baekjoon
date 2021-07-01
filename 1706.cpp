#include <stdio.h>
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <string>
#include <set>
using namespace std;
int N,M;
int g_cnt = 0;
vector<string> arr;
set<string> result;

int main(void)
{
	std::cin >> N >> M;
	vector<vector<char>> graph;
	graph.resize(N);

	for (int i = 0; i < N; i++)
	{
		string temp;
		graph[i].resize(M);
		std::cin >> temp;
		for (int j = 0; j < M; j++)
		{
			graph[i][j] = temp[j];
		}
	}
	for (int i = 0; i < N; i++)
	{
		string k;
		for (int j = 0; j < M; j++)
		{
			if (graph[i][j] != '#')
			{
				k = k + graph[i][j];
			}
			if (graph[i][j] == '#' || j==M-1)
			{
				if (k.size() > 1)
				{
					result.insert(k);
					k.clear();
				}
				else
				{
					k.clear();
				}
			}
		}
	}
	for (int i = 0; i < M; i++)
	{
		string k;
		for (int j = 0; j < N; j++)
		{
			if (graph[j][i] != '#')
			{
				k = k + graph[j][i];
			}
			if (graph[j][i] == '#' || j == N-1)
			{
				if (k.size() > 1)
				{
				//	std::cout << k << endl;
					result.insert(k);
					k.clear();
				}
				else
				{
					k.clear();
				}
			}
		}
	}
	auto it = result.begin();
	std::cout << *it;
	   	  
	return 0;
	
}