#define _CRT_SECURE_NO_WARNINGS

#define GET_ARRAY_LENGTH(array,len){len=(sizeof(array)/sizeof(array[0]));}


//#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

/*
int _tmain(int argc, _TCHAR* argv[])
{
return 2 ;
}

*/





int change1(int b){
	b = 2;
	return 1;
}


int change2(int* b){
	*b = 3;
	return 1;
}

// 变量的长度和赋值操作
int class2(){
	int i = 99;
	printf("int i %d ", i);
	int* p = &i;
	double d = 88.9;
	printf("double size: %d\n ", sizeof(d));
	printf("double d %lf ", d);

	// 将8字节double赋值给4字节的int指针，截断了
	*p = d;
	//  double d 88.900000 int *p 0x6ffd30 , 0.000000
	printf("int *p %#x , %lf \n  ",p, *p);

	// 1 NULL对应的值为0x 00000000
	*p = NULL;
	printf("为NULL 指针 int *p %#x , %lf \n ", p, *p);

	return 0;

}


// 多级指针
int class3(){
	int a = 50;
	// 一级指针存放a的地址
	int *p = &a;
	// 二级指针 存放一级指针的地址
	int** p2 = &p;
	// 获取到a中的值
	printf("a %d , *p %d ,**p %d \n ", a, *p, **p2);
	// 存放a的地址
	printf("&a %#x , p %#x ,*p %#x \n ", &a, p, *p2);

	return 0;
}

// 数组的操作
int class4(){
	double ids[] = { 1.2, 2.4, 3.6, 4.8, 6.0 };
	// &ids[0],ids,&ids 都是ids第一个元素的地址
	printf("&ids %#x ids %#x \n ", &ids, ids);
	printf("&ids[0] %#x ids[0] %lf \n ", &ids[0], ids[0]);

	double *p = ids;
	printf("sizeof %d \n ", sizeof(double));
	// 每次指针会移动一个sizeof(ids所装元素类型)的距离，到下一个位置
	for (; p < ids + 5; p++){
		printf("p %#x *p %lf \n ",p, *p);
	}

	return 0;
}

// 弹出通知
void msg(){
	MessageBox(0, "消息通知","标题",0);
}

int minus(int a, int b){
	return a - b;
}

int add(int a, int b){
	return a + b;
}


// 函数指针
void func_print(
	int(*minus)(int a, int b)
	, int(*add)(int a, int b)
	, int x
	, int y){
	printf("minus x= %d, y= %d minus = %d \n", x, y, minus(x, y));
	printf("add x= %d, y= %d add = %d", x, y, add(x, y));
}


// 函数指针
int class5(){
	//msg();
	// 输出了函数的地址
	// _msg:
	// 01011131  jmp         msg(010119A0h)
	// 010119A0h
	// 010119A0  push        ebp  
	// 010119A1  mov         ebp, esp
	//	010119A3  sub         esp, 0C0h
	//	010119A9  push        ebx
	//	010119AA  push        esi
	//	010119AB  push        edi
	//	010119AC  lea         edi, [ebp - 0C0h
	// 程序包含了一系列数据和操作
	printf("method msg %#x &msg %#x \n ", msg, &msg);
	// 函数返回值 函数指针名称 函数的参数列表
	void(*fun_p)() = msg;
	//fun_p();
	func_print(minus, add, 5, 4);
	return 0;

}

// 内存分配 
// 静态内存分配 存放在栈中，系统会自动回收
// 动态内存分配 存放在堆中，由程序员回收
void class6(){
	/*
	int len;
	printf("输入数组的长度 \n ");
	scanf("%d", &len);


	malloc(1024 * 1024 * sizeof(int));

	// 静态数组，存放在栈中
	int arrary1[1024];

	// 使用动态内存分配为数组
	int*p = malloc(len * sizeof(int));
	// 直接使用指针 i 访问数组，指针每次会移动一个int大小的位置
	/*0x32b6660 : 2
	  0x32b6664 : 2
	  0x32b6668 : 2
	  0x32b666c : 2
	*/

	/*
	int*i = p;
	for (; i < p + len; i++){
		*i = 2;
		printf(" %#x : %d \n ", i, *i);
	}
	// 使用 指针p 和 [ ],访问数组
	int index = 0;
	for (; index < len; index++){
		p[index] = 3;
		printf(" %#x : %d \n ", &p[index], p[index]);
	
	}
	
	GET_ARRAY_LENGTH(arrary, len2);

	//  5241356
	// 15726556
	//printf("sizeof(arrary)  %d \n ",len2);

	*/

	int len2;
	int arrary[] = { 1, 23 };
	int* p1 = arrary;
	//realloc 函数不能使用在定态数组上，只能用在动态数组和指针上

	len2 = (sizeof(arrary) / sizeof(int));

	printf("before len = %d \n ", len2);

	int* p2 = realloc(p1, (len2 + 5)*sizeof(int));
	// realloc 会分配连续的内存区域
	// 1.如果新增的区域空间充足，则直接扩充，当前数组指针地址为原地址
	// 2.如果新增的区域出现被占用的情况，则会找到一个整体空闲的位置分配，
	// 将原数据复制到新的区域，数组指针保存为新的地址
	// 3.如果系统不满足内存分配，则会返回NULL，原指针还是有效
	// 
	len2 = (sizeof(p1) / sizeof(int));
	printf("after len = %d \n ", len2);
	getchar();

}

/*
	
	内存不能多次释放
	释放时将变量置为NULL作为标志
	指针重新赋值前要手动释放，否则容易造成内存泄漏
*/
int class62(void)
{
	//char str[] = calloc(4,sizeof(char));
	char *str = malloc(4*sizeof(char));
	int index=0;
	for (; index < 4; index++){
		str[index] = index + 'a'/*97*/; // 赋值 abcd
	}

	printf("str[0] is %c \n  Address is %#x \n", str[0], str);
	// 分配到的地址给str指针
	str = realloc(str, 20);
	printf("str[0] is %c \n  New address is %#x \n",str[0], str);

	/* free memory */
	//不能多次释放
	if (str != NULL){
		free(str);
		str = NULL;
	}
	int *p = malloc(1024 * 1024 * 100 * sizeof(int));
	// 重新赋值前要手动释放
	free(p);
	p = malloc(1024 * 1024 * 50 * sizeof(int));
	free(p);
	return 0;
}



//int main() {
	//	int b = 1;
	//	printf("change1 b %#x ", &b); // 0x93f7d8
	//	printf("change1 b %d ", b);
	//	change1(b);
	//	printf("change1 b %d", b);

	//	printf("change2 b %d", b);
	//	change2(&b);
	//	printf("change2 b %d ", b);
	//	system("pause");
	//	class2();
	//	class3();
	//	class4();
	//	class5();
//	class62();
//	getchar();
//	return 0;
//}





































