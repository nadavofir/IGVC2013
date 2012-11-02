////////////////////////////////////////////////////////////////////////////////////
///
///  \file queryservices.cpp
///  \brief This file contains the implementation of a JAUS message.
///
///  <br>Author(s): Daniel Barber
///  <br>Created: 11 November 2009
///  <br>Copyright (c) 2009
///  <br>Applied Cognition and Training in Immersive Virtual Environments
///  <br>(ACTIVE) Laboratory
///  <br>Institute for Simulation and Training (IST)
///  <br>University of Central Florida (UCF)
///  <br>All rights reserved.
///  <br>Email: dbarber@ist.ucf.edu
///  <br>Web:  http://active.ist.ucf.edu
///
///  Redistribution and use in source and binary forms, with or without
///  modification, are permitted provided that the following conditions are met:
///      * Redistributions of source code must retain the above copyright
///        notice, this list of conditions and the following disclaimer.
///      * Redistributions in binary form must reproduce the above copyright
///        notice, this list of conditions and the following disclaimer in the
///        documentation and/or other materials provided with the distribution.
///      * Neither the name of the ACTIVE LAB, IST, UCF, nor the
///        names of its contributors may be used to endorse or promote products
///        derived from this software without specific prior written permission.
/// 
///  THIS SOFTWARE IS PROVIDED BY THE ACTIVE LAB''AS IS'' AND ANY
///  EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
///  WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
///  DISCLAIMED. IN NO EVENT SHALL UCF BE LIABLE FOR ANY
///  DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
///  (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
///  LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
///  ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
///  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
///  SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
///
////////////////////////////////////////////////////////////////////////////////////
#include "jaus/core/discovery/queryservices.h"

using namespace JAUS;

////////////////////////////////////////////////////////////////////////////////////
///
///   \brief Constructor, initializes default values.
///
///   \param[in] src Source ID of message sender.
///   \param[in] dest Destination ID of message.
///
////////////////////////////////////////////////////////////////////////////////////
QueryServices::QueryServices(const Address& dest,
                             const Address& src) : Message(QUERY_SERVICES, dest, src)
{
}


////////////////////////////////////////////////////////////////////////////////////
///
///   \brief Copy constructor.
///
////////////////////////////////////////////////////////////////////////////////////
QueryServices::QueryServices(const QueryServices& message) : Message(QUERY_SERVICES)
{
    *this = message;
}


////////////////////////////////////////////////////////////////////////////////////
///
///   \brief Destructor.
///
////////////////////////////////////////////////////////////////////////////////////
QueryServices::~QueryServices()
{

}


////////////////////////////////////////////////////////////////////////////////////
///
///   \brief Writes message payload to the packet.
///
///   Message contents are written to the packet following the JAUS standard.
///
///   \param[out] packet Packet to write payload to.
///
///   \return -1 on error, otherwise number of bytes written.
///
////////////////////////////////////////////////////////////////////////////////////
int QueryServices::WriteMessageBody(Packet& packet) const
{
    int total = 0;
    int expected = BYTE_SIZE;
    Byte count = (Byte)mNodeList.size();
    total += packet.WriteByte(count);
    
    List::const_iterator node;
    for(node = mNodeList.begin();
        node != mNodeList.end();
        node++)
    {        
        expected += BYTE_SIZE*2;
        Byte count2 = (Byte)node->second.size();
        total += packet.Write(node->first);
        total += packet.Write(count2);

        std::vector<Byte>::const_iterator component;
        for(component = node->second.begin();
            component != node->second.end();
            component++)
        {
            expected += BYTE_SIZE;
            total += packet.Write(*component);
        }
    }

    return total == expected ? total : -1;
}


////////////////////////////////////////////////////////////////////////////////////
///
///   \brief Reads message payload from the packet.
///
///   Message contents are read from the packet following the JAUS standard.
///
///   \param[in] packet Packet containing message payload data to read.
///
///   \return -1 on error, otherwise number of bytes written.
///
////////////////////////////////////////////////////////////////////////////////////
int QueryServices::ReadMessageBody(const Packet& packet) 
{
    int total = 0;
    int expected = BYTE_SIZE;
    Byte count = 0;

    total += packet.Read(count);
    
    for(Byte i = 0; i < count; i++)
    {        
        expected += BYTE_SIZE*2;
        Byte node = 0, count2 = 0;
        std::vector<Byte> components;

        total += packet.Read(node);
        total += packet.Read(count2);        

        for(Byte j = 0; j < count2; j++)
        {
            expected += BYTE_SIZE;
            Byte component = 0;
            total += packet.Read(component);
            components.push_back(component);
        }
        mNodeList[node] = components;
    }

    return total == expected ? total : -1;
}


////////////////////////////////////////////////////////////////////////////////////
///
///   \brief Clears message payload data.
///
////////////////////////////////////////////////////////////////////////////////////
void QueryServices::ClearMessageBody()
{
    mNodeList.clear();
}



////////////////////////////////////////////////////////////////////////////////////
///
///   \brief Sets equal to.
///
////////////////////////////////////////////////////////////////////////////////////
QueryServices& QueryServices::operator =(const QueryServices& message)
{
    if(this != &message)
    {
        CopyHeaderData(&message);
        mNodeList = message.mNodeList;
    }
    return *this;
}


/*  End of File */
