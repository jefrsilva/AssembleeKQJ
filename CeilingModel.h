#ifndef __ceilingmodel__
#define __ceilingmodel__

#include "Model.h"

/**
 * \class CeilingModel
 * \author Jeferson Rodrigues da Silva
 * \date 12/06/2009
 * \file CeilingModel.h
 * \brief A ceiling model.
 */
class CeilingModel : public Model {
    
private:
    int textureRow;
    int textureCol;
    double height;

public:
	CeilingModel(int textureRow, int textureCol, double height);
	~CeilingModel();

	virtual std::vector<int> getFaces();
	virtual std::vector<double> getNormals();
	virtual std::vector<double> getUVs();
	virtual std::vector<double> getVertices();
    
};

#endif // __ceilingmodel__
