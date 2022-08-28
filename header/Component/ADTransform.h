//
// Created by Antoine DESOBRY on 28/08/2022.
//

#ifndef ADMOTOR_ADTRANSFORM_H
#define ADMOTOR_ADTRANSFORM_H

#include "ADComponent.h"
#include "Structure/Point3D.h"

class ADTransform: public ADComponent{
private:
    Point3D position;
    Point3D scale;
    Point3D rotation;

public:
    void setPostion(Point3D);
    Point3D getPostion();
    void setScale(Point3D);
    Point3D getScale();
    void setRotation(Point3D);
    Point3D getRotation();
    void reset();

    void init() override;

};

#endif //ADMOTOR_ADTRANSFORM_H
