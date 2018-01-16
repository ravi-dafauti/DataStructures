/*given a postorder traversal contruct an expression tree
eg : ABC*+D/ 
              (/)
			/    \
		  (+)     D
		 /  \
		A   (*)
            /  \
           B    C
*/
#include<iostream>
#include<stack>
#include<string>
using namespace std;

struct Node
{
	char data;
	Node *left;
	Node *right;
};

Node *createNode(char data)
{
	Node *temp = (Node *)malloc(sizeof(Node));
	temp->data = data;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

bool isOperator(char a)
{
	if (a == '+' || a == '-' || a == '/' || a == '*')
		return true;
	return false;
}
Node *createExpressionTree(string postorder)
{
	stack<Node *> aux_stack;
	for (int i = 0; i < postorder.length(); i++)
	{
		Node *temp = createNode(postorder.at(i));
		if (isOperator(postorder.at(i)))
		{
			temp->right = aux_stack.top();
			aux_stack.pop();
			temp->left = aux_stack.top();
			aux_stack.pop();
		}
		aux_stack.push(temp);
	}
	return aux_stack.top();
}
void inorderTraversal(Node *root_ref)
{
	if (root_ref)
	{
		inorderTraversal(root_ref->left);
		cout << root_ref->data << " ";
		inorderTraversal(root_ref->right);
	}
}
int main()
{
	string expression = "ABC*+D/";
	Node *root = createExpressionTree(expression);
	inorderTraversal(root);
	return 0;
}