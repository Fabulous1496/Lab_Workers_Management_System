#pragma once
#include<iostream>
# include<string>
#include"Worker.h"
using namespace std;

class Employee :public Worker
{
public:
	//���캯��
	Employee(int ID,string name,int dID);
	//��ʾ������Ϣ
	virtual void showInfo();
	//��ȡ��λ����
	virtual string getDeptName();

};