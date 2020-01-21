#include <iostream>
#include "surrogate.h"
using namespace std;
using namespace lb;

int main()
{
	AutoMobile x(364);
	int num_vehicles = 0;

	//Vehicle parking_port1[100]; // 不成功！1、纯虚类无法创建对象
	//parking_port1[num_vehicles++] = x; // 2、派生类向基类赋值只是对基类存在的成员赋值

	Vehicle *parking_port2[100]; // 传统的解决办法是提供一个间接层，即使用基类的指针
	//parking_port2[num_vehicles++] = &x; // 此时保存的是指针,如果x一段时间后没了会出错
	parking_port2[num_vehicles++] = new AutoMobile(x); //此时保存的是x的副本,x随后是否存在无关;还需要注意动态内存的管理:
	//if (p != q)
	//{
	//	delete parking_port2[p];
	//	parking_port2[p] = parking_port2[q]; // 两个对象指针指向同一个内存,释放时会出现问题
	//}
	//if (p != q)
	//{
	//	delete parking_port2[p];
	//	parking_port2[p] = new Vehicle(parking_port2[q]); // 不确定应该new哪个对象
	//}
	// 应该使用虚复制函数copy()返回自身的一个拷贝,注意动态内存的管理

	// 代理类: 使用一个类来避免显示地处理内存分配,保持Vehicle在运行时绑定的属性
	// 每个Vehicle代理都代表一个继承自Vehicle类的对象。只要该代理关联着这个对象，该对象就肯定存在
	// 复制代理就会复制对应的对象，而给代理赋新值也会先删除旧对象后再赋值新对象
	VehicleSurrogate parking_port3[2];
	parking_port3[num_vehicles++] = x; // 等价于parking_port3[num_vehicles++] = VehicleSurrogate(x);
	// 创建了一个对象x的副本,并将VehicleSurrogate对象绑定到该副本,然后将这个对象赋给parking_port3的一个元素
	// 当销毁parking_port3数组时,所有的副本都将被销毁

	// 测试
	RoadVehicle a(2356);
	a.start();
	cout << a.weight() << endl;

	AutoMobile b(25.5);
	b.start();
	cout << b.weight() << endl;

	Aircraft c(84);
	c.start();
	c.weight();
	c.fly();

	Helicopter d(73);
	d.start();
	d.weight();
	d.hover();

	return 0;
}