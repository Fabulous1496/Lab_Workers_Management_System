#include<iostream>
#include<string>
#include<fstream>
#include"workerManager.h"
#include"Employee.h"
#include"Manager.h"
#include"Boss.h"
using namespace std;


int main()
{
	WorkerManager wm;
	int choice = 0;
	while (1)
	{
		wm.Show_Meau();
		cout << "��ѡ���ܣ�" << endl;
		cin >> choice;
		switch (choice)
		{
		case 0:     //�˳�ϵͳ
			wm.ExitSystem();
			break;
		case 1:     //����ְ��
			wm.AddWorker();
			break;
		case 2:		//��ʾְ��
			wm.Show_Worker();
			break;
		case 3:		//ɾ��Ա��
			wm.Delete_Worker();
			break;
		case 4:		//�޸�ְ��
			wm.Change_Worker();
			break;
		case 5:		//����ְ��
			wm.Find_Worker();
			break;
		case 6:		//����ְ��
			wm.Sort_Worker();
			break;
		case 7:		//�������
			wm.CLEAN();
			break;
		default:
			system("cls");
			break;
		}
	}
	
	system("pause");
	return 0;
}