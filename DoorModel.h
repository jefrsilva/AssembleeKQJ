#ifndef __doormodel__
#define __doormodel__

#include "Model.h"

/**
 * \class DoorModel
 * \author Jeferson Rodrigues da Silva
 * \date 12/20/2009
 * \file DoorModel.h
 * \brief 
 */
class DoorModel : public Model {

private:
    int textureRow;
    int textureCol;
    double bottom;
    double top;

public:
    DoorModel(int textureRow, int textureCol, double bottom, double top);
    ~DoorModel();

    virtual std::vector<int> getFaces();
    virtual std::vector<double> getNormals();
    virtual std::vector<double> getUVs();
    virtual std::vector<double> getVertices();

};

#endif // __doormodel__
