class TPoint <T> {
	// 此时x,y的类型并不确定
	private T x;
	private T y;
	public TPoint() {}
	public TPoint(T x, T y) {
		this.x = x;
		this.y = y;
	}
	public T getX() {
		return this.x;
	}
	public T getY() {
		return this.y;
	}
	public void setX(T x) {
		this.x = x;
	}
	public void setY(T y) {
		this.y = y;
	}
}
// 使用泛型可以解决大部分的类对象的强制类型转换，这样的程序才是一个合理的设计
// 引入泛型后就不需要再使用Object接收所有类型，因为Object存在转换隐患
class JavaDemo {
	public static void main(String [] args) {
		// TPoint point = new TPoint(); // 不适用<Type>时，自动将使用Object但会出现编译警告
		// Type不能直接使用基本数据类型，这时可以使用包装类作为Type
		// 1.7开始，泛型对象实例化可以简化为TPoint<Integer> point = new TPoint<>();
		TPoint<Integer> point = new TPoint<Integer>();
		// 第一步： 根据需求进行内容的设置
		point.setX(10); // 自动装箱
		point.setY(20); // 自动装箱
		// point.setY("北纬20度"); // 此时会直接编译报错
		// 第二步： 从里面获取数据
		// 指定了Type后，可以不用转型
		int x = point.getX();
		int y = point.getY();
		System.out.println("x坐标: " + x + ", y坐标: " + y);
	}
}