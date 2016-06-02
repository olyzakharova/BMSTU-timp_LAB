#include <iostream>
#include <string>

struct ListObj
{
	int data;
	ListObj* next;

	ListObj(int data_v) : data(data_v), next(nullptr) {}
	~ListObj()
	{
		if (next != nullptr)
			delete next;
	}
};
class List
{
	ListObj* root;
	int last_el;
public:
	List() : root(nullptr), last_el(0) {};

	/* \func void add(int i, int data_v){} добавление элемента перед заданным индексом (начиная с 0) */
	void add(int i, int data_v)
	{
		if (i > last_el)
			std::cout << "index is too big";
		else if (i == 0)
		{
			ListObj* newRoot = new ListObj(data_v);
			newRoot->next = root;
			root = newRoot;
		}
		else
		{
			ListObj* prev_ = nullptr; ListObj* next_ = root;
			for (int j = 0; j < i; j++)
			{
				prev_ = next_;
				next_ = next_->next;
			}
			ListObj* newObj = new ListObj(data_v);
			prev_->next = newObj;
			newObj->next = next_;
		}
		last_el++;
		return;
	}
	/* \func int get(int i){} Получение значения элемента по индексу i */
	int get(int i)
	{
		if (i >= last_el)
		{
			std::cout << "index is too big";
			return 0;
		}
		else
		{
			ListObj* next_ = root;
			for (int j = 0; j < i; j++)
				next_ = next_->next;
			return next_->data;
		}
	}
	/* \func void del(int i){} удалениe элемента перед заданным индексом i */
	void del(int i)
	{
		ListObj* prev_ = nullptr; ListObj* next_ = root;
		for (int j = 0; j < i; j++)
		{
			prev_ = next_;
			next_ = next_->next;
		}
		next_ = prev_->next->next;
		prev_->next->next = nullptr;
		delete prev_->next;
		prev_->next = next_;
		last_el--;
		return;
	}
	/* \func void print(){} печать содержимого списка*/
	void print()
	{
		ListObj* thisObj = root;
		for (int i = 0; i < last_el; i++)
		{
			std::cout << thisObj->data << " ";
			thisObj = thisObj->next;
		}
	}

	~List()
	{ delete root; }
};

int main()
{
	int n;
	std::string operation = "";
	int index = 0; int data = 0;
	int k = 0;
	List l;
	std::cout << "write number of operations: "; std::cin >> n;
	for (int i = 0; i < n; i++)
	{
		std::cin >> operation;
		if (operation == "add")
		{
			std::cin >> index >> data;
			l.add(index, data);
		}
		else if (operation == "del")
		{
			std::cin >> index;
			l.del(index);
		}
		else if (operation == "get")
		{
			std::cin >> index;
			std::cout << l.get(index) << std::endl;
		}
		else
			std::cout << "wrong operation name" << std::endl;
	}
	l.print();
	system("pause");
	return 0;
}
