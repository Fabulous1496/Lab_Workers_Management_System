#include"Manager.h"
Manager::Manager(int ID, string name, int dID)
{
	this->m_ID = ID;
	this->m_Name = name;
	this->m_DeptID = dID;
}

void Manager::showInfo()
{
	cout <<"ְ����ţ� " << this->m_ID
		<< "\tְ�������� " << this->m_Name
		<< "\t��λ�� " << this->getDeptName()
		<< "\tְ������ϰ彻��������" << endl;
}

string Manager::getDeptName()
{
	return string("����");
}