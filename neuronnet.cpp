#include "neuronnet.h"
#include "weightsmatrix.h"
#include <qdebug.h>
#include <fstream>

NeuronNet::NeuronNet()
{

}

NeuronNet::NeuronNet(vector<int> net_topology)                // constructor of the net, uses topology, pretty much Aufgabe 2a)
{
    /* net_topology vector will be something like [68,68,10]
     * this means it has 3 layers ( net_topology.size() = 3)
     * the first layer(hidden layer) has 68 neurons, second has 68, last output layer has 10 neurons*/

    for (int m = 0; m < net_topology.size(); m++)               // net_topology.size() is the ammount of layers
    {
        vector <Neuron> single_layer;                              // for each element create a layer with neurons

        for (int n = 0; n < net_topology[m]; n++)               // each element of net_topology is a number, representing the number of neurons in the layer
        {
            Neuron neuron;                                      // create class object of neuron

            if(m == (net_topology.size() - 1)){                 // sets last layer indicator, so the weight matrix can be created correctly.
                neuron.setLastLayer();
            }
            single_layer.push_back(neuron);                     // push this object to the layer

        }
        netLayers.push_back(single_layer);                      // push the layer with the given neurons to the main vector
    }


    for (int k = 0; k < net_topology.size() - 1 ; k ++)                 // loop all layers except the output, thats why size() -1
    {
        Neuron bias_neuron;                                          // create extra neuron with bias as value
        bias_neuron.setOutput(1);
        netLayers[k].push_back(bias_neuron);                           // add it to all layers except the output
    }


    /*
        In this part we create a weight matrix between two layers. Instead of creating a list with all weight matrices we
        give each neuron one list containing the connections to every next layer neuron, except the bias. For further usage of
        the weights, it can be called from each neuron individually, together with the neurons output.
    */


    for (unsigned int i = 0; i < netLayers.size() - 1; i++)
    {

        vector<vector<double>> weights = createWeightmatrix(netLayers[i], netLayers[i+1]);



        for (unsigned int j = 0; j < netLayers[i].size(); j++)
        {
            vector<double> weightsPerNeuron;

            for (unsigned int k = 0; k < weights.size(); k++)
            {
                weightsPerNeuron.push_back(weights[k][j]);
            }
            netLayers[i][j].setWeights(weightsPerNeuron);
        }

    }

    print();

}



void NeuronNet::print()
{
    for (unsigned int i = 0; i < netLayers.size(); i++)
    {
        for (unsigned j = 0; j < netLayers[i].size(); j++)
        {
            qDebug() << "layer: " << i;
            qDebug() << "size: " << netLayers[i].size();
            qDebug() << j << netLayers[i][j].getWeights();
        }
    }
}



vector<vector<double>> NeuronNet::createWeightmatrix(vector<Neuron> layerOne, vector<Neuron> layerTwo)
{
    WeightsMatrix matrix(layerOne, layerTwo);
    vector<vector<double>> returnMatrix = matrix.getMatrix();
    return returnMatrix;

}



// outter layer ist noch nicht definiert !! siehe: outter_layer = netLayers.back();
/*
vector<double> NeuronNet::outputGetter()                        // Aufgabe 2b)
{
    vector <double> output_values;

    for (int n = 0 ; n < outter_layer.size(); n++)
        output_values.push_back(outter_layer[n].getOutput());

    return output_values;
}

void Neuron_net::setInputValues(vector<double> input_values)             // Aufgabe 2c)
{                                                                       // input_values is a vector with prepared values for the input layer
    for (int k = 0; k < netLayers.front().size(); k++)                  // for each neuron in the input layer
        netLayers.front()[k].setOutput(input_values[k]);                   // set the values of these neurons to the values of the input_values vector

    outputGetter();                                                     // call the outputGetter function to return the Output from the newly
                                                                        // given values
}
*/


vector<double> NeuronNet::calculateSingleOutput()
{

}

void NeuronNet::export_data(string file_name)
{
    // first export the info from topology

    string text_stream;                                                 // the whole text we want to export
    for (int k = 0; k < net_topology.size(); k++)
    {
        text_stream.append(to_string(net_topology[k]));                 // we need to convert the integers from net_topology to strings
        text_stream.append(",");                                        // commas to separate the ints
    }
    text_stream.append("/");                                            // separator between topology and weights


    // exporting weights;


     for (int k = 0 ; k < net_topology.size(); k++)                      // number of layers
     {
         for (int j = 0; j < netLayers[k].size(); j++)                   // number of neurons in a layer

         {
            vector <double > weights = netLayers[k][j].getWeights();     // weights from one neuron to the other neurons in the next layer
            for (int m = 0; m < weights.size(); m++)
            {
            text_stream.append(to_string(weights[m]));
            text_stream.append(",");
            }
         }
     }
     text_stream.append(";");                                           // end of the stream




        ofstream file;                                                      
        file.open(file_name);                                           // open the requested file
        file << text_stream;                                            // export the state to the file
        file.close();
}

void NeuronNet::import_data(string file_name)
{
    net_topology.erase(net_topology.begin(),net_topology.begin()+net_topology.size());      // clear the topology vector
    
    vector <int> imported_topology;
    
    
    ifstream input(file_name);
    if(input.is_open())
    {}




    input.close();
    
}


