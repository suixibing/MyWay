class Person {
	private String name;
	private String addr;
	private int age;
	private char sex;
	public Person() {}
	public Person(String name, String addr) {
		this(name, addr, '男', 18);
	}
	public Person(String name, String addr, char sex, int age) {
		this.name = name;
		this.addr = addr;
		this.sex = sex;
		this.age = age;
	}
	public String getInfo() {
		return "name = " + this.name +
		", addr = " + this.addr +
		", sex = " + this.sex +
		", age = " + this.age;
	}
}
public class Student extends Person { // Student是子类
	private double math;
	private double english;
	public Student() {}
	public Student(String name, String addr) {
		super(name, addr);
	}
	public Student(String name, String addr, char sex, int age, double math, double english) {
		super(name, addr, sex, age);
		this.math = math;
		this.english = english;
	}
	public String getInfo() {
		return super.getInfo() +
		", math = " + this.math +
		", english = " + this.english;
	}
}
class JavaDemo {
	public static void main(String [] args) {
		Student stu = new Student("张三", "上海", '男', 15, 75.5, 86.0);
		System.out.println(stu.getInfo());
	}
}