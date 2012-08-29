#include "DoorModel.h"
#include "GlobalConstants.h"

DoorModel::DoorModel(int textureRow, int textureCol,
                     double bottom, double top) {
    this->textureRow = textureRow;
    this->textureCol = textureCol;
    this->bottom = bottom;
    this->top = top;
}

DoorModel::~DoorModel() {

}

std::vector<int> DoorModel::getFaces() {
    int fd[] = {1, 1, 0,
                2, 2, 0,
                0, 0, 0,
                3, 3, 0,
                
                5, 5, 1,
                6, 6, 1,
                4, 4, 1,
                7, 7, 1,
                
                9, 9, 2,
                10, 10, 2,
                8, 8, 2,
                11, 11, 2
               };

    std::vector<int> f(fd, fd + sizeof(fd) / sizeof(int));
    return f;
}

std::vector<double> DoorModel::getNormals() {
    double vnd[] = { 0.0,  0.0,  1.0,
                     0.0, -1.0,  0.0,
                     0.0,  0.0, -1.0};

    std::vector<double> vn(vnd, vnd + sizeof(vnd) / sizeof(double));
    return vn;
}

std::vector<double> DoorModel::getUVs() {
    double pw = 1.0 / TEX_IMAGE_TILE_WIDTH;
    double ph = 1.0 / TEX_IMAGE_TILE_HEIGHT;

    double tileWidth = TEX_TILE_WIDTH * pw;
    double tileHeight = TEX_TILE_HEIGHT * ph;

    double hJump = tileWidth + 2 * pw;
    double vJump = tileHeight + 2 * ph;

    double uOffset = (hJump * textureCol) + pw;
    double vOffset = 1.0 - (vJump * (textureRow + 1)) + ph;

    double vtd[] = {// Front Face
                    uOffset, vOffset,
                    uOffset + tileWidth, vOffset,
                    uOffset + tileWidth, vOffset + tileHeight,
                    uOffset, vOffset + tileHeight,
                    
                    // Bottom Face
                    uOffset, vOffset,
                    uOffset + tileWidth, vOffset,
                    uOffset + tileWidth, vOffset + ph,
                    uOffset, vOffset + ph,
                    
                    // Back Face
                    uOffset + tileWidth, vOffset,
                    uOffset, vOffset,
                    uOffset, vOffset + tileHeight,
                    uOffset + tileWidth, vOffset + tileHeight
                   };

    std::vector<double> vt(vtd, vtd + sizeof(vtd) / sizeof(double));
    return vt;
}

std::vector<double> DoorModel::getVertices() {
    double pz = TILE_SIZE / 16.0;
    
    double left = -0.5 * TILE_SIZE;
    double right = 0.5 * TILE_SIZE;
    
    double vd[] = {// Front Face
                   left, bottom, 1.0 * pz,
                   right, bottom, 1.0 * pz,
                   right, top, 1.0 * pz,
                   left, top, 1.0 * pz,
                   
                   // Bottom Face
                   left, 0.0, -1.0 * pz,
                   right, 0.0, -1.0 * pz,
                   right, 0.0, 1.0 * pz,
                   left, 0.0, 1.0 * pz,
                   
                   // Back Face
                   right, bottom, -1.0 * pz,
                   left, bottom, -1.0 * pz,
                   left, top, -1.0 * pz,
                   right, top, -1.0 * pz
                  };

    std::vector<double> v(vd, vd + sizeof(vd) / sizeof(double));
    return v;
}
