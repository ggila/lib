#include <iostream>
#include <iomanip>
#include <list>

int                         main()
{
    std::list<int> lol[1];

    void *ptr = (void*)lol;
    size_t *ip = (size_t*)ptr;


    std::cout << "debut" << std::endl;
    std::cout << "self:" << std::setbase(16) << (unsigned long long int)ptr << std::endl;
    for (int i = 0; i < 3; i++)
    {
        std::cout << ip[i] << std::endl;

    }


    std::cout << "" << std::endl;
    lol->push_back(42);


    std::cout << "self:" << (unsigned long long int)ptr << std::endl;
    for (int i = 0; i < 3; i++)
    {
        std::cout << ip[i] << std::endl;

    }

    std::cout << "" << std::endl;
    lol->push_back(42);


    std::cout << "self:" << (unsigned long long int)ptr << std::endl;
    for (int i = 0; i < 3; i++)
    {
        std::cout << ip[i] << std::endl;

    }

    return (0);
}
