/*
	joon - #1068
	트리
	Coded by yimo22
*/
#include <iostream>
#include <vector>
using namespace std;
#define Max 50
typedef struct Node{
    int value;
    int parent_Node;
}Node;
Node s[Max];
void DeleteNode(int rootNode,int size){
    s[rootNode].parent_Node = -2;

    for(int i=rootNode+1;i<size;i++){
        if(s[i].parent_Node == rootNode && s[i].parent_Node != -2){
            DeleteNode(i,size);
        } 
    }
}
int main()
{
    int cnt_node =0;
    cin >> cnt_node;
    for(int i=0;i<cnt_node;i++){
        Node temp;
        temp.value = i;
        cin >> temp.parent_Node ;
        s[i] = temp;
    }
    int del_node;
    cin >> del_node;

    // 해당 원소 삭제
    DeleteNode(del_node,cnt_node);


    



    return 0;
}