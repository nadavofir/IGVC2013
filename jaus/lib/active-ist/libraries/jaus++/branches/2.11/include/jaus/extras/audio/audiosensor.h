////////////////////////////////////////////////////////////////////////////////////
///
///  \file audiosensor.h
///  \brief Contains the Audio Sensor Service implementation.
///
///  <br>Author(s): Daniel Barber
///  Created: 5 July 2010
///  Copyright (c) 2010
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
#ifndef __JAUS_EXTRAS_AUDIO_AUDIO_SENSOR__H
#define __JAUS_EXTRAS_AUDIO_AUDIO_SENSOR__H

#include "jaus/core/events/events.h"
#include "jaus/core/sensor.h"
#include "jaus/extras/audio/reportaudio.h"
#include "jaus/extras/audio/queryaudio.h"

namespace JAUS
{
    typedef ReportAudio Audio;

    ////////////////////////////////////////////////////////////////////////////////////
    ///
    ///   \class AudioSensor
    ///   \brief This service provides a means to share audio data
    ///          captured from a sound source (e.g. microphone).
    ///
    ////////////////////////////////////////////////////////////////////////////////////
    class JAUS_EXTRAS_DLL AudioSensor : public Sensor, public Events::Child
    {
    public:
        const static std::string Name; ///< String name of the Service.
        // Constructor.
        AudioSensor();
        // Destructor.
        ~AudioSensor();
        // Set a sample of audio data from a device.
        virtual bool SetAudioSample(const Byte deviceID,
                                    const Audio::Format format,
                                    const int frequency,
                                    const Packet& audioBuffer,
                                    const Time& timestamp = Time(true));
        Audio GetAudioSample(const int deviceID = -1) const;
        // Method called when an Event has been signaled, generates an Event message.
        virtual bool GenerateEvent(const Events::Subscription& info) const;
        // Method called to determine if an Event is supported by the service.
        virtual bool IsEventSupported(const Events::Type type,
                                      const double requestedPeriodicRate,
                                      const Message* queryMessage,
                                      double& confirmedPeriodicRate,
                                      std::string& errorMessage) const;
        // Audio Sensor is always discoverable.
        virtual bool IsDiscoverable() const { return true; }
        // Processes messages associated with the Audio Sensor Services.
        virtual void Receive(const Message* message);
        // Creates messages associated with the Audio Sensor Service.
        virtual Message* CreateMessage(const UShort messageCode) const;
    private:
        virtual void CheckServiceSynchronization(const unsigned int timeSinceLastCheckMs);
        Mutex mAudioSensorMutex;                ///< Mutex for thread protection of data.
        std::map<Byte, Audio> mAudioData;       ///< Audio data.
    };
}

#endif
/*  End of File */
