#pragma once    //��ֹͷ�ļ��ظ�����
#include<iostream>
#include<fstream>
#include"Worker.h"
#include"Boss.h"
#include"Employee.h"
#include"Manager.h"
#define FILENAME "empFile.txt"
using namespace std;

class WorkerManager
{
public:
	//���캯��
	WorkerManager();
	//��������
	~WorkerManager();
	//��ʾ�˵�
	void Show_Meau();
	//�˳�ϵͳ
	void ExitSystem();
	//��¼ְ������
	int m_WorkerNum;
	//ְ������ָ��
	Worker** m_WorkerArray;
	//�������ְ��
	void AddWorker();
	//�����ļ�
	void Save();
	//�ж��ļ��Ƿ�Ϊ��
	bool isEmpty;
	//ͳ��ְ������
	int get_Num();
	//���ļ��г�ʼ��ְ���б�
	void initalize();
	//��ʾְ��
	void Show_Worker();
	//�ж�ְ���Ƿ����
	int isExist(int ID);
	//ɾ��ְ��
	void Delete_Worker();
	//�޸�ְ��
	void Change_Worker();
	//����Ա��
	void Find_Worker();
	//��������������
	void Sort_Worker();
	//����ļ�
	void CLEAN();
};
