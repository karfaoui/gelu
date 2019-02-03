/*
 * @Author: Kais Arfaoui 
 * @Date: 2019-02-03 15:17:14 
 * @Last Modified by:   karfaoui 
 * @Last Modified time: 2019-02-03 15:17:14 
 */

#include<iostream>

#include "../include/Activation.hpp"
#include "../include/FileUtils.hpp"

int main(){   
    // generate pseudo-random sample data
    auto x = Activation::getSample();    

    // activate the sample data    
    auto yRelu = Activation::relu(x);    
    auto yleakyRelu = Activation::leakyRelu(x);    
    auto yGelu = Activation::gelu(x);

    // save to csv file
    FileUtils::toCsv({&x, &yRelu, &yleakyRelu, &yGelu}, "activations.csv");
}