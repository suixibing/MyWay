class Solution {
public:
	void replaceSpace(char *str,int length)
    {
        char *start = new char[length];
        strcpy(start, str);
        for (char *tmp = start; *tmp; ++tmp, ++str)
        {
            if (*tmp == ' ')
            {
                *str++ = '%';
                *str++ = '2';
                *str = '0';
            }
            else
                *str = *tmp;
        }
        *str = '\0';
        delete[] start;
	}
};