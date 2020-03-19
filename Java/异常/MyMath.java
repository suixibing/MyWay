class MyMath {
	// 异常交给被调用处进行处理，一定要在方法上使用throws
	public static int div(int x, int y) throws Exception {
		int temp;
		System.out.println("********* 【START】 除法计算开始");
		// 注释前是标准的try-catch结构，当必须输出结束信息时使用此结构
		// 例如网路连接时，需要输出连接关闭的提示信息
		try {
			temp = x / y;
		}/* catch (Exception e) { // 实际上可以省略catch与throw的操作
			throw e; // 向上抛异常
		} */finally {
			// 使用finally使每次都必然会输出结束提示
			// 不使用finally的话，当出现异常时，不会输出结束提示
			System.out.println("********* 【END】 除法计算结束");
		}
		return temp;
	}
}
class JavaDemo {
	public static void main(String [] args) {
		try {
			System.out.println(MyMath.div(10, 0));
		} catch (Exception e) {
			e.printStackTrace();
		}
	}
}