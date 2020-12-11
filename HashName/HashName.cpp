#include <iostream>
#include "hashTable.h"

std::vector<int> getStringCode(std::vector < std::string > str);
void print(std::vector<int> vec);

int main()
{
    using namespace std;
    vector<string> str = { "Ren Lei", "Zhu Ru", "He Li", "Miao A", "Ming Zi",
    "Shen Xian", "Da Lao", "Ren Shangren", "Jin Longyu", "Kang Shifu",
    "Zao Shu", "An Jing", "Zhuang Bi", "Ha Xiren", "San lieren",
    "Qiang Da", "Bian De", "He Shui", "Hai Youa", "Duo Shaole",
    "Zai Lai", "Ji Xubian", "Xia xie", "Gou Leba", "Ke Yile" };
    
    HashTable table(str);
    table.search("Bian De");
    table.print();
    return 0;
}