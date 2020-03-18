class Point { // 没有使用泛型时，Object的向下转换存在ClassCastException隐患
	private Object x;
	private Object y;
	public Point() {}
	public Point(Object x, Object y) {
		this.x = x;
		this.y = y;
	}
	public Object getX() {
		return this.x;
	}
	public Object getY() {
		return this.y;
	}
	public void setX(Object x) {
		this.x = x;
	}
	public void setY(Object y) {
		this.y = y;
	}
}

class JavaDemo {
	public static void main(String [] args) {
		Point point = new Point();
		// 第一步： 根据需求进行内容的设置
		point.setX(10); // 自动装箱
		point.setY(20); // 自动装箱
		// point.setY("北纬20度"); // 此时还进行Integer转换会出错
		// 第二步： 从里面获取数据
		int x = (Integer)point.getX();
		int y = (Integer)point.getY();
		System.out.println("x坐标: " + x + ", y坐标: " + y);
	}
}