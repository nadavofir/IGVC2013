/* Auto-generated by genmsg_cpp for file /home/ras/IGVC2013/external/brown-ros-pkg-read-only/distribution/brown_drivers/irobot_create_2_1/srv/Demo.srv */
#ifndef IROBOT_CREATE_2_1_SERVICE_DEMO_H
#define IROBOT_CREATE_2_1_SERVICE_DEMO_H
#include <string>
#include <vector>
#include <map>
#include <ostream>
#include "ros/serialization.h"
#include "ros/builtin_message_traits.h"
#include "ros/message_operations.h"
#include "ros/time.h"

#include "ros/macros.h"

#include "ros/assert.h"

#include "ros/service_traits.h"




namespace irobot_create_2_1
{
template <class ContainerAllocator>
struct DemoRequest_ {
  typedef DemoRequest_<ContainerAllocator> Type;

  DemoRequest_()
  : demo(0)
  {
  }

  DemoRequest_(const ContainerAllocator& _alloc)
  : demo(0)
  {
  }

  typedef uint8_t _demo_type;
  uint8_t demo;


  typedef boost::shared_ptr< ::irobot_create_2_1::DemoRequest_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::irobot_create_2_1::DemoRequest_<ContainerAllocator>  const> ConstPtr;
  boost::shared_ptr<std::map<std::string, std::string> > __connection_header;
}; // struct DemoRequest
typedef  ::irobot_create_2_1::DemoRequest_<std::allocator<void> > DemoRequest;

typedef boost::shared_ptr< ::irobot_create_2_1::DemoRequest> DemoRequestPtr;
typedef boost::shared_ptr< ::irobot_create_2_1::DemoRequest const> DemoRequestConstPtr;


template <class ContainerAllocator>
struct DemoResponse_ {
  typedef DemoResponse_<ContainerAllocator> Type;

  DemoResponse_()
  : success(false)
  {
  }

  DemoResponse_(const ContainerAllocator& _alloc)
  : success(false)
  {
  }

  typedef uint8_t _success_type;
  uint8_t success;


  typedef boost::shared_ptr< ::irobot_create_2_1::DemoResponse_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::irobot_create_2_1::DemoResponse_<ContainerAllocator>  const> ConstPtr;
  boost::shared_ptr<std::map<std::string, std::string> > __connection_header;
}; // struct DemoResponse
typedef  ::irobot_create_2_1::DemoResponse_<std::allocator<void> > DemoResponse;

typedef boost::shared_ptr< ::irobot_create_2_1::DemoResponse> DemoResponsePtr;
typedef boost::shared_ptr< ::irobot_create_2_1::DemoResponse const> DemoResponseConstPtr;

struct Demo
{

typedef DemoRequest Request;
typedef DemoResponse Response;
Request request;
Response response;

typedef Request RequestType;
typedef Response ResponseType;
}; // struct Demo
} // namespace irobot_create_2_1

namespace ros
{
namespace message_traits
{
template<class ContainerAllocator> struct IsMessage< ::irobot_create_2_1::DemoRequest_<ContainerAllocator> > : public TrueType {};
template<class ContainerAllocator> struct IsMessage< ::irobot_create_2_1::DemoRequest_<ContainerAllocator>  const> : public TrueType {};
template<class ContainerAllocator>
struct MD5Sum< ::irobot_create_2_1::DemoRequest_<ContainerAllocator> > {
  static const char* value() 
  {
    return "38cce318410d78a3661e585adc1dbcfa";
  }

  static const char* value(const  ::irobot_create_2_1::DemoRequest_<ContainerAllocator> &) { return value(); } 
  static const uint64_t static_value1 = 0x38cce318410d78a3ULL;
  static const uint64_t static_value2 = 0x661e585adc1dbcfaULL;
};

template<class ContainerAllocator>
struct DataType< ::irobot_create_2_1::DemoRequest_<ContainerAllocator> > {
  static const char* value() 
  {
    return "irobot_create_2_1/DemoRequest";
  }

  static const char* value(const  ::irobot_create_2_1::DemoRequest_<ContainerAllocator> &) { return value(); } 
};

template<class ContainerAllocator>
struct Definition< ::irobot_create_2_1::DemoRequest_<ContainerAllocator> > {
  static const char* value() 
  {
    return "uint8 demo\n\
\n\
";
  }

  static const char* value(const  ::irobot_create_2_1::DemoRequest_<ContainerAllocator> &) { return value(); } 
};

template<class ContainerAllocator> struct IsFixedSize< ::irobot_create_2_1::DemoRequest_<ContainerAllocator> > : public TrueType {};
} // namespace message_traits
} // namespace ros


