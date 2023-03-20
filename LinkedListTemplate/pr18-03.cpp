// This program demonstrates the add and 
// display linked list operations. 

#include "Numberlist.h"
#include <string>
using namespace std;

int main()
{
    NumberList<string> list;
    list.addSorted("Hey");
    list.addSorted("Hello");
    list.addSorted("How's it going?");
    list.addSorted("Howdy");
    list.addSorted("Hola");
    //list.addSorted(15.2);
    //list.addSorted(1.1);
    //list.addSorted(2.9);
    //list.addSorted(4.7);
    list.displayList();
    cout << endl;
    return 0;
}