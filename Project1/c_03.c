#define _CRT_SECURE_NO_WARNINGS

//#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>

struct InnerStruct{
	int innerId;
}innerStruct;


// 结构体的大小中的字节对齐
// 为最大基本类型的整数倍，按最大基本类型对齐

//将struct MyStruct 别名为 MyStruct
typedef struct MyStruct MyStruct;

// 结构体指针别名
typedef MyStruct* MyStructP;

struct MyStruct{
	int id;
	char* passWord;
	char name[20];
	struct InnerStruct inner;

}mySturct; //直接定义了一个变量为myStruct


// 匿名结构体，只包含初始的变量
struct{
	char* name;
}anoymity;

// 结构体
void class31(){
	// 使用结构体别名，省去了 struct 关键的书写
	MyStruct s = { 123 };
	printf("syStruct s.id = %d \n ", s.id);

	MyStructP myStructP = &s;
	printf("myStructP myStructP->id = %d \n ", myStructP->id);
	mySturct.id = 123;
	// mySturct.name = "123";
	strcpy(mySturct.name, "hello");
	mySturct.passWord = "123";
	mySturct.inner.innerId = 321;

	// 结构体的初始化赋值
	struct MyStruct mySturct2 = { 123, "mySturct2_passWord", "mySturct2_name", {111} };
	
	// struct指针
	struct MyStruct *p = &mySturct;
	p = &mySturct2;
	
	// 使用结构体 p->的方式访问结构体，为 *p. 的简写 
	printf("syStruct : mySturct.name %s \n , mySturct.passWord %s \n , mySturct.inner.innerId %d "
		, p->name
		, (*p).passWord
		, (*p).inner.innerId);

}





// 联合体（共用体）不同变量共同占用相同的存储器区域，节省内存
union MyUnion{
	int unionInt;
	float unionFloat;
	double uniondouble;
	struct MyStruct struct2;
};

typedef union MyUnion UnionValue;

// 枚举类型 不一定是连续存储的
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