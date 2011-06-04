#include "RawByteBuffer.h"
#include <stdlib.h>
#include <iostream>
using namespace std;

RawByteBuffer::RawByteBuffer() : value(*(new ByteArray))
{
}

RawByteBuffer::RawByteBuffer(ByteArray& valueToSet) : value(valueToSet)
{
}

RawByteBuffer::~RawByteBuffer()
{
}

void RawByteBuffer::operator=(const SerializableObject& objectToCopy)
    {
    const RawByteBuffer* castReference = dynamic_cast<const RawByteBuffer*>(&objectToCopy);
    value = castReference->value;
    }

uint64_t RawByteBuffer::serialize(void** destinationBuffer)
    {
    uint64_t size = sizeof(uint64_t) + value.getLength();
    *destinationBuffer = malloc(size);
    *((uint64_t*)(*destinationBuffer)) = value.getLength();
    for(int i = 0; i < value.getLength(); i++)
        {
        *(((byte*)(*destinationBuffer))+sizeof(uint64_t)+i) = value[i];
        }
    return size;
    }

void RawByteBuffer::deserialize(void* bufferToUse)
{
    cout << "Il buffer da appendere è lungo " << *((uint64_t*)bufferToUse) << " bytes" << endl;
    value.erase();
    value.append((byte*)bufferToUse,sizeof(uint64_t), *((uint64_t*)bufferToUse));
}
