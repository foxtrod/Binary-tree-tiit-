#include <iostream>
#include <conio.h>
#include "head.h"

using namespace std;

/*������� ������ �������� � �������� ������*/
void add_element(int a, node **t)
{
	if ((*t) == NULL) //���� ������ �� ����������
	{
		(*t) = new node; //�������� ������
		(*t)->data = a; //������ � ���������� ����� �������� a
		(*t)->left = (*t)->right = NULL; //������� ������ ��� ���������� �����
		return; 
	}
	//������ ����
	if (a>(*t)->data) 
	{
		add_element(a,&(*t)->right); 
	}
	else 
	{
		add_element(a,&(*t)->left); 
	}
}

/*������� ����������� ������ �� ������*/
void print_tree(node *t,int u) 
{
	if (t == NULL)
	{
		return; //���� ������ ������, �� ���������� ������
	}
	else 
	{
		print_tree(t->left, u++);//� ������� ������������ �������� ����� ���������
		for (int i = 0; i < u; i++) cout << "|"; //��� �������
		cout << t->data << endl; //� ���������� �������
		u --;
	}
	print_tree(t->right, u++); //� ������� �������� �������� ������ ���������
}

/*������ ������*/
node *search(node *tree, int key)
{
	if(!tree)
	{
		return tree; //������ ������
	}
	
	while (tree->data != key)
	{
		if (key < tree->data)
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
	if (tree->data = key)
	{
		cout << "Found" << endl;	
	}
	else
	{
		cout << "Not found" << endl;
	}
}

/*������� ��������*/
void remove_element()
{
	
}

/*������� ������*/
void view_tree()
{
		
}

/*������� ���������� ������ �� �������*/
void tree_array()
{
	
}



int menu()
{
	cout << "1. Find element" << endl;
	cout << "2. Remove element" << endl;
	cout << "3. View tree" << endl;
	cout << "4. Tree of arrays" << endl;
	cout << "5. Exit" << endl;
	int i;
	cin >> i;
	return i;
}

int main ()
{   
	int n; 
	int s; 
	cout << "Enter number of elements: ";
	cin >> n; 
	for (int i = 0; i < n; i++)
	{
		cout << "Enter a number " << i << ": ";
		cin >> s; 
		add_element(s, &tree); 
	}
	cout << "Tree \n";
	print_tree(tree, 0);
	getch();

	while(true)
	{
		switch(menu())
		{
			case 1: *search(tree, 10);
			case 2: remove_element();
			case 3: view_tree();
			case 4: tree_array();
			case 5: return 0;
		}
		puts("Press any key to continue");
		getch();
		system("cls");
	}
} 





	