interface IMessage {
	public String getMessage();
}
// 使用枚举定义Color
// 枚举类中可以定义构造方法，但是不能是public访问权限
// 但是可以通过覆写父类的方法获得public方法
// 使用枚举实现远远比多例模式要方便简单
enum EColor implements IMessage { // 枚举类
	// 不提倡使用汉字
	// 没有无参构造，需要显式调用构造函数
	RED("红色"), GREEN("绿色"), BLUE("蓝色"), 
	红色("红色"), 绿色("绿色"), 蓝色("蓝色"); // 实例化对象
	private String title; // 枚举变量要写在首行
	private EColor(String title) {
		this.title = title;
	}
	public String toString() {
		return this.title;
	}
	@Override
	public String getMessage() {
		return this.title;
	}
}

enum EColor1 {
	RED("红色") {
		public String getMessage() {
			return this.toString();
		}
	}, GREEN("绿色") {
		public String getMessage() {
			return this.toString();
		}
	}, BLUE("蓝色") {
		public String getMessage() {
			return this.toString();
		}
	};
	private String title;
	private EColor1(String title) {
		this.title = title;
	}
	public String toString() {
		return this.title;
	}
	// 枚举可以直接定义抽象方法，并直接在每个实例时覆写
	public abstract String getMessage();
}

/* -------------------------------------------------------------------------------- */

enum Sex {
	MALE("男"), FEMALE("女");
	private String title;
	private Sex(String title) {
		this.title = title;
	}
	public String toString() {
		return this.title;
	}
}

class Person {
	private String name;
	private int age;
	private Sex sex;
	public Person(String name, int age, Sex sex) {
		this.name = name;
		this.age = age;
		this.sex = sex;
	}
	public String toString() {
		return "name = " + this.name + 
		", age = " + this.age + 
		", sex = " + this.sex;
	}
}

/* -------------------------------------------------------------------------------- */

class JavaDemo {
	public static void main(String [] args) {
		// 多例模式实现的Color
		// 当指定不存在的目标时，返回null
		// Color c = Color.getInstance("pink");
		// Color c = Color.getInstance("Blue");
		// System.out.println(c);
		
		// 当指定不存在的目标时，直接报错，错误: 找不到符号
		// EColor ec = EColor.红;
		EColor ec = EColor.红色; // 获取实例化对象
		System.out.println(ec);
		// 使用枚举可以很简单的实现遍历
		for (EColor temp : EColor.values()) {
			System.out.println(temp);
		}
		// switch也支持使用枚举
		switch (ec) {
			case RED:
			case 红色:
				System.out.println("红色");
				break;
			case GREEN:
			case 绿色:
				System.out.println("绿色");
				break;
			case BLUE:
			case 蓝色:
				System.out.println("蓝色");
				break;
		}
		
		// enum定义的类实际是继承自Enum类，所有继承有ordinal和name方法
		for (EColor temp : EColor.values()) {
			System.out.println(temp.ordinal() + " - " + temp.name() + " - " + temp);
		}
		
		IMessage msg = EColor.RED;
		System.out.println(msg.getMessage());
		
		System.out.println(EColor1.RED.getMessage());
		
		System.out.println("-----------------------实际应用----------------------");
		System.out.println(new Person("张三", 20, Sex.MALE));
	}
}