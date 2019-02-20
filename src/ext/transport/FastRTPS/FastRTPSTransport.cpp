﻿// -*- C++ -*-
/*!
 * @file  FastRTPSOutPort.cpp
 * @brief FastRTPSOutPort class
 * @date  $Date: 2019-01-31 03:08:03 $
 * @author Nobuhiko Miyamoto <n-miyamoto@aist.go.jp>
 *
 * Copyright (C) 2019
 *     Nobuhiko Miyamoto
 *     Robot Innovation Research Center,
 *     National Institute of
 *         Advanced Industrial Science and Technology (AIST), Japan
 *
 *     All rights reserved.
 *
 *
 */


#include "FastRTPSTransport.h"



extern "C"
{
  /*!
   * @if jp
   * @brief モジュール初期化関数
   * @else
   * @brief Module initialization
   * @endif
   */
  void FastRTPSTransportInit(RTC::Manager* manager)
  {
    (void)manager;
    {
        
      RTC::InPortProviderFactory& factory(RTC::InPortProviderFactory::instance());
      factory.addFactory("fast-rtps",
                        ::coil::Creator< ::RTC::InPortProvider,
                                          ::RTC::FastRTPSInPort>,
                        ::coil::Destructor< ::RTC::InPortProvider,
                                            ::RTC::FastRTPSInPort>);
    }

    {
      RTC::InPortConsumerFactory& factory(RTC::InPortConsumerFactory::instance());
      factory.addFactory("fast-rtps",
                        ::coil::Creator< ::RTC::InPortConsumer,
                                          ::RTC::FastRTPSOutPort>,
                        ::coil::Destructor< ::RTC::InPortConsumer,
                                            ::RTC::FastRTPSOutPort>);
    }
    
  }
  
};


