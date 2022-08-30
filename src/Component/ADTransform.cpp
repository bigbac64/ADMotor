//
// Created by Antoine DESOBRY on 28/08/2022.
//
#include "Component/ADTransform.h"

/**
 * modifie la position d'un objet
 * @param pos position en point x, y, z
 **********************************************************************************************************************/
void ADTransform::setPostion(Point3D pos) {
    position = pos;
}

/**
 *
 * @return la position d'un objet
 **********************************************************************************************************************/
Point3D ADTransform::getPostion() {
    return position;
}

/**
 * modifie la taille d'un objet
 * @param sca taille en point x, y, z
 **********************************************************************************************************************/
void ADTransform::setScale(Point3D sca) {
    scale = sca;
}

/**
 *
 * @return la taille d'un objet
 **********************************************************************************************************************/
Point3D ADTransform::getScale() {
    return scale;
}

/**
 * modifie la rotation d'un objet
 * @param rot rotation en point x, y z
 **********************************************************************************************************************/
void ADTransform::setRotation(Point3D rot) {
    rotation = rot;
}

/**
 *
 * @return la rotation d'un objet
 **********************************************************************************************************************/
Point3D ADTransform::getRotation() {
    return rotation;
}

/**
 * replace tous les points à zéro
 **********************************************************************************************************************/
void ADTransform::reset() {
    position = Point3D{0,0,0};
    scale = Point3D{1,1,1};
    rotation = Point3D{0,0,0};
}


void ADTransform::init() {
    cout << "never init" <<endl;
    reset();
}




