// 链表实现在LinkList.java中
interface Pet { // 定义宠物标准
	public String getName(); // 获得名字
	public String getColor(); // 获得颜色
}
class PetShop { // 宠物商店
	private ILink<Pet> allPets = new LinkImpl<Pet>(); // 保存多个宠物信息
	public void add(Pet pet) { // 追加对象，商品上架
		this.allPets.add(pet); // 集合中保存对象
	}
	public void delete(Pet pet) {
		this.allPets.remove(pet);
	}
	public ILink<Pet> search(String keyword) {
		ILink<Pet> searchResult = new LinkImpl<Pet>();
		Object [] result = this.allPets.toArray(); // 获取全部数据
		if (result != null) {
			for (Object obj : result) {
				Pet pet = (Pet)obj;
				if (pet.getName().contains(keyword) 
					|| pet.getColor().contains(keyword)) {
					searchResult.add(pet); // 保存查询结果
				}
			}
		}
		return searchResult;
	}
}
class Cat implements Pet { // 实现宠物标准
	private String name;
	private String color;
	public Cat(String name, String color) {
		this.name = name;
		this.color = color;
	}
	public String getName() {
		return this.name;
	}
	public String getColor() {
		return this.color;
	}
	public boolean equals(Object obj) {
		if (obj == null || !(obj instanceof Cat)) {
			return false;
		}
		if (this == obj) {
			return true;
		}
		Cat cat = (Cat)obj;
		return cat.name.equals(this.name) && cat.color.equals(this.color);
	}
	public String toString() {
		return "【宠物猫】 名字： " + this.name + "，颜色： " + this.color;
	}
}
class Dog implements Pet { // 实现宠物标准
	private String name;
	private String color;
	public Dog(String name, String color) {
		this.name = name;
		this.color = color;
	}
	public String getName() {
		return this.name;
	}
	public String getColor() {
		return this.color;
	}
	public boolean equals(Object obj) {
		if (obj == null || !(obj instanceof Dog)) {
			return false;
		}
		if (this == obj) {
			return true;
		}
		Dog dog = (Dog)obj;
		return dog.name.equals(this.name) && dog.color.equals(this.color);
	}
	public String toString() {
		return "【宠物狗】 名字： " + this.name + "，颜色： " + this.color;
	}
}
class JavaDemo {
	public static void main(String [] args) {
		PetShop shop = new PetShop(); // 开店
		shop.add(new Dog("黄斑狗", "黄色"));
		shop.add(new Dog("黄狗", "黄色"));
		shop.add(new Cat("黄猫", "黄色"));
		shop.add(new Cat("斑点猫", "黄色"));
		shop.add(new Cat("小强猫", "绿色"));
		shop.add(new Dog("花狗", "杂色"));
		shop.add(new Dog("小黑狗", "黑色"));
		Object [] result = shop.search("黄").toArray();
		if (result != null) {
			for (Object obj : result) {
				System.out.println(obj);
			}
		}
	}
}