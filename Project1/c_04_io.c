#define _CRT_SECURE_NO_WARNINGS

//#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include <io.h>


// io ����
// c�����ַ���д�Ͷ����ƶ�д������������� д�ı�ʱ \n�ᱻ�滻Ϊ \r\n�����ļ�ʱ \r\n���滻Ϊ\n 
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
	// �����ƶ�д
	while (len = fread(buffer, sizeof(int), 50, readFile)){
		fwrite(buffer, sizeof(int), len, writeFile);
	}
		
	fclose(readFile);
	fclose(writeFile);
	printf("������� \n");
}

// io ���� ʹ���ַ�������
// c�����ַ���д�Ͷ����ƶ�д������������� д�ı�ʱ \n�ᱻ�滻Ϊ \r\n�����ļ�ʱ \r\n���滻Ϊ\n 
void class42(){
	FILE * readFile = fopen("C:\\Users\\Administrator\\Desktop\\�ٶ�vip�˺�.txt", "rb");
	FILE * writeFile = fopen("C:\\Users\\Administrator\\Desktop\\�ٶ�vip�˺�_copy.txt", "wb");
	if (readFile == NULL
		|| writeFile == NULL){
		fprintf(stderr,
			"Cannot open output file.\n");
	}

	char ch;
	// ����д��д
	while (ch = fgetc(readFile) != EOF){
		fputc(ch/*^9,*/, writeFile);
	} 
	
	fclose(readFile);
	fclose(writeFile);
	printf("������� \n");
}


//��ȡ�ļ��Ĵ�С
// 1.�����ֽ���
// 2.ʹ��fseek�ض�λ���ļ�ĩβ������ó��ļ���С
void class43(){
	FILE * readFile = fopen("C:\\Users\\Administrator\\Desktop\\�ٶ�vip�˺�_copy.txt", "rb");
	
	long currentPos = ftell(readFile);
	// �ض�λreadFileָ����ָ��λ��
	fseek(readFile, 0, SEEK_END);
	// ���㵱ǰָ���ƫ��λ��
	long fielsize = ftell(readFile);
	// �ڼ������С�Ժ���Ҫ���»ָ�ָ��λ��
	fseek(readFile, currentPos, SEEK_SET);

	printf(" %d\n ", fielsize);

}

// �ļ��ָ�ϲ�
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