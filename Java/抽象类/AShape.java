abstract class AShape {
	public abstract double area();
	public abstract double perimeter();
}
class Circular extends AShape {
	private double radius;
	public Circular(double radius) {
		this.radius = radius;
	}
	@Override
	public double area() {
		return 3.1415926 * this.radius * this.radius;
	}
	@Override
	public double perimeter() {
		return 2 * 3.1415926 * this.radius;
	}
}
class Rectangle extends AShape {
	private double length;
	private double width;
	public Rectangle(double length, double width) {
		this.length = length;
		this.width = width;
	}
	@Override
	public double area() {
		return this.length * this.width;
	}
	@Override
	public double perimeter() {
		return 2 * (this.length + this.width);
	}
}
class Factory {
	public static AShape getInstance(String className, double ... args) {
		if ("circular".equalsIgnoreCase(className)) {
			return new Circular(args[0]);
		} else if ("rectangle".equalsIgnoreCase(className)) {
			return new Rectangle(args[0], args[1]);
		} else {
			return null;
		}
	}
}
class JavaDemo {
	public static void main(String [] args) {
		AShape asa = Factory.getInstance("Circular", 1.0);
		AShape asb = Factory.getInstance("Rectangle", 10, 20);
		System.out.println("圆形面积: " + asa.area() + ", 周长: " + asa.perimeter());
		System.out.println("矩形面积: " + asb.area() + ", 周长: " + asb.perimeter());
		
	}
}