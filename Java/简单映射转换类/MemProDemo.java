class Member {
	private String mid;
	private String name;
	private Product [] products;
	public Member(String mid, String name) {
		this.mid = mid;
		this.name = name;
	}
	public String getInfo() {
		return "【用户信息】 mid = " + this.mid +
		",name = " + this.name;
	}
	public Product [] getProducts() {
		return this.products;
	}
	public void setProducts(Product [] products) {
		this.products = products;
	}
}
class Product {
	private long pid;
	private String title;
	private double price;
	private Member [] members;
	public Product(long pid, String title, double price) {
		this.pid = pid;
		this.title = title;
		this.price = price;
	}
	public String getInfo() {
		return "【商品信息】 pid = " + this.pid +
		",title = " + this.title +
		",price = " + this.price;
	}
	public Member [] getMembers() {
		return this.members;
	}
	public void setMembers(Member [] members) {
		this.members = members;
	}
}

public class MemProDemo {
	public static void main(String [] args) {
		// 第一步： 根据结构设置对象数据
		Member memA = new Member("zc", "张三");
		Member memB = new Member("lisi", "李四");
		Product proA = new Product(1L, "Java开发图书", 79.8);
		Product proB = new Product(2L, "Java测试图书", 59.2);
		Product proC = new Product(3L, "C++开发图书", 93.4);
		memA.setProducts(new Product[] {proA, proB, proC});
		memB.setProducts(new Product[] {proA});
		proA.setMembers(new Member[] {memA, memB});
		proB.setMembers(new Member[] {memA});
		proC.setMembers(new Member[] {memA});
		// 第二步： 根据要求获取数据
		System.out.println("--------------根据用户查看浏览商品信息-------------");
		System.out.println(memA.getInfo());
		for (int i = 0; i < memA.getProducts().length; i++) {
			System.out.println("\t|- " + memA.getProducts()[i].getInfo());
		}
		System.out.println(memB.getInfo());
		for (int i = 0; i < memB.getProducts().length; i++) {
			System.out.println("\t|- " + memB.getProducts()[i].getInfo());
		}
		System.out.println("--------------根据商品找到被浏览的记录-------------");
		System.out.println(proA.getInfo());
		for (int i = 0; i < proA.getMembers().length; i++) {
			System.out.println("\t|- " + proA.getMembers()[i].getInfo());
		}
		System.out.println(proB.getInfo());
		for (int i = 0; i < proB.getMembers().length; i++) {
			System.out.println("\t|- " + proB.getMembers()[i].getInfo());
		}
		System.out.println(proC.getInfo());
		for (int i = 0; i < proC.getMembers().length; i++) {
			System.out.println("\t|- " + proC.getMembers()[i].getInfo());
		}
	}
}