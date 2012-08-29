#ifndef __doorframemodel__
#define __doorframemodel__

#include "Model.h"

/**
 * \class DoorFrameModel
 * \author Jeferson Rodrigues da Silva
 * \date 12/20/2009
 * \file DoorFrameModel.h
 * \brief 
 */
class DoorFrameModel : public Model {

private:
    int textureRow;
    int textureCol;
    double bottom;
    double top;

public:
	DoorFrameModel(int textureRow, int textureCol, double bottom, double top);
	~DoorFrameModel();

	virtual std::vector<int> getFaces();
	virtual std::vector<double> getNormals();
	virtual std::vector<double> getUVs();
	virtual std::vector<double> getVertices();
    
};

#endif // __doorframemodel__
