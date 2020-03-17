class Int {
	private int data; // 包装了一个基本数据类型
	public Int(int data) {
		this.data = data;
	}
	public int intValue() {
		return this.data;
	}
}
/*
 * Java 自带有包装类，使基本数据类型能够转换为Object
 * Object的直接子类: Boolean,Character,Void
 * Object的一个抽象子类: Number---> Integer,Short,Byte,Long,Float,Double
 * Number自带的方法有 intValue,shortValue,byteValue,longValue,floatValue,doubleValue
 */
class JavaDemo {
	public static void main(String [] args) {
		Object obj = new Int(10); // 装箱: 将基本数据类型保存在包装类之中
		int num = ((Int)obj).intValue(); // 装箱: 从包装类对象中获取基本数据类型
		System.out.println(num * 2);
		
		Integer obj1 = new Integer(5);
		int num1 = obj1.intValue();
		System.out.println(num1 * 2);
		
		// 1.5以后支持自动包装
		Integer obj2 = 10; // 自动装箱，此时不再关心构造方法了
		int num2 = obj2; // 自动拆箱
		obj2++; // 包装类对象可以直接参与数学运算
		System.out.println(num2 * obj2); // 直接参与数学运算
		
		Object obj3 = 19.2; // double自动装箱为Double，向上转型为Object
		double num3 = (Double)obj3; // 向下转型为包装类，再自动拆箱
		System.out.println(num3 * 2);
		
		Integer xx = 17;
		Integer yy = 17;
		System.out.println(xx == yy); // true
		
		Integer xx1 = 190;
		Integer yy1 = 190;
		System.out.println(xx1 == yy1); // false
		// 包装类超过一个字节时需要使用equals()来进行比较
		
		Integer xx2 = 17;
		Integer yy2 = new Integer(17);
		System.out.println(xx2 == yy2); // false，原因与String相同
	}
}