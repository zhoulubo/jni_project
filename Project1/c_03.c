#define _CRT_SECURE_NO_WARNINGS

//#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>

struct InnerStruct{
	int innerId;
}innerStruct;


// �ṹ��Ĵ�С�е��ֽڶ���
// Ϊ���������͵��������������������Ͷ���

//��struct MyStruct ����Ϊ MyStruct
typedef struct MyStruct MyStruct;

// �ṹ��ָ�����
typedef MyStruct* MyStructP;

struct MyStruct{
	int id;
	char* passWord;
	char name[20];
	struct InnerStruct inner;

}mySturct; //ֱ�Ӷ�����һ������ΪmyStruct


// �����ṹ�壬ֻ������ʼ�ı���
struct{
	char* name;
}anoymity;

// �ṹ��
void class31(){
	// ʹ�ýṹ�������ʡȥ�� struct �ؼ�����д
	MyStruct s = { 123 };
	printf("syStruct s.id = %d \n ", s.id);

	MyStructP myStructP = &s;
	printf("myStructP myStructP->id = %d \n ", myStructP->id);
	mySturct.id = 123;
	// mySturct.name = "123";
	strcpy(mySturct.name, "hello");
	mySturct.passWord = "123";
	mySturct.inner.innerId = 321;

	// �ṹ��ĳ�ʼ����ֵ
	struct MyStruct mySturct2 = { 123, "mySturct2_passWord", "mySturct2_name", {111} };
	
	// structָ��
	struct MyStruct *p = &mySturct;
	p = &mySturct2;
	
	// ʹ�ýṹ�� p->�ķ�ʽ���ʽṹ�壬Ϊ *p. �ļ�д 
	printf("syStruct : mySturct.name %s \n , mySturct.passWord %s \n , mySturct.inner.innerId %d "
		, p->name
		, (*p).passWord
		, (*p).inner.innerId);

}





// �����壨�����壩��ͬ������ͬռ����ͬ�Ĵ洢�����򣬽�ʡ�ڴ�
union MyUnion{
	int unionInt;
	float unionFloat;
	double uniondouble;
	struct MyStruct struct2;
};

typedef union MyUnion UnionValue;

// ö������ ��һ���������洢��
enum MyEnum{
	one =1,
	two,
	three,
	four
};


void class32(){
	//UnionValue unionValue = 
	printf("one %d two %d three %d ", one, two, three, four);
}



/*
int main(){
	//class31();
	class32();
	getchar();
	return 0;

}
*/