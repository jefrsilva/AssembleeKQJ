#include "Model.h"

#include "Engine.h"

void Model::render() {
    std::vector<double> v = getVertices();
    std::vector<double> vn = getNormals();
    std::vector<double> vt = getUVs();

    std::vector<int> f = getFaces();

    int fSize = f.size();
    for (int fi = 0; fi < fSize; fi += 12) {
        glBegin(GL_TRIANGLE_STRIP);

        glTexCoord2d(vt[f[fi + 1] * 2 + 0],
                     vt[f[fi + 1] * 2 + 1]);
        glNormal3d(vn[f[fi + 2] * 3 + 0],
                   vn[f[fi + 2] * 3 + 1],
                   vn[f[fi + 2] * 3 + 2]);
        glVertex3d(v[f[fi + 0] * 3 + 0],
                   v[f[fi + 0] * 3 + 1],
                   v[f[fi + 0] * 3 + 2]);

        glTexCoord2d(vt[f[fi + 4] * 2 + 0],
                     vt[f[fi + 4] * 2 + 1]);
        glNormal3d(vn[f[fi + 5] * 3 + 0],
                   vn[f[fi + 5] * 3 + 1],
                   vn[f[fi + 5] * 3 + 2]);
        glVertex3d(v[f[fi + 3] * 3 + 0],
                   v[f[fi + 3] * 3 + 1],
                   v[f[fi + 3] * 3 + 2]);

        glTexCoord2d(vt[f[fi + 7] * 2 + 0],
                     vt[f[fi + 7] * 2 + 1]);
        glNormal3d(vn[f[fi + 8] * 3 + 0],
                   vn[f[fi + 8] * 3 + 1],
                   vn[f[fi + 8] * 3 + 2]);
        glVertex3d(v[f[fi + 6] * 3 + 0],
                   v[f[fi + 6] * 3 + 1],
                   v[f[fi + 6] * 3 + 2]);

        glTexCoord2d(vt[f[fi + 10] * 2 + 0],
                     vt[f[fi + 10] * 2 + 1]);
        glNormal3d(vn[f[fi + 11] * 3 + 0],
                   vn[f[fi + 11] * 3 + 1],
                   vn[f[fi + 11] * 3 + 2]);
        glVertex3d(v[f[fi + 9] * 3 + 0],
                   v[f[fi + 9] * 3 + 1],
                   v[f[fi + 9] * 3 + 2]);
                   
        glEnd();
    }
}
