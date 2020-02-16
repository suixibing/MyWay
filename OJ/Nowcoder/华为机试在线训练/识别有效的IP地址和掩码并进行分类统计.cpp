#include <cstring>
#include <cstdio>
using namespace std;

int Acnt, Bcnt, Ccnt, Dcnt, Ecnt, Err, Pri;

bool getIp(char *ip, unsigned int &ret)
{
	unsigned int n1, n2, n3, n4;
	if (sscanf(ip, "%u.%u.%u.%u", &n1, &n2, &n3, &n4) != 4)
		return false;
	ret = (n1 << 24) + (n2 << 16) + (n3 << 8) + n4;
	return true;
}

bool checkMask(unsigned int mask)
{
	if (mask == 0 || mask == 0xffffffff)
		return false;
	return !(~mask & (~mask + 1)); // 数取反后1的位数
}

int main()
{
	char line[32];

	while (scanf("%s\n", line) != EOF)
	{
		unsigned int ip = 0, mask = 0;
		char *pos = strchr(line, '~');
		*pos = '\0';
		if (!getIp(line, ip)
			|| !getIp(pos + 1, mask)
			|| !checkMask(mask))
		{
			++Err;
			continue;
		}
		if (ip >= 0x01000000 && ip <= 0x7effffff)
			++Acnt;
		else if (ip >= 0x80000000 && ip <= 0xbfffffff)
			++Bcnt;
		else if (ip >= 0xc0000000 && ip <= 0xdfffffff)
			++Ccnt;
		else if (ip >= 0xe0000000 && ip <= 0xefffffff)
			++Dcnt;
		else if (ip >= 0xf0000000 && ip <= 0xffffffff)
			++Ecnt;
		if (ip >= 0x0a000000 && ip <= 0x0affffff)
			++Pri;
		else if (ip >= 0xac100000 && ip <= 0xac1fffff)
			++Pri;
		else if (ip >= 0xc0a80000 && ip <= 0xc0a8ffff)
			++Pri;
	}
	printf("%d %d %d %d %d %d %d\n", Acnt, Bcnt, Ccnt, Dcnt, Ecnt, Err, Pri);

	return 0;
}