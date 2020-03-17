abstract class AMessage { // 定义抽象类
	private String type;
	public AMessage(String type) { // 没有提供无参构造
		this.type = type;
	}
	public abstract String getConnectInfo(); // 抽象方法
	public String getType() {
		return "type: " + this.type;
	}
	public void setType(String type) {
		this.type = type;
	}
	// static方法不受抽象类的影响，可以直接使用类名调用
	public static AMessage getInstance() {
		return new DatabaseAMessage();
	}
}
class DatabaseAMessage extends AMessage { // 类的继承关系
	public DatabaseAMessage() {
		super("反馈信息"); // 必须显式调用父类的构造方法
	}
	@Override // Annotation注解
	public String getConnectInfo() { // 方法覆写
		return "Oracle数据库连接信息";
	}
}
class JavaDemo {
	public static void main(String [] args) {
		AMessage msg = AMessage.getInstance();
		System.out.println(msg.getConnectInfo());
		System.out.println(msg.getType());
		msg.setType("客户信息");
		System.out.println(msg.getConnectInfo());
		System.out.println(msg.getType());
	}
}