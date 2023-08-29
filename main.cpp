#include"header.h"
#include <iostream>

using namespace std;

int main()
{
    Clock c;
    Assistant a(c);
    a.display();
    a.read();
    a.introduce();
    a.get_command();
}
