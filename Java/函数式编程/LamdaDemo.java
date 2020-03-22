/*
 * Lambda表达式有如下几种格式：
 * 	方法没有参数： ()->{};
 * 	方法有参数： (参数, 参数)->{};
 * 	如果现在只有一行语句返回： (参数, 参数)->语句;
 */
 
// 要使用Lambda表达式有一个重要的实现要求：
// SAM（Single Abstract Method），即只有一个抽象方法的类
@FunctionalInterface // 函数式接口
interface IMessage1 {
	public void send(String str);
}
@FunctionalInterface // 函数式接口
interface IMessage2 {
	public void send();
}
@FunctionalInterface // 函数式接口
interface IMath {
	public int add(int x, int y);
}
class JavaDemo {
	public static void main(String [] args) {
		// 匿名内部类实现
		IMessage1 msg1 = new IMessage1(){
			public void send(String str) {
				System.out.println("发送消息： " + str);
			}
		};
		msg1.send("www.hao123.com");
		
		// Lambda表达式实现
		IMessage1 msg2 = (str)->{
			System.out.println("发送消息： " + str);
		};
		msg2.send("www.baidu.com");
		
		IMessage2 msg3 = ()->{
			System.out.println("发送消息： mail.qq.com");
		};
		msg3.send();
		
		IMath math1 = (x, y)-> x + y;
		IMath math2 = (x, y)->{
			return x + y;
		};
		System.out.println(math1.add(10, 20));
		System.out.println(math2.add(10, 20));
	}
}