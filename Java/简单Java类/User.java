public class User {
	private String uid;
	private String password;
	private static int count = 0;
	public User() {
		this("NO ID", "123456");
	}
	public User(String uid) {
		this(uid, "123456");
	}
	public User(String uid, String password) {
		this.uid = uid;
		this.password = password;
		count++;
	}
	public String getInfo() {
		return "ÓÃ»§Ãû: " + this.uid +
		"\nÃÜÂë: " + this.password;
	}
	public String getUid() {
		return this.uid;
	}
	public String getPassword() {
		return this.password;
	}
	public static int getCount() {
		return User.count;
	}
	public void setUid(String uid) {
		this.uid = uid;
	}
	public void setPassword(String password) {
		this.password = password;
	}
}