#include "weightsmatrix.h"
#include <stdlib.h>
#include <time.h>
#include <qdebug.h>

WeightsMatrix::WeightsMatrix(vector<Neuron> firstlayer, vector<Neuron> secondlayer)
{
    innerLayer = &firstlayer;                              // points to the memory address of the inner layer vector
    outterLayer = &secondlayer;                             // points to the memory address of the outter layer 2 vector
    
    
    srand(time(NULL));
    
    vector<vector<double>> matrix;

    unsigned int nextCounter = outterLayer->size() - 1;              // excludes the bias of the following layer
    if(outterLayer->at(0).getLastLayerIndicator() == true)  // last layer doesnt have a bias, so the subtracted neuron has to be replaced
    {
        nextCounter++;
    }


    for (unsigned int i = 0; i < nextCounter; i++)           // get the number of neurons in the otter layer

    {vector < double> matrix_line;
        
        for (unsigned int k = 0 ; k < innerLayer->size(); k++)       // get the number of neurons in the hidden layer

        {
            double number;
            double prevColon = rand()%9 - 4;                                //generates random number in the intervall [-4,4], decimal spaces will be added to -4.999 and 4.999.
            if (prevColon < 0)
            {
                double decimal = double(rand()) / (double(RAND_MAX) + 1.0); // adds decimal spaces to the random number
                 number = prevColon - decimal;
            }
            else{
                double decimal = double(rand()) / (double(RAND_MAX) + 1.0);     // adds decimal spaces to the random number
                 number = prevColon + decimal;
            }

            matrix_line.push_back(number);
        }
        
        matrix.push_back(matrix_line);                     // matrix is a matrix with (number of neurons in outter layer)*(number of neurons in
                                                            // inner layer) weights
                                                            // this is done since the weights at the first run are randomly generated in the
                                                            // range of [0,1]
    }
    
    weights_matrix = matrix;
      
}



vector<vector<double>> WeightsMatrix::getMatrix()
{
    return weights_matrix;
}

void WeightsMatrix::setWeight(int par_x, int par_y, double value)
{
    weights_matrix[par_x][par_y] = value;
}

void WeightsMatrix::setHiddenGradient(double alpha, double eta)
{
    double weights_delta;
    
    // weights_delta = eta*2*(actual values - activation_output[outterLayer])*derivative_output[outterLayer]*activation_output[innerlayer])
    // traegheitsmoent :  matrix += (1-alpha)*weights_delta + alpha * weights_delta
            
}

void WeightsMatrix::setOutputGradient(double alpha, double eta)
{
    
}

double WeightsMatrix::getWeight(int par_x, int par_y)
{
    return weights_matrix[par_x][par_y];                    // for example weights_matrix[4][10] shows the weight getting in 4th neuron from 10th neuron
                                                            // in the previous layer
}
