#include<stdio.h>
#include<string.h>
void test(){

	//写文件
	FILE* fp_write= NULL;
	//写方式打开文件
    int i;
	fp_write = fopen("./mydata.txt", "w+");
	if (fp_write == NULL){
		return;
	}

	char buf[] = "this is a test for pfutc!";
	for (i = 0; i < strlen(buf);i++){
		fputc(buf[i], fp_write);
	}
	
	fclose(fp_write);

	//读文件
	FILE* fp_read = NULL;
	fp_read = fopen("./mydata.txt", "r");
	if (fp_read == NULL){
		return;
	}

#if 0
	//判断文件结尾 注意：多输出一个空格
	while (!feof(fp_read)){
		printf("%c",fgetc(fp_read));
	}
#else
	char ch;
	while ((ch = fgetc(fp_read)) != EOF){
		printf("%c", ch);
	}
#endif
}
void test1(){

	int i;
    //写文件
	FILE* fp_write= NULL;
	//写方式打开文件
	fp_write = fopen("./mydata.txt", "w+");
	if (fp_write == NULL){
		perror("fopen:");
		return;
	}
    char* buf[] = {
		"01 this is a test for pfutc!\n",
		"02 this is a test for pfutc!\n",
		"03 this is a test for pfutc!\n",
		"04 this is a test for pfutc!\n",
	};
	for ( i = 0; i < 4; i ++){
		fputs(buf[i], fp_write);
	}
	
	fclose(fp_write);

	//读文件
	FILE* fp_read = NULL;
	fp_read = fopen("./mydata.txt", "r");
	if (fp_read == NULL){
		perror("fopen:");
		return;
	}

	//判断文件结尾
	while (!feof(fp_read)){
		char temp[1024] = { 0 };
		fgets(temp, 1024, fp_read);
		printf("%s",temp);
	}

	fclose(fp_read);
}


int main(){
    //test();
    test1();
}
