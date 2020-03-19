class MyMath {
	// 表示这个代码执行的时候可能产生异常，如果产生异常，要在调用处进行处理
	// 【编译时报错】 错误: 未报告的异常错误Exception; 必须对其进行捕获或声明以便抛出
	public static int div(int x, int y) throws Exception {
		return x / y;
	}
}
class JavaDemo {
	public static void main(String [] args) {
		try {
			// throw用于抛出异常
			// 1、自己抛的异常也需要try处理，不然会编译报错
			// 错误: 未报告的异常错误Exception; 必须对其进行捕获或声明以便抛出
            //            throw new Exception("自己抛着玩的对象。");
			throw new Exception("自己抛着玩的对象。");
		} catch (Exception e) {
			e.printStackTrace();
		}
	}
	// 主方法也可以向上抛异常，此时就不需要由主方法来处理这个异常了
	// 表示该异常将由JVM负责进行处理，实际使用中一般不会这么使用
	// public static void main(String [] args) throws Exception {
	// 	System.out.println(MyMath.div(10, 0));
	// }
	
	// public static void main(String [] args) {
	// 	try {
	// 		// 此时尽管没有错误也需要使用try
	// 		// throws 强制需要使用try处理可能存在的异常
	// 		System.out.println(MyMath.div(10, 0));
	// 	} catch (Exception e) {
	// 		e.printStackTrace();
	// 	}
	// }
}