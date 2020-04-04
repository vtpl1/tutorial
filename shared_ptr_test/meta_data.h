#ifndef meta_data_h
#define meta_data_h
#include <memory>
#include "big_data.h"
class meta_data
{
private:
    static int id_generator;
    int id;
public:
    meta_data();
    ~meta_data();
    std::shared_ptr<big_data> b_d;
};



#endif