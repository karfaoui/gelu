#include "../include/Activation.hpp"

#include<iostream>

#define PI  3.14159265358979323846
#define A 0.044715
#define SAMPLE_INTERVAL 0.25

Activation::Activation() {

}

Activation::~Activation() {

}

Tensor Activation::getSample(float start, int size) {    
    Tensor x = at::zeros({ size }, at::kFloat);
    x[0] = start;

    for (int i = 1; i < x.size(0); i++) {
        x[i] = x[i-1] + SAMPLE_INTERVAL;        
    }   

    return x;
}

Tensor Activation::relu(const Tensor& x) {
    cout << "-> Activation::relu" << endl;    
    Tensor y = leakyRelu(x, 0.0);      
    cout << "<- Activation::relu" << endl;    

    return y;
}

Tensor Activation::leakyRelu(const Tensor& x, float leak) {
    if (leak > 0.0) {
        cout << "-> Activation::leakyRelu" << endl;
    }
    
    Tensor y = x.clone();

    for (int i = 1; i < x.size(0); i++) {
        y[i] = max(leak * x[i], x[i]);        
    }     
      
    if (leak > 0.0) {        
        cout << "<- Activation::leakyRelu" << endl;
    }

    return y;
}

Tensor Activation::gelu(const Tensor& x) {
    cout << "-> Activation::gelu" << endl;
    
    Tensor y = 0.5 * x * (1 + tanh(sqrt(2.0 / PI) * (x + A * x.pow(3))));
      
    cout << "<- Activation::gelu" << endl;

    return y;
}
