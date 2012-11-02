/* auto-generated by gensrv_cpp from /home/iscander/ros/projects/sogp_node/srv/Predict.srv.  Do not edit! */
#ifndef SRV_SOGP_NODE_PREDICT_H
#define SRV_SOGP_NODE_PREDICT_H

#include <string>
#include <cstring>
#include <vector>
#include <map>

#include "sogp_node/Vector.h"

#include "sogp_node/Vector.h"

namespace sogp_node
{

struct Predict
{

inline static std::string getDataType() { return "sogp_node/Predict"; }
inline static std::string getMD5Sum() { return "fba85ef2d1dc3a06205281f14b943df8"; }

//! \htmlinclude Request.msg.html

class Request : public ros::Message
{
public:
  typedef boost::shared_ptr<Request> Ptr;
  typedef boost::shared_ptr<Request const> ConstPtr;

  typedef sogp_node::Vector _predictor_type;

  sogp_node::Vector predictor;

  Request() : ros::Message()
  {
  }
  Request(const Request &copy) : ros::Message(),
    predictor(copy.predictor)
  {
    (void)copy;
  }
  Request &operator =(const Request &copy)
  {
    if (this == &copy)
      return *this;
    predictor = copy.predictor;
    return *this;
  }
  virtual ~Request() 
  {
  }
  inline static std::string __s_getDataType() { return std::string("sogp_node/PredictRequest"); }
  inline static std::string __s_getMD5Sum() { return std::string(""); }
  inline static std::string __s_getMessageDefinition()
  {
    return std::string(
    "Vector predictor\n"
    "\n"
    );
  }
  inline virtual const std::string __getDataType() const { return __s_getDataType(); }
  inline virtual const std::string __getMD5Sum() const { return __s_getMD5Sum(); }
  inline virtual const std::string __getMessageDefinition() const { return __s_getMessageDefinition(); }
  inline static std::string __s_getServerMD5Sum() { return std::string("fba85ef2d1dc3a06205281f14b943df8"); }
  inline virtual const std::string __getServerMD5Sum() const { return __s_getServerMD5Sum(); }
  inline static std::string __s_getServiceDataType() { return std::string("sogp_node/Predict"); }
  inline virtual const std::string __getServiceDataType() const { return __s_getServiceDataType(); }
  inline uint32_t serializationLength() const
  {
    unsigned __l = 0;
    __l += predictor.serializationLength(); // predictor
    return __l;
  }
  virtual uint8_t *serialize(uint8_t *write_ptr, uint32_t seq) const
  {
    write_ptr = predictor.serialize(write_ptr, seq);
    return write_ptr;
  }
  virtual uint8_t *deserialize(uint8_t *read_ptr)
  {
    read_ptr = predictor.deserialize(read_ptr);
    return read_ptr;
  }
};

typedef boost::shared_ptr<Request> RequestPtr;
typedef boost::shared_ptr<Request const> RequestConstPtr;

//! \htmlinclude Response.msg.html

class Response : public ros::Message
{
public:
  typedef boost::shared_ptr<Response> Ptr;
  typedef boost::shared_ptr<Response const> ConstPtr;

  typedef sogp_node::Vector _prediction_type;
  typedef std::string _error_msg_type;

  sogp_node::Vector prediction;
  std::string error_msg;

  Response() : ros::Message()
  {
  }
  Response(const Response &copy) : ros::Message(),
    prediction(copy.prediction),
    error_msg(copy.error_msg)
  {
    (void)copy;
  }
  Response &operator =(const Response &copy)
  {
    if (this == &copy)
      return *this;
    prediction = copy.prediction;
    error_msg = copy.error_msg;
    return *this;
  }
  virtual ~Response() 
  {
  }
  inline static std::string __s_getDataType() { return std::string("sogp_node/PredictResponse"); }
  inline static std::string __s_getMD5Sum() { return std::string(""); }
  inline static std::string __s_getMessageDefinition()
  {
    return std::string(
    "Vector prediction\n"
    "string error_msg\n"
    "================================================================================\n"
    "MSG: sogp_node/Vector\n"
    "float32[] data\n"
    "\n"
    "\n"
    );
  }
  inline virtual const std::string __getDataType() const { return __s_getDataType(); }
  inline virtual const std::string __getMD5Sum() const { return __s_getMD5Sum(); }
  inline virtual const std::string __getMessageDefinition() const { return __s_getMessageDefinition(); }
  inline static std::string __s_getServerMD5Sum() { return std::string("fba85ef2d1dc3a06205281f14b943df8"); }
  inline virtual const std::string __getServerMD5Sum() const { return __s_getServerMD5Sum(); }
  inline static std::string __s_getServiceDataType() { return std::string("sogp_node/Predict"); }
  inline virtual const std::string __getServiceDataType() const { return __s_getServiceDataType(); }
  inline uint32_t serializationLength() const
  {
    unsigned __l = 0;
    __l += prediction.serializationLength(); // prediction
    __l += 4 + error_msg.length(); // error_msg
    return __l;
  }
  virtual uint8_t *serialize(uint8_t *write_ptr, uint32_t seq) const
  {
    write_ptr = prediction.serialize(write_ptr, seq);
    unsigned __ros_error_msg_len = error_msg.length();
    SROS_SERIALIZE_PRIMITIVE(write_ptr, __ros_error_msg_len);
    SROS_SERIALIZE_BUFFER(write_ptr, error_msg.c_str(), __ros_error_msg_len);
    return write_ptr;
  }
  virtual uint8_t *deserialize(uint8_t *read_ptr)
  {
    read_ptr = prediction.deserialize(read_ptr);
    unsigned __ros_error_msg_len;
    SROS_DESERIALIZE_PRIMITIVE(read_ptr, __ros_error_msg_len);
    error_msg = std::string((const char *)read_ptr, __ros_error_msg_len);
    read_ptr += __ros_error_msg_len;
    return read_ptr;
  }
};

typedef boost::shared_ptr<Response> ResponsePtr;
typedef boost::shared_ptr<Response const> ResponseConstPtr;

Request request;
Response response;

};

}

#endif
