//
// Created by Antoine DESOBRY on 28/08/2022.
//
#include "Component/ADTransform.h"

/**
 * modifie la position d'un objet
 * @param pos position en point x, y, z
 **********************************************************************************************************************/
void ADTransformTest::setPostion(Point3D pos) {
    position = pos;
}

/**
 *
 * @return la position d'un objet
 **********************************************************************************************************************/
Point3D ADTransformTest::getPostion() {
    return position;
}

/**
 * modifie la taille d'un objet
 * @param sca taille en point x, y, z
 **********************************************************************************************************************/
void ADTransformTest::setScale(Point3D sca) {
    scale = sca;
}

/**
 *
 * @return la taille d'un objet
 **********************************************************************************************************************/
Point3D ADTransformTest::getScale() {
    return scale;
}

/**
 * modifie la rotation d'un objet
 * @param rot rotation en point x, y z
 **********************************************************************************************************************/
void ADTransformTest::setRotation(Point3D rot) {
    rotation = rot;
}

/**
 *
 * @return la rotation d'un objet
 **********************************************************************************************************************/
Point3D ADTransformTest::getRotation() {
    return rotation;
}

/**
 * replace tous les points à zéro
 **********************************************************************************************************************/
void ADTransformTest::reset() {
    position = Point3D{0,0,0};
    scale = Point3D{0,0,0};
    rotation = Point3D{0,0,0};
}


void ADTransformTest::init() {
    reset();
}




