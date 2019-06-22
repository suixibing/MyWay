#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define CHARNUM 256
#define BIT 8

typedef struct
{
	unsigned char uch;
	unsigned long weight;
}TmpHuff;

typedef struct
{	
	unsigned char uch;
	char *huff_code;
	unsigned long weight;
	int lchild, rchild, parent;
}Huffman;

int CmpTmpHuff(const void *h1, const void *h2)
{
	return ((TmpHuff*)h2)->weight - ((TmpHuff*)h1)->weight;
}

void Select(Huffman *huff_tree, int n, int *s1, int *s2)
{
	int i;
	unsigned long min = ULONG_MAX;

	for (i = 0; i < n; i++)
	{
		if (huff_tree[i].parent == 0 && huff_tree[i].weight < min)
		{
			min = huff_tree[i].weight;
			*s1 = i;
		}
	}
	huff_tree[*s1].parent = n;
	min = ULONG_MAX;
	for (i = 0; i < n; i++)
	{
		if (huff_tree[i].parent == 0 && huff_tree[i].weight < min)
		{
			min = huff_tree[i].weight;
			*s2 = i;
		}
	}
}

void CreateTree(Huffman *huff_tree, unsigned char code_kinds, int node_num)
{
	int i, s1, s2;

	for (i = code_kinds; i < node_num; i++)
	{
		Select(huff_tree, i, &s1, &s2);
		huff_tree[i].weight = huff_tree[s1].weight + huff_tree[s2].weight;
		huff_tree[i].lchild = s1;
		huff_tree[i].rchild = s2;
		huff_tree[s1].parent = i;
		huff_tree[s2].parent = i;
	}
}

void HufCode(Huffman *huff_tree, unsigned char code_kinds)
{
	int i, j, point;
	int cur, next;
	char *huff_code = (char*)calloc(CHARNUM, sizeof(char));

	for (i = 0, j = 0; i < code_kinds; i++)
	{
		point = CHARNUM - 1;
		huff_code[point] = '\0';
		for (cur = j, next = huff_tree[j].parent; next != 0; j = next, next = huff_tree[j].parent)
		{
			if (cur == huff_tree[next].lchild)
			{
				huff_code[--point] = '1';
			}
			else
			{
				huff_code[--point] = '0';
			}
		}
		huff_tree[i].huff_code = (char*)calloc(1, (CHARNUM - point) * sizeof(char));
		strcpy(huff_tree[i].huff_code, &huff_code[point]);
	}
	free(huff_code);
}

int Compress(char *ifilename, char *ofilename)//压缩函数
{
	int i, buf_len, node_num;
	unsigned char char_tmp, *code_buf, code_kinds;
	unsigned long file_len = 0;
	FILE *infile, *outfile;
	TmpHuff *tmp_huff = (TmpHuff*)calloc(CHARNUM, sizeof(TmpHuff));
	Huffman *huff_tree;

	for (i = 0; i < CHARNUM; i++)
	{
		tmp_huff[i].uch = (unsigned char)i;
		tmp_huff[i].weight = 0;
	}
	infile = fopen(ifilename, "rb");
	if (infile == NULL)
	{
		return -1;
	}
	fread(&char_tmp, sizeof(char), 1, infile);
	while (!feof(infile))
	{
		file_len++;
		tmp_huff[char_tmp].weight++;
		fread(&char_tmp, sizeof(char), 1, infile);
	}
	qsort(tmp_huff, CHARNUM, sizeof(TmpHuff), CmpTmpHuff);
	for (code_kinds = 0; tmp_huff[code_kinds].weight != 0; code_kinds++)//统计有几种字符
		;
	if (code_kinds == 1)
	{
		outfile = fopen(ofilename, "wb");
		fwrite(&code_kinds, sizeof(unsigned char), 1, outfile);
		fwrite(&tmp_huff[0].uch, sizeof(unsigned char), 1, outfile);
		fwrite(&tmp_huff[0].weight, sizeof(unsigned long), 1, outfile);
		free(tmp_huff);
		fclose(outfile);
	}
	else
	{
		node_num = 2 * code_kinds - 1;
		huff_tree = (Huffman*)calloc(node_num, sizeof(Huffman));
		for (i = 0; i < code_kinds; i++)
		{
			huff_tree[i].uch = tmp_huff[i].uch;
			huff_tree[i].weight = tmp_huff[i].weight;
			huff_tree[i].parent = 0;
		}
		free(tmp_huff);
		for (; i < node_num; i++)
		{
			huff_tree[i].parent = 0;
		}
		CreateTree(huff_tree, code_kinds, node_num);
		HufCode(huff_tree, code_kinds);
		outfile = fopen(ofilename, "wb");
		fwrite(&code_kinds, sizeof(unsigned char), 1, outfile);
		for (i = 0; i < code_kinds; i++)
		{
			fwrite(&huff_tree[i].uch, sizeof(unsigned char), 1, outfile);
			fwrite(&huff_tree[i].weight, sizeof(unsigned long), 1, outfile);
		}
		fwrite(&file_len, sizeof(unsigned long), 1, outfile);
		infile = fopen(ifilename, "rb");
		fread(&char_tmp, sizeof(unsigned char), 1, infile);
		code_buf = (unsigned char*)calloc(CHARNUM, sizeof(unsigned char));
		while (!feof(infile))
		{
			for (i = 0; i < code_kinds; i++)
			{
				if (huff_tree[i].uch == char_tmp)
				{
					strcat(code_buf, huff_tree[i].huff_code);
				}
			}
			while (strlen(code_buf) >= BIT)
			{
				char_tmp = '\0';
				for (i = 0; i < BIT; i++)
				{
					char_tmp <<= 1;
					if (code_buf[i])
					{
						char_tmp |= 1;
					}
				}
				fwrite(&char_tmp, sizeof(unsigned char), 1, outfile);
				strcpy(code_buf, code_buf + BIT);
			}
			fread(&char_tmp, sizeof(unsigned char), 1, infile);
		}
		buf_len = strlen(code_buf);
		if (buf_len > 0)
		{
			for (i = 0; i < buf_len; i++)
			{
				char_tmp = '\0';
				if (code_buf[i])
				{
					char_tmp |= 1;
				}
			}
			char_tmp <<= BIT - buf_len;
			fwrite(&char_tmp, sizeof(unsigned char), 1, outfile);
		}
		free(code_buf);
		fclose(outfile);
		fclose(infile);
		for (i = 0; i < node_num; i++)
		{
			free(huff_tree[i].huff_code);
		}
		free(huff_tree);
	}

	return 1;
}

void Test()
{
	Compress("C:\\Users\\10142\\Desktop\\1.txt", "C:\\Users\\10142\\Desktop\\2.txt");
	//Extract("C:\\Users\\10142\\Desktop\\2.txt", "C:\\Users\\10142\\Desktop\\3.txt");
}

int main()
{
	Test();

	return 0;
}