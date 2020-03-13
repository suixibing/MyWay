public class Person {
	private int age;
	private String name;
	private static String country = "中华民国";
	public Person() {
		//System.out.println("********一个Person类被构造了*******");
	}
	public Person(String name) {
		this();
		this.setName(name);
	}
	public Person(String name, int age) {
		this(name);
		if (age >= 0) {
			this.setAge(age);
		}
	}
	public void tell() {
		System.out.println("姓名: " + this.name + 
		"\n年龄: " + this.age + 
		"\n国家: " + this.country);
	}
	public String getInfo() {
		return "姓名: " + this.name + 
		"\n年龄: " + this.age + 
		"\n国家: " + this.country;
	}
	public int getAge() {
		return this.age;
	}
	public String getName() {
		return this.name;
	}
	public static String getCountry() {
		return Person.country;
	}
	public void setAge(int age) {
		this.age = age;
	}
	public void setName(String name) {
		this.name = name;
	}
	public static void setCountry(String country) {
		Person.country = country;
	}
}