#include "HoleModel.h"
#include "GlobalConstants.h"

HoleModel::HoleModel(int textureRow, int textureCol, double height) {
    this->textureRow = textureRow;
    this->textureCol = textureCol;
    this->height = height;
}

HoleModel::~HoleModel() {

}

std::vector<int> HoleModel::getFaces() {
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

                13, 13, 0,
                14, 14, 0,
                12, 12, 0,
                15, 15, 0,

                17, 17, 1,
                18, 18, 1,
                16, 16, 1,
                19, 19, 1,

                21, 21, 2,
                22, 22, 2,
                20, 20, 2,
                23, 23, 2,

                25, 25, 3,
                26, 26, 3,
                24, 24, 3,
                27, 27, 3,

                29, 29, 4,
                30, 30, 4,
                28, 28, 4,
                31, 31, 4
               };

    std::vector<int> f(fd, fd + sizeof(fd) / sizeof(int));
    return f;
}

std::vector<double> HoleModel::getNormals() {
    double vnd[] = { 0.0,  1.0,  0.0,
                     0.0,  0.0,  1.0,
                     1.0,  0.0,  0.0,
                    -1.0,  0.0,  0.0,
                     0.0,  0.0, -1.0
                   };

    std::vector<double> vn(vnd, vnd + sizeof(vnd) / sizeof(double));
    return vn;
}

std::vector<double> HoleModel::getUVs() {
    double pw = 1.0 / TEX_IMAGE_TILE_WIDTH;
    double ph = 1.0 / TEX_IMAGE_TILE_HEIGHT;

    double tileWidth = TEX_TILE_WIDTH * pw;
    double tileHeight = TEX_TILE_HEIGHT * ph;

    double hJump = tileWidth + 2 * pw;
    double vJump = tileHeight + 2 * ph;

    double uOffset = (hJump * textureCol) + pw;
    double vOffset = 1.0 - (vJump * (textureRow + 1)) + ph;
    
    double ufOffset = (hJump * 1) + pw;
    double vfOffset = 1.0 - (vJump * (textureRow + 1)) + ph;

    double vtd[] = {// Back Floor
                    ufOffset, vfOffset + tileHeight - ph,
                    ufOffset + tileWidth, vfOffset + tileHeight - ph,
                    ufOffset + tileWidth, vfOffset + tileHeight,
                    ufOffset, vfOffset + tileHeight,
                    
                    // Left Floor
                    ufOffset, vfOffset + ph,
                    ufOffset + pw, vfOffset + ph,
                    ufOffset + pw, vfOffset + tileHeight - ph,
                    ufOffset, vfOffset + tileHeight - ph,
                    
                    // Right Floor
                    ufOffset + tileWidth - pw, vfOffset + ph,
                    ufOffset + tileWidth, vfOffset + ph,
                    ufOffset + tileWidth, vfOffset + tileHeight - ph,
                    ufOffset + tileWidth - pw, vfOffset + tileHeight - ph,
                    
                    // Front Floor
                    ufOffset, vfOffset,
                    ufOffset + tileWidth, vfOffset,
                    ufOffset + tileWidth, vfOffset + ph,
                    ufOffset, vfOffset + ph,
                    
                    // Back Face
                    uOffset + pw, vOffset,
                    uOffset + tileWidth - pw, vOffset,
                    uOffset + tileWidth - pw, vOffset + tileHeight,
                    uOffset + pw, vOffset + tileHeight,
                    
                    // Left Face
                    uOffset + pw, vOffset,
                    uOffset + tileWidth - pw, vOffset,
                    uOffset + tileWidth - pw, vOffset + tileHeight,
                    uOffset + pw, vOffset + tileHeight,

                    // Right Face
                    uOffset + pw, vOffset,
                    uOffset + tileWidth - pw, vOffset,
                    uOffset + tileWidth - pw, vOffset + tileHeight,
                    uOffset + pw, vOffset + tileHeight,

                    // Front Face
                    uOffset + pw, vOffset,
                    uOffset + tileWidth - pw, vOffset,
                    uOffset + tileWidth - pw, vOffset + tileHeight,
                    uOffset + pw, vOffset + tileHeight
                   };

    std::vector<double> vt(vtd, vtd + sizeof(vtd) / sizeof(double));
    return vt;
}

std::vector<double> HoleModel::getVertices() {
    double pw = TILE_SIZE / 16.0;
    double pz = TILE_SIZE / 16.0;

    double left = -0.5 * TILE_SIZE;
    double right = 0.5 * TILE_SIZE;

    double back = -0.5 * TILE_SIZE;
    double front = 0.5 * TILE_SIZE;

    double vd[] = {// Back Floor
        left, height, back + pz,
        right, height, back + pz,
        right, height, back,
        left, height, back,

        // Left Floor
        left, height, front - pz,
        left + pw, height, front - pz,
        left + pw, height, back + pz,
        left, height, back + pz,

        // Right Floor
        right - pw, height, front - pz,
        right, height, front - pz,
        right, height, back + pz,
        right - pw, height, back + pz,

        // Front Floor
        left, height, front,
        right, height, front,
        right, height, front - pz,
        left, height, front - pz,

        // Back Wall
        left + pw, height - TILE_SIZE, back + pz,
        right - pw, height - TILE_SIZE, back + pz,
        right - pw, height, back + pz,
        left + pw, height, back + pz,

        // Left Wall
        left + pw, height - TILE_SIZE, front - pz,
        left + pw, height - TILE_SIZE, back + pz,
        left + pw, height, back + pz,
        left + pw, height, front - pz,

        // Right Wall
        right - pw, height - TILE_SIZE, back + pz,
        right - pw, height - TILE_SIZE, front - pz,
        right - pw, height, front - pz,
        right - pw, height, back + pz,

        // Front Wall
        right - pw, height - TILE_SIZE, front - pz,
        left + pw, height - TILE_SIZE, front - pz,
        left + pw, height, front - pz,
        right - pw, height, front - pz
    };

    std::vector<double> v(vd, vd + sizeof(vd) / sizeof(double));
    return v;
}
