#include "big_data.h"

#include <iostream>
int big_data::id_generator = 0;

big_data::big_data()
    : id(big_data::id_generator++)
{
    std::cout << "===== Big data ctor " << id << std::endl;
}

big_data::~big_data()
{
    std::cout << "===== Big data dtor " << id << std::endl;
}
