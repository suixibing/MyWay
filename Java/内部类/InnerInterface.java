interface IChannel1 { // 定义接口
	public void send(IMessage1 msg); // 发送消息
	interface IMessage1 { // 内部接口
		public String getContent(); // 获取消息内容
	}
}
class ChannelImpl implements IChannel1 {
	public void send(IMessage1 msg) {
		System.out.println("发送消息： " + msg.getContent());
	}
	// 内部接口并不是一定要实现
	class MessageImpl implements IMessage1 {
		public String getContent() {
			return "www.baidu.com";
		}
	}
}
interface IChannel2 { // 定义接口
	public void send(); // 发送消息
	class ChannelImpl2 implements IChannel2 {
		public void send() {
			System.out.println("www.hao123.com");
		}
	}
	public static IChannel2 getInstance() {
		return new ChannelImpl2();
	}
}
/*------------------------------------内部static接口-------------------------------*/
interface IMessageWarp { // 消息包装
	static interface IMessage2 {
		public String getContent();
	}
	static interface IChannel3 {
		public boolean connect(); // 消息的发送通道
	}
	public static void send(IMessage2 msg, IChannel3 channel) { // 消息发送
		if (channel.connect()) {
			System.out.println(msg.getContent());
		} else {
			System.out.println("消息通道无法建立，消息发送失败！");
		}
	}
}
// 可以通过'.'直接继承接口的内部static接口
class DefaultMessage implements IMessageWarp.IMessage2 {
	public String getContent() {
		return "mail.google.com";
	}
}
class NetChannel implements IMessageWarp.IChannel3 {
	public boolean connect() {
		return true;
	}
}
interface IMessage3 {
	public void send(String str);
	// 使用static方法获得一个本接口的匿名类对象
	public static IMessage3 getInstance() {
		return new IMessage3() {
			public void send(String str) {
				System.out.println(str);
			}
		};
	}
}
class JavaDemo {
	public static void main(String [] args) {
		IChannel1 channel1 = new ChannelImpl();
		channel1.send(((ChannelImpl)channel1).new MessageImpl());
		channel1.send(new ChannelImpl().new MessageImpl());
		
		IChannel2 channel2 = IChannel2.getInstance();
		channel2.send();
		
		//内部static接口
		IMessageWarp.send(new DefaultMessage(), new NetChannel());
	
		// 匿名内部类一般使用于抽象类和接口，创建只使用几次的匿名类对象
		IChannel2 channel3 = new IChannel2() { // 匿名内部类
			public void send() {
				System.out.println("mail.qq.com");
			}
		};
		channel3.send();
		
		// 使用static方法获得一个本接口的匿名类对象
		IMessage3.getInstance().send("www.bilibili.com");
	}
}