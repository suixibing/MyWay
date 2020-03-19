// 两种自定义异常：
// 继承 Exception 时，会强制要求处理异常
// 继承 RuntimeErrorException 时，不会要求强制处理异常
class BombException extends RuntimeException {
	public BombException(String msg) {
		super(msg);
	}
}
class Food {
	public static void eat(int num) throws BombException {
		if (num > 10) {
			throw new BombException("吃太多了，肚子爆了。");
		} else {
			System.out.println("正常开始吃，不怕吃胖。");
		}
	}
}
class JavaDemo {
	public static void main(String [] args) {
		// Exception in thread "main" BombException: 吃太多了，肚子爆了。
		//     at Food.eat(JavaDemo.java:12)
		//     at JavaDemo.main(JavaDemo.java:20)
		Food.eat(11);
		
		int x = 10;
		
		// 中间会经过许多的x变量的操作步骤
		
		// 断言：
		// 在Java中断言并不是一个程序必须执行的步骤
		// 只是个建议，即使不成立，运行也不会出问题
		assert x == 100 : "x的内容不是100";
		// 只有使用如下参数运行时，才会报错
		// >java -ea JavaDemo
		// Exception in thread "main" java.lang.AssertionError: x的内容不是100
		// 		at JavaDemo.main(JavaDemo.java:6)
		
		System.out.println(x);
	}
}