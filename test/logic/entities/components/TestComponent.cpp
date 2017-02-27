/*
 * TestComponent.cpp
 *
 *  Created on: 5 feb. 2017
 *      Author: hedu
 */

#include "TestComponent.h"

TestComponent::TestComponent() {
	// TODO Auto-generated constructor stub

}

TestComponent::~TestComponent() {
	// TODO Auto-generated destructor stub
}

void TestComponent::init() {
	std::cout << "Init method: "<< std::endl;
}

void TestComponent::update(const float millis) {
	std::cout << "Update method: " << millis << std::endl;
}
