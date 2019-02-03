#pragma once

#include "pch.h"

class Activation {

public:
    Activation();
    ~Activation();

public:
    // Returns an equally spaced sample of length 'size' 
    // and starting at value 'start'
    static Tensor getSample(float start = -10.0, int size = 50);

    // see  https://arxiv.org/pdf/1606.08415.pdf
    // GELU activation
    static Tensor gelu(const Tensor& x);
    
    // RELU activation
    static Tensor relu(const Tensor& x);

    // Leaky RELU with a default leak factor of 0.01
    static Tensor leakyRelu(const Tensor& x, float leak = 0.01);
};