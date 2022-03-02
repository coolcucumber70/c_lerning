#include <stdio.h>
main()
{
	char  ch;
	printf("Press a key and then press Enter:");	
	ch = getchar(); 
	ch = ch + 32;   
	printf("%c, %d\n", ch, ch); /* 分别输出变量ch中的字符及其ASCII码值 */
}
