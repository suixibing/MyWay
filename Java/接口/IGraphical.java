interface IGraphical { // 定义绘图标准
	public void paint(); // 绘图
}
class Point { // 定义坐标类
	private double x;
	private double y;
	public Point(double x, double y) {
		this.x = x;
		this.y = y;
	}
	public double getX() {
		return this.x;
	}
	public double getY() {
		return this.y;
	}
	public String toString() {
		return "[" + this.x + "," + this.y + "]";
	}
}
class Triangle implements IGraphical { // 绘制三角形
	private Point [] x;
	private Point [] y;
	private Point [] z;
	public Triangle(Point [] x, Point [] y, Point [] z) {
		this.x = x;
		this.y = y;
		this.z = z;
	}
	@Override
	public void paint() {
		System.out.println("【绘制三角形】 开始绘制: ");
		System.out.println("\t|-【第一条边】 开始坐标: " + this.x[0] + ", 结束坐标: " + this.x[1]);
		System.out.println("\t|-【第二条边】 开始坐标: " + this.y[0] + ", 结束坐标: " + this.y[1]);
		System.out.println("\t|-【第三条边】 开始坐标: " + this.z[0] + ", 结束坐标: " + this.z[1]);
	}
}
class Circular implements IGraphical { // 绘制圆形
	private Point center;
	private double radius;
	public Circular(Point center, double radius) {
		this.center = center;
		this.radius = radius;
	}
	@Override
	public void paint() {
		System.out.println("【绘制圆形】 开始绘制: 以" + 
		this.center + "为圆心, 以" + this.radius + "为半径绘制圆形");
	}
}
class Factory { // 定义工厂类
	public static IGraphical getInstance(String className, double ... args) {
		if ("triangl".equalsIgnoreCase(className)) {
			return new Triangle(
				new Point[] {
					new Point(args[0], args[1]), 
					new Point(args[2], args[3])
				}, new Point[] {
					new Point(args[2], args[3]), 
					new Point(args[4], args[5])
				}, new Point[] {
					new Point(args[4], args[5]), 
					new Point(args[0], args[1])
				}
			);
		} else if ("circular".equalsIgnoreCase(className)) {
			return new Circular(new Point(args[0], args[1]), args[2]);
		} else {
			return null;
		}
	}
}
class JavaDemo {
	public static void main(String [] args) {
		IGraphical iga = Factory.getInstance("triangl", 1.1, 2.2, 3.3, 4.4, 5.5, 6.6);
		iga.paint();
		IGraphical iga2 = Factory.getInstance("circular", 2.5, 2.6, 10);
		iga2.paint();
	}
}