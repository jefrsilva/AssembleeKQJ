#ifndef __holemodel__
#define __holemodel__

#include "Model.h"

/**
 * \class HoleModel
 * \author Jeferson Rodrigues da Silva
 * \date 12/21/2009
 * \file HoleModel.h
 * \brief 
 */
class HoleModel : public Model {

private:
    int textureRow;
    int textureCol;
    double height;

public:
	HoleModel(int textureRow, int textureCol, double height);
	~HoleModel();

	virtual std::vector<int> getFaces();
	virtual std::vector<double> getNormals();
	virtual std::vector<double> getUVs();
	virtual std::vector<double> getVertices();
    
};

#endif // __holemodel__
