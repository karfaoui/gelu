#pragma once

#include "pch.h"

class FileUtils {

public:
    FileUtils();
    ~FileUtils();

public:
    static void toCsv(initializer_list<const Tensor*> list, const string& path);
};