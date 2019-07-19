#define _CRT_SECURE_NO_WARNINGS

//#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include <io.h>


// io 操作
// c语言字符读写和二进制读写的区别仅仅在于 写文本时 \n会被替换为 \r\n，读文件时 \r\n被替换为\n 
void class41(){
	FILE * readFile = fopen("C:\\Users\\Administrator\\Desktop\\MultiFunctionAndroidDemo-master.zip", "rb");
	FILE * writeFile = fopen("C:\\Users\\Administrator\\Desktop\\MultiFunctionAndroidDemo-master_2.zip", "wb");
	if (readFile == NULL
		|| writeFile == NULL){
		fprintf(stderr,
			"Cannot open output file.\n");
	}

	int buffer[50];
	int len;
	// 二进制读写
	while (len = fread(buffer, sizeof(int), 50, readFile)){
		fwrite(buffer, sizeof(int), len, writeFile);
	}
		
	fclose(readFile);
	fclose(writeFile);
	printf("复制完成 \n");
}

// io 操作 使用字符流操作
// c语言字符读写和二进制读写的区别仅仅在于 写文本时 \n会被替换为 \r\n，读文件时 \r\n被替换为\n 
void class42(){
	FILE * readFile = fopen("C:\\Users\\Administrator\\Desktop\\百度vip账号.txt", "rb");
	FILE * writeFile = fopen("C:\\Users\\Administrator\\Desktop\\百度vip账号_copy.txt", "wb");
	if (readFile == NULL
		|| writeFile == NULL){
		fprintf(stderr,
			"Cannot open output file.\n");
	}

	char ch;
	// 流读写读写
	while (ch = fgetc(readFile) != EOF){
		fputc(ch/*^9,*/, writeFile);
	} 
	
	fclose(readFile);
	fclose(writeFile);
	printf("复制完成 \n");
}


//获取文件的大小
// 1.遍历字节数
// 2.使用fseek重定位到文件末尾，计算得出文件大小
void class43(){
	FILE * readFile = fopen("C:\\Users\\Administrator\\Desktop\\百度vip账号_copy.txt", "rb");
	
	long currentPos = ftell(readFile);
	// 重定位readFile指针所指的位置
	fseek(readFile, 0, SEEK_END);
	// 计算当前指针的偏移位置
	long fielsize = ftell(readFile);
	// 在计算完大小以后需要重新恢复指针位置
	fseek(readFile, currentPos, SEEK_SET);

	printf(" %d\n ", fielsize);

}

// 文件分割合并
void class44(){ 


}

/*
int main(){
	//class41();
	class42();
	//class43();
	getchar();
	return 0;

	}*/