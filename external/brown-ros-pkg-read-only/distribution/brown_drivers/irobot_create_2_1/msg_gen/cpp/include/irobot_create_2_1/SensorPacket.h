/* Auto-generated by genmsg_cpp for file /home/ras/IGVC2013/external/brown-ros-pkg-read-only/distribution/brown_drivers/irobot_create_2_1/msg/SensorPacket.msg */
#ifndef IROBOT_CREATE_2_1_MESSAGE_SENSORPACKET_H
#define IROBOT_CREATE_2_1_MESSAGE_SENSORPACKET_H
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

#include "std_msgs/Header.h"

namespace irobot_create_2_1
{
template <class ContainerAllocator>
struct SensorPacket_ {
  typedef SensorPacket_<ContainerAllocator> Type;

  SensorPacket_()
  : header()
  , wheeldropCaster(false)
  , wheeldropLeft(false)
  , wheeldropRight(false)
  , bumpLeft(false)
  , bumpRight(false)
  , wall(false)
  , cliffLeft(false)
  , cliffFronLeft(false)
  , cliffFrontRight(false)
  , cliffRight(false)
  , virtualWall(false)
  , infraredByte(0)
  , advance(false)
  , play(false)
  , distance(0)
  , angle(0)
  , chargingState(0)
  , voltage(0)
  , current(0)
  , batteryTemperature(0)
  , batteryCharge(0)
  , batteryCapacity(0)
  , wallSignal(0)
  , cliffLeftSignal(0)
  , cliffFrontLeftSignal(0)
  , cliffFrontRightSignal(0)
  , cliffRightSignal(0)
  , homeBase(false)
  , internalCharger(false)
  , songNumber(0)
  , songPlaying(0)
  {
  }

  SensorPacket_(const ContainerAllocator& _alloc)
  : header(_alloc)
  , wheeldropCaster(false)
  , wheeldropLeft(false)
  , wheeldropRight(false)
  , bumpLeft(false)
  , bumpRight(false)
  , wall(false)
  , cliffLeft(false)
  , cliffFronLeft(false)
  , cliffFrontRight(false)
  , cliffRight(false)
  , virtualWall(false)
  , infraredByte(0)
  , advance(false)
  , play(false)
  , distance(0)
  , angle(0)
  , chargingState(0)
  , voltage(0)
  , current(0)
  , batteryTemperature(0)
  , batteryCharge(0)
  , batteryCapacity(0)
  , wallSignal(0)
  , cliffLeftSignal(0)
  , cliffFrontLeftSignal(0)
  , cliffFrontRightSignal(0)
  , cliffRightSignal(0)
  , homeBase(false)
  , internalCharger(false)
  , songNumber(0)
  , songPlaying(0)
  {
  }

  typedef  ::std_msgs::Header_<ContainerAllocator>  _header_type;
   ::std_msgs::Header_<ContainerAllocator>  header;

  typedef uint8_t _wheeldropCaster_type;
  uint8_t wheeldropCaster;

  typedef uint8_t _wheeldropLeft_type;
  uint8_t wheeldropLeft;

  typedef uint8_t _wheeldropRight_type;
  uint8_t wheeldropRight;

  typedef uint8_t _bumpLeft_type;
  uint8_t bumpLeft;

  typedef uint8_t _bumpRight_type;
  uint8_t bumpRight;

  typedef uint8_t _wall_type;
  uint8_t wall;

  typedef uint8_t _cliffLeft_type;
  uint8_t cliffLeft;

  typedef uint8_t _cliffFronLeft_type;
  uint8_t cliffFronLeft;

  typedef uint8_t _cliffFrontRight_type;
  uint8_t cliffFrontRight;

  typedef uint8_t _cliffRight_type;
  uint8_t cliffRight;

  typedef uint8_t _virtualWall_type;
  uint8_t virtualWall;

  typedef uint8_t _infraredByte_type;
  uint8_t infraredByte;

  typedef uint8_t _advance_type;
  uint8_t advance;

  typedef uint8_t _play_type;
  uint8_t play;

  typedef int16_t _distance_type;
  int16_t distance;

  typedef int16_t _angle_type;
  int16_t angle;

  typedef uint8_t _chargingState_type;
  uint8_t chargingState;

  typedef uint16_t _voltage_type;
  uint16_t voltage;

  typedef int16_t _current_type;
  int16_t current;

  typedef int8_t _batteryTemperature_type;
  int8_t batteryTemperature;

  typedef uint16_t _batteryCharge_type;
  uint16_t batteryCharge;

  typedef uint16_t _batteryCapacity_type;
  uint16_t batteryCapacity;

  typedef uint16_t _wallSignal_type;
  uint16_t wallSignal;

  typedef uint16_t _cliffLeftSignal_type;
  uint16_t cliffLeftSignal;

