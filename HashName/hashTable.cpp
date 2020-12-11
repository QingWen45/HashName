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
	} //获取名字中除空格外的字符的和做初始值
	return sum % primeNum;
}

HashTable::HashTable(std::vector<std::string> str) {
	size = str.size() * 2; 
	hashTable.resize(size); //用名字数加10做表的大小

	getHashNum(size);
	int hashCode;


	for (auto i : str) {
		hashCode = hashFunction(i);

		//std::cout << "Code first is: " << hashCode << std::endl;
		u.reset(); //重置随机函数

		rand.seed(hashCode); //用位置做seed
		while (hashTable[hashCode].value != "empty") {
			unsigned int tmp = u(rand);

			//std::cout << "Randed: " << tmp << std::endl;
			hashCode += tmp % size;
			hashCode = hashCode % size;

			//std::cout << "Code changed to: " << hashCode << std::endl;

		} //若为空，则选作位置
		Elm tmp(i);
		hashTable[hashCode] = tmp;

		//std::cout << "Position:" << hashCode << " Name:" << i << std::endl << std::endl;
	} //灰色输出函数为调试时检查用
}

void HashTable::search(std::string name) {
	int hashCode = hashFunction(name); //获取索引
	u.reset(); //重置
	rand.seed(hashCode);
	std::string out = hashTable[hashCode].value;
	while (out != name) {
		if (out == "empty") {//为空则返回
			std::cout << "Not found!" << std::endl;
			return;
		}
		hashCode += u(rand) % size;
		hashCode = hashCode % size; //获取伪随机偏移量
		out = hashTable[hashCode].value; //更新值
	}
	std::cout << "Position: " << hashCode << " Name: " << name << std::endl << std::endl;
}

void HashTable::print() {
	for (unsigned int i = 0; i < hashTable.size(); i++) {
		std::cout << "Pos: " << std::setw(3) << i << " Name: " << std::setw(12) << hashTable[i].value << "  ";
		if ((i + 1) % 4 == 0) std::cout << std::endl;
	}
}