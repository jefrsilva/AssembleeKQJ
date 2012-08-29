#ifndef __pressureplatemodel__
#define __pressureplatemodel__

#include "Model.h"

/**
 * \class PressurePlateModel
 * \author Jeferson Rodrigues da Silva
 * \date 12/21/2009
 * \file PressurePlateModel.h
 * \brief 
 */
class PressurePlateModel : public Model {

private:
    int textureRow;
    int textureCol;
    double height;

public:
	PressurePlateModel(int textureRow, int textureCol, double height);
	~PressurePlateModel();

	virtual std::vector<int> getFaces();
	virtual std::vector<double> getNormals();
	virtual std::vector<double> getUVs();
	virtual std::vector<double> getVertices();
    
};

#endif // __pressureplatemodel__
