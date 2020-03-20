class Outer { // 外部类
	private String msg = "www.baidu.com"; // 私有成员属性
	public void fun1() { // 普通方法
		Inner1 in = new Inner1(); // 实例化内部类对象
		in.print(); // 调用内部类方法
		System.out.println(in.info); // 访问内部类的私有属性
	}
	// 内部类能够方便的访问外部类中的私有属性
	// 内部类与外部类之间的私有操作的访问不再需要getter、setter等间接方法
	class Inner1 { // 在Outer类的内部定义了Inner1类
	private String info = "今天天气不好，收衣服啦！";
		public void print() {
			System.out.println(Outer.this.msg); // Ouber类中的属性
		}
	}
	
	// 思考一： msg属性如果要被外部访问需要提供有getter方法
	public String getMsg() {
		return this.msg;
	}
	public void fun2() { // 普通方法
		// 思考五： 需要将当前对象Outer传递到Inner2类之中
		Inner2 in = new Inner2(this); // 实例化inner2类对象
		in.print(); // 调用inner2类方法
		System.out.println(in.getInfo()); // 访问inner2类的私有属性
	}
	
	private class Inner3 { // 在Outer类的内部定义了Inner3类
	private String info = "今天天气一般，还是呆在家里玩吧。";
		public void print() {
			System.out.println(Outer.this.msg); // Ouber类中的属性
		}
	}
	
	private static final String MSG = "www.baidu.com";
	// 内部static类
	static class Inner4 {
		public void print() {
			System.out.println(Outer.MSG);
		}
	}
}
class Inner2 { // 模仿内部类inner1实现相同的功能
	private String info = "今天又是好天气，快去晾衣服吧。";
	// 思考三： inner2这个类对象实例化的时候需要Outer类的引用
	private Outer out;
	// 思考四： 应该通过Inner2类的构造方法获取Outer类对象
	public Inner2(Outer out) {
		this.out = out;
	}
	public void print() {
		// 思考二： 如果想要调用外部类中的getter方法，那么一定要有Outer类对象
		System.out.println(this.out.getMsg()); // Ouber类中的属性
	}
	public String getInfo() {
		return this.info;
	}
}
class JavaDemo {
	public static void main(String [] args) {
		Outer out = new Outer();
		out.fun1();
		out.fun2();
		
		// 实例化内部类的方法：
		// 外部类.内部类 内部类对象 = new 外部类().new 内部类();
		Outer.Inner1 in1 = new Outer().new Inner1();		
		// 内部类编译完成之后会形成一个Outer$Inner1.class类文件，其中'$'换到程序中就变为了'.'
		// 内部类的全称就是"外部类.内部类"
		// 只有先实例化了外部类之后才能实例化内部类
		in1.print();
		
		// Inner3是private定义的，此时的Inner3无法在外部进行使用
		// 错误: Outer.Inner3可以在Outer中访问private
        //         Outer.Inner3 in2 = new Outer().new Inner3();
		// Outer.Inner3 in2 = new Outer().new Inner3();
		// in2.print();
		
		// 实例化内部static类的方法：
		// 外部类.内部类 内部类对象 = new 外部类.内部类();
		Outer.Inner4 in3 = new Outer.Inner4();
		in3.print();
	}
}