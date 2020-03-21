/*
	单例模式
		单例模式（Singleton Pattern）是 Java 中最简单的设计模式之一。
		这种类型的设计模式属于创建型模式，它提供了一种创建对象的最佳方式。
		这种模式涉及到一个单一的类，该类负责创建自己的对象，同时确保只有单个对象被创建。
		这个类提供了一种访问其唯一的对象的方式，可以直接访问，不需要实例化该类的对象。
	
	注意：
		1、单例类只能有一个实例。
		2、单例类必须自己创建自己的唯一实例。
		3、单例类必须给所有其他对象提供这一实例。
	
	意图：
		保证一个类仅有一个实例，并提供一个访问它的全局访问点。
	
	主要解决：
		一个全局使用的类频繁地创建与销毁。
	
	何时使用：
		当想控制实例数目，节省系统资源的时候。
	
	如何解决：
		判断系统是否已经有这个单例，如果有则返回，如果没有则创建。
	
	关键代码：
		构造函数是私有的。
	
	应用实例：
		1、一个班级只有一个班主任。
		2、Windows 是多进程多线程的，在操作一个文件的时候，就不可避免地出现多个进程或线程
		同时操作一个文件的现象，所以所有文件的处理必须通过唯一的实例来进行。
		3、一些设备管理器常常设计为单例模式，比如一个电脑有两台打印机，
		在输出的时候就要处理不能两台打印机打印同一个文件。
	
	优点：
		1、在内存里只有一个实例，减少了内存的开销，尤其是频繁的创建和销毁实例（比如管理学院首页页面缓存）。
		2、避免对资源的多重占用（比如写文件操作）。
	
	缺点：
		没有接口，不能继承，与单一职责原则冲突，一个类应该只关心内部逻辑，而不关心外面怎么样来实例化。
	
	使用场景：
		1、要求生产唯一序列号。
		2、WEB 中的计数器，不用每次刷新都在数据库里加一次，用单例先缓存起来。
		3、创建的一个对象需要消耗的资源过多，比如 I/O 与数据库的连接等。
	
	注意事项：
		getInstance() 方法中需要使用同步锁 synchronized (Singleton.class) 防止多线程同时进入造成 instance 被多次实例化。
*/

class Singleton {
	// 此时instance属于普通属性，只有通过实例化对象后才能创建
	// 当前无法在外部实例化对象，因此也无法创建instance
	// Singleton instance = new Singleton();
	
	// 目标是在没有实例化对象时也能获取此属性，所以使用static
	// static Singleton instance = new Singleton();
	
	// 为了实现封装，属性一般定义为private访问权限，此时需要通过方法获得属性
	// private static Singleton instance = new Singleton();
	
	// 为了保证实例化只有一个，我们使用final定义
	private static final Singleton INSTANCE = new Singleton();
	// private访问权限主要特点如下： 不能在类外部访问，但是可以在类内部调用
	private Singleton() {} // 构造方法私有化
	public void print() {
		System.out.println("www.baidu.com");
	}
	public static Singleton getInstance() {
		return Singleton.INSTANCE;
	}
}
class JavaDemo {
	public static void main(String [] args) {
		Singleton instance = null; // 声明对象
		// instance = new Singleton(); // 错误: Singleton()可以在Singleton中访问private
		// instance = Singleton.instance; // 当属性不是private或protected时可以直接使用
		
		instance = Singleton.getInstance();
		instance.print();
	}
}