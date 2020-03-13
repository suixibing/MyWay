public class Book {
	private String bid; // 图书编号
	private String title; // 书名
	private double price; // 价格
	private static int count = 0;
	
	/*
	static {
		// 可能有很多语句需要用于初始化静态成员
		System.out.println("【静态块】 Book静态块执行");
	}
	{
		System.out.println("【构造块】 Book构造块执行");
	}
	*/
	public Book() {
		this("NOTITLE - " + (Book.count + 1), -1);
	}
	public Book(String title) {
		this(title, -1);
	}
	public Book(String title, double price) {
		//System.out.println("【构造方法】 Book类构造方法执行");
		Book.count++;
		this.bid = "" + Book.count;
		this.title = title;
		this.price = price;
		//System.out.println("创建第" + Book.count + "本图书: " + this.title);
	}
	public String getInfo() {
		return "图书编号: " + this.bid +
		"\n书名: " + this.title +
		"\n价格: " + this.price;
	}
	public String getBid() {
		return this.bid;
	}
	public String getTitle() {
		return this.title;
	}
	public double getPrice() {
		return this.price;
	}
	public static int getCount() {
		return Book.count;
	}
	public void setBid(String bid) {
		this.bid = bid;
	}
	public void setTitle(String title) {
		this.title = title;
	}
	public void setPrice(double price) {
		this.price = price;
	}
}