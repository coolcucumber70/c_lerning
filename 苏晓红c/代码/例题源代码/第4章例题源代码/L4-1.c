#include <stdio.h>
main()
{
	char  ch;
	printf("Press a key and then press Enter:");	
	ch = getchar(); /* �Ӽ�������һ���ַ�,���س�����������,���ַ����������ch */
	ch = ch + 32;   /* ����дӢ����ĸת��ΪСдӢ����ĸ */
	putchar(ch);    /* ����Ļ����ʾ����ch�е��ַ� */
	putchar('\n');  /* ���һ���س����п��Ʒ� */
}
