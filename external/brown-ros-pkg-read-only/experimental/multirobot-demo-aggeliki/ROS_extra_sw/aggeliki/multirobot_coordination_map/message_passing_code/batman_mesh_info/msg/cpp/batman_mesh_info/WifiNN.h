/* auto-generated by genmsg_cpp from /opt/ros/boxturtle/ros/aggeliki/message_passing_code/batman_mesh_info/msg/WifiNN.msg.  Do not edit! */
#ifndef BATMAN_MESH_INFO_WIFINN_H
#define BATMAN_MESH_INFO_WIFINN_H

#include <string>
#include <vector>
#include "ros/message.h"
#include "ros/debug.h"
#include "ros/assert.h"
#include "ros/time.h"

namespace batman_mesh_info
{

//! \htmlinclude WifiNN.msg.html

class WifiNN : public ros::Message
{
public:
  typedef boost::shared_ptr<WifiNN> Ptr;
  typedef boost::shared_ptr<WifiNN const> ConstPtr;

  typedef std::string _ip_type;
  typedef uint32_t _quality_type;

  std::string ip;
  uint32_t quality;

  WifiNN() : ros::Message(),
    quality(0)
  {
  }
  WifiNN(const WifiNN &copy) : ros::Message(),
    ip(copy.ip),
    quality(copy.quality)
  {
    (void)copy;
  }
  WifiNN &operator =(const WifiNN &copy)
  {
    if (this == &copy)
      return *this;
    ip = copy.ip;
    quality = copy.quality;
    return *this;
  }
  virtual ~WifiNN() 
  {
  }
  inline static std::string __s_getDataType() { return std::string("batman_mesh_info/WifiNN"); }
  inline static std::string __s_getMD5Sum() { return std::string("52868941085aea3ab1ea77d0d88e5d2d"); }
  inline static std::string __s_getMessageDefinition()
  {
    return std::string(
    "string ip\n"
    "uint32 quality\n"
    "\n"
    "\n"
    );
  }
  inline virtual const std::string __getDataType() const { return __s_getDataType(); }
  inline virtual const std::string __getMD5Sum() const { return __s_getMD5Sum(); }
  inline virtual const std::string __getMessageDefinition() const { return __s_getMessageDefinition(); }
  inline uint32_t serializationLength() const
  {
    unsigned __l = 0;
    __l += 4 + ip.length(); // ip
    __l += 4; // quality
    return __l;
  }
  virtual uint8_t *serialize(uint8_t *write_ptr,
#if defined(__GNUC__)
                             __attribute__((unused)) uint32_t seq) const
#else
                             uint32_t seq) const
#endif
  {
    unsigned __ros_ip_len = ip.length();
    SROS_SERIALIZE_PRIMITIVE(write_ptr, __ros_ip_len);
    SROS_SERIALIZE_BUFFER(write_ptr, ip.c_str(), __ros_ip_len);
    SROS_SERIALIZE_PRIMITIVE(write_ptr, quality);
    return write_ptr;
  }
  virtual uint8_t *deserialize(uint8_t *read_ptr)
  {
    unsigned __ros_ip_len;
    SROS_DESERIALIZE_PRIMITIVE(read_ptr, __ros_ip_len);
    ip = std::string((const char *)read_ptr, __ros_ip_len);
    read_ptr += __ros_ip_len;
    SROS_DESERIALIZE_PRIMITIVE(read_ptr, quality);
    return read_ptr;
  }
};

typedef boost::shared_ptr<WifiNN> WifiNNPtr;
typedef boost::shared_ptr<WifiNN const> WifiNNConstPtr;


}

#endif
