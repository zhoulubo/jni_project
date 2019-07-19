#define _CRT_SECURE_NO_WARNINGS

//#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include <io.h>
#include "other_head.h"

/* c执行流程
	预编译 将预先编写好的c代码插入到指定c代码
		为编译做好准备，进行代码替换 
		#include #define
		D:\Program Files\Microsoft Visual Studio 12.0\VC\include
		D:\Program Files\Microsoft Visual Studio 12.0\VC\crt\src

	位置
	编译 c代码生成目标代码 （obj）
	连接 将目标代码和c库进行连接合并，形成可执行文件
	运行
*/


// 宏定义没有类型区分，只是一个替换
// 定义一个宏标记
#define A //定义一个宏
#ifndef A
#endif
#ifdef A  // 如果定义就不再定义，防止重复定义
#endif
#pragma once // head文件只包含一次

// 定义一个常数
#define MAX 100

// 定义一个无参宏函数
#define jni(FORMAT) test_com_jni_##FORMAT();
// 定义一个带参数的宏函数(重载了一个函数)
#define jni(FORMAT,...) test_com_jni_##FORMAT(__VA_ARGS__);
// 定义一个带参数的宏函数,使用了默认的参数
#define jni_tag(FORMAT,...) test_com_jni_##FORMAT("withTag",__VA_ARGS__);
// 定义一个带参数的宏函数
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
	jni(get); // 调用 test_com_jni_get
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