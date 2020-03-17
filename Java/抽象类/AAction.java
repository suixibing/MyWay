public abstract class AAction {
	public static final int EAT = 1;
	public static final int SLEEP = 5;
	public static final int WORK = 10;
	public void command(int code) {
		switch (code) {
			case EAT: {
				this.eat();
				break;
			}
			case SLEEP: {
				this.sleep();
				break;
			}
			case WORK: {
				this.work();
				break;
			}
			case EAT + SLEEP + WORK: {
				this.eat();
				this.sleep();
				this.work();
				break;
			}
		}
	}
	public abstract void eat();
	public abstract void sleep();
	public abstract void work();
}
class Person extends AAction {
	@Override
	public void eat() {
		System.out.println("饿的时候安静的坐下吃饭。");
	}
	@Override
	public void sleep() {
		System.out.println("安静的躺下，慢慢的睡着，而后做着美梦。");
	}
	@Override
	public void work() {
		System.out.println("人类是高级脑类动物，所以要有想法的工作。");
	}
}
class Pig extends AAction {
	@Override
	public void eat() {
		System.out.println("吃食槽中的人类的剩饭。");
	}
	@Override
	public void sleep() {
		System.out.println("倒地就睡。");
	}
	@Override
	public void work() {}
}
class Robot extends AAction {
	@Override
	public void eat() {
		System.out.println("机器人需要接通电源充电。");
	}
	@Override
	public void sleep() {}
	@Override
	public void work() {
		System.out.println("机器人按照固定的套路进行工作。");
	}
}
class JavaDemo {
	public static void main(String [] args) {
		AAction robot = new Robot();
		AAction person = new Person();
		AAction pig = new Pig();
		System.out.println("----------------机器人行为-----------");
		robot.command(AAction.SLEEP);
		robot.command(AAction.WORK);
		System.out.println("----------------人类的行为-----------");
		person.command(AAction.SLEEP + AAction.EAT + AAction.WORK);
		System.out.println("-----------------猪的行为------------");
		pig.command(AAction.EAT);
		pig.command(AAction.SLEEP);
	}
}