namespace ros
{
namespace message_traits
{
template<class ContainerAllocator> struct IsMessage< ::irobot_create_2_1::DemoResponse_<ContainerAllocator> > : public TrueType {};
template<class ContainerAllocator> struct IsMessage< ::irobot_create_2_1::DemoResponse_<ContainerAllocator>  const> : public TrueType {};
template<class ContainerAllocator>
struct MD5Sum< ::irobot_create_2_1::DemoResponse_<ContainerAllocator> > {
  static const char* value() 
  {
    return "358e233cde0c8a8bcfea4ce193f8fc15";
  }

  static const char* value(const  ::irobot_create_2_1::DemoResponse_<ContainerAllocator> &) { return value(); } 
  static const uint64_t static_value1 = 0x358e233cde0c8a8bULL;
  static const uint64_t static_value2 = 0xcfea4ce193f8fc15ULL;
};

template<class ContainerAllocator>
struct DataType< ::irobot_create_2_1::DemoResponse_<ContainerAllocator> > {
  static const char* value() 
  {
    return "irobot_create_2_1/DemoResponse";
  }

  static const char* value(const  ::irobot_create_2_1::DemoResponse_<ContainerAllocator> &) { return value(); } 
};

template<class ContainerAllocator>
struct Definition< ::irobot_create_2_1::DemoResponse_<ContainerAllocator> > {
  static const char* value() 
  {
    return "bool success\n\
\n\
\n\
";
  }

  static const char* value(const  ::irobot_create_2_1::DemoResponse_<ContainerAllocator> &) { return value(); } 
};

template<class ContainerAllocator> struct IsFixedSize< ::irobot_create_2_1::DemoResponse_<ContainerAllocator> > : public TrueType {};
} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

template<class ContainerAllocator> struct Serializer< ::irobot_create_2_1::DemoRequest_<ContainerAllocator> >
{
  template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
  {
    stream.next(m.demo);
  }

  ROS_DECLARE_ALLINONE_SERIALIZER;
}; // struct DemoRequest_
} // namespace serialization
} // namespace ros


namespace ros
{
namespace serialization
{

template<class ContainerAllocator> struct Serializer< ::irobot_create_2_1::DemoResponse_<ContainerAllocator> >
{
  template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
  {
    stream.next(m.success);
  }

  ROS_DECLARE_ALLINONE_SERIALIZER;
}; // struct DemoResponse_
} // namespace serialization
} // namespace ros

namespace ros
{
namespace service_traits
{
template<>
struct MD5Sum<irobot_create_2_1::Demo> {
  static const char* value() 
  {
    return "ba6bc2ba3d93bab324b9d12a59c0df25";
  }

  static const char* value(const irobot_create_2_1::Demo&) { return value(); } 
};

template<>
struct DataType<irobot_create_2_1::Demo> {
  static const char* value() 
  {
    return "irobot_create_2_1/Demo";
  }

  static const char* value(const irobot_create_2_1::Demo&) { return value(); } 
};

template<class ContainerAllocator>
struct MD5Sum<irobot_create_2_1::DemoRequest_<ContainerAllocator> > {
  static const char* value() 
  {
    return "ba6bc2ba3d93bab324b9d12a59c0df25";
  }

  static const char* value(const irobot_create_2_1::DemoRequest_<ContainerAllocator> &) { return value(); } 
};

template<class ContainerAllocator>
struct DataType<irobot_create_2_1::DemoRequest_<ContainerAllocator> > {
  static const char* value() 
  {
    return "irobot_create_2_1/Demo";
  }

  static const char* value(const irobot_create_2_1::DemoRequest_<ContainerAllocator> &) { return value(); } 
};

template<class ContainerAllocator>
struct MD5Sum<irobot_create_2_1::DemoResponse_<ContainerAllocator> > {
  static const char* value() 
  {
    return "ba6bc2ba3d93bab324b9d12a59c0df25";
  }

  static const char* value(const irobot_create_2_1::DemoResponse_<ContainerAllocator> &) { return value(); } 
};

template<class ContainerAllocator>
struct DataType<irobot_create_2_1::DemoResponse_<ContainerAllocator> > {
  static const char* value() 
  {
    return "irobot_create_2_1/Demo";
  }

  static const char* value(const irobot_create_2_1::DemoResponse_<ContainerAllocator> &) { return value(); } 
};

} // namespace service_traits
} // namespace ros

#endif // IROBOT_CREATE_2_1_SERVICE_DEMO_H

