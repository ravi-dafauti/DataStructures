/*
Given a Balanced Binary Search Tree and a target sum, write a function that returns true if there is a pair with sum equals to target sum,
otherwise return false. Expected time complexity is O(n) and only O(Logn) extra space can be used. 
Any modification to Binary Search Tree is not allowed. Note that height of a Balanced BST is always O(Logn).
*/
#include<iostream>
#include<stack>
using namespace std;

struct Node
{
	int data;
	Node *left, *right;
};
Node * NewNode(int val)
{
	Node *tmp = (Node *)malloc(sizeof(Node));
	tmp->data = val;
	tmp->right = tmp->left = NULL;
	return tmp;
}

bool isPairPresent(Node *root, int sum)
{
	if (!root)
		return false;
	bool done1, done2;
	int val1, val2;
	Node *cur1, *cur2;
	done1 = done2 = false;
	stack<Node *> s1;
	stack<Node *> s2;
	cur1 = cur2 = root;
	while (1)
	{
		while (!done1)
		{
			if (cur1)
			{
				s1.push(cur1);
				cur1 = cur1->left;
			}
			else
			{
				if (s1.empty())
					done1 = true;
				else
				{
					cur1 = s1.top();
					s1.pop();
					val1 = cur1->data;
					cur1 = cur1->right;
					done1 = true;
				}
			}
		}
		while (!done2)
		{
			if (cur2)
			{
				s2.push(cur2);
				cur2 = cur2->right;
			}
			else
			{
				if (s2.empty())
					done2 = true;
				else
				{
					cur2 = s2.top();
					s2.pop();
					val2 = cur2->data;
					cur2 = cur2->left;
					done2 = true;
				}
			}
		}
		if (val1 != val2&&(val1 + val2) == sum)
			return true;
		else if (val1 + val2 < sum)
		{
			done1 = false;
		}
		else if (val1 + val2 > sum)
		{
			done2 = false;
		}
		if (val1 >= val2)
			return false;
	}
}
// Driver program to test above functions
int main()
{

    /*
                   15
                /     \
              10      20
             / \     /  \
            8  12   16  25    */
	Node *root = NewNode(15);
	root->left = NewNode(10);
	root->right = NewNode(20);
	root->left->left = NewNode(8);
	root->left->right = NewNode(12);
	root->right->left = NewNode(16);
	root->right->right = NewNode(25);

	int target = 33;
	if (isPairPresent(root, target) == false)
		cout << "\n No such values are found\n";
	else
		cout << "found pair\n";
	return 0;
}
