// 同时catch多个已知的异常，并不是异常的精髓
// 此时完全可以通过判断避免异常，而不是catch多个异常
class JavaDemo {
	public static void main(String [] args) {
		// 1、此时编译不报错，执行会出现异常
		// 【1】 *******************程序开始执行********************
		// Exception in thread "main" java.lang.ArithmeticException: / by zero
		//		at JavaDemo.main(JavaDemo.java:5)
		// System.out.println("【1】 *******************程序开始执行********************");
		// System.out.println("【2】 *******************数学计算： " + (10 / 0));
		// System.out.println("【3】 *******************程序执行结束********************");
		
		System.out.println("【1】 *******************程序开始执行********************");
		try {
			// 此时可能有三类异常：
			// 1、【未处理状态】 程序执行的时候没有输入初始化参数
			// >java JavaDemo (回车)
			// 【1】 *******************程序开始执行********************
			// 【finally】 不管是否会出现异常，都会执行
			// Exception in thread "main" java.lang.ArrayIndexOutOfBoundsException: 0
			//		at JavaDemo.main(JavaDemo.java:15)
			// 2、【未处理状态】 输入的数据不是数字
			// >java JavaDemo a b (回车)
			// 【1】 *******************程序开始执行********************
			// 【finally】 不管是否会出现异常，都会执行
			// Exception in thread "main" java.lang.NumberFormatException: For input string: "a"
			// 		at java.lang.NumberFormatException.forInputString(Unknown Source)
			// 		at java.lang.Integer.parseInt(Unknown Source)
			// 		at java.lang.Integer.parseInt(Unknown Source)
			// 		at JavaDemo.main(JavaDemo.java:15)
			// 3、【已处理状态】 输入的被除数为0
			// >java JavaDemo 10 0 (回车)
			// 【1】 *******************程序开始执行********************
			// 【catch处理异常】 java.lang.ArithmeticException: / by zero
			// 【finally】 不管是否会出现异常，都会执行
			// 【3】 *******************程序执行结束********************
			
			int x = Integer.parseInt(args[0]);
			int y = Integer.parseInt(args[1]);
			System.out.println("【2】 *******************数学计算： " + (x / y));
		} /*catch (ArrayIndexOutOfBoundsException e) { // 处理第一个异常
			System.out.println("【catch处理异常】 " + e);
		} catch (NumberFormatException e) { // 处理第二个异常
			System.out.println("【catch处理异常】 " + e);
		} */catch (ArithmeticException e) {
			// e.printStackTrace(); // 更完整的异常信息，带有文件名和行号
			System.out.println("【catch处理异常】 " + e); // 处理异常
		} finally { // finally
			// 即使异常没有正常捕获，finally还是会执行
			System.out.println("【finally】 不管是否出现异常，都会执行");
		}
		System.out.println("【3】 *******************程序执行结束********************");
	}
}