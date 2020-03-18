class TMessage <T> { // 只有Number和Number子类能够使用
	private T content;
	public void setContent(T content) {
		this.content = content;
	}
	public T getContent() {
		return this.content;
	}
}
class TMessageExtendsNumber <T extends Number> { // 只有Number和Number子类能够使用
	private T content;
	public void setContent(T content) {
		this.content = content;
	}
	public T getContent() {
		return this.content;
	}
}
class JavaDemo {
	public static void main(String [] args) {
		TMessage<String> msg1 = new TMessage<String>();
		msg1.setContent("www.baidu.com");
		fun(msg1);
		
		TMessage<Integer> msg2 = new TMessage<Integer>();
		msg2.setContent(1024);
		fun(msg2);
		
		TMessageExtendsNumber<Double> msg3 = new TMessageExtendsNumber<Double>();
		msg3.setContent(3.14);
		fun(msg3);
		
		// 报错，泛型不能接收String型的Type为参数
		// TMessageExtendsNumber<String> msg4 = new TMessageExtendsNumber<String>();
		// msg4.setContent("www.hao123.com");
		// fun(msg4); // 报错，方法不能接收String型的Type为参数
	}

	public static void fun(TMessage<?> temp) {
		System.out.println(temp.getContent());
	}
	public static void fun(TMessageExtendsNumber<?extends Number> temp) {
		System.out.println(temp.getContent());
	}
	
	/*
	 * 还有两类范围更小的通配符
	 * 1、?extends 类： 设置泛型的上限
	 *	形如"?extends Number": 表示该泛型类型只允许设置Number或Number的子类
	 * 2、?super 类： 设置泛型的下限
	 *	形如"?super String": 表示只能使用String或其父类
	 */
	
	
	/* 
	 * 问题1 引用传递时出现问题，同时只能有一个TMessage作为参数的函数
	 * 即内部类型Type只能有一个准确定义，出现第二个定义时不构成重载
	 * 20: 错误: 名称冲突: fun(TMessage<Integer>)和fun(TMessage<String>)具有相同疑符
	 * 
	 * public static void fun(TMessage<String> temp) {
	 * 	System.out.println(temp.getContent());
	 * }
	 * public static void fun(TMessage<Integer> temp) {
	 *	System.out.println(temp.getContent());
	 * }
	 */
	 
	 /*
	 * 问题2 一旦不设置泛型则在方法中就允许对数据进行修改，存在隐患
	 * 
	 * public static void fun(TMessage temp) {
	 *  temp.setContent(242); // 可以进行修改
	 *	System.out.println(temp.getContent());
	 * }
	 */
	 
	 /*
	 * 问题3 使用统配符'?'使函数可以接收所有的类型，并且不允许修改只能获取数据
	 * 这个函数使用了更小范围的通配符 ?extends Number
	 *
	 * public static void fun(TMessage<?extends Number> temp) {
	 * 	//temp.setContent("sdfs"); // 不能进行修改
	 * 	System.out.println(temp.getContent());
	 * }
	 */
}