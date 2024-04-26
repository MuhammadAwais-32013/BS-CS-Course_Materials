#include <iostream>
#include "SLL.h"
using namespace std;
/* write a function name search that will take element as parameter 
function return true if found  otherwise 0*/
/* run this program using the console pauser or add your own getch, system("pause") or input loop */


int main(int argc, char** argv) {
	SLL<int> list1;
// 	list1.addTohead(17);// /17/0 H,T
// 	list1.addTohead(15);// without new mean compile time call // /15\0xA1/H 
// 	list1.addTohead(19);
// //	list1.addTohead(29);
//     //list1.traverse();
// 	//19,15,17
	
// 	list1.addTotail(29);
// 	list1.traverse();
	
// 	SLL<char> list2;
// 	list2.addTohead('q');
// 	list2.addTohead('a');
// 	list2.addTohead('b');
// 	list2.traverse();
	
	SLL<string> list3;
	list3.addTohead("Awais");
	list3.addTohead("Qarni");
	list3.addTohead("C++");
	list3.addTotail("Khaplu");
 	//list3.traverse();
	//list3.addTotail("Java");
	//list3.traverse();
	list3.addAfterGivenelement("SQL","C++"); // new element, existing element
    list3.addBeforGivenelement("Qarni", "C#"); // Existing elemnt , new Element
    list3.traverse();
    //cout<<list3.search("C++")<<endl;
    //list3.removeFromTail(); // delete from tail function 
	//list3.removeFromHead();
	list3.removeGivenElement("Khaplu");
	list3.traverse();
	
	return 0;
}
