// 由于类名称与接口名称的定义要求相同
// 为了区分接口名称在接口名前加I开头
interface IMessage { // 定义了一个接口
	// 接口中的方法默认是public，不是default，因此覆写时只能使用public
	// 方法默认 public abstract
	// 变量默认 public static final
	/*public static final */String INFO = "www.baidu.cn"; // 全局变量
	/*public abstract */String getInfo(); // 抽象方法
	
	// 通过增加一个过渡的抽象类，来解决每次增加新接口都需要在每个子类重新实现的问题
	// 1.8后有了改变，可以直接在接口中定义default普通方法和static方法
	// 但是正常开发中还是不建议定义普通方法和static方法
	// public default boolean connectMessage() {
	// 	System.out.println("建立消息的发送通道。");
	// 	return true;
	// }
	// 可以定义static方法，能通过接口名直接调用
	// public static IMessage getInstance() {
	// 	return new MessageImpl(); // 获得子类对象
	// }
}

// 使用接口可以实现多继承
interface IChannel {
	public abstract boolean connect(); // 定义抽象方法
}

abstract class DatabaseAbstract { // 定义一个抽象类
	// 接口中的abstract能够省略，抽象类中不允许省略
	public abstract boolean getDatabaseConnection();
}

// 此时接口无法直接产生实例化对象，接口只有被子类实现后才能使用
// 子类一定要覆写接口中所有的抽象方法
class MessageImpl extends DatabaseAbstract implements IMessage, IChannel { // 实现了接口
	@Override
	public String getInfo() {
		if (this.connect()) {
			if (this.getDatabaseConnection()) {
				return "数据库中得到一个消息，秘密的消息，有人胖了（不是我）。";
			} else {
				return "数据库消息无法访问。";
			}
		}
		return "通道创建失败，无法获得消息";
	}
	@Override
	public boolean connect() {
		System.out.println("消息发送通道已经成功建立。");
		return true;
	}
	@Override
	public boolean getDatabaseConnection() {
		return true;
	}
}

/* -------------------------接口的多继承----------------------------- */
// extends在类继承上只能继承一个父类，但是接口上可以继承多个
interface IService extends IMessage, IChannel { // 接口多继承
	public String service();
}
class MessageService implements IService {
	@Override
	public String getInfo() {
		return null;
	}
	@Override
	public boolean connect() {
		return true;
	}
	@Override
	public String service() {
		return "获取消息服务。";
	}
}


/*
 * 在实际开发中，接口的使用往往有三种形式: 
 *	1、进行标准设置
 *	2、表示一种操作的能力
 *	3、暴露远程方法视图，这个一般都在RPC分布式开发中使用
*/

class JavaDemo {
	public static void main(String [] args) {
		IMessage msg = new MessageImpl();
		System.out.println(msg.getInfo());
		System.out.println(IMessage.INFO);
		
		IChannel chl = (IChannel)msg;
		System.out.println(chl.connect());
		
		// Object类对象可以接受所有数据类型，包括基本数据类型、类对象、接口对象、数组
		Object obj = (Object)msg; // 向上转型
		IChannel chan = (IChannel)obj; // 合法
	}
}