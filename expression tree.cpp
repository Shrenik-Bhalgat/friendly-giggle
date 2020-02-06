#include<iostream>
#include<stack>
#include<string.h>
using namespace std;

struct node
{
	node *left,*right;
	char data;	 
};

class exptree
{
	public:
		node *root,*curr;
		stack<node*> s;
		
		exrtree()
		{
			root=NULL;
		}
		
		void tree()
		{
			char x;
			curr=new node;
			cout<<"Enter the term: ";
			cin>>x;               
			curr->data=x;
			curr->left=NULL;
			curr->right=NULL;
			if(curr->data=='*'||curr->data=='+'||curr->data=='-'||curr->data=='/'||curr->data=='^')
			{
				curr->right=s.top();
				s.pop();
				curr->left=s.top();
				s.pop();
			}
			s.push(curr);
			root=s.top();
		}
		
		void inorder(node *temp)				
		{
			if(temp!=NULL)
			{
				inorder(temp->left);
				cout<<temp->data<<"\t";
				inorder(temp->right);
			}
		}
		
};

int main()
{
	exptree e;
	int n;
	cout<<"Enter no of terms in exp: ";
	cin>>n;
	for(int i=0;i<n;i++)
	{
		e.tree();
	}
	e.inorder(e.root);
}
