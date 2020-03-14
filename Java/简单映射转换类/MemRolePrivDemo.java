class Member {
	private String mid;
	private String name;
	private Role [] roles;
	public Member(String mid, String name) {
		this.mid = mid;
		this.name = name;
	}
	public String getInfo() {
		return "【用户信息】 mid = " + this.mid +
		", name = " + this.name;
	}
	public Role [] getRoles() {
		return this.roles;
	}
	public void setRoles(Role [] roles) {
		this.roles = roles;
	}
}
class Role {
	private long rid;
	private String title;
	private Member [] members;
	private Privilege [] privileges;
	public Role(long rid, String title) {
		this.rid = rid;
		this.title = title;
	}
	public String getInfo() {
		return "【角色信息】 rid = " + this.rid +
		", title = " + this.title;
	}
	public Member [] getMembers() {
		return this.members;
	}
	public Privilege [] getPrivileges() {
		return this.privileges;
	}
	public void setMembers(Member [] members) {
		this.members = members;
	}
	public void setPrivileges(Privilege [] privileges) {
		this.privileges = privileges;
	}
}
class Privilege {
	private long pid;
	private String title;
	private Role role;
	public Privilege(long pid, String title) {
		this.pid = pid;
		this.title = title;
	}
	public String getInfo() {
		return "【权限信息】 pid = " + this.pid +
		", title = " + this.title;
	}
	public Role getRole() {
		return this.role;
	}
	public void setRole(Role role) {
		this.role = role;
	}
}

public class MemRolePrivDemo {
	public static void main(String [] args) {
		// 第一步： 根据结构设置对象数据
		Member memA = new Member("lb-a", "张三");
		Member memB = new Member("lb-b", "李四");
		Role roleA = new Role(1L, "系统配置");
		Role roleB = new Role(2L, "备份管理");
		Role roleC = new Role(3L, "人事管理");
		Privilege priA = new Privilege(1000L, "系统初始化");
		Privilege priB = new Privilege(1001L, "系统还原");
		Privilege priC = new Privilege(1002L, "系统环境修改");
		Privilege priD = new Privilege(1003L, "备份员工数据");
		Privilege priE = new Privilege(1004L, "备份部门数据");
		Privilege priF = new Privilege(1005L, "备份公文数据");
		Privilege priG = new Privilege(1006L, "增加员工");
		Privilege priH = new Privilege(1007L, "编辑员工");
		Privilege priI = new Privilege(1006L, "浏览员工");
		Privilege priJ = new Privilege(1007L, "员工离职");
		// 增加角色与权限的对应关系
		roleA.setPrivileges(new Privilege[] {priA, priB, priC});
		roleB.setPrivileges(new Privilege[] {priD, priE, priF});
		roleC.setPrivileges(new Privilege[] {priG, priH, priI, priJ});
		// 增加权限与角色对应
		priA.setRole(roleA);
		priB.setRole(roleA);
		priC.setRole(roleA);
		priD.setRole(roleB);
		priE.setRole(roleB);
		priF.setRole(roleB);
		priG.setRole(roleC);
		priH.setRole(roleC);
		priI.setRole(roleC);
		priJ.setRole(roleC);
		// 增加用户与角色的对应关系
		memA.setRoles(new Role[] {roleA, roleB});
		memB.setRoles(new Role[] {roleA, roleB, roleC});
		roleA.setMembers(new Member[] {memA, memB});
		roleB.setMembers(new Member[] {memA, memB});
		roleC.setMembers(new Member[] {memB});
		// 第二步： 根据要求获取数据
		System.out.println("---------------通过用户查找信息------------");
		System.out.println(memB.getInfo());
		for (int i = 0; i < memB.getRoles().length; i++) {
			System.out.println("\t|- " + memB.getRoles()[i].getInfo());
			for (int j = 0; j < memB.getRoles()[i].getPrivileges().length; j++) {
				System.out.println("\t\t|- " + memB.getRoles()[i].getPrivileges()[j].getInfo());
			}
		}
		System.out.println("---------------通过角色查找信息------------");
		System.out.println(roleB.getInfo());
		System.out.println("\t|- 浏览此角色下的所有权限信息");
		for (int i = 0; i < roleB.getPrivileges().length; i++ ) {
			System.out.println("\t\t|- " + roleB.getPrivileges()[i].getInfo());
		}
		System.out.println("\t|- 浏览此角色下的所有用户信息");
		for (int i = 0; i < roleB.getMembers().length; i++ ) {
			System.out.println("\t\t|- " + roleB.getMembers()[i].getInfo());
		}
		System.out.println("---------------通过权限查找信息------------");
		System.out.println(priA.getInfo());
		for (int i = 0; i < priA.getRole().getMembers().length; i++) {
			System.out.println("\t|- " + priA.getRole().getMembers()[i].getInfo());
		}
	}
}