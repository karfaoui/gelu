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