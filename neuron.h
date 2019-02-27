#ifndef NEURON_H
#define NEURON_H


#include <mainwindow.h>
#include <vector>

using namespace std;


class Neuron
{
public:
    Neuron();

    //getter
    double getActivation();
    double getDerivative();
    double getOutput();                             // x = correct line of (weight matrix) * (previous layer inputs)
    vector<double> getWeights();
    bool getLastLayerIndicator();


    //setter
    void setDerivative(double (*func)(double x));
    void setActivation(double (*func)(double x));
    void setOutput(double x);                       // only for input layer neurons! Sets the output directly
    void setWeights(vector<double>);
    void setLastLayer();                            // needed for weightmatrix creation, so the missing bias will be ignored.

    void calculateOutput(double x);                 // for every neuron not in the input layer -> calculates ouput using the activation function

private:

    bool lastLayerIndicator = false;
    double outputValue;                             // basically the input value for the next layer neuron calculation
    double (*activationFunc)(double x);             // function pointer that holds the current activation function
    double (*derivativeFunc)(double x);
    vector<double> weights;
    static double sigmoid(double x);                // default activation function. It is set in the constructor if the neuron is not an input layer neuron.
    static double sigmoidDerivative(double x);

};

#endif // NEURON_H
