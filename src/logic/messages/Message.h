/*
 * Message.h
 *
 *  Created on: 24 feb. 2017
 *      Author: hedu
 */

#ifndef LOGIC_MESSAGES_MESSAGE_H_
#define LOGIC_MESSAGES_MESSAGE_H_

namespace kingdoms {

class Entity;

class Message {
public:
	Message(Entity *e);
	virtual ~Message();

private:
	Entity *_origin;
};

} /* namespace kingdoms */

#endif /* LOGIC_MESSAGES_MESSAGE_H_ */