  typedef uint16_t _cliffFrontLeftSignal_type;
  uint16_t cliffFrontLeftSignal;

  typedef uint16_t _cliffFrontRightSignal_type;
  uint16_t cliffFrontRightSignal;

  typedef uint16_t _cliffRightSignal_type;
  uint16_t cliffRightSignal;

  typedef uint8_t _homeBase_type;
  uint8_t homeBase;

  typedef uint8_t _internalCharger_type;
  uint8_t internalCharger;

  typedef uint8_t _songNumber_type;
  uint8_t songNumber;

  typedef uint8_t _songPlaying_type;
  uint8_t songPlaying;


  typedef boost::shared_ptr< ::irobot_create_2_1::SensorPacket_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::irobot_create_2_1::SensorPacket_<ContainerAllocator>  const> ConstPtr;
  boost::shared_ptr<std::map<std::string, std::string> > __connection_header;
}; // struct SensorPacket
typedef  ::irobot_create_2_1::SensorPacket_<std::allocator<void> > SensorPacket;

typedef boost::shared_ptr< ::irobot_create_2_1::SensorPacket> SensorPacketPtr;
typedef boost::shared_ptr< ::irobot_create_2_1::SensorPacket const> SensorPacketConstPtr;


template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const  ::irobot_create_2_1::SensorPacket_<ContainerAllocator> & v)
{
  ros::message_operations::Printer< ::irobot_create_2_1::SensorPacket_<ContainerAllocator> >::stream(s, "", v);
  return s;}

} // namespace irobot_create_2_1

namespace ros
{
namespace message_traits
{
template<class ContainerAllocator> struct IsMessage< ::irobot_create_2_1::SensorPacket_<ContainerAllocator> > : public TrueType {};
template<class ContainerAllocator> struct IsMessage< ::irobot_create_2_1::SensorPacket_<ContainerAllocator>  const> : public TrueType {};
template<class ContainerAllocator>
struct MD5Sum< ::irobot_create_2_1::SensorPacket_<ContainerAllocator> > {
  static const char* value() 
  {
    return "56f92e8d70d283e7e15aa47855e73ea7";
  }

  static const char* value(const  ::irobot_create_2_1::SensorPacket_<ContainerAllocator> &) { return value(); } 
  static const uint64_t static_value1 = 0x56f92e8d70d283e7ULL;
  static const uint64_t static_value2 = 0xe15aa47855e73ea7ULL;
};

template<class ContainerAllocator>
struct DataType< ::irobot_create_2_1::SensorPacket_<ContainerAllocator> > {
  static const char* value() 
  {
    return "irobot_create_2_1/SensorPacket";
  }

  static const char* value(const  ::irobot_create_2_1::SensorPacket_<ContainerAllocator> &) { return value(); } 
};

template<class ContainerAllocator>
struct Definition< ::irobot_create_2_1::SensorPacket_<ContainerAllocator> > {
  static const char* value() 
  {
    return "Header header\n\
bool wheeldropCaster\n\
bool wheeldropLeft\n\
bool wheeldropRight\n\
bool bumpLeft\n\
bool bumpRight\n\
bool wall\n\
bool cliffLeft\n\
bool cliffFronLeft\n\
bool cliffFrontRight\n\
bool cliffRight\n\
bool virtualWall\n\
uint8 infraredByte\n\
bool advance\n\
bool play\n\
int16 distance\n\
int16 angle\n\
uint8 chargingState\n\
uint16 voltage\n\
int16 current\n\
int8 batteryTemperature\n\
uint16 batteryCharge\n\
uint16 batteryCapacity\n\
uint16 wallSignal\n\
uint16 cliffLeftSignal\n\
uint16 cliffFrontLeftSignal\n\
uint16 cliffFrontRightSignal\n\
uint16 cliffRightSignal\n\
bool homeBase\n\
bool internalCharger\n\
uint8 songNumber\n\
uint8 songPlaying\n\
\n\
================================================================================\n\
MSG: std_msgs/Header\n\
# Standard metadata for higher-level stamped data types.\n\
# This is generally used to communicate timestamped data \n\
# in a particular coordinate frame.\n\
# \n\
# sequence ID: consecutively increasing ID \n\
uint32 seq\n\
#Two-integer timestamp that is expressed as:\n\
# * stamp.secs: seconds (stamp_secs) since epoch\n\
# * stamp.nsecs: nanoseconds since stamp_secs\n\
# time-handling sugar is provided by the client library\n\
time stamp\n\
#Frame this data is associated with\n\
# 0: no frame\n\
# 1: global frame\n\
string frame_id\n\
\n\
";
  }

