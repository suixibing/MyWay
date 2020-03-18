package cn.lb.test;
// import cn.lb.util.MyMath; // 原始方法导入只含静态方法的类
import static cn.lb.util.MyMath.*; // 1.5开始的静态导入只含静态方法的类
public class TestMath {
	public static void main(String [] args) {
		// System.out.println(MyMath.add(10, 20, 30));
		// System.out.println(MyMath.sub(30, 20));
		
		// 静态导入相当于直接导入主类，可以直接使用
		System.out.println(add(10, 20, 30));
		System.out.println(sub(30, 20));
	}
}