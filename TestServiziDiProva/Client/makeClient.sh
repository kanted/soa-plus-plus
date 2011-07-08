g++ -g client.cpp ../../TcpIpSocket/TcpIp*.cpp ../../TcpIpSocket/TcpIpPassiveSocket/*.cpp ../../TcpIpSocket/TcpIpActiveSocket/*.cpp ../../SerializableObjects/SerializationStrategies/IntegerSerializationStrategy/*.cpp ../../ObjectInterfaces/SerializableObject/*.cpp ../../SerializableObjects/DeserializationStrategies/*.cpp ../../SerializableObjects/Utilities/ByteArray/*.cpp ../../SerializableObjects/SerializationStrategies/RealSerializationStrategy/*.cpp ../../SerializableObjects/SerializationStrategies/RawByteBufferSerializationStrategy/*.cpp ../../SerializableObjects/SerializationStrategies/StringSerializationStrategy/*.cpp ../../SerializableObjects/SerializationStrategies/SignalSerializationStrategy/*.cpp ../../SerializableObjects/SerializationStrategies/SignalSerializationStrategy/ParticularSignals/BadRequestSerializationStrategy/*.cpp ../../SerializableObjects/SerializationStrategies/SignalSerializationStrategy/ParticularSignals/GenericSignalSerializationStrategy/*.cpp ../../ServiceOrientedArchitecture/Service/*.cpp ../../ServiceOrientedArchitecture/Service/Stub/*.cpp ../../ServiceOrientedArchitecture/Service/Stub/StreamStub/*.cpp ../../Utilities/RegularExpressionChecker/*.cpp -Wall -lboost_thread -lpthread -lboost_regex -o client
