package cn.lb.test;
// 为了能够一次导入多个类，可以使用通配符'*'
// import cn.lb.util.*
// 注意： 即使使用了'*'来进行导入，也不是所有的类都会被加载，
// 编译器会根据需要加载相应的类，即与直接导入没有性能差别

// 由于某种需要，同时导入了两个不同的Message类
import cn.lb.demo.*; // 也可以在这里直接导入指定类，消除歧义
import cn.lb.util.*; // 导入其它包的类
import cn.lb.sub.NetMessage; // 直接引入要测试的子类
public class TestMessage {
	public static void main(String [] args) {
		// 实例化类对象
		// cn.lb.util 中的类 cn.lb.util.Message 和 cn.lb.demo 中的类 cn.lb.demo.Message 都匹配
		// Message msg = new Message(); // 引用不明确
		cn.lb.util.Message msg = new cn.lb.util.Message(); // 明确指出使用的包
		System.out.println(msg.getContent());
		
		// 测试protected访问权限
		new NetMessage().print();
		// System.out.println(new Message().info); // 编译报错，无关系的类不能直接访问protected成员
	}
}