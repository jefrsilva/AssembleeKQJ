#include "PressurePlateModel.h"
#include "GlobalConstants.h"

PressurePlateModel::PressurePlateModel(int textureRow, int textureCol,
                                       double height) {
    this->textureRow = textureRow;
    this->textureCol = textureCol;
    this->height = height;
}

PressurePlateModel::~PressurePlateModel() {

}

std::vector<int> PressurePlateModel::getFaces() {
    int fd[] = {1, 1, 0,
                2, 2, 0,
                0, 0, 0,
                3, 3, 0
               };

    std::vector<int> f(fd, fd + sizeof(fd) / sizeof(int));
    return f;
}

std::vector<double> PressurePlateModel::getNormals() {
    double vnd[] = {0.0, 1.0, 0.0};

    std::vector<double> vn(vnd, vnd + sizeof(vnd) / sizeof(double));
    return vn;
}

std::vector<double> PressurePlateModel::getUVs() {
    double pw = 1.0 / TEX_IMAGE_TILE_WIDTH;
    double ph = 1.0 / TEX_IMAGE_TILE_HEIGHT;

    double tileWidth = TEX_TILE_WIDTH * pw;
    double tileHeight = TEX_TILE_HEIGHT * ph;

    double hJump = tileWidth + 2 * pw;
    double vJump = tileHeight + 2 * ph;

    double uOffset = (hJump * textureCol) + pw;
    double vOffset = 1.0 - (vJump * (textureRow + 1)) + ph;

    double vtd[] = {uOffset + pw, vOffset + ph,
                    uOffset + tileWidth - pw, vOffset + ph,
                    uOffset + tileWidth - pw, vOffset + tileHeight - ph,
                    uOffset + pw, vOffset + tileHeight - ph
                   };

    std::vector<double> vt(vtd, vtd + sizeof(vtd) / sizeof(double));
    return vt;
}

std::vector<double> PressurePlateModel::getVertices() {
    double pw = TILE_SIZE / 16.0;
    double ph = TILE_SIZE / 16.0;
    
    double left = -0.5 * TILE_SIZE;
    double right = 0.5 * TILE_SIZE;
    
    double back = -0.5 * TILE_SIZE;
    double front = 0.5 * TILE_SIZE;
    
    double vd[] = {left + pw, height, front - ph,
                   right - pw, height, front - ph,
                   right - pw, height, back + ph,
                   left + pw, height, back + ph
                  };

    std::vector<double> v(vd, vd + sizeof(vd) / sizeof(double));
    return v;
}
