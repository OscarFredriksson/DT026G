#include "linked_list.h"
#include <cstdlib>
#include <ctime>

int main()
{
    srand(time(NULL));
    linked_list list1;
    linked_list list2;
    for(int i = 0; i < 100; i++)
    {
      list1.push_back(list1.back() + rand() % 20);
      list2.push_back(list2.back() + rand() % 20);
    }

    if(list1[50] > list2[50]) 
        std::cout << "Elementet i lista 1 är störst." << std::endl;
    else if(list1[50] < list2[50])
        std::cout << "Elementet i lista 2 är störst." << std::endl;
    else
        std::cout << "Elementen är lika stora." << std::endl;

    return 0; 
}