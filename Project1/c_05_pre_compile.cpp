#define _CRT_SECURE_NO_WARNINGS

//#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include <io.h>
#include "other_head.h"

/* cִ������
	Ԥ���� ��Ԥ�ȱ�д�õ�c������뵽ָ��c����
		Ϊ��������׼�������д����滻 
		#include #define
		D:\Program Files\Microsoft Visual Studio 12.0\VC\include
		D:\Program Files\Microsoft Visual Studio 12.0\VC\crt\src

	λ��
	���� c��������Ŀ����� ��obj��
	���� ��Ŀ������c��������Ӻϲ����γɿ�ִ���ļ�
	����
*/


// �궨��û���������֣�ֻ��һ���滻
// ����һ������
#define A //����һ����
#ifndef A
#endif
#ifdef A  // �������Ͳ��ٶ��壬��ֹ�ظ�����
#endif
#pragma once // head�ļ�ֻ����һ��

// ����һ������
#define MAX 100

// ����һ���޲κ꺯��
#define jni(FORMAT) test_com_jni_##FORMAT();
// ����һ���������ĺ꺯��(������һ������)
#define jni(FORMAT,...) test_com_jni_##FORMAT(__VA_ARGS__);
// ����һ���������ĺ꺯��,ʹ����Ĭ�ϵĲ���
#define jni_tag(FORMAT,...) test_com_jni_##FORMAT("withTag",__VA_ARGS__);
// ����һ���������ĺ꺯��
#define printArgs(FORMAT,...) test_com_jni_args_##FORMAT(__VA_ARGS__);

void test_com_jni_get(){
	printf("test_com_jni_get1 \n");
}

void test_com_jni_get(char chrs[]){
	printf("test_com_jni_get2 %s \n", chrs);
}

void test_com_jni_get(char tag[],char chrs[]){
	printf("test_com_jni_get %s : %s \n", tag,chrs);
}

void test_com_jni_args_get(char chrs[]){
	printf("test_com_jni_args_get %s",chrs);
}

void class51(){
	//#include "class_head.h";
	//printOther();
	jni(get); // ���� test_com_jni_get
	jni(get,"second");
	jni_tag(get,"log");
	printArgs(get, "have nice day !");
}

void printOther(){
	printf("printOther");
}


/*
int main(){
	class51();
	getchar();
}
*/