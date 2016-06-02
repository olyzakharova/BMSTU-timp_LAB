#include <iostream>
#include <vector>
#include <string>

class Stack
{
	int last_el; // point to last element
	std::vector<int> st;
public:
	Stack(std::vector<int> v_v) : last_el(-1), st(v_v){};
	
	/* \func void add(int num){} Функция добавления элемента*/
	void add(int num) 
	{
		last_el++;
		st[last_el] = num;
		return;
	}
	/* \func int get(){} Получение значения верхнего элемента*/
	int get() 
	{
		return st[last_el];
	}
	/* \func void del(){}  Функция удаления элемента*/
	void del() 
	{
		last_el--;
		return;
	}
	/* \func void print(){} печать содержимого стека в данный момент */
	void print() 
	{
		for (int i = 0; i < last_el + 1; i++)
			std::cout << st[i] << " ";
	}

	~Stack(){};
};

int main()
{
	int n; int data = 0;
	std::string operation = "";
	std::cout << "write number of operations: "; std::cin >> n;
	std::vector<int> v(n);
	Stack s(v);
	for (int i = 0; i < n; i++)
	{
		std::cin >> operation;
		if (operation == "add")
		{
			std::cin >> data;
			s.add(data);
		}
		else if (operation == "del")
			s.del();
		else if (operation == "get")
		{
			std::cout << s.get() << std::endl;
		}
		else
			std::cout << "wrong operation name" << std::endl;
	}
	s.print();
	system("pause");
	return 0;
}
