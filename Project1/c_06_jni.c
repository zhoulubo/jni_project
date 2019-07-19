#define _CRT_SECURE_NO_WARNINGS


#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include <io.h>
#include "jni_test_JniTestEntry.h"

char* chars = "string from c";

// 函数实现
// .a为静态库
// .dll
// JNIEnv是一个二级指针
// 
// 使用 javap -s xxx.class 可以获取到java class中所有方法对应的 signature


// 这个生成的是静态的方法
// 访问静态变量
JNIEXPORT jstring JNICALL Java_jni_1test_JniTestEntry_getStringFromC(JNIEnv *env, jclass jclass){

	char* field_name = "staticField";

	jfieldID staticFieldId = (*env)->GetStaticFieldID(env, jclass, field_name, "Ljava/lang/String;");
	if (staticFieldId != NULL){
		printf("staticFieldId is not null \n");
	}
	else{
		printf("staticFieldId is null \n");
	}

	jstring java_jstr = (*env)->GetStaticObjectField(env, jclass, staticFieldId);

	printf("call java Field strField value : %s ", java_jstr);
	// 获取UTF字符串
	char* java_jstr_char = (*env)->GetStringUTFChars(env, java_jstr, NULL);
		
	// 改变值并赋值到java静态变量
	strcat(java_jstr_char,"_c_strcat_static");
	// 转换为jstring
	jstring jstr = (*env)->NewStringUTF(env, java_jstr_char);

	//(*env)->ReleaseStringUTFChars(env, java_jstr, java_jstr_char);

	// 设置到java中
	(*env)->SetStaticObjectField(env, jclass, staticFieldId, jstr);

	// 访问一下静态java方法
	jmethodID methotdId = (*env)->GetStaticMethodID(env, jclass, "javaStaticPrintMethod", "(Ljava/lang/String;)V");

	if (methotdId != NULL){
		printf("javaStaticPrintMethod methotdId is not null \n");
	}
	else{
		printf("javaStaticPrintMethod methotdId is null \n");
	}

	jstring jmsg = (*env)->NewStringUTF(env, "from c arg");
	(*env)->CallStaticVoidMethod(env, jclass, methotdId, jmsg);


	return (*env)->NewStringUTF(env, chars);
};


// 访问java非静态变量,并赋值非静态变量
JNIEXPORT jstring JNICALL Java_jni_1test_JniTestEntry_nativeMethodAccessJavaField(JNIEnv *env, jobject jobj){

	char* field_name = "strField";
	jclass clazz = (*env)->GetObjectClass(env,jobj);

	jfieldID fieldID = (*env)->GetFieldID(env, clazz, field_name, "Ljava/lang/String;");

	if (fieldID!=NULL){
		printf("fieldID is not null \n");
	}else{
		printf("fieldID is null \n");
	}

	jstring java_str;
	java_str = (*env)->GetObjectField(env, jobj, fieldID);
	
	char * java_str_chars = (*env)->GetStringUTFChars(env,java_str,NULL);
	strcat(java_str_chars, "_c_strcat_no_static");
	
	jstring jstr = (*env)->NewStringUTF(env, java_str_chars);
	// 设置非静态变量
	(*env)->SetObjectField(env, jobj, fieldID, jstr);

	printf("call java Field strField value : %s ", java_str);
	// 访问一下非静态java方法
	jmethodID methotdId = (*env)->GetMethodID(env, clazz, "javaPrintMethod", "(Ljava/lang/String;)V");


	if (methotdId != NULL){
		printf("javaPrintMethod methotdId is not null \n");
	}
	else{
		printf("javaPrintMethod methotdId is null \n");
	}

	jstring jmsg = (*env)->NewStringUTF(env, "from c arg");
	(*env)->CallVoidMethod(env, jobj, methotdId, jmsg);


	return jstr;
}








// jni
void class61(){


}

/*
void main(){

	class61();
	getchar();

}
*/



