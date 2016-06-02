#include <iostream>
#include <vector>
#include <string>

class Queue
{
	int last_el;
	std::vector<int> q;
public:
	Queue(std::vector<int> q_v) : q(q_v), last_el(-1){};

	/* \func void add(int data){} добавлениe элемента */
	void add(int data) 
	{
		last_el++;
		q[last_el] = data;
		return;
	}
	/* \func void del(){} удалениe элемента */
	void del() 
	{
		std::vector<int> newQ = q;
		for (int i = 1; i < last_el + 1; i++)
			newQ[i - 1] = q[i];
		q = newQ;
		last_el--;
		return;
	}
	/* \func int get(){} Получение значения первого на выход элемента */
	int get() 
	{
		return q[0];
	}
	/* \func void print(){} печать содержимого очереди в данный момент */
	void print() 
	{
		for (int i = 0; i < last_el + 1; i++)
			std::cout << q[i] << " ";
	}

	~Queue(){};
};

int main()
{
	int n; int data = 0;
	std::string operation = "";
	std::cout << "write number of operations: "; std::cin >> n;
	std::vector<int> q(n);
	Queue queue(q);
	for (int i = 0; i < n; i++)
	{
		std::cin >> operation;
		if (operation == "add")
		{
			std::cin >> data;
			queue.add(data);
		}
		else if (operation == "del")
			queue.del();
		else if (operation == "get")
		{
			std::cout << queue.get() << std::endl;
		}
		else
			std::cout << "wrong operation name" << std::endl;
	}
	queue.print();
	system("pause");
	return 0;
}
