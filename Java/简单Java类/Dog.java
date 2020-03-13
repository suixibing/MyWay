public class Dog {
	private String name;
	private String color;
	private int age;
	public Dog() {}
	public Dog(String name, String color, int age) {
		this.name = name;
		this.color = color;
		this.age = age;
	}
	public String getInfo() {
		return "狗的名字: " + this.name +
		"\n狗的颜色: " + this.color +
		"\n狗的年龄: " + this.age;
	}
	public String getName() {
		return this.name;
	}
	public String getColor() {
		return this.color;
	}
	public int getAge() {
		return this.age;
	}
	public void setName(String name) {
		this.name = name;
	}
	public void setColor(String color) {
		this.color = color;
	}
	public void setAge(int age) {
		this.age = age;
	}
}