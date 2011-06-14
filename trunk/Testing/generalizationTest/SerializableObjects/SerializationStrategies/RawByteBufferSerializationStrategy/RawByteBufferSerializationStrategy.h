#ifndef RAWBYTEBUFFER_SERIALIZATION_STRATEGY_H
#define RAWBYTEBUFFER_SERIALIZATION_STRATEGY_H

#include "../../SerializableObject.h"
#include "../../Utilities/ByteArray/ByteArray.h"
#include "../../TypeConstants.h"
#include "../../GenericSerializableReferenceLayer/GenericSerializableReferenceLayer.h"

class RawByteBufferSerializationStrategy : public GenericSerializableReferenceLayer<ByteArray>
{
    public:
        RawByteBufferSerializationStrategy();
        RawByteBufferSerializationStrategy(ByteArray& userReferenceToSet);
        Type getType();
        int getValueLengthLength();
        uint64_t serialize(void** destinationBuffer);
        void deserialize(uint64_t length, void* bufferToUse);
};

typedef RawByteBufferSerializationStrategy RawByteBuffer;

#endif // RAWBYTEBUFFER_SERIALIZATION_STRATEGY_H
