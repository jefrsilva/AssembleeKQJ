#ifndef __wallmodel__
#define __wallmodel__

#include "Model.h"

/**
 * \class WallModel
 * \author Jeferson Rodrigues da Silva
 * \date 12/06/2009
 * \file WallModel.h
 * \brief A wall model.
 */
class WallModel : public Model {
    
private:
    int textureRow;
    int textureCol;
    double bottom;
    double top;

public:
    WallModel(int textureRow, int textureCol, double bottom, double top);
    ~WallModel();

    virtual std::vector<int> getFaces();
    virtual std::vector<double> getNormals();
    virtual std::vector<double> getUVs();
    virtual std::vector<double> getVertices();

};

#endif // __wallmodel__
