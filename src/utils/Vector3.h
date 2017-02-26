/*
 * Vector3.h
 *
 *  Created on: 14 feb. 2017
 *      Author: hedu
 */

#ifndef UTILS_VECTOR3_H_
#define UTILS_VECTOR3_H_

class Vector3 {
public:
	double _x, _y, _z;

public:
	Vector3();
	Vector3(double x, double y, double z);
	Vector3(const Vector3& v);
	virtual ~Vector3();

	static const Vector3 ZERO;
};

#endif /* UTILS_VECTOR3_H_ */
