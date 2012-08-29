#include "DoorFrameModel.h"
#include "GlobalConstants.h"

DoorFrameModel::DoorFrameModel(int textureRow, int textureCol,
                               double bottom, double top) {
    this->textureRow = textureRow;
    this->textureCol = textureCol;
    this->bottom = bottom;
    this->top = top;
}

DoorFrameModel::~DoorFrameModel() {

}

std::vector<int> DoorFrameModel::getFaces() {
    int fd[] = {1, 1, 0,
                2, 2, 0,
                0, 0, 0,
                3, 3, 0,
                
                5, 5, 0,
                6, 6, 0,
                4, 4, 0,
                7, 7, 0,
                
                9, 9, 0, 
                10, 10, 0,
                8, 8, 0,
                11, 11, 0,
                
                13, 13, 1,
                14, 14, 1, 
                12, 12, 1,
                15, 15, 1,
                
                17, 17, 3,
                18, 18, 3,
                16, 16, 3,
                19, 19, 3,
                
                21, 21, 2,
                22, 22, 2,
                20, 20, 2,
                23, 23, 2,
                
                25, 25, 4,
                26, 26, 4,
                24, 24, 4,
                27, 27, 4,
                
                29, 29, 4,
                30, 30, 4,
                28, 28, 4,
                31, 31, 4,
                
                33, 33, 4,
                34, 34, 4,
                32, 32, 4, 
                35, 35, 4
               };

    std::vector<int> f(fd, fd + sizeof(fd) / sizeof(int));
    return f;
}

std::vector<double> DoorFrameModel::getNormals() {
    double vnd[] = { 0.0,  0.0,  1.0,
                     1.0,  0.0,  0.0,
                     0.0, -1.0,  0.0,
                    -1.0,  0.0,  0.0,
                     0.0,  0.0, -1.0,
                   };

    std::vector<double> vn(vnd, vnd + sizeof(vnd) / sizeof(double));
    return vn;
}

std::vector<double> DoorFrameModel::getUVs() {
    double pw = 1.0 / TEX_IMAGE_TILE_WIDTH;
    double ph = 1.0 / TEX_IMAGE_TILE_HEIGHT;

    double tileWidth = TEX_TILE_WIDTH * pw;
    double tileHeight = TEX_TILE_HEIGHT * ph;

    // double height = top - bottom;
    // double heightOffset = ((height - TILE_SIZE) / TILE_SIZE) * tileHeight;

    double hJump = tileWidth + 2 * pw;
    double vJump = tileHeight + 2 * ph;

    double uOffset = (hJump * textureCol) + pw;
    double vOffset = 1.0 - (vJump * (textureRow + 1)) + ph;

    double vtd[] = {// Front Top Face
                    uOffset, vOffset + tileHeight - ph,
                    uOffset + tileWidth, vOffset + tileHeight - ph,
                    uOffset + tileWidth, vOffset + tileHeight,
                    uOffset, vOffset + tileHeight,
                    
                    // Front Right Face
                    uOffset + tileWidth - pw, vOffset,
                    uOffset + tileWidth, vOffset,
                    uOffset + tileWidth, vOffset + tileHeight - ph,
                    uOffset + tileWidth - pw, vOffset + tileHeight - ph,
                    
                    // Front Left Face
                    uOffset, vOffset,
                    uOffset + pw, vOffset,
                    uOffset + pw, vOffset + tileHeight - ph,
                    uOffset, vOffset + tileHeight - ph,
                    
                    // Side Left Face
                    uOffset + 2.0 * pw, vOffset,
                    uOffset + 3.0 * pw, vOffset,
                    uOffset + 3.0 * pw, vOffset + tileHeight - ph,
                    uOffset + 2.0 * pw, vOffset + tileHeight - ph,
                    
                    // Side Right Face
                    uOffset + 5.0 * pw, vOffset,
                    uOffset + 6.0 * pw, vOffset,
                    uOffset + 6.0 * pw, vOffset + tileHeight - ph,
                    uOffset + 5.0 * pw, vOffset + tileHeight - ph,
                    
                    // Side Top Face
                    uOffset + pw, vOffset + 3.0 * ph,
                    uOffset + tileWidth - pw, vOffset + 3.0 * ph,
                    uOffset + tileWidth - pw, vOffset + 2.0 * ph,
                    uOffset + pw, vOffset + 2.0 * ph,
                    
                    // Back Top Face
                    uOffset + tileWidth, vOffset + tileHeight - ph,
                    uOffset, vOffset + tileHeight - ph,
                    uOffset, vOffset + tileHeight,
                    uOffset + tileWidth, vOffset + tileHeight,
                    
                    // Back Right Face
                    uOffset + tileWidth, vOffset,
                    uOffset + tileWidth - pw, vOffset,
                    uOffset + tileWidth - pw, vOffset + tileHeight - ph,
                    uOffset + tileWidth, vOffset + tileHeight - ph,
                    
                    // Back Left Face
                    uOffset + pw, vOffset,
                    uOffset, vOffset,
                    uOffset, vOffset + tileHeight - ph,
                    uOffset + pw, vOffset + tileHeight - ph
                   };

    std::vector<double> vt(vtd, vtd + sizeof(vtd) / sizeof(double));
    return vt;
}

