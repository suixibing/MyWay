/*
	多例模式：
		在多例模式中，多例类可以有多个实例，而且多例类必须自己创建、管理自己的实例，并向外界提供自己的实例。
		
	注意：
		1. 通过实例容器保存容器。
		2. 利用私有构造阻止外部构造。
		3. 提供getInstantce()方法获取实例。
		
	主要解决：
		为了防止并发问题；即一个请求改变了对象的状态，此时对象又处理另一个请求，
		而之前请求对对象状态的改变导致了对象对另一个请求做了错误的处理。
		
	何时使用：
		对象含有可改变的状态时（更精确的说就是在实际应用中该状态会改变）。
		
	关键代码：
		构造函数是私有的。
		
	应用实例：
		1、以打麻将为例，每盘开局都会掷骰子，而正常情况下骰子只有2粒。
		所以抽象之后就是：骰子的的个数是有限的，每个代表不同的状态。

*/
class Color {
	private static final Color RED = new Color("红色");
	private static final Color GREEN = new Color("绿色");
	private static final Color BLUE = new Color("蓝色");
	private String title;
	private Color(String title) { // 构造方法私有化
		this.title = title;
	}
	public static Color getInstance(String color) {
		switch (color.toLowerCase()) {
			case "red": return RED;
			case "green": return GREEN;
			case "blue": return BLUE;
			default: return null;
		}
	}
	public String toString() {
		return this.title;
	}
}
class JavaDemo {
	public static void main(String [] args) {
		// 当指定不存在的目标时，返回null
		// Color c = Color.getInstance("pink");
		Color c = Color.getInstance("Blue");
		System.out.println(c);
	}
}