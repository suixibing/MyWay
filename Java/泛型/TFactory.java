interface TIMessage {
	public void send(String str);
}
class MessageImpl implements TIMessage {
	public void send(String str) {
		System.out.println("消息发送: " + str);
	}
}
class TFactory { // 注意这里没有定义为泛型类，只是有一个泛型方法
	public static <T> T getInstance(String className, Class<T> t) {
		if ("messageImpl".equalsIgnoreCase(className)) {
			// 不适用强转会报错
			return (T)new MessageImpl();
		}
		return null;
	}
}
class JavaDemo {
	public static void main(String [] args) {
		Integer num [] = fun(1, 3, 4);
		for (int temp : num) {
			System.out.print(temp + ", ");
		}
		System.out.println();
		// System.out.println(TIMessage.class);
		
		TIMessage msg = TFactory.getInstance("messageImpl", TIMessage.class);
		msg.send("吃了吗？");
	}
	// 泛型方法也可以在普通类中定义
	// 必须使用<T>指出T是一个占位符
	public static <T> T[] fun(T ... args) {
		return args;
	}
}