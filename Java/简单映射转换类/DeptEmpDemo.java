class Dept {
	private long deptno;
	private String dname;
	private String loc;
	private Emp emps []; // 多个雇员信息
	public Dept() {}
	public Dept(long deptno, String dname, String loc) {
		this.deptno = deptno;
		this.dname = dname;
		this.loc = loc;
	}
	public String getInfo() {
		return "【部门信息】 部门编号: " + this.deptno + 
		", 部门名称: " + this.dname +
		", 部门位置: " + this.loc;
	}
	public void setEmps(Emp [] emps) {
		this.emps = emps;
	}
	public Emp [] getEmps() {
		return this.emps;
	}
}	
class Emp {
	private long empno;
	private String ename;
	private String job;
	private double salary;
	private double comm;
	private Dept dept; // 所属部门
	private Emp mgr; // 所属领导
	public Emp(long empno, String ename, String job, double salary, double comm) {
		this.empno = empno;
		this.ename = ename;
		this.job = job;
		this.salary = salary;
		this.comm = comm;
	}
	public String getInfo() {
		return "【雇员信息】 雇员编号: " + this.empno + 
		",雇员姓名: " + this.ename + 
		",雇员职位： " + this.job +
		",基本工资: " + this.salary + 
		",佣金: " + this.comm;
	}
	public Dept getDept() {
		return this.dept;
	}
	public Emp getMgr() {
		return this.mgr;
	}
	public void setDept(Dept dept) {
		this.dept = dept;
	}
	public void setMgr(Emp mgr) {
		this.mgr = mgr;
	}
}
public class DeptEmpDemo {

	public static void main(String [] args) {
		// 第一步： 根据关系进行类的定义
		// 定义出各个实例化对象，此时并没有任何的关联定义
		Dept dept = new Dept(10, "财务部", "上海");
		Emp empA = new Emp(7369L, "SMITH", "CLERK", 800.00, 0.0);
		Emp empB = new Emp(7566L, "FIRD", "MANAGER", 2450.00, 0.0);
		Emp empC = new Emp(7839L, "KING", "PRESIDENT", 5000.00, 0.0);
		// 需要为对象进行关联的设置
		empA.setDept(dept); // 设置雇员与部门的关联
		empB.setDept(dept); // 设置雇员与部门的关联
		empC.setDept(dept); // 设置雇员与部门的关联
		empA.setMgr(empB); // 设置雇员与领导的关联
		empB.setMgr(empC); // 设置雇员与领导的关联
		dept.setEmps(new Emp[] {empA, empB, empC}); // 部门与雇员
		// 第二步： 根据关系获取数据
		System.out.println(dept.getInfo());
		for (int i = 0; i < dept.getEmps().length; i++) {
			System.out.println("\t|- " + dept.getEmps()[i].getInfo());
			if (dept.getEmps()[i].getMgr() != null)
				System.out.println("\t\t|- " + dept.getEmps()[i].getMgr().getInfo());
		}
		System.out.println("--------------------------------------------");
		System.out.println(empB.getDept().getInfo()); // 根据雇员获取部门信息
		System.out.println(empB.getMgr().getInfo()); // 根据雇员获取领导信息

	}
}