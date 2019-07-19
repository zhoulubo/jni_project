#define _CRT_SECURE_NO_WARNINGS

//#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>


// 字符串声明和赋值方式
void class1(){ 
	printf("say hello \n");
	// 加 '\0' 表示字符串结尾
	// 字符数组赋初值以后无法再次赋初值
	// 字符数组表示的字符串可以被修改
	// 字符数组表示字符串
	char chars[] = { 'h','e', 'l', 'l', 'o','\0'};
	// 双引号表示
	char str[] = "haha";
	// 字符串指针定义的字符串无法修改
	char *strp = "how are you";
	printf("%d" ,'\0');
	while (*strp){
		printf("%d %c , ", *strp,*strp);
		strp++;
	}

	printf("\n 结束");

	printf(" chars %#x : %s \n str %#x : %s \n strp %#x : %s "
		, &chars, chars
		, &str, str
		, &strp, strp);

}


// 匹配字符在字符串中的位置
void class22(){
	char str[] = "this is my computer";
	//char *str = "this is my computer";
	char *str_p = str;
	char *c = "m";

	int findIndex = 0;
	// 使用 strstr(char* str1,char* str2)参数都是字符指针
	str_p = strstr(str, c);
	if (*str_p){
		findIndex = str_p - str;
	}
	printf("find %c in :\n %s \n strstr index : %d \n", *c, str, findIndex);

	while (*str_p){
		if (*str_p == c){
			break;
		}
		str_p++;
	}

	if (*str_p){
		findIndex = str_p - str;
	}

	printf("find %s in :\n %s \n index : %d \n", c, str, findIndex);

}

/*
int main(){

	
	class22();
	getchar();
	return 0;
}
*/