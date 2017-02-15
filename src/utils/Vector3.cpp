/*
 * Vector3.cpp
 *
 *  Created on: 15 feb. 2017
 *      Author: hedu
 */

#include "Vector3.h"

Vector3::Vector3(): _x(0), _y(0), _z(0) {}

Vector3::Vector3(double x, double y, double z): _x(x), _y(y), _z(z) {}

Vector3::Vector3( const Vector3& v): _x(v._x), _y(v._y), _z(v._z) {}

Vector3::~Vector3() {}

Vector3 const Vector3::ZERO = Vector3();


