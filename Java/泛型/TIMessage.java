interface TIMessage<T> { // 泛型接口
	public String echo(T t);
}
// 实现方式1 继续设置为泛型
class TMessageImpl<S> implements TIMessage<S> {
	public String echo(S t) {
		return "【ECHO】 " + t;
	}
}
// 实现方式2 在子类定义父接口的时候直接定义除具体泛型类型
class MessageImplString implements TIMessage<String> {
	public String echo(String t) {
		return "【ECHO】 " + t;
	}
}
class JavaDemo {
	public static void main(String [] args) {
		TIMessage<String> msg1 = new TMessageImpl<String>();
		System.out.println(msg1.echo("www.baidu.com"));
		
		TIMessage<String> msg2 = new MessageImplString();
		System.out.println(msg2.echo("www.hao123.com"));
	}
}