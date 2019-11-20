/*
* Copyright (c) 2018-present, aliminabc@gmail.com.
*
* This source code is licensed under the MIT license found in the
* LICENSE file in the root directory of this source tree.
*/

#ifndef HWVC_ANDROID_ALIMAGELAYER_H
#define HWVC_ANDROID_ALIMAGELAYER_H

#include "Object.h"
#include "AlImageCanvas.h"
#include "HwAbsTexture.h"

al_class(AlImageLayer) {
public:
public:
    static AlImageLayer *create(HwAbsTexture *tex);

public:
    ~AlImageLayer();

    void draw(AlImageCanvas *canvas);

private:
    AlImageLayer(HwAbsTexture *tex);

    AlImageLayer(const AlImageLayer &e) : Object() {};

private:
    HwAbsTexture *tex;
};


#endif //HWVC_ANDROID_ALIMAGELAYER_H
