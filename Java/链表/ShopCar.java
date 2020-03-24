// 链表实现在LinkList.java中
interface IGoods { // 定义商品标准
	public String getName();
	public double getPrice();
}
interface IShopCar { // 定义购物车标准
	public void add(IGoods goods); // 添加商品信息
	public void delete(IGoods goods); // 删除商品
	public Object [] getAll(); // 获得购物车中的全部商品信息
}
class ShopCarImpl implements IShopCar { // 购物车
	private ILink<IGoods> allGoodses = new LinkImpl<IGoods>();
	public void add(IGoods goods) {
		this.allGoodses.add(goods);
	}
	public void delete(IGoods goods) {
		this.allGoodses.remove(goods);
	}
	public Object [] getAll() {
		return this.allGoodses.toArray();
	}
}
class Cashier { // 收银台
	private IShopCar shopcar;
	public Cashier(IShopCar shopcar) {
		this.shopcar = shopcar;
	}
	public double allPrice() { // 计算总价
		double all = 0.0;
		Object [] result = this.shopcar.getAll();
		for (Object obj : result) {
			IGoods goods = (IGoods)obj;
			all += goods.getPrice();
		}
		return all;
	}
	public int allCount() { // 商品数量
		return this.shopcar.getAll().length;
	}
}
class Book implements IGoods {
	private String name;
	private double price;
	public Book(String name, double price) {
		this.name = name;
		this.price = price;
	}
	public String getName() {
		return this.name;
	}
	public double getPrice() {
		return this.price;
	}
	public boolean equals(Object obj) {
		if (obj == null || !(obj instanceof Book)) {
			return false;
		}
		if (this == obj) {
			return true;
		}
		Book book = (Book)obj;
		return book.name.equals(this.name) && book.price == this.price;
	}
	public String toString() {
		return "【图书信息】 名称： " + this.name + "，价格： " + this.price;
	}
}
class Bag implements IGoods {
	private String name;
	private double price;
	public Bag(String name, double price) {
		this.name = name;
		this.price = price;
	}
	public String getName() {
		return this.name;
	}
	public double getPrice() {
		return this.price;
	}
	public boolean equals(Object obj) {
		if (obj == null || !(obj instanceof Bag)) {
			return false;
		}
		if (this == obj) {
			return true;
		}
		Bag bag = (Bag)obj;
		return bag.name.equals(this.name) && bag.price == this.price;
	}
	public String toString() {
		return "【背包信息】 名称： " + this.name + "，价格： " + this.price;
	}
}
class JavaDemo {
	public static void main(String [] args) {
		IShopCar car = new ShopCarImpl();
		car.add(new Book("Java开发", 79.9));
		car.add(new Book("Oracle开发", 89.9));
		car.add(new Book("小强牌背包", 899.9));
		Cashier cas = new Cashier(car);
		System.out.println("总价格： " + cas.allPrice() + ", 购买数量： " + cas.allCount());
	}
}