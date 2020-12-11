#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <iomanip>

class Elm {
public:
	std::string value; //ֵ��Ҳ�Ǽ�

	Elm() :value("empty") {} //Ĭ��Ϊempty,�������˽�������ְ�?
	Elm(std::string v) :value(v) {} //������vΪֵ��Ԫ��
}; //Ԫ����

class HashTable
{
private:
	int size, primeNum; //����ģֵ������
	std::vector<Elm> hashTable;
	std::default_random_engine rand; //���������
	std::uniform_int_distribution<unsigned> u; //��unsigned

	void getHashNum(int n); //��ȡС�ڱ����������
	int hashFunction(std::string key); //��ȡ��ϣֵ
public:
	HashTable(std::vector<std::string>); //���캯��
	void search(std::string name); //��������
	void print(); //��ӡ��ϣ��

};

