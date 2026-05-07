#include <iostream>
#include <Windows.h>
using namespace std;

struct elem
{
	int key;
	elem* pleft, * pright;
} *root = NULL;

void add(int n, elem* &t);
void inorder(elem* t);
elem* findParent(int k);
void printmenu();

int main()
{
	int izbor, num;

	do
	{
		printmenu();
		cin >> izbor;

		switch (izbor)
		{
			case 1:
				cout << "Enter a number: ";
				cin >> num;
				add(num, root);
				cout << "The number has been added!\n";
				break;

			case 2:
				cout << "Elements in ascending order (inorder): ";
				inorder(root);
				cout << "\n";
				break;

			case 3:
			{


				// Find parent
				cout << "Find parent of: ";
				cin >> num;

				//  Ако търсеният елемент е самият корен,
				// той НЯМА родител (той е върхът на дървото).
				if (root != NULL && root->key == num)
				{
					cout << "Element " << num
						<< " is the ROOT - has no parent.\n";
					break;
				}

				// Викаме функцията, тя връща указател към родителя
					// (или NULL ако елементът не е намерен)
				elem* parent = findParent(num);

				if (parent == NULL)
					cout << "Element " << num
					<< " is NOT found in the tree.\n";
				else
					cout << "Parent of " << num
					<< " is: " << parent->key << "\n";
				break;
			}
			case 4:
				cout << "Exiting the program.\n";
				break;


			default:
				cout << "Invalid choice.\n";
		}

	} while (izbor != 4);
	
	system("pause");
	return 0;
}

void printmenu()
{
	cout << "1. Add element\n";
	cout << "2. Display elements in ascending order (inorder)\n";
	cout << "3. Find parent of a given element\n";
	cout << "4. Exit\n";
	cout << "Choose an option: ";
}

void add(int n, elem* &t)
{
	if (t == NULL)
	{
		t = new elem;
		t->key = n;
		t->pleft = t->pright = NULL; // листото няма деца
	}
	else
	{
		if (n < t->key)
			add(n, t->pleft); // n е по-голямо -> търсим дясно
		else
			add(n, t->pright); // n е по-малко или равно -> търсим ляво
	}
}

void inorder(elem* t)
{
	if (t)
	{
		inorder(t->pleft);
		cout << t->key << " ";
		inorder(t->pright);
	}
}

elem* findParent (int k)
{
	elem* current = root; // Започваме от корена
	elem* parent = NULL;  // Корена няма родител -> NULL
	while (current != NULL) 
	{
		if (current->key == k)
			return parent; // намерихме елемента, връщаме родителя
		parent = current; // запазваме текущия като потенциален родител
		if (k < current->key)
			current = current->pleft; // търсим в лявото поддърво
		else
			current = current->pright; // търсим в дясното поддърво
	}
	return NULL; // елементът не е намерен
}
