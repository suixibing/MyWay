class Employee {
	private String name;
	private char sex;
	private int age;
	public Employee() {}
	public Employee(String name, char sex, int age) {
		this.name = name;
		this.sex = sex;
		this.age = age;
	}
	public String getInfo() {
		return "name = " + this.name +
		", sex = " + this.sex +
		", age = " + this.age;
	}
}
class Manager extends Employee {
	private String job;
	private double income;
	public Manager() {}
	public Manager(String name, char sex, int age, String job, double income) {
		super(name, sex, age);
		this.job = job;
		this.income = income;
	}
	@Override
	public String getInfo() {
		return "【管理层】 " + super.getInfo() +
		", job = " + this.job +
		", income = " + this.income;
	}
}
class Staff extends Employee {
	private String dept;
	private double salary;
	public Staff() {}
	public Staff(String name, char sex, int age, String dept, double salary) {
		super(name, sex, age);
		this.dept = dept;
		this.salary = salary;
	}
	@Override
	public String getInfo() {
		return "【职员】 " + super.getInfo() +
		", dept = " + this.dept +
		", salary = " + this.salary;
	}
}
class JavaDemo {
	public static void main(String [] args) {
		Manager man = new Manager("张三", '男', 25, "主管", 15000.0);
		Staff sta = new Staff("李四", '男', 20, "项目部", 8000.0);
		
		System.out.println(man.getInfo());
		System.out.println(sta.getInfo());
	}
}