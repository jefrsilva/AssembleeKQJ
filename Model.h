#ifndef __model__
#define __model__

#include <vector>

/**
 * \class Model
 * \author Jeferson Rodrigues da Silva
 * \date 12/06/2009
 * \file Model.h
 * \brief Virtual class defining a model.
 */
class Model {
    
public:
    virtual ~Model() {};
    
    virtual std::vector<double> getVertices() = 0;
    virtual std::vector<double> getNormals() = 0;
    virtual std::vector<double> getUVs() = 0;
    
    virtual std::vector<int> getFaces() = 0;
    
    virtual void render();

};

#endif // __model__
