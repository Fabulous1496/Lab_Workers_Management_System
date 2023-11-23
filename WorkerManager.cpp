#include"workerManager.h"

WorkerManager::WorkerManager()
{
	//�ļ�������
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	if (!ifs.is_open())
	{
		this->m_WorkerNum = 0;
		this->m_WorkerArray = NULL;
		this->isEmpty = true;
		ifs.close();
		return;
	}
	//�ļ�Ϊ��
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		this->m_WorkerNum = 0;
		this->m_WorkerArray = NULL;
		this->isEmpty = true;
		ifs.close();
		return;
	}
	//��ȡ�����ļ�
	int num = this->get_Num();
	this->m_WorkerNum = num;
	this->m_WorkerArray = new Worker * [this->m_WorkerNum];
	this->initalize();
}

void WorkerManager::Show_Meau()
{
	cout << "-------------------------------------\n";
	cout << "-------------------------------------\n";
	cout << "--------��ӭʹ��ְ������ϵͳ��-------\n";
	cout << "------------0.�˳�����ϵͳ-----------\n";
	cout << "------------1.���ְ����Ϣ-----------\n";
	cout << "------------2.��ʾְ����Ϣ-----------\n";
	cout << "------------3.ɾ����ְְ��-----------\n";
	cout << "------------4.�޸�ְ����Ϣ-----------\n";
	cout << "------------5.����ְ����Ϣ-----------\n";
	cout << "------------6.���չ�������-----------\n";
	cout << "------------7.��������ĵ�-----------\n";
	cout << "-------------------------------------\n";
	cout << "-------------------------------------\n";
	cout << endl;
}

WorkerManager::~WorkerManager()
{
	if (this->m_WorkerArray != NULL)
	{
		for (int i = 0; i < this->m_WorkerNum; i++)
		{
			if (this->m_WorkerArray[i] != NULL)
			{
				delete this->m_WorkerArray[i];
				this->m_WorkerArray[i] = NULL;
			}
		}
		delete[]this->m_WorkerArray;
		this->m_WorkerArray = NULL;
	}
}

void WorkerManager::ExitSystem()
{
	cout << "��ӭ�´�ʹ�ã�" << endl;
	system("pause");
	exit(0);
}

void WorkerManager::AddWorker()
{
	cout << "���������������" << endl;
	int AddNum = 0;
	cin >> AddNum;
	if (AddNum > 0)
	{
		//�����¿ռ��С
		int newSize = this->m_WorkerNum + AddNum;
		//�����¿ռ�
		Worker** newspace = new Worker * [newSize];
		//��ԭ�����鿽��
		if (this->m_WorkerArray != NULL)
		{
			for (int i = 0; i < this->m_WorkerNum; i++)
			{
				newspace[i] = this->m_WorkerArray[i];
			}
		}
		//�������
		for (int i = 0; i < AddNum; i++)
		{
			int id;
			string name;
			int Dselect;
			cout << "�������" << i + 1 << "����ְ����ţ� " << endl;
			cin >> id;
			cout << "�������" << i + 1 << "����ְ�������� " << endl;
			cin >> name;
			cout << "�������" << i + 1 << "����ְ����λ�� " << endl;
			cout << "1.��ְͨ��\n" << "2.����\n" << "3.�ϰ�\n";
			cin >> Dselect;

			Worker* worker = NULL;
			switch (Dselect)
			{
			case 1:
				worker = new Employee(id, name, 1);
				break;
			case 2:
				worker = new Manager(id, name, 2);
				break;
			case 3:
				worker = new Boss(id, name, 3);
				break;
			default:
				break;
			}

			newspace[this->m_WorkerNum + i] = worker;
		}
		delete[] this->m_WorkerArray;
		this->m_WorkerArray = newspace;
		this->m_WorkerNum = newSize;
		cout << "��ӳɹ���" << endl;
		this->Save();
		this->isEmpty = false;
	}
	else
	{
		cout << "��������"<< endl;
	}
	system("pause");
	system("cls");
}

void WorkerManager::Save()
{
	ofstream ofs;
	ofs.open(FILENAME, ios::out);
	for (int i = 0; i < this->m_WorkerNum; i++)
	{
		ofs << this->m_WorkerArray[i]->m_ID << " "
			<< this->m_WorkerArray[i]->m_Name << " "
			<< this->m_WorkerArray[i]->m_DeptID << endl;
	}
	ofs.close();
}

int WorkerManager::get_Num()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int ID;
	string name;
	int dID;
	int num = 0;
	while (ifs >> ID && ifs >> name && ifs >> dID)
	{
		num++;
	}
	ifs.close();
	return num;
}

void WorkerManager::initalize()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	int ID;
	string name;
	int dID;
	int index = 0;
	while (ifs >> ID && ifs >> name && ifs >> dID)
	{
		Worker* worker = NULL;
		if (dID == 1)
		{
			worker = new Employee(ID, name, dID);
		}
		if (dID == 2)
		{
			worker = new Manager(ID, name, dID);
		}
		if (dID == 3)
		{
			worker = new Boss(ID, name, dID);
		}
		this->m_WorkerArray[index] = worker;
		index++;
	}
}

