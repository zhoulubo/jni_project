#define _CRT_SECURE_NO_WARNINGS

//#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>


// �ַ��������͸�ֵ��ʽ
void class1(){ 
	printf("say hello \n");
	// �� '\0' ��ʾ�ַ�����β
	// �ַ����鸳��ֵ�Ժ��޷��ٴθ���ֵ
	// �ַ������ʾ���ַ������Ա��޸�
	// �ַ������ʾ�ַ���
	char chars[] = { 'h','e', 'l', 'l', 'o','\0'};
	// ˫���ű�ʾ
	char str[] = "haha";
	// �ַ���ָ�붨����ַ����޷��޸�
	char *strp = "how are you";
	printf("%d" ,'\0');
	while (*strp){
		printf("%d %c , ", *strp,*strp);
		strp++;
	}

	printf("\n ����");

	printf(" chars %#x : %s \n str %#x : %s \n strp %#x : %s "
		, &chars, chars
		, &str, str
		, &strp, strp);

}


// ƥ���ַ����ַ����е�λ��
void class22(){
	char str[] = "this is my computer";
	//char *str = "this is my computer";
	char *str_p = str;
	char *c = "m";

	int findIndex = 0;
	// ʹ�� strstr(char* str1,char* str2)���������ַ�ָ��
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