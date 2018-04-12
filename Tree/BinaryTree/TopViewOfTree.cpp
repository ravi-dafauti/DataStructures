/*
       1
    /     \
   2       3
  /  \    / \
 4    5  6   7
Top view of the above binary tree is
4 2 1 3 7

        1
      /   \
    2       3
      \   
        4  
          \
            5
             \
               6
Top view of the above binary tree is
2 1 3 6
*/
#include<iostream>
#include<unordered_map>
#include<queue>
using namespace std;
 
//Structure of binary tree
struct Node
{
    int data;
    struct Node* left, * right;
};
 
 
// function to create a new node
struct Node* newNode(int key)
{
    struct Node* node = new Node;
    node->data= key;
    node->left = node->right = NULL;
    return node;
}

void topView(Node *root)
{
	if (root == NULL)
		return;
	unordered_map<int, int> m;
	queue < pair<Node *, int>> q;
	q.push(make_pair(root, 0));
	while (!q.empty())
	{
		pair<Node *, int> temp = q.front();
		Node *n = temp.first;
		int index = temp.second;
		q.pop();
		if (m.find(index) == m.end())
			m[index] = n->data;
		if (n->left)
		{
			q.push(make_pair(n->left, index-1));
		}
		if (n->right)
		{
			q.push(make_pair(n->right, index+1));
		}
	}
	unordered_map<int, int>::iterator it;
	for (it = m.begin(); it != m.end(); it++)
	{
		cout << it->second << " ";
	}
}
// main function
int main()
{
    /* Create following Binary Tree
             1
           /  \
          2    3
           \
            4
             \
              5
               \
                6*/
                 
    Node *root=newNode(1);
    root->left=newNode(2);
    root->right=newNode(3);
    root->left->right=newNode(4);
    root->left->right->right=newNode(5);
    root->left->right->right->right=newNode(6);
     
	topView(root);
    return 0;
}