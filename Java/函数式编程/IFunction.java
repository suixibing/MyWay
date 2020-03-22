@FunctionalInterface
interface IFunction1<P, R> {
	public R change(P p);
	// 可以取中文名方法，但是不提倡这么做
	// public R 转换(P p);
}
@FunctionalInterface
interface IFunction2<R> {
	public R upper();
}
@FunctionalInterface
interface IFunction3<P> {
	public int compare(P p1, P p2);
}
class Person {
	private String name;
	private int age;
	public Person(String name, int age) {
		this.name = name;
		this.age = age;
	}
	public String toString() {
		return "name = " + this.name +
		", age = " + this.age;
	}
}
@FunctionalInterface
interface IFunction4<R> {
	public R create(String s, int a);
}
class JavaDemo {
	public static void main(String [] args) {
		// MethodReferences 方法引用
		// 引用数据类型最大的特点是可以进行内存的指向处理，
		// 但是在传统的开发之中一直所使用的只是对象引用操作，
		// 而JDK1.8之后也提供有方法的引用，即不同的方法名称可以描述同一个方法。
		// 提供方法引用的概念更多的情况下也只是弥补了对于引用的支持功能

		// 如果要进行方法的引用，在Java里面提供有如下的四种：	
		// 1、引用静态方法 【类名称：：static方法名称】
		//	在String类里面提供有String.valueOf()方法，这个方法就属于静态方法
		//		|- 方法定义： public static String valueOf(int i), 该方法有参数，并且还有返回值
		IFunction1<Integer, String> fun1 = String::valueOf;
		String str1 = fun1.change(100);
		System.out.println(str1.length());
		
		// 2、引用实例化对象中的方法 【实例化对象：：普通方法】
		//	在String类里面提供有一个转大写的方法： public String toUpperCase()
		//		|- 这个方法是必须在有实例化对象提供的情况下才可以调用
		IFunction2<String> fun2 = "www.baidu.com"::toUpperCase;
		System.out.println(fun2.upper());
		
		// 3、引用特定类型的方法 【特定类：：普通方法】
		// 	在进行方法引用的时候也可以引用特定类中的一些操作方法，
		//	在String类里面提供有一个字符串大小关系的比较
		//		|- 比较方法： public int compareTo(String anotherString);
		// 			这是一个普通方法，如果要引用普通方法，则往往都需要实例化对象，
		//			但是如果说不想给出实例化对象，只是想引用这个方法，则就可以使用特定类来引用处理
		IFunction3<String> fun3 = String::compareTo;
		System.out.println(fun3.compare("A", "a"));
		
		// 4、引用构造方法 【类名称：：new】
		// 在方法引用里面最具有杀伤力的就是构造方法的引用
		IFunction4<Person> fun4 = Person::new;
		System.out.println(fun4.create("张三", 20));
	}
}