  static const char* value(const  ::irobot_create_2_1::SensorPacket_<ContainerAllocator> &) { return value(); } 
};

template<class ContainerAllocator> struct HasHeader< ::irobot_create_2_1::SensorPacket_<ContainerAllocator> > : public TrueType {};
template<class ContainerAllocator> struct HasHeader< const ::irobot_create_2_1::SensorPacket_<ContainerAllocator> > : public TrueType {};
} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

template<class ContainerAllocator> struct Serializer< ::irobot_create_2_1::SensorPacket_<ContainerAllocator> >
{
  template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
  {
    stream.next(m.header);
    stream.next(m.wheeldropCaster);
    stream.next(m.wheeldropLeft);
    stream.next(m.wheeldropRight);
    stream.next(m.bumpLeft);
    stream.next(m.bumpRight);
    stream.next(m.wall);
    stream.next(m.cliffLeft);
    stream.next(m.cliffFronLeft);
    stream.next(m.cliffFrontRight);
    stream.next(m.cliffRight);
    stream.next(m.virtualWall);
    stream.next(m.infraredByte);
    stream.next(m.advance);
    stream.next(m.play);
    stream.next(m.distance);
    stream.next(m.angle);
    stream.next(m.chargingState);
    stream.next(m.voltage);
    stream.next(m.current);
    stream.next(m.batteryTemperature);
    stream.next(m.batteryCharge);
    stream.next(m.batteryCapacity);
    stream.next(m.wallSignal);
    stream.next(m.cliffLeftSignal);
    stream.next(m.cliffFrontLeftSignal);
    stream.next(m.cliffFrontRightSignal);
    stream.next(m.cliffRightSignal);
    stream.next(m.homeBase);
    stream.next(m.internalCharger);
    stream.next(m.songNumber);
    stream.next(m.songPlaying);
  }

  ROS_DECLARE_ALLINONE_SERIALIZER;
}; // struct SensorPacket_
} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::irobot_create_2_1::SensorPacket_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const  ::irobot_create_2_1::SensorPacket_<ContainerAllocator> & v) 
  {
    s << indent << "header: ";
s << std::endl;
    Printer< ::std_msgs::Header_<ContainerAllocator> >::stream(s, indent + "  ", v.header);
    s << indent << "wheeldropCaster: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.wheeldropCaster);
    s << indent << "wheeldropLeft: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.wheeldropLeft);
    s << indent << "wheeldropRight: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.wheeldropRight);
    s << indent << "bumpLeft: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.bumpLeft);
    s << indent << "bumpRight: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.bumpRight);
    s << indent << "wall: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.wall);
    s << indent << "cliffLeft: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.cliffLeft);
    s << indent << "cliffFronLeft: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.cliffFronLeft);
    s << indent << "cliffFrontRight: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.cliffFrontRight);
    s << indent << "cliffRight: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.cliffRight);
    s << indent << "virtualWall: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.virtualWall);
    s << indent << "infraredByte: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.infraredByte);
    s << indent << "advance: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.advance);
    s << indent << "play: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.play);
    s << indent << "distance: ";
    Printer<int16_t>::stream(s, indent + "  ", v.distance);
    s << indent << "angle: ";
    Printer<int16_t>::stream(s, indent + "  ", v.angle);
    s << indent << "chargingState: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.chargingState);
    s << indent << "voltage: ";
    Printer<uint16_t>::stream(s, indent + "  ", v.voltage);
    s << indent << "current: ";
    Printer<int16_t>::stream(s, indent + "  ", v.current);
    s << indent << "batteryTemperature: ";
    Printer<int8_t>::stream(s, indent + "  ", v.batteryTemperature);
    s << indent << "batteryCharge: ";
    Printer<uint16_t>::stream(s, indent + "  ", v.batteryCharge);
    s << indent << "batteryCapacity: ";
    Printer<uint16_t>::stream(s, indent + "  ", v.batteryCapacity);
    s << indent << "wallSignal: ";
    Printer<uint16_t>::stream(s, indent + "  ", v.wallSignal);
    s << indent << "cliffLeftSignal: ";
    Printer<uint16_t>::stream(s, indent + "  ", v.cliffLeftSignal);
    s << indent << "cliffFrontLeftSignal: ";
    Printer<uint16_t>::stream(s, indent + "  ", v.cliffFrontLeftSignal);
    s << indent << "cliffFrontRightSignal: ";
    Printer<uint16_t>::stream(s, indent + "  ", v.cliffFrontRightSignal);
    s << indent << "cliffRightSignal: ";
    Printer<uint16_t>::stream(s, indent + "  ", v.cliffRightSignal);
    s << indent << "homeBase: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.homeBase);
    s << indent << "internalCharger: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.internalCharger);
    s << indent << "songNumber: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.songNumber);
    s << indent << "songPlaying: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.songPlaying);
  }
};


} // namespace message_operations
} // namespace ros

#endif // IROBOT_CREATE_2_1_MESSAGE_SENSORPACKET_H

