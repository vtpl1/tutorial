#include <iostream>
#include <memory>
#include "meta_data.h"
#include <vector>

int main(int argc, char const *argv[])
{
    std::shared_ptr<big_data> b = std::make_shared<big_data>();
    std::shared_ptr<meta_data> m = std::make_shared<meta_data>();
    b.reset(new big_data());
    m->b_d = b;
    {
        std::vector<std::shared_ptr<meta_data>> l;
        l.push_back(m);
        //m->b_d = b;
        {
            for (size_t i = 0; i < 10; i++)
            {
                std::shared_ptr<meta_data> m = std::make_shared<meta_data>();
                l.push_back(m);
                //m->b_d = b;
            }        
        }        
        std::cout << "Erasing causes memory delete: " << std::endl;
        std::cout << "Before Erasing " << std::endl;
        l.erase(l.end());
        std::cout << "After Erasing " << std::endl;
        std::cout << "Before clear " << std::endl;
    }
    
    std::cout << "Hellow world" << std::endl;
    return 0;
}
