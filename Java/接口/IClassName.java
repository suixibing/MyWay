interface IClassName { // 定义接口
	public String getClassName(); // 数据一定要返回
}
class Company implements IClassName {
	public String getClassName() {
		return "Company";
	}
}
class JavaDemo {
	public static void main(String [] args) {
		IClassName ica = new Company();
		System.out.println(ica.getClassName());
	}
}