public class Account {
	private String name;
	private double balance;
	public Account() {}
	public Account(String name) {
		this(name, 0.0);
	}
	public Account(String name, double balance) {
		this.name = name;
		this.balance = balance;
	}
	public String getInfo() {
		return "’Àªß√˚≥∆: " + this.name +
		"\n”‡∂Ó: " + this.balance;
	}
	public String getName() {
		return this.name;
	}
	public double getBalance() {
		return this.balance;
	}
	public void setName(String name) {
		this.name = name;
	}
	public void setBalance(double balance) {
		this.balance = balance;
	}
}