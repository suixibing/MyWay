public class Dept {
	private long deptno;
	private String dname;
	private String loc;
	public Dept() {}
	public Dept(long deptno, String dname, String loc) {
		this.deptno = deptno;
		this.dname = dname;
		this.loc = loc;
	}
	public String getInfo() {
		return "部门编号: " + this.deptno + 
		"\n部门名称: " + this.dname +
		"\n部门位置: " + this.loc;
	}
	public void setDeptno(long deptno) {
		this.deptno = deptno;
	}
	public void setDname(String dname) {
		this.dname = dname;
	}
	public void setLoc(String loc) {
		this.loc = loc;
	}
	public long getDeptno() {
		return this.deptno;
	}
	public String getDname() {
		return this.dname;
	}
	public String getLoc() {
		return this.loc;
	}
}	