void WorkerManager::Show_Worker()
{
	if (this->isEmpty)
	{
		cout << "�б�Ϊ�գ�" << endl;
		return;
	}
	else
	{
		for (int i = 0; i < this->m_WorkerNum; i++)
		{
			this->m_WorkerArray[i]->showInfo();
		}
	}
	system("pause");
	system("cls");
}

int WorkerManager::isExist(int ID)
{
	int index = -1;
	for (int i = 0; i < this->m_WorkerNum; i++)
	{
		if (this->m_WorkerArray[i]->m_ID == ID)
		{
			index = i;
			break;
		}
	}
	return index;
}

void WorkerManager::Delete_Worker()
{
	if (this->isEmpty)
	{
		cout << "�б�Ϊ�գ�" << endl;
	}
	else
	{
		cout << "�����빤�ţ�" << endl;
		int ID;
		cin >> ID;
		if (this->isExist(ID) != -1)
		{
			for (int i = this->isExist(ID); i < this->m_WorkerNum - 1; i++)
			{
				this->m_WorkerArray[i] = this->m_WorkerArray[i + 1];
			}
			this->m_WorkerNum--;
			this->Save();
			cout << "ɾ���ɹ���" << endl;
		}
		else
		{
			cout << "δ����ˣ�" << endl;
		}
	}
	system("pause");
	system("cls");
}

void WorkerManager::Change_Worker()
{
	if (this->isEmpty)
	{
		cout << "�б�Ϊ�գ�" << endl;
	}
	else
	{
		cout << "�����빤��" << endl;
		int ID;
		cin >> ID;
		if (this->isExist(ID) != -1)
		{
			int index = this->isExist(ID);
			cout << "ƥ��ɹ��� " << endl;
			this->m_WorkerArray[index]->showInfo();
			delete this->m_WorkerArray[index];
			int newID = 0;
			string newName;
			int dID = 0;
			cout << "�������¹��ţ� " << endl;
			cin >> newID;
			cout << "�������������� " << endl;
			cin >> newName;
			cout << "�������λ��" << endl;
			cin >> dID;
			Worker* worker = NULL;
			switch (dID)
			{
			case 1:
				worker = new Employee(newID, newName, dID);
				break;
			case 2:
				worker = new Manager(newID, newName, dID);
				break;
			case 3:
				worker = new Boss(newID, newName, dID);
			default:
				break;
			}
			this->m_WorkerArray[index] = worker;
			cout << "�޸ĳɹ���" << endl;
			this->Save();
		}
		else
		{
			cout << "���޴��ˣ�" << endl;
		}
	}
	system("pause");
	system("cls");
}

void WorkerManager::Find_Worker()
{
	if (this->isEmpty)
	{
		cout << "�б�Ϊ�գ�" << endl;
	}
	else
	{
		cout << "�����빤�ţ�" << endl;
		int ID;
		cin >> ID;
		int index = this->isExist(ID);
		if (index != -1)
		{
			cout << "���ҳɹ�����Ϣ���£�" << endl;
			this->m_WorkerArray[index]->showInfo();
		}
		else
		{
			cout << "���޴��ˣ�" << endl;
		}
	}
	system("pause");
	system("cls");
}

void WorkerManager::Sort_Worker()
{
	if (this->isEmpty)
	{
		cout << "�б�Ϊ�գ�" << endl;
	}
	else
	{
		for (int i = 0; i < this->m_WorkerNum; i++)
		{
			for (int j = 0; j < this->m_WorkerNum - 1 - i; j++)
			{
				Worker* temp;
				if (this->m_WorkerArray[j]->m_ID > this->m_WorkerArray[j + 1]->m_ID)
				{
					temp = this->m_WorkerArray[j];
					this->m_WorkerArray[j] = this->m_WorkerArray[j + 1];
					this->m_WorkerArray[j + 1] = temp;
				}
			}
		}
		this->Save();
		cout << "������ɣ�" << endl;
	}
	system("pause");
	system("cls");
}

void WorkerManager::CLEAN()
{
	cout << "ȷ����գ�������ʧȥ������Ϣ��" << endl;
	cout << "1.ȷ��" << endl << "2.ȡ��" << endl;
	int choice = 0;
	cin >> choice;
	if (choice == 1)
	{
		ofstream ofs(FILENAME, ios::trunc);
		ofs.close();
		if (this->m_WorkerArray != NULL)
		{
			for (int i = 0; i < this->m_WorkerNum; i++)
			{
				if (this->m_WorkerArray[i] != NULL)
				{
					delete this->m_WorkerArray[i];
					this->m_WorkerArray[i] = NULL;
				}
			}
			delete[]this->m_WorkerArray;
			this->m_WorkerArray = NULL;
			this->m_WorkerNum = 0;
			this->isEmpty = true;
		}
		cout << "�����ɣ�" << endl;
	}
	system("pause");
	system("cls");
}