#ifndef _MAILCLASS_HPP_
#define _MAILCLASS_HPP_

#include <set>
#include <string>
#include <iostream>

namespace lb
{
	class Folder;

	class Message
	{
		friend class Folder;
		// 交换两个message
		friend void swap(Message &msg1, Message &msg2);

	private:
		// 消息文本
		std::string m_contents;
		// 记录消息所存在的目录
		std::set<Folder*> m_folders;

	private:
		// 使当前message保存指定folder的位置信息
		void addFldr(Folder *fldr);
		// 使当前message删除指定folder的位置信息
		void remFldr(Folder *fldr);
		// 使所有保存有旧message信息的folder添加当前message的位置信息
		void addToFolders();
		// 使所有保存有当前message信息的folder删除当前message的位置信息
		void removeFromFolders();

	public:
		// m_folders隐式初始化为空
		explicit Message(const std::string &contents = "")
			: m_contents(contents) { }
		// 拷贝构造函数，负责将新message信息添加到所有的folder中
		Message(const Message &msg)
			: m_contents(msg.m_contents), m_folders(msg.m_folders)
		{
			addToFolders();
		}
		// 析构函数，负责将要销毁的message从所有folder中删除
		~Message() { removeFromFolders(); }

		// 删除原有folder保存的旧message信息并添加一份新message信息
		Message& operator=(const Message &msg);
		// 将message保存到指定的folder中
		void save(Folder &fldr);
		// 将message从指定的folder删除
		void remove(Folder &fldr);
		// 输出当前message的信息
		void print() const;
	};
	void swap(Message &msg1, Message &msg2)
	{
		// 这样可以让编译器选择最合适的swap来进行交换
		using std::swap;
		// 先将所有目录中message的旧位置信息删除
		msg1.removeFromFolders();
		msg2.removeFromFolders();
		// 使用最合适的swap进行交换
		swap(msg1.m_contents, msg2.m_contents);
		swap(msg1.m_folders, msg2.m_folders);
		// 使所有目录重新保存message的新位置信息
		msg1.addToFolders();
		msg2.addToFolders();
	}

	class Folder
	{
		friend class Message;
		// 交换两个folder
		friend void swap(Folder &fldr1, Folder &fldr2);

	private:
		// 记录目录中保存的消息
		std::set<Message*> m_msg;
		
	private:
		// 使当前folder保存指定message的位置信息
		void addMsg(Message *msg);
		// 使当前folder删除指定message的位置信息
		void remMsg(Message *msg);
		// 使旧目录中所有message添加当前folder的位置信息
		void addToMessages();
		// 使当前目录中所有message删除当前folder的位置信息
		void removeFromMessages();

	public:
		// m_msg隐式初始化为空
		explicit Folder() { }
		// 拷贝构造函数，负责将新folder信息添加到保存的所有message中
		Folder(const Folder &fldr)
			: m_msg(fldr.m_msg)
		{
			addToMessages();
		}
		// 析构函数，负责将要销毁的当前folder从所有保存的message中删除
		~Folder() { removeFromMessages(); }

		// 删除旧目录中所有message保留的旧folder信息并为新message添加新folder信息
		Folder& operator=(const Folder &fldr);
		// 将指定message保存到当前folder中
		void save(Message &msg);
		// 将指定message从当前folder删除
		void remove(Message &msg);
		// 输出保存在folder中message的信息
		void print(const std::string &fldrname = "") const;
	};
	void swap(Folder &fldr1, Folder &fldr2)
	{
		// 这样可以让编译器选择最合适的swap来进行交换
		using std::swap;
		// 先将目录中所有message保存的旧floder位置信息删除
		fldr1.removeFromMessages();
		fldr2.removeFromMessages();
		// 使用最合适的swap进行交换
		swap(fldr1.m_msg, fldr2.m_msg);
		// 使目录中所有message重新保存floder的新位置信息
		fldr1.addToMessages();
		fldr2.addToMessages();
	}

	Message& Message::operator=(const Message &msg)
	{
		removeFromFolders();
		m_contents = msg.m_contents;
		m_folders = msg.m_folders;
		addToFolders();
		return *this;
	}
	inline void Message::save(Folder &fldr)
	{
		addFldr(&fldr);
		fldr.addMsg(this);
	}
	inline void Message::remove(Folder &fldr)
	{
		remFldr(&fldr);
		fldr.remMsg(this);
	}
	inline void Message::print() const
	{
		std::cout << "message: " << m_contents << ";";
	}
	inline void Message::addFldr(Folder *fldr)
	{
		m_folders.insert(fldr);
	}
	inline void Message::remFldr(Folder *fldr)
	{
		m_folders.erase(fldr);
	}
	void Message::addToFolders()
	{
		for (auto f : m_folders)
			f->addMsg(this);
	}
	void Message::removeFromFolders()
	{
		for (auto f : m_folders)
			f->remMsg(this);
	}

	Folder& Folder::operator=(const Folder &fldr)
	{
		removeFromMessages();
		m_msg = fldr.m_msg;
		addToMessages();
		return *this;
	}
	inline void Folder::save(Message &msg)
	{
		addMsg(&msg);
		msg.addFldr(this);
	}
	inline void Folder::remove(Message &msg)
	{
		remMsg(&msg);
		msg.remFldr(this);
	}
	void Folder::print(const std::string &fldrname) const
	{
		std::cout << fldrname << "目录:";
		for (auto m : m_msg)
		{
			std::cout << " ";
			m->print();
		}
		std::cout << std::endl;
	}
	inline void Folder::addMsg(Message *msg)
	{
		m_msg.insert(msg);
	}
	inline void Folder::remMsg(Message *msg)
	{
		m_msg.erase(msg);
	}
	void Folder::addToMessages()
	{
		for (auto m : m_msg)
			m->addFldr(this);
	}
	void Folder::removeFromMessages()
	{
		for (auto m : m_msg)
			m->remFldr(this);
	}
}

#endif /* _MAILCLASS_HPP_ */