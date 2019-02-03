/*
 * @Author: Kais Arfaoui 
 * @Date: 2019-02-03 15:16:50 
 * @Last Modified by:   karfaoui 
 * @Last Modified time: 2019-02-03 15:16:50 
 */

#pragma once

#include "pch.h"

class FileUtils {

public:
    FileUtils();
    ~FileUtils();

public:
    static void toCsv(initializer_list<const Tensor*> list, const string& path);
};