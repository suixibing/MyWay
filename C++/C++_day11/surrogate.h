#pragma once
#include <iostream>

namespace lb
{
	const bool ShowName = false;
	class Vehicle
	{
	public:
		virtual double weight() const = 0;
		virtual void start() = 0;
		virtual void show() const = 0;
		virtual Vehicle* copy() const = 0;
		virtual ~Vehicle() {  }
	};

	class RoadVehicle : public Vehicle
	{
	private:
		double m_weight;
	public:
		RoadVehicle(const double weight = 0) : m_weight(weight) { }
		virtual double weight() const;
		virtual void start() { show(); std::cout << "start()" << std::endl; }
		virtual void show() const { if (ShowName) std::cout << "RoadVehicle::"; }
		virtual Vehicle* copy() const { return new RoadVehicle(*this); }
	};
	double RoadVehicle::weight() const
	{
		show();
		std::cout << "weight = " << m_weight << std::endl;
		return m_weight;
	}

	class AutoMobile : public RoadVehicle
	{
	public:
		AutoMobile(const double weight = 0) : RoadVehicle(weight) { }
		AutoMobile(const AutoMobile & am) : RoadVehicle(am.weight()) { }
		//virtual double weight() const;
		//virtual void start() { show(); std::cout << "start()" << std::endl; }
		virtual void show() const { if (ShowName) std::cout << "AutoMobile::"; }
		virtual Vehicle* copy() const { return new AutoMobile(*this); }
	};
	//double AutoMobile::weight() const
	//{
	//	return RoadVehicle::weight();
	//}

	class Aircraft : public Vehicle
	{
	private:
		double m_weight;
	public:
		Aircraft(const double weight = 0) : m_weight(weight) { }
		virtual double weight() const;
		virtual void start() { show(); std::cout << "start()" << std::endl; }
		virtual void show() const { if (ShowName) std::cout << "Aircraft::"; }
		virtual Vehicle* copy() const { return new Aircraft(*this); }
		void fly() const { show(); std::cout << "fly()" << std::endl; }
	};
	double Aircraft::weight() const
	{
		show();
		std::cout << "weight = " << m_weight << std::endl;
		return m_weight;
	}

	class Helicopter : public Aircraft
	{
	public:
		Helicopter(const double weight = 0) : Aircraft(weight) { }
		//virtual double weight() const;
		//virtual void start() { show(); std::cout << "start()" << std::endl; }
		virtual void show() const { if (ShowName) std::cout << "Helicopter::"; }
		virtual Vehicle* copy() const { return new Helicopter(*this); }
		void hover() const { show(); std::cout << "hover()" << std::endl; } // 盘旋
	};
	//double Helicopter::weight() const
	//{
	//	return Aircraft::weight();
	//}

	class VehicleSurrogate
	{
	private:
		Vehicle *m_vp;
	public:
		VehicleSurrogate() : m_vp(nullptr) { }
		VehicleSurrogate(const Vehicle & v) : m_vp(v.copy()) { } // 1、每次copy都是虚调用,Vehicle类对象不存在;v是引用而非对象
		VehicleSurrogate(const VehicleSurrogate & vs) : m_vp(vs.m_vp ? vs.m_vp->copy() : nullptr) {	} // 2、注意代理是否为空
		~VehicleSurrogate() { if (m_vp != nullptr) delete m_vp; }
		VehicleSurrogate& operator=(const VehicleSurrogate & vs);
		double weight() const;
		void start();
	};
	VehicleSurrogate& VehicleSurrogate::operator=(const VehicleSurrogate & vs)
	{
		if (&vs != this) // 3、注意代理是否给自己
		{
			delete m_vp;
			m_vp = (vs.m_vp ? vs.m_vp->copy() : nullptr); // 2、注意代理是否为空
		}
		return *this;
	}
	double VehicleSurrogate::weight() const
	{
		if (m_vp == nullptr)
			throw "empty VehicleSurrogate.weight()";
		return m_vp->weight();
	}
	void VehicleSurrogate::start()
	{
		if (m_vp == nullptr)
			throw "empty VehicleSurrogate.start()";
		m_vp->start();
	}
}