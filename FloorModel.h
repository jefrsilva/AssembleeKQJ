#ifndef __floormodel__
#define __floormodel__

#include "Model.h"

/**
 * \class FloorModel
 * \author Jeferson Rodrigues da Silva
 * \date 12/06/2009
 * \file FloorModel.h
 * \brief A floor model.
 */
class FloorModel : public Model {
    
private:
    int textureRow;
    int textureCol;
    double height;

public:
	FloorModel(int textureRow, int textureCol, double height);
	~FloorModel();

	virtual std::vector<int> getFaces();
	virtual std::vector<double> getNormals();
	virtual std::vector<double> getUVs();
	virtual std::vector<double> getVertices();

};

#endif // __floormodel__
