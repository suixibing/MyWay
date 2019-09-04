#include "Worker.h"

Worker::~Worker() {}

void Worker::Show()const
{
	std::cout << "姓名：" << m_name << std::endl;
	std::cout << "id号：" << m_id << std::endl;
}

void Worker::Set()
{
	std::cout << "输入工作人员的姓名：";
	std::getline(std::cin, m_name);
	std::cout << "输入id：";
	std::cin >> m_id;
	while (std::cin.get() != '\n');
}

void Waiter::Data()const
{
	std::cout << "panache rating：" << m_panache << std::endl;
}

void Waiter::Get()
{
	std::cout << "panache rating：";
	std::cin >> m_panache;
}

void Waiter::Show()const
{
	Worker::Show();
	Data();
}

void Waiter::Set()
{
	Worker::Set();
	Get();
	while (std::cin.get() != '\n');
}

std::string Singer::m_s_p[] = { "OTHER", "ALTO", "CONTRALTO", "SOPRANO", "BASS", "BARITONE", "TENOR" };

void Singer::Data()const
{
	std::cout << "voice：" << m_s_p[m_voice] << std::endl;
}

void Singer::Get()
{
	std::cout << "every case:\n";
	for (int i = 0; i < VTYPES; i++)
	{
		std::cout << "case " << i << ":" << m_s_p[i] << "  ";
		if (i % 4 == 3)
		{
			std::cout << std::endl;
		}
	}
	std::cout << std::endl;
	std::cout << "voice：";
	std::cin >> m_voice;
}

void Singer::Show()const
{
	Worker::Show();
	Data();
}

void Singer::Set()
{
	Worker::Set();
	Get();
	while (std::cin.get() != '\n');
}

void SingingWaiter::Data()const
{
	Singer::Data();
	Waiter::Data();
}

void SingingWaiter::Get()
{
	Waiter::Get();
	Singer::Get();
}

void SingingWaiter::Show()const
{
	Worker::Show();
	Data();
}

void SingingWaiter::Set()
{
	Worker::Set();
	Get();
	while (std::cin.get() != '\n');
}