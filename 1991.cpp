#include <iostream>
using namespace std;
typedef struct Node
{
  char ele;
  struct Node *left;
  struct Node *right;
} Node;
Node *NewNode(char ele)
{
  Node *New;
  New = (Node *)malloc(sizeof(Node));
  New->ele = ele;
  New->left = NULL;
  New->right = NULL;
  return New;
}
Node *search_Node(Node *H, char ele)
{
  if (H != NULL)
  {
    if (H->ele == ele)
    {
      return H;
    }
    else
    {
      Node *tmp = search_Node(H->left, ele);
      if (tmp != NULL)
      {
        return tmp;
      }

      return search_Node(H->right, ele);
    }
  }
  return NULL;
}
void insert_Node(Node *H, char A, char B, char C)
{
  H->ele = A;
  if (B != '.')
  {
    H->left = NewNode(B);
  }
  if (C != '.')
  {
    H->right = NewNode(C);
  }
}

void print_pre(Node *H)
{
  if (H != NULL)
    cout << H->ele;
  if (H->left != NULL)
    print_pre(H->left);
  if (H->right != NULL)
    print_pre(H->right);
}
void print_in(Node *H)
{
  if (H->left != NULL)
    print_in(H->left);
  if (H != NULL)
    cout << H->ele;
  if (H->right != NULL)
    print_in(H->right);
}
void print_post(Node *H)
{
  if (H->left != NULL)
    print_post(H->left);
  if (H->right != NULL)
    print_post(H->right);
  if (H != NULL)
    cout << H->ele;
}

int main()
{
  Node *H = NewNode(NULL);
  Node *tmp;
  int N;
  int i;
  cin >> N ;
  for (i = 0; i < N; i++)
  {
    char A, B, C;
    cin >> A >>  B >> C;
    tmp = search_Node(H, A);
    if (tmp != NULL)
      insert_Node(tmp, A, B, C);
    else
      insert_Node(H, A, B, C);
  }
  print_pre(H);
  cout << endl;
  print_in(H);
  cout << endl;
  print_post(H);

  return 0;
}
