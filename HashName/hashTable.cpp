#include "hashTable.h"

void HashTable::getHashNum(int n) {
	bool flag = true;
	do{
		flag = true;
		for (int i = 2; i * i < n; i++) {
			if (n % i == 0) {
				flag = false;
				break;
			}	
		}
		if (flag) {
			primeNum = n;
			return;
		}
	} while (n--);
}

int HashTable::hashFunction(std::string str) {
	int sum = 0;
	for (auto i : str) {
		if (i == ' ') continue;
		sum += i;
	} //��ȡ�����г��ո�����ַ��ĺ�����ʼֵ
	return sum % primeNum;
}

HashTable::HashTable(std::vector<std::string> str) {
	size = str.size() * 2; 
	hashTable.resize(size); //����������10����Ĵ�С

	getHashNum(size);
	int hashCode;


	for (auto i : str) {
		hashCode = hashFunction(i);

		//std::cout << "Code first is: " << hashCode << std::endl;
		u.reset(); //�����������

		rand.seed(hashCode); //��λ����seed
		while (hashTable[hashCode].value != "empty") {
			unsigned int tmp = u(rand);

			//std::cout << "Randed: " << tmp << std::endl;
			hashCode += tmp % size;
			hashCode = hashCode % size;

			//std::cout << "Code changed to: " << hashCode << std::endl;

		} //��Ϊ�գ���ѡ��λ��
		Elm tmp(i);
		hashTable[hashCode] = tmp;

		//std::cout << "Position:" << hashCode << " Name:" << i << std::endl << std::endl;
	} //��ɫ�������Ϊ����ʱ�����
}

void HashTable::search(std::string name) {
	int hashCode = hashFunction(name); //��ȡ����
	u.reset(); //����
	rand.seed(hashCode);
	std::string out = hashTable[hashCode].value;
	while (out != name) {
		if (out == "empty") {//Ϊ���򷵻�
			std::cout << "Not found!" << std::endl;
			return;
		}
		hashCode += u(rand) % size;
		hashCode = hashCode % size; //��ȡα���ƫ����
		out = hashTable[hashCode].value; //����ֵ
	}
	std::cout << "Position: " << hashCode << " Name: " << name << std::endl << std::endl;
}

void HashTable::print() {
	for (unsigned int i = 0; i < hashTable.size(); i++) {
		std::cout << "Pos: " << std::setw(3) << i << " Name: " << std::setw(12) << hashTable[i].value << "  ";
		if ((i + 1) % 4 == 0) std::cout << std::endl;
	}
}