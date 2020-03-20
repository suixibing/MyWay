interface IChannel { // 定义接口
	public void send(); // 发送消息
	abstract class AbstractMessage { // 内部抽象类
		public abstract String getContent(); // 获取消息内容
	}
}
class ChannelImpl implements IChannel {
	public void send() {
		AbstractMessage msg = new MessageImpl();
		System.out.println("发送消息： " + msg.getContent());
	}
	class MessageImpl extends AbstractMessage {
		public String getContent() {
			return "www.baidu.com";
		}
	}
}
class JavaDemo {
	public static void main(String [] args) {
		IChannel channel = new ChannelImpl();
		channel.send();
	}
}