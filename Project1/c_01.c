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

// �����ĳ��Ⱥ͸�ֵ����
int class2(){
	int i = 99;
	printf("int i %d ", i);
	int* p = &i;
	double d = 88.9;
	printf("double size: %d\n ", sizeof(d));
	printf("double d %lf ", d);

	// ��8�ֽ�double��ֵ��4�ֽڵ�intָ�룬�ض���
	*p = d;
	//  double d 88.900000 int *p 0x6ffd30 , 0.000000
	printf("int *p %#x , %lf \n  ",p, *p);

	// 1 NULL��Ӧ��ֵΪ0x 00000000
	*p = NULL;
	printf("ΪNULL ָ�� int *p %#x , %lf \n ", p, *p);

	return 0;

}


// �༶ָ��
int class3(){
	int a = 50;
	// һ��ָ����a�ĵ�ַ
	int *p = &a;
	// ����ָ�� ���һ��ָ��ĵ�ַ
	int** p2 = &p;
	// ��ȡ��a�е�ֵ
	printf("a %d , *p %d ,**p %d \n ", a, *p, **p2);
	// ���a�ĵ�ַ
	printf("&a %#x , p %#x ,*p %#x \n ", &a, p, *p2);

	return 0;
}

// ����Ĳ���
int class4(){
	double ids[] = { 1.2, 2.4, 3.6, 4.8, 6.0 };
	// &ids[0],ids,&ids ����ids��һ��Ԫ�صĵ�ַ
	printf("&ids %#x ids %#x \n ", &ids, ids);
	printf("&ids[0] %#x ids[0] %lf \n ", &ids[0], ids[0]);

	double *p = ids;
	printf("sizeof %d \n ", sizeof(double));
	// ÿ��ָ����ƶ�һ��sizeof(ids��װԪ������)�ľ��룬����һ��λ��
	for (; p < ids + 5; p++){
		printf("p %#x *p %lf \n ",p, *p);
	}

	return 0;
}

// ����֪ͨ
void msg(){
	MessageBox(0, "��Ϣ֪ͨ","����",0);
}

int minus(int a, int b){
	return a - b;
}

int add(int a, int b){
	return a + b;
}


// ����ָ��
void func_print(
	int(*minus)(int a, int b)
	, int(*add)(int a, int b)
	, int x
	, int y){
	printf("minus x= %d, y= %d minus = %d \n", x, y, minus(x, y));
	printf("add x= %d, y= %d add = %d", x, y, add(x, y));
}


// ����ָ��
int class5(){
	//msg();
	// ����˺����ĵ�ַ
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
	// ���������һϵ�����ݺͲ���
	printf("method msg %#x &msg %#x \n ", msg, &msg);
	// ��������ֵ ����ָ������ �����Ĳ����б�
	void(*fun_p)() = msg;
	//fun_p();
	func_print(minus, add, 5, 4);
	return 0;

}

// �ڴ���� 
// ��̬�ڴ���� �����ջ�У�ϵͳ���Զ�����
// ��̬�ڴ���� ����ڶ��У��ɳ���Ա����
void class6(){
	/*
	int len;
	printf("��������ĳ��� \n ");
	scanf("%d", &len);


	malloc(1024 * 1024 * sizeof(int));

	// ��̬���飬�����ջ��
	int arrary1[1024];

	// ʹ�ö�̬�ڴ����Ϊ����
	int*p = malloc(len * sizeof(int));
	// ֱ��ʹ��ָ�� i �������飬ָ��ÿ�λ��ƶ�һ��int��С��λ��
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
	// ʹ�� ָ��p �� [ ],��������
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
	//realloc ��������ʹ���ڶ�̬�����ϣ�ֻ�����ڶ�̬�����ָ����

	len2 = (sizeof(arrary) / sizeof(int));

	printf("before len = %d \n ", len2);

	int* p2 = realloc(p1, (len2 + 5)*sizeof(int));
	// realloc ������������ڴ�����
	// 1.�������������ռ���㣬��ֱ�����䣬��ǰ����ָ���ַΪԭ��ַ
	// 2.���������������ֱ�ռ�õ����������ҵ�һ��������е�λ�÷��䣬
	// ��ԭ���ݸ��Ƶ��µ���������ָ�뱣��Ϊ�µĵ�ַ
	// 3.���ϵͳ�������ڴ���䣬��᷵��NULL��ԭָ�뻹����Ч
	// 
	len2 = (sizeof(p1) / sizeof(int));
	printf("after len = %d \n ", len2);
	getchar();

}

/*
	
	�ڴ治�ܶ���ͷ�
	�ͷ�ʱ��������ΪNULL��Ϊ��־
	ָ�����¸�ֵǰҪ�ֶ��ͷţ�������������ڴ�й©
*/
int class62(void)
{
	//char str[] = calloc(4,sizeof(char));
	char *str = malloc(4*sizeof(char));
	int index=0;
	for (; index < 4; index++){
		str[index] = index + 'a'/*97*/; // ��ֵ abcd
	}

	printf("str[0] is %c \n  Address is %#x \n", str[0], str);
	// ���䵽�ĵ�ַ��strָ��
	str = realloc(str, 20);
	printf("str[0] is %c \n  New address is %#x \n",str[0], str);

	/* free memory */
	//���ܶ���ͷ�
	if (str != NULL){
		free(str);
		str = NULL;
	}
	int *p = malloc(1024 * 1024 * 100 * sizeof(int));
	// ���¸�ֵǰҪ�ֶ��ͷ�
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





































