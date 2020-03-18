package cn.lb.util; // 1号
// package cn.lb.demo; // 2号
// 将此文件Message类依次编译到不同的包中

public class Message {
	protected String info = "www.baidu.com"; // 1号
	// protected String info = "人民万岁。"; // 2号
	public String getContent() {
		return this.info;
	}
}
