/*
	joon - #1068
	트리
	Coded by yimo22
*/
#include <iostream>
using namespace std;
#define Max 50
typedef struct Node
{
    int value;
    int parent_Node;
} Node;
Node s[Max];
int Visited[Max];
void DeleteNode(int dNode, int size)
{
    s[dNode].parent_Node = -2;

    for (int i = 0; i < size; i++)
    {
        if (s[i].parent_Node == dNode && s[i].parent_Node != -2)
        {
            DeleteNode(i, size);
        }
    }
}
int Find_Leaf(int size)
{
    int cnt = 0, root;
    // 루트만 남은 경우

    for (; root < size; root++)
        if (s[root].parent_Node == -1)
        {
            break;
        }
    for (int i = 0; i < size; i++)
    {
        if (s[i].parent_Node == -2) // deleted
            continue;
        bool flag = false;
        if (Visited[i] != 1)
        {
            for (int j = 0; j < size; j++)
            {
                if (s[i].parent_Node == -2) // deleted
                    continue;

                if (s[j].parent_Node == i)
                {
                    flag = true;
                    break;
                }
            }
            if (flag)
            {
                continue;
            }
            else
            {
                Visited[i] = 1;
                cnt++;
            }
        }
    }

    return cnt;
}
int main()
{
    int cnt_node = 0;
    cin >> cnt_node;
    for (int i = 0; i < cnt_node; i++)
    {
        Node temp;
        temp.value = i;
        cin >> temp.parent_Node;
        s[i] = temp;
    }
    int del_node;
    cin >> del_node;

    // 해당 원소 삭제
    DeleteNode(del_node, cnt_node);

    cout << Find_Leaf(cnt_node);

    return 0;
}