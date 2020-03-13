public class JavaDemo {
	/*
	static {
		// 静态代码块比主类主方法先执行
		System.out.println("***********【静态块】主类初始化***********");
	}
	*/
	public static void main(String [] args) {
		Book b1 = new Book();
		Book b2 = new Book("JAVA");
		Book b3 = new Book("Orcale", 363);
		Book b4 = new Book("C++Primer", 564);
		System.out.println(b1.getInfo());
		System.out.println(b2.getInfo());
		System.out.println(b3.getInfo());
		System.out.println(b4.getInfo());
		System.out.println("图书总册数: " + Book.getCount());
		System.out.println();
		
		Address address = new Address("中华人民共和国", "山西", "凤凰城", "降龙街", "234423");
		System.out.println(address.getInfo());
		System.out.println();
		
		Dept dept = new Dept(4234, "项目", "上海");
		System.out.println(dept.getInfo());
		System.out.println();
		
		Employee emp = new Employee(2012, "汤姆", "项目", 2564.2, 0.3);
		System.out.println(emp.getInfo());
		System.out.println("工资调整额度: " + emp.salaryIncValue());
		System.out.println(emp.getInfo());
		System.out.println("上调后的工资: " + emp.salaryIncResult());
		System.out.println(emp.getInfo());
		System.out.println();
		
		Person p1 = new Person("杰克", 34);
		Person p2 = new Person("汉斯", 36);
		Person p3 = new Person("唐纳德", 24);
		Person.setCountry("煤国");
		System.out.println(p1.getInfo());
		System.out.println(p2.getInfo());
		System.out.println(p3.getInfo());
		System.out.println();
		
		Dog dog = new Dog("小白", "黄色", 3);
		System.out.println(dog.getInfo());
		dog.setAge(5);
		dog.setName("大黄");
		System.out.println(dog.getInfo());
		System.out.println();
		
		Account ac = new Account("小张", 25642.5);
		System.out.println(ac.getInfo());
		System.out.println();

		User userA = new User();
		User userB = new User("小强");
		User userC = new User("大强", "你猜");
		System.out.println(userA.getInfo());
		System.out.println(userB.getInfo());
		System.out.println(userC.getInfo());
		System.out.println(User.getCount());
		System.out.println();
	}
}