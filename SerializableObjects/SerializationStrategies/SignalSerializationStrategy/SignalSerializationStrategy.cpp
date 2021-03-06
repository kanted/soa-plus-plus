#include "SignalSerializationStrategy.h"
#include <stdlib.h>

SignalSerializationStrategy::SignalSerializationStrategy() {}

Type Signal::getType() const
{
    return SERIALIZABLE_SIGNAL;
}

uint64_t Signal::serialize(void** destinationBuffer)
{
    int size = sizeof(uint8_t) + 2*sizeof(Type);
    *destinationBuffer = malloc(size);
    *((Type*)(*destinationBuffer)) = getType();
    *((uint8_t*)(((Type*)(*destinationBuffer))+1)) = sizeof(Type);
    *((Type*)(((uint8_t*)(((Type*)(*destinationBuffer))+1))+1)) = this->getSignalType();
    return size;
}

void Signal::deserialize(uint64_t length, void* bufferToUse)
{
	// Il campo value viene già gestito nel builder
    this->signalHandler();
}

string SignalSerializationStrategy::getValueTypeStringRepresentation()
{
    return "signal";
}
