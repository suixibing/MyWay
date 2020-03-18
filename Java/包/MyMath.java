package cn.lb.util;

public class MyMath {
	public static int add(int ... args) {
		int sum = 0;
		for (int temp : args) {
			sum += temp;
		}
		return sum;
	}
	public static int sub(int x, int y) {
		return x - y;
	}
}