#include"Worker.h"

const int LIM = 5;

int main()
{
	int i, j;
	Worker* worker[LIM];

	for (i = 0; i < LIM; i++)
	{
		char choice;
		std::cout << "w:waiter   s:singer   t:singing waiter\n";
		std::cout << "请输入要选择的职业：";
		std::cin >> choice;
		while (strchr("wstq", choice) == NULL)
		{
			std::cout << "请输入w，s，t，q\n";
			std::cin >> choice;
		}
		if (choice == 'q')
		{
			break;
		}
		switch (choice)
		{
		case 'w':
			worker[i] = new Waiter;
			break;
		case 's':
			worker[i] = new Singer;
			break;
		case 't':
			worker[i] = new SingingWaiter;
			break;
		default:
			break;
		}
		while (std::cin.get() != '\n');
		worker[i]->Set();
	}
	for (j = 0; j < i; j++)
	{
		std::cout << std::endl;
		worker[j]->Show();
		delete worker[j];
	}
	std::cout << "再见！\n";

	system("pause");
	return 0;
}