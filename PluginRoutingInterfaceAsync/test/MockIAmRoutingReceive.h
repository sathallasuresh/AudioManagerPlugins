/**
 *  Copyright (c) 2012 BMW
 *
 *  \author Christian Linke, christian.linke@bmw.de BMW 2011,2012
 *
 *  \copyright
 *  Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction,
 *  including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so,
 *  subject to the following conditions:
 *  The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
 *  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 *  IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR
 *  THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 *  For further information see http://www.genivi.org/.
 */

#ifndef MOCKROUTINGINTERFACE_H_
#define MOCKROUTINGINTERFACE_H_

#include "IAmRouting.h"

namespace am {

class MockIAmRoutingReceive : public IAmRoutingReceive {
 public:
  MOCK_CONST_METHOD1(getInterfaceVersion,
      void(std::string& version));
  MOCK_METHOD3(ackConnect,
      void(const am_Handle_s handle, const am_connectionID_t connectionID, const am_Error_e error));
  MOCK_METHOD3(ackDisconnect,
      void(const am_Handle_s handle, const am_connectionID_t connectionID, const am_Error_e error));
  MOCK_METHOD3(ackSetSinkVolumeChange,
      void(const am_Handle_s handle, const am_volume_t volume, const am_Error_e error));
  MOCK_METHOD3(ackSetSourceVolumeChange,
      void(const am_Handle_s handle, const am_volume_t volume, const am_Error_e error));
  MOCK_METHOD2(ackSetSourceState,
      void(const am_Handle_s handle, const am_Error_e error));
  MOCK_METHOD2(ackSetSinkSoundProperties,
      void(const am_Handle_s handle, const am_Error_e error));
  MOCK_METHOD2(ackSetSinkSoundProperty,
      void(const am_Handle_s handle, const am_Error_e error));
  MOCK_METHOD2(ackSetSourceSoundProperties,
      void(const am_Handle_s handle, const am_Error_e error));
  MOCK_METHOD2(ackSetSourceSoundProperty,
      void(const am_Handle_s handle, const am_Error_e error));
  MOCK_METHOD3(ackCrossFading,
      void(const am_Handle_s handle, const am_HotSink_e hotSink, const am_Error_e error));
  MOCK_METHOD3(ackSourceVolumeTick,
      void(const am_Handle_s handle, const am_sourceID_t sourceID, const am_volume_t volume));
  MOCK_METHOD3(ackSinkVolumeTick,
      void(const am_Handle_s handle, const am_sinkID_t sinkID, const am_volume_t volume));
  MOCK_METHOD2(peekDomain,
      am_Error_e(const std::string& name, am_domainID_t& domainID));
  MOCK_METHOD2(registerDomain,
      am_Error_e(const am_Domain_s& domainData, am_domainID_t& domainID));
  MOCK_METHOD1(deregisterDomain,
      am_Error_e(const am_domainID_t domainID));
  MOCK_METHOD2(registerConverter,
      am_Error_e(const am_Converter_s& converterData, am_converterID_t& converterID));
  MOCK_METHOD2(registerGateway,
      am_Error_e(const am_Gateway_s& gatewayData, am_gatewayID_t& gatewayID));
  MOCK_METHOD1(deregisterConverter,
      am_Error_e(const am_converterID_t converterID));
  MOCK_METHOD1(deregisterGateway,
      am_Error_e(const am_gatewayID_t gatewayID));
  MOCK_METHOD2(peekSink,
      am_Error_e(const std::string& name, am_sinkID_t& sinkID));
  MOCK_METHOD2(registerSink,
      am_Error_e(const am_Sink_s& sinkData, am_sinkID_t& sinkID));
  MOCK_METHOD1(deregisterSink,
      am_Error_e(const am_sinkID_t sinkID));
  MOCK_METHOD2(peekSource,
      am_Error_e(const std::string& name, am_sourceID_t& sourceID));
  MOCK_METHOD2(registerSource,
      am_Error_e(const am_Source_s& sourceData, am_sourceID_t& sourceID));
  MOCK_METHOD1(deregisterSource,
      am_Error_e(const am_sourceID_t sourceID));
  MOCK_METHOD2(registerCrossfader,
      am_Error_e(const am_Crossfader_s& crossfaderData, am_crossfaderID_t& crossfaderID));
  MOCK_METHOD1(deregisterCrossfader,
      am_Error_e(const am_crossfaderID_t crossfaderID));
  MOCK_METHOD2(peekSourceClassID,
      am_Error_e(const std::string& name, am_sourceClass_t& sourceClassID));
  MOCK_METHOD2(peekSinkClassID,
      am_Error_e(const std::string& name, am_sinkClass_t& sinkClassID));
  MOCK_METHOD2(hookInterruptStatusChange,
      void(const am_sourceID_t sourceID, const am_InterruptState_e interruptState));
  MOCK_METHOD1(hookDomainRegistrationComplete,
      void(const am_domainID_t domainID));
  MOCK_METHOD2(hookSinkAvailablityStatusChange,
      void(const am_sinkID_t sinkID, const am_Availability_s& availability));
  MOCK_METHOD2(hookSourceAvailablityStatusChange,
      void(const am_sourceID_t sourceID, const am_Availability_s& availability));
  MOCK_METHOD2(hookDomainStateChange,
      void(const am_domainID_t domainID, const am_DomainState_e domainState));
  MOCK_METHOD2(hookTimingInformationChanged,
      void(const am_connectionID_t connectionID, const am_timeSync_t delay));
  MOCK_METHOD1(sendChangedData,
      void(const std::vector<am_EarlyData_s>& earlyData));
  MOCK_CONST_METHOD1(getDBusConnectionWrapper,
      am_Error_e(CAmDbusWrapper*& dbusConnectionWrapper));
  MOCK_CONST_METHOD1(getSocketHandler,
      am_Error_e(CAmSocketHandler*& socketHandler));
  MOCK_METHOD2(confirmRoutingReady,
      void(const uint16_t handle, const am_Error_e error));
  MOCK_METHOD2(confirmRoutingRundown,
      void(const uint16_t handle, const am_Error_e error));
  MOCK_METHOD4(updateConverter,
      am_Error_e(const am_converterID_t converterID, const std::vector<am_CustomConnectionFormat_t>& listSourceFormats, const std::vector<am_CustomConnectionFormat_t>& listSinkFormats, const std::vector<bool>& convertionMatrix));
  MOCK_METHOD4(updateGateway,
      am_Error_e(const am_gatewayID_t gatewayID, const std::vector<am_CustomConnectionFormat_t>& listSourceFormats, const std::vector<am_CustomConnectionFormat_t>& listSinkFormats, const std::vector<bool>& convertionMatrix));
  MOCK_METHOD5(updateSink,
      am_Error_e(const am_sinkID_t sinkID, const am_sinkClass_t sinkClassID, const std::vector<am_SoundProperty_s>& listSoundProperties, const std::vector<am_CustomConnectionFormat_t>& listConnectionFormats, const std::vector<am_MainSoundProperty_s>& listMainSoundProperties));
  MOCK_METHOD5(updateSource,
      am_Error_e(const am_sourceID_t sourceID, const am_sourceClass_t sourceClassID, const std::vector<am_SoundProperty_s>& listSoundProperties, const std::vector<am_CustomConnectionFormat_t>& listConnectionFormats, const std::vector<am_MainSoundProperty_s>& listMainSoundProperties));
  MOCK_METHOD3(ackSetVolumes,
      void(const am_Handle_s handle, const std::vector<am_Volumes_s>& listvolumes, const am_Error_e error));
  MOCK_METHOD2(ackSinkNotificationConfiguration,
      void(const am_Handle_s handle, const am_Error_e error));
  MOCK_METHOD2(ackSourceNotificationConfiguration,
      void(const am_Handle_s handle, const am_Error_e error));
  MOCK_METHOD2(hookSinkNotificationDataChange,
      void(const am_sinkID_t sinkID, const am_NotificationPayload_s& payload));
  MOCK_METHOD2(hookSourceNotificationDataChange,
      void(const am_sourceID_t sourceID, const am_NotificationPayload_s& payload));
  MOCK_CONST_METHOD2(getDomainOfSink,
      am_Error_e(const am_sinkID_t sinkID, am_domainID_t& domainID));
  MOCK_CONST_METHOD2(getDomainOfSource,
      am_Error_e(const am_sourceID_t sourceID, am_domainID_t& domainID));
  MOCK_CONST_METHOD2(getDomainOfCrossfader,
      am_Error_e(const am_crossfaderID_t crossfader, am_domainID_t& domainID));
};


}  // namespace am
#endif /* MOCKROUTINGINTERFACE_H_ */
