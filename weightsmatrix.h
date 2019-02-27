#ifndef WEIGHTSMATRIX_H
#define WEIGHTSMATRIX_H

#include <neuron.h>
#include <vector>


class WeightsMatrix
{
public:

    WeightsMatrix(vector <Neuron> firstlayer, vector <Neuron> secondlayer);  // takes both hiddenlayers and makes a matrix


    //getter
    vector<vector<double>> getMatrix();
    double getWeight(int par_x, int par_y);
    
    //setter
    void setWeight(int par_x, int par_y, double value);                       // set a specific location with new weight
    void setHiddenGradient(double alpha, double eta);                         // setting the formulas for the gradients
    void setOutputGradient(double alpha, double eta);                         // taken from Folie 4, slides 14-15 



private:
    vector <Neuron> *innerLayer;                                                         // pointer to the inner layer
    vector <Neuron> *outterLayer;                                                        // pointer to the outter layer
    vector <vector <double>> weights_matrix;                                                 // matrix containing the weights


};

#endif // WEIGHTSMATRIX_H
