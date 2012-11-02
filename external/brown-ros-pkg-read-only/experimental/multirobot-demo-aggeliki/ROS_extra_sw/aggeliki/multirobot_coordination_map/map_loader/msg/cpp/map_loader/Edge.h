/* auto-generated by genmsg_cpp from /opt/ros/boxturtle/ros/aggeliki/map_loader/msg/Edge.msg.  Do not edit! */
#ifndef MAP_LOADER_EDGE_H
#define MAP_LOADER_EDGE_H

#include <string>
#include <vector>
#include "ros/message.h"
#include "ros/debug.h"
#include "ros/assert.h"
#include "ros/time.h"

namespace map_loader
{

//! \htmlinclude Edge.msg.html

class Edge : public ros::Message
{
public:
  typedef boost::shared_ptr<Edge> Ptr;
  typedef boost::shared_ptr<Edge const> ConstPtr;

  typedef uint32_t _node1_id_type;
  typedef uint32_t _node2_id_type;
  typedef int32_t _distance_type;

  uint32_t node1_id;
  uint32_t node2_id;
  int32_t distance;

  Edge() : ros::Message(),
    node1_id(0),
    node2_id(0),
    distance(0)
  {
  }
  Edge(const Edge &copy) : ros::Message(),
    node1_id(copy.node1_id),
    node2_id(copy.node2_id),
    distance(copy.distance)
  {
    (void)copy;
  }
  Edge &operator =(const Edge &copy)
  {
    if (this == &copy)
      return *this;
    node1_id = copy.node1_id;
    node2_id = copy.node2_id;
    distance = copy.distance;
    return *this;
  }
  virtual ~Edge() 
  {
  }
  inline static std::string __s_getDataType() { return std::string("map_loader/Edge"); }
  inline static std::string __s_getMD5Sum() { return std::string("60ed6c4b8ed538ed87bc9c74b47d243a"); }
  inline static std::string __s_getMessageDefinition()
  {
    return std::string(
    "uint32 node1_id\n"
    "uint32 node2_id\n"
    "int32 distance\n"
    "\n"
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
    __l += 4; // node1_id
    __l += 4; // node2_id
    __l += 4; // distance
    return __l;
  }
  virtual uint8_t *serialize(uint8_t *write_ptr,
#if defined(__GNUC__)
                             __attribute__((unused)) uint32_t seq) const
#else
                             uint32_t seq) const
#endif
  {
    SROS_SERIALIZE_PRIMITIVE(write_ptr, node1_id);
    SROS_SERIALIZE_PRIMITIVE(write_ptr, node2_id);
    SROS_SERIALIZE_PRIMITIVE(write_ptr, distance);
    return write_ptr;
  }
  virtual uint8_t *deserialize(uint8_t *read_ptr)
  {
    SROS_DESERIALIZE_PRIMITIVE(read_ptr, node1_id);
    SROS_DESERIALIZE_PRIMITIVE(read_ptr, node2_id);
    SROS_DESERIALIZE_PRIMITIVE(read_ptr, distance);
    return read_ptr;
  }
};

typedef boost::shared_ptr<Edge> EdgePtr;
typedef boost::shared_ptr<Edge const> EdgeConstPtr;


}

#endif
