import java.util.function.*;
/*
 *		Java内建有几个比较典型的函数式接口如下：
 *	1、功能型函数式接口： 接收数据并返回结构
 *		在String类中提供有一个接收参数同时有返回操作结果的方法
 *			|- String.startsWith;
 * 		@FunctionalInterface
 * 		public interface Function<T, R> {
 * 			public R apply(T t);
 * 		}

 *	2、消费型函数式接口： 只能进行数据的处理操作，而没有任何的返回
 *		在进行系统数据输出的时候使用是一个接收参数，没有返回值的方法
 *			|- System.out.println;
 * 		@FunctionalInterface
 * 		public interface Consumer<T> {
 * 			public void apply(T t);
 * 		}
 *
 * 	3、供给型函数式接口： 不接受数据，只有返回的操作
 *		在String类中提供有一个没有接收参数，但是有返回值的方法
 *			|- String.toLowerCase;
 *		@FunctionalInterface
 * 		public interface Supplier<T> {
 * 			public T get();
 * 		}
 *
 *	4、断言型函数式接口： 进行数据判断处理
 *		在String类中提供有一个只进行判断的方法
 *			|- String.equalsIgnoreCase;
 *		@FunctionalInterface
 * 		public interface Predicate<T> {
 * 			public boolean test(T t);
 * 		}
*/
class JavaDemo {
	public static void main(String [] args) {
		Function<String, Boolean> fun = "**Function"::startsWith;
		System.out.println(fun.apply("**"));
		
		Consumer<String> con = System.out::println;
		con.accept("www.baidu.com");
		
		Supplier<String> sup = "WWW.HAO123.COM"::toLowerCase;
		System.out.println(sup.get());
		
		Predicate<String> pre = "lb"::equalsIgnoreCase;
		System.out.println(pre.test("LB"));
	}
}