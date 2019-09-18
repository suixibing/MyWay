#pragma once

#include<iostream>
#include<string>

class Worker
{
private:
	std::string m_name;
	long m_id;
public:
	Worker() : m_name("No man"), m_id(0L) {}
	Worker(std::string& name, long id = -1) : m_name(name), m_id(id) {}
	Worker(const char* name, long id = -1) : m_name(name), m_id(id) {}
	virtual ~Worker() = 0;
	virtual void Show()const;
	virtual void Set();
};

class Waiter : public virtual Worker
{
private:
	int m_panache;
protected:
	void Data()const;
	void Get();
public:
	Waiter() : Worker(), m_panache(0) {}
	Waiter(std::string& name, long id, int p = 0) : Worker(name, id), m_panache(p) {}
	Waiter(const char* name, long id, int p = 0) : Worker(name, id), m_panache(p) {}
	Waiter(Worker& worker, int p = 0) : Worker(worker), m_panache(p) {}
	void Show()const;
	void Set();
};

class Singer : virtual public Worker
{
protected:
	enum { OTHER, ALTO, CONTRALTO, SOPRANO, BASS, BARITONE, TENOR };
	enum { VTYPES = 7 };
	void Data()const;
	void Get();
private:
	static std::string m_s_p[VTYPES];
	int m_voice;
public:
	Singer() : Worker(), m_voice(0) {}
	Singer(std::string& name, long id, int voice = OTHER) : Worker(name, id), m_voice(voice) {}
	Singer(const char* name, long id, int voice = OTHER) : Worker(name, id), m_voice(voice) {}
	Singer(Worker& worker, int voice = OTHER) : Worker(worker), m_voice(voice) {}
	void Show()const;
	void Set();
};


class SingingWaiter : public Singer, public Waiter
{
protected:
	void Data()const;
	void Get();
public:
	SingingWaiter() : Worker(), Singer(), Waiter() {}
	SingingWaiter(std::string& name, long id, int voice = OTHER, int p = 0) : Worker(name, id), Singer(name, id, voice), Waiter(name, id, p) {}
	SingingWaiter(const char* name, long id, int voice = OTHER, int p = 0) : Worker(name, id), Singer(name, id, voice), Waiter(name, id, p) {}
	SingingWaiter(Worker& worker, int voice = OTHER, int p = 0) : Worker(worker), Singer(worker, voice), Waiter(worker, p) {}
	void Show()const;
	void Set();
};