class Array { // 数组的操作类
	private int [] data; // 整型数组
	private int foot;
	public Array(int len) {
		if (len > 0) {
			this.data = new int[len]; // 开辟数组
		} else {
			this.data = new int[1]; // 开辟一个空间
		}
	}
	// 实现数组的容量扩充，给出的是扩充大小，实际大小: 已有大小+扩充大小
	public void increment(int num) {
		int [] newData = new int[this.data.length + num];
		System.arraycopy(this.data, 0, newData, 0, this.data.length);
		this.data = newData; // 改变数组引用
	}
	public boolean add(int num) { // 数据增加
		if (this.foot < this.data.length) { // 有位置
			this.data[this.foot++] = num;
			return true;
		}
		return false;
	}
	public int[] getData() {
		return this.data;
	}
}
class SortArray extends Array { // 定义排序子类
	public SortArray(int len) {
		super(len);
	}
	public int [] getData() { // 获得排序结果
		java.util.Arrays.sort(super.getData()); // 排序
		return super.getData();
	}
}
class ReverseArray extends Array { // 定义反转子类
	public ReverseArray(int len) {
		super(len);
	}
	public int [] getData() { // 获得反转结果
		int center = super.getData().length / 2;
		int temp, head = 0, tail = super.getData().length - 1;
		for (int i = 0; i < center; i++) {
			temp = super.getData()[head];
			super.getData()[head] = super.getData()[tail];
			super.getData()[tail] = temp;
			++head;
			--tail;
		}
		return super.getData();
	}
}
class JavaDemo {
	public static void main(String [] args) {
		Array arr1 = new SortArray(5);
		System.out.println(arr1.add(16));
		System.out.println(arr1.add(82));
		System.out.println(arr1.add(23));
		System.out.println(arr1.add(74));
		System.out.println(arr1.add(55));
		System.out.println(arr1.add(62));
		arr1.increment(3);
		System.out.println(arr1.add(62));
		System.out.println(arr1.add(47));
		System.out.println(arr1.add(89));
		int [] data1 = arr1.getData();
		for (int i : data1) {
			System.out.print(i + ", ");
		}
		System.out.println();
		
		Array arr2 = new ReverseArray(5);
		System.out.println(arr2.add(1));
		System.out.println(arr2.add(2));
		System.out.println(arr2.add(3));
		System.out.println(arr2.add(4));
		System.out.println(arr2.add(5));
		int [] data2 = arr2.getData();
		for (int i : data2) {
			System.out.print(i + ", ");
		}
		System.out.println();
	}
}