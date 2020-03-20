class Outer {
	private String msg = "www.baidu.com";
	public void fun(/*final*/ long time) {
		// 1.8以前要想内部类能够直接访问局部变量，变量必须要使用final
		// 之所以取消这样的限制，主要是为了支持1.8所扩展的函数式编程
		/*final*/ String info = "我很好";
		class Inner { // 内部类
			// 1.8以后内部类能够直接访问局部变量
			public void print() {
				System.out.println(Outer.this.msg);
				System.out.println(time);
				System.out.println(info);
			}
		}
		new Inner().print(); // 方法中直接实例化内部类
	}
}
class JavaDemo {
	public static void main(String [] args) {
		new Outer().fun(3423456L);
	}
}