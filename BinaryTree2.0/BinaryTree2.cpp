#include <iostream>
#include <conio.h>
#include "head.h"

using namespace std;

/*ФУНКЦИЯ ЗАПИСИ ЭЛЕМЕНТА В БИНАРНОЕ ДЕРЕВО*/
void add_element(int a, node **t)
{
	if ((*t) == NULL) //Если дерева не существует
	{
		(*t) = new node; //Выделяем память
		(*t)->data = a; //Кладем в выделенное место аргумент a
		(*t)->left = (*t)->right = NULL; //Очищаем память для следующего роста
		return; 
	}
	//Дерево есть
	if (a>(*t)->data) 
	{
		add_element(a,&(*t)->right); 
	}
	else 
	{
		add_element(a,&(*t)->left); 
	}
}

/*ФУНКЦИЯ ОТОБРАЖЕНИЯ ДЕРЕВА НА ЭКРАНЕ*/
void print_tree(node *t,int u) 
{
	if (t == NULL)
	{
		return; //Если дерево пустое, то отображает ничего
	}
	else 
	{
		print_tree(t->left, u++);//С помощью рекурсивного посещаем левое поддерево
		for (int i = 0; i < u; i++) cout << "|"; //Для красоты
		cout << t->data << endl; //И показываем элемент
		u --;
	}
	print_tree(t->right, u++); //С помощью рекурсии посещаем правое поддерево
}

/*ФУНЦИЯ ПОИСКА*/
node *search(node *tree, int key)
{
	if(!tree)
	{
		return tree; //Пустое дерево
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

/*Функция удаления*/
void remove_element()
{
	
}

/*Функция обхода*/
void view_tree()
{
		
}

/*Функция построения дерева из массива*/
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





	