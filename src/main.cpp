#include <iostream>
#include "stos_tablica.hh"
#include "stackList.hh"

using namespace std;

int main()
{
    stackList<int> stosik;

    stosik.push(5);

    std::cout << "Top of the stack: " << stosik.top() << std::endl;

    stosik.push(6);
    std::cout << "Top of the stack: " << stosik.top() << std::endl;
    std::cout << stosik.getHead()->getNext()->getElement() << std::endl;

    return 0;
}