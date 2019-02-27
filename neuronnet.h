#ifndef NEURON_NET_H
#define NEURON_NET_H

#include <neuron.h>
#include <weightsmatrix.h>




class NeuronNet
{
public:
    NeuronNet();
    NeuronNet(vector<int> net_topology);                                  // info for the number of neurons for each layer

    double targetOutputGetter();
    double calculatedOutputGetter();
    double marginOfErrorGetter();



    vector <vector <Neuron>> netLayers;                                     // vector of vectors(layers), each layer is a vector of neurons
    vector <int> net_topology;                                              // gives how many layers and how many neurons in each one
    vector <double> outputGetter();

    vector <Neuron> outter_layer;                        // vector containing the output layer
    vector<vector<double>> createWeightmatrix(vector<Neuron> layerOne, vector<Neuron> layerTwo);
    vector <double> input_values;
    
    void setInputValues(vector <double> input_values);                       // Aufgabe 2c)
    vector<double> calculateSingleOutput();
    
    void export_data(string file_name);                                     // Aufgabe 2e)
    void import_data(string file_name);                                     // Aufgabe 2f)



private:
    double target_output;
    double calculated_output;
    double margin_of_error = target_output - calculated_output;
    void print();

};

#endif // NEURON_NET_H
