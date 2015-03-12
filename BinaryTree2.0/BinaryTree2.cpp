# include <iostream>
# include <conio.h>

using namespace std;

struct node
{
	int info; 
	node *left, *right;
};

node *tree = NULL; 

/*ФУНКЦИЯ ЗАПИСИ ЭЛЕМЕНТА В БИНАРНОЕ ДЕРЕВО*/
void push(int a, node **t)
{
	if ((*t) == NULL) //Если дерева не существует
	{
		(*t) = new node; //Выделяем память
		(*t)->info = a; //Кладем в выделенное место аргумент a
		(*t)->left = (*t)->right = NULL; //Очищаем память для следующего роста
		return; 
	}
	//Дерево есть
	if (a>(*t)->info) 
	{
		push(a,&(*t)->right); 
	}
	else 
	{
		push(a,&(*t)->left); 
	}
}

/*ФУНКЦИЯ ОТОБРАЖЕНИЯ ДЕРЕВА НА ЭКРАНЕ*/
void print(node *t,int u) 
{
	if (t == NULL)
	{
		return; //Если дерево пустое, то отображает ничего
	}
	else 
	{
		print(t->left, u++);//С помощью рекурсивного посещаем левое поддерево
		for (int i = 0; i < u; i++) cout << "|"; //Для красоты
		cout << t->info << endl; //И показываем элемент
		u --;
	}
	print(t->right, u++); //С помощью рекурсии посещаем правое поддерево
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