#include "stdafx.h"
#include <iostream>
using namespace std;

int getroot(int *t, int n) //функция возвращает индекс корня -1
{
	for (int i = 0; i < n; i++)
	{
		if (t[i] == -1)
		{
			return i;
		}
	}
	return -1;
}
int getparent(int *t, int node) //функция возвращает индекс узла
{
	return t[node];
}
int getleftbro(int *t, int n, int node) //функция возвращает индекс левого сына
{
	for (int i = 0; i < n; i++)
	{
		if (t[i] == node)
		{
			return i;
		}
	}
	return -2;
}
int getrightbro(int *t, int n, int node) //функция возвращает индекс правого сына
{
	int parent = getparent(t, node);
	for (int i =( node + 1); i < n; i++)
	{
		if (t[i] == parent)
		{
			return i;
		}
	}
	return -3;
}

int soncount(int *t, int n, int node) //функция возвращает количество поддеревьев
{
	int k = 0;
	for (int i = 0; i < n; i++) 
	{
		if (t[i] == node) { k++; }
	}
	return k;
}
void pr_godown(int *t, int n, int node) //прямой обход (сверху-вниз)
{
	cout << node << " ";
	int p = soncount(t, n, node);
	if (p == 0) return;
	int ls = getleftbro(t, n, node);
	pr_godown(t, n, ls);
	for (int i = 0; i < (p - 1); i++) 
	{
		pr_godown(t, n, getrightbro(t, n, ls));
		ls = getrightbro(t, n, ls);
	}
}
void godown(int *t, int n)
{
	pr_godown(t, n, getroot(t, n));
	cout << endl;
}
void pr_goup(int *t, int n, int node) //обратный обход (снизу-вверх)
{
	int p = soncount(t, n, node);

	if (p == 0) 
	{
		cout << node << " ";
		return;
	} 
	int ls = getleftbro(t, n, node);
	pr_goup(t, n, ls);
	for (int i = 0; i < (p - 1); i++)
	{
		pr_goup(t, n, getrightbro(t, n, ls));
		ls = getrightbro(t, n, ls);
	}
	cout << node << " ";
}
void goup(int *t, int n) 
{
	pr_goup(t, n, (getroot(t, n)));
	cout << endl;
}
void pr_symmetr(int *t, int n, int node) //обход в симметричном порядке
{
	int p = soncount(t, n, node);
	if (p == 0)
	{
		cout << node << " ";
		return;
	}
	int ls = getleftbro(t, n, node);
	pr_symmetr(t, n, ls);
	cout << node << " ";
	for (int i = 0; i < (p - 1); i++)
	{
		pr_symmetr(t, n, getrightbro(t, n, ls));
		ls = getrightbro(t, n, ls);
	}
}
void symmetr(int *t, int n) 
{
	pr_symmetr(t, n, (getroot(t, n)));
	cout << endl;
}

int main()
{
	int n, i;
	int *tree;
	cout<<"n= "; 
	cin>>n;
		tree = new int[n];
		for (i = 0; i<n; i++)
		{
			cin >> tree[i];
		}
		//совершаем обход
		godown(tree, n);
		goup(tree, n);
		symmetr(tree, n);
}
