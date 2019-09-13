#include"func.h"

void MailSystem()
{
	int id, ret, flag;
	char aim[50] = { 0 };

	g_mail.num = 0;
	g_mail.man = (MailMSG*)calloc(MANNUM, sizeof(MailMSG));
	LoadMail();
	while (flag = Menu())
	{
		switch (flag)
		{
		case EXIT_SYS:
			printf("退出中。。。\n");
			return;
		case ADD_MSG:
			InsertMail();
			break;
		case DELETE_MSG:
			printf("请输入要删除信息人的编号:>");
			scanf("%d", &id);
			if (DeleteMail(id - 1))
			{
				printf("删除成功!\n");
			}
			else
			{
				printf("该信息不存在!\n");
			}
			break;
		case SEARCH_MSG:
			printf("请输入要查找的信息:>");
			scanf("%s", aim);
			printf("查找开始：\n");
			ret = SearchMail(aim);
			if (ret)
			{
				printf("查找结束！\n");
				printf("共查找到信息%d条\n", ret);
			}
			else
			{
				printf("不存在符合条件的信息\n");
				printf("查找结束！\n");
			}
			break;
		case CHANGE_MSG:
			printf("请输入要修改信息人的编号:>");
			scanf("%d", &id);
			if (ChangeMail(id - 1))
			{
				printf("修改成功!\n");
			}
			else
			{
				printf("该信息不存在!\n");
			}
			break;
		case OUTPUT_MSG:
			OutputMail();
			break;
		
		default:
			printf("ERROR!\n");
			break;
		}
	}
}

int main()
{
	MailSystem();
	SaveMail();
	printf("已退出!\n");

	system("pause");
	return 0;
}