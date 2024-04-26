#include <iostream>
#include "SLL.h"
using namespace std;

int main(int argc, char **argv)
{
    SLL<string> list1;
    list1.addToHead("Awais");
    list1.addToHead("Qarni");
    list1.addToTail("C++");
    list1.addToTail("Code");
    // list1.traverse();
    list1.addAfterGivenElement("C#", "Qarni");
     list1.addAfterGivenElement("C","C++");
    // list1.addAfterGivenElement("CSS", "Awais");
    list1.addBeforeGivenElement("Awais", " Haider");
    list1.addBeforeGivenElement("C++", "python");
    list1.traverse();
    //list1.searchElement("Html");
    // list1.searchElement("C++");
    // list1.traverse();
    // list1.removeFromHead();
    list1.removeFromTail();
    //list1.removeGivenElement("C++");
    list1.removeGivenElement("Awais");
    list1.removeGivenElement("C#");
   // list1.removeGivenElement("DSA");
    list1.removeGivenElement("Qarni");
   // list1.removeGivenElement("Code");
   // list1.traverse();

    // 	SLL<string> list3;
    // list3.addToHead("Awais");
    // list3.addToHead("Qarni");
    // list3.addToHead("C++");
    // list3.addToTail("Khaplu");
    // //list3.traverse();
    // //list3.addTotail("Java");
    // //list3.traverse();
    // list3.addAfterGivenElement("SQL","C++"); // new element, existing element
    // list3.addBeforeGivenElement("Qarni", "C#"); // Existing elemnt , new Element
    // list3.traverse();
    // //cout<<list3.search("C++")<<endl;
    // //list3.removeFromTail(); // delete from tail function
    // //list3.removeFromHead();
    // list3.removeGivenElement("Khaplu");
    // list3.traverse();

    return 0;
}
