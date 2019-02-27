#include "neuron.h"
#include <math.h>
#include <stdlib.h>             // for rand functions
#include <time.h>


Neuron::Neuron()
{
    activationFunc = sigmoid;
    derivativeFunc = sigmoidDerivative;
    outputValue = 0;
}


double Neuron::sigmoid(double x)
{
    double result = 1 / (1 + exp(-x));
    return result;
}


double Neuron::sigmoidDerivative(double x)
{
    double result = sigmoid(x) * (1 - sigmoid(x));
    return result;
}


void Neuron::setDerivative(double (*newFunc)(double))
{
    derivativeFunc = newFunc;
}


void Neuron::setActivation(double (*newFunc)(double x))
{
    activationFunc = newFunc;
}

void Neuron::calculateOutput(double x)    // x = correct line of (weight matrix) * (previous layer inputs)
{
    outputValue = activationFunc(x);
}


void Neuron::setOutput(double x)
{
    outputValue = x;
}


double Neuron::getOutput()
{
    return outputValue;
}


void Neuron::setWeights(vector<double> matrixLine)
{
    weights = matrixLine;
}

void Neuron::setLastLayer()
{
    lastLayerIndicator = true;
}


vector<double> Neuron::getWeights()
{
    return weights;
}

bool Neuron::getLastLayerIndicator()
{
    return lastLayerIndicator;
}