std::vector<double> DoorFrameModel::getVertices() {
    double pw = TILE_SIZE / 16.0;
    double ph = TILE_SIZE / 16.0;
    double pz = TILE_SIZE / 16.0;

    double left = -0.5 * TILE_SIZE;
    double right = 0.5 * TILE_SIZE;

    double vd[] = {// Front Top Face
                   left, top - ph, 2.0 * pz,
                   right, top - ph, 2.0 * pz,
                   right, top, 2.0 * pz,
                   left, top, 2.0 * pz,

                   // Front Right Face
                   right - pw, bottom, 2.0 * pz,
                   right, bottom, 2.0 * pz,
                   right, top - ph, 2.0 * pz,
                   right - pw, top - ph, 2.0 * pz,

                   // Front Left Face
                   left, bottom, 2.0 * pz,
                   left + pw, bottom, 2.0 * pz,
                   left + pw, top - ph, 2.0 * pz,
                   left, top - ph, 2.0 * pz,

                   // Side Left Face
                   left + pw, bottom, 2.0 * pz,
                   left + pw, bottom, 1.0 * pz,
                   left + pw, top - ph, 1.0 * pz,
                   left + pw, top - ph, 2.0 * pz,

                   // Side Right Face
                   right - pw, bottom, 1.0 * pz,
                   right - pw, bottom, 2.0 * pz,
                   right - pw, top - ph, 2.0 * pz,
                   right - pw, top - ph, 1.0 * pz,

                   // Side Top Face
                   left + pw, top - ph, 1.0 * pz,
                   right - pw, top - ph, 1.0 * pz,
                   right - pw, top - ph, 2.0 * pz,
                   left + pw, top - ph, 2.0 * pz,
                   
                   // Back Top Face
                   right, top - ph, 1.0 * pz,
                   left, top - ph, 1.0 * pz,
                   left, top, 1.0 * pz,
                   right, top, 1.0 * pz,
                   
                   // Back Right Face
                   right, bottom, 1.0 * pz,
                   right - pw, bottom, 1.0 * pz,
                   right - pw, top - ph, 1.0 * pz,
                   right, top - ph, 1.0 * pz,
                   
                   // Back Left Face
                   left + pw, bottom, 1.0 * pz,
                   left, bottom, 1.0 * pz,
                   left, top - ph, 1.0 * pz,
                   left + pw, top - ph, 1.0 * pz
                  };

    std::vector<double> v(vd, vd + sizeof(vd) / sizeof(double));
    return v;
}
