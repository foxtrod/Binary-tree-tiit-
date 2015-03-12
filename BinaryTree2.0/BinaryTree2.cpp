# include <iostream>
# include <conio.h>

using namespace std;

struct node
{
	int info; 
	node *left, *right;
};

node *tree = NULL; 

/*������� ������ �������� � �������� ������*/
void push(int a, node **t)
{
	if ((*t) == NULL) //���� ������ �� ����������
	{
		(*t) = new node; //�������� ������
		(*t)->info = a; //������ � ���������� ����� �������� a
		(*t)->left = (*t)->right = NULL; //������� ������ ��� ���������� �����
		return; 
	}
	//������ ����
	if (a>(*t)->info) 
	{
		push(a,&(*t)->right); 
	}
	else 
	{
		push(a,&(*t)->left); 
	}
}

/*������� ����������� ������ �� ������*/
void print(node *t,int u) 
{
	if (t == NULL)
	{
		return; //���� ������ ������, �� ���������� ������
	}
	else 
	{
		print(t->left, u++);//� ������� ������������ �������� ����� ���������
		for (int i = 0; i < u; i++) cout << "|"; //��� �������
		cout << t->info << endl; //� ���������� �������
		u --;
	}
	print(t->right, u++); //� ������� �������� �������� ������ ���������
}

node *search(node *tree, int key)
{
	if(!tree)
	{
		return tree; //pustoe derevo
	}
	
	while (tree->info != key)
	{
		if (key < tree->info)
		{
			tree = tree->left;
		}
		else
		{
			tree = tree->right;
		}
		if (tree == NULL)
		{
			break;
		}
	}
	return tree;
}

void add_element()
{

}

void main ()
{   
	int n; 
	int s; 
	cout << "Enter number of elements: ";
	cin >> n; 

	for (int i = 0; i < n; i++)
	{
		cout << "Enter a number " << i << ": ";
		cin >> s; 
		push(s, &tree); 
	}
	cout << "Tree \n";
	print(tree, 0);
	getch();       
	*search(tree, 10);
	getch();
} 