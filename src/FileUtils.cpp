/*
 * @Author: Kais Arfaoui 
 * @Date: 2019-02-03 15:17:29 
 * @Last Modified by:   karfaoui 
 * @Last Modified time: 2019-02-03 15:17:29 
 */

#include "../include/FileUtils.hpp"

#include <fstream>
#include<stdarg.h>

FileUtils::FileUtils() {

}

FileUtils::~FileUtils() {

}

void FileUtils::toCsv(initializer_list<const Tensor*> list, const string& path) {
    std::ofstream out(path);

    size_t minSize = 0;
    size_t n = 0;

    for(auto item : list ) {        

        if (item) {
            n = item->size(0);
            if ((minSize == 0) || (minSize > n)) {
                minSize = n;
            }                    
        }
    }

    out << std::fixed;
    out << std::setprecision(3);

    size_t m = list.size();

    for(size_t i = 0; i < minSize; i++)
    {
        size_t j = 0;

        for(auto item : list) {
            auto t = (*item);    
            auto f = t[i].item().toFloat();
            out << (f != -0.00 ? f : 0); 

            if (j < m - 1) {
                out << ",";
            }

            j++;
        }

        out << endl;
    }   

    out.close();
    cout << "=> FileUtils::toCsv(...) :: " << path << endl;
}