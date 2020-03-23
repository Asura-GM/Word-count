#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int charCount(char* filePath){//�����ļ��ַ��� 
	FILE* fp;
	fp = fopen(filePath,"r");	
	int n = 0;
	char ch;
	if(fp == NULL)
	{
		printf("cannot find file!\n");
		return -1;
	}else{
		do{
			ch = fgetc(fp);
			if(ch>=0 && ch<=127){	/*����ch!=NULL���ֲ�֪�����ɵĶ�ȡtxt�ĵ� n ���1,��ȡcpp�ĵ���2 
							��������ֹ��ʶ������ȡ��һ��������ASCII��ʱ����ȡtxt�ĵ���������ȡcpp�ĵ���1	*/
				n++;	
			}
		}while(ch != EOF);
		fclose(fp);
	}
	return n;
}

int wordCount(char* filePath) {//�����ļ��Ĵʵ���Ŀ 
	FILE* file;
	file =  fopen(filePath,"r");
	int n = 0 ;
	printf("%s",file);
	char ch;
	if(file == NULL)
	{
		printf("cannot find file!\n");
		return -1 ;
	}else{
		do{
			ch = fgetc(file);
			if(ch=='\n' || ch==' '){
				n++;	
			}
		}while(ch != EOF);
		fclose(file);
	}
	return ++n;
}

int lineCount(char* filePath) {//�����ļ������� 
	FILE* file ;
	file = fopen(filePath,"r");
	int n = 0;
	char ch;
	if(file == NULL)
	{
		printf("cannot find file!\n");
		return -1;
	}else{
		do{
			ch = fgetc(file);
			if(ch=='\n'){
				n++;	
			}
		}while(ch != EOF);
		fclose(file);
	}
	return ++n;
}

int operateFILE(char* filePath, char cmd) {
    int count = 0;
    switch (cmd) {
    case 'c':
        count = charCount(filePath);
        break;
    case 'l':
        count = lineCount(filePath);
        break;
    case 'w':
        count = wordCount(filePath);
        break;
    default:
        break;
    }
    return count;
}

bool isCharCmd(char c) {
    return (c == 'c' || c == 'l' || c == 'w');
}

int main(int argc, char* argv[]) {
    char* path;
    //��������ʽ��ȷ���
    if (argc == 3 && argv[1][0]== '-' && isCharCmd(argv[1][1])) {
		int count = operateFILE(argv[2], argv[1][1]);
        switch (argv[1][1]) {
        case 'c':
            printf("charCount=%d",count);
            break;
        case 'w':
            printf("wordCount=%d",count);
            break;
        case 'l':
            printf("lineCount=%d",count);
            break;
        default:
            break;
        }
    }
    else {
        printf("wrong");
       return 0;
    }
}
