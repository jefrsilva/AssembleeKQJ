#include "WallModel.h"
#include "GlobalConstants.h"

WallModel::WallModel(int textureRow, int textureCol,
                     double bottom, double top) {
    this->textureRow = textureRow;
    this->textureCol = textureCol;
    this->bottom = bottom;
    this->top = top;
}

WallModel::~WallModel() {

}

std::vector<int> WallModel::getFaces() {
    int fd[] = {1, 1, 0,
                2, 2, 0,
                0, 0, 0,
                3, 3, 0
               };

    std::vector<int> f(fd, fd + sizeof(fd) / sizeof(int));
    return f;
}

std::vector<double> WallModel::getNormals() {
    double vnd[] = {0.0, 0.0, 1.0};

    std::vector<double> vn(vnd, vnd + sizeof(vnd) / sizeof(double));
    return vn;
}

std::vector<double> WallModel::getUVs() {
    double pw = 1.0 / TEX_IMAGE_TILE_WIDTH;
    double ph = 1.0 / TEX_IMAGE_TILE_HEIGHT;

    double tileWidth = TEX_TILE_WIDTH * pw;
    double tileHeight = TEX_TILE_HEIGHT * ph;

    double height = top - bottom;
    double heightOffset = ((height - TILE_SIZE) / TILE_SIZE) * tileHeight;

    double hJump = tileWidth + 2 * pw;
    double vJump = tileHeight + 2 * ph;

    double uOffset = (hJump * textureCol) + pw;
    double vOffset = 1.0 - (vJump * (textureRow + 1)) + ph;

    double vtd[] = {uOffset, vOffset,
                    uOffset + tileWidth, vOffset,
                    uOffset + tileWidth, vOffset + tileHeight + heightOffset,
                    uOffset, vOffset + tileHeight + heightOffset
                   };

    std::vector<double> vt(vtd, vtd + sizeof(vtd) / sizeof(double));
    return vt;
}

std::vector<double> WallModel::getVertices() {
    double vd[] = {-0.5 * TILE_SIZE, bottom, 0.0,
                   0.5 * TILE_SIZE, bottom, 0.0,
                   0.5 * TILE_SIZE, top, 0.0,
                   -0.5 * TILE_SIZE, top, 0.0
                  };

    std::vector<double> v(vd, vd + sizeof(vd) / sizeof(double));
    return v;
}
