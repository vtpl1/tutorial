#include "meta_data.h"
#include <iostream>
int meta_data::id_generator = 0;
meta_data::meta_data()
    : id(meta_data::id_generator++)
{
    std::cout << "Meta data ctor " << id << std::endl;
}

meta_data::~meta_data()
{
    std::cout << "Meta data dtor " << id << std::endl;
}