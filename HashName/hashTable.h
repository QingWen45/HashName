#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <iomanip>

class Elm {
public:
	std::string value; //值，也是键

	Elm() :value("empty") {} //默认为empty,不会有人叫这个名字吧?
	Elm(std::string v) :value(v) {} //构造以v为值的元素
}; //元素类

class HashTable
{
private:
	int size, primeNum; //表长和模值用质数
	std::vector<Elm> hashTable;
	std::default_random_engine rand; //随机数引擎
	std::uniform_int_distribution<unsigned> u; //用unsigned

	void getHashNum(int n); //获取小于表长的最大质数
	int hashFunction(std::string key); //获取哈希值
public:
	HashTable(std::vector<std::string>); //构造函数
	void search(std::string name); //搜索函数
	void print(); //打印哈希表

};

