﻿// -*- C++ -*-

/*!
 * @file  FastRTPSInPort.cpp
 * @brief FastRTPSInPort class
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


#include "FastRTPSInPort.h"
#include <coil/UUID.h>
#include <fastrtps/participant/Participant.h>
#include <fastrtps/attributes/ParticipantAttributes.h>
#include <fastrtps/attributes/SubscriberAttributes.h>
#include <fastrtps/Domain.h>
#include "FastRTPSManager.h"
#include "FastRTPSMessageInfo.h"

using namespace eprosima::fastrtps;
using namespace eprosima::fastrtps::rtps;




#ifdef WIN32
#pragma warning( disable : 4290 )
#endif



namespace RTC
{
  /*!
   * @if jp
   * @brief コンストラクタ
   * @else
   * @brief Constructor
   * @endif
   */
  FastRTPSInPort::FastRTPSInPort(void)
   : m_buffer(0), m_listener(this)
  {
    // PortProfile setting
    setInterfaceType("fast-rtps");
    // ConnectorProfile setting

  }

  

  /*!
   * @if jp
   * @brief デストラクタ
   * @else
   * @brief Destructor
   * @endif
   */
  FastRTPSInPort::~FastRTPSInPort(void)
  {
    RTC_PARANOID(("~FastRTPSInPort()"));

    if (m_subscriber != nullptr)
    {
        Domain::removeSubscriber(m_subscriber);
    }

  }


  /*!
   * @if jp
   * @brief 設定初期化
   *
   * 
   * @param prop 設定情報
   *
   * @else
   *
   * @brief Initializing configuration
   *
   *
   * @param prop Configuration information
   *
   * @endif
   */
  void FastRTPSInPort::init(coil::Properties& prop)
  {
      
    RTC_PARANOID(("FastRTPSInPort::init()"));

    if(prop.propertyNames().size() == 0)
    {
      RTC_DEBUG(("Property is empty."));
      return;
    }

    FastRTPSManager& topicmgr = FastRTPSManager::instance();
    
    

    std::string marshaling_type = prop.getProperty("marshaling_type", "corba");
    m_topic = prop.getProperty("topic", "chatter");
    

    if (marshaling_type != "corba")
    {
        FastRTPSMessageInfoBase* info = FastRTPSMessageInfoFactory::instance().createObject(marshaling_type);

        if (!info)
        {
            RTC_ERROR(("Can not find message type(%s)", marshaling_type.c_str()));
            return;
        }

        m_dataType = info->data_type();
        m_topic = info->topic_name(m_topic);

        FastRTPSMessageInfoFactory::instance().deleteObject(info);
    }
    else
    {
        m_dataType = prop.getProperty("data_type", "RTC::CDR_Data");
    }
    

    Participant* paticipant = topicmgr.getParticipant();


    //m_roscorehost = prop.getProperty("roscore_host", "localhost");
    //std::string tmp_port = prop.getProperty("roscore_port", "11311");
    //coil::stringTo<unsigned int>(m_roscoreport, tmp_port.c_str());



    //RTC_VERBOSE(("topic name: %s", m_topic.c_str()));
    //RTC_VERBOSE(("roscore address: %s:%d", m_roscorehost.c_str(), m_roscoreport));

    if(paticipant == nullptr)
    {
        return;
    }

    

    //std::cout << m_type.getName() << "\t" << m_topic << std::endl;



    m_type.init(m_dataType);

    topicmgr.registerType(&m_type);


    SubscriberAttributes Rparam;
    Rparam.topic.topicKind = NO_KEY;
    Rparam.topic.topicDataType = m_type.getName();
    Rparam.topic.topicName = m_topic;
    m_subscriber = Domain::createSubscriber(paticipant,Rparam,(SubscriberListener*)&m_listener);
    if(m_subscriber == nullptr)
    {
        return;
    }

    

  }


  /*!
   * @if jp
   * @brief バッファをセットする
   * @else
   * @brief Setting outside buffer's pointer
   * @endif
   */
  void FastRTPSInPort::
  setBuffer(BufferBase<ByteData>* buffer)
  {
    m_buffer = buffer;
  }

  /*!
   * @if jp
   * @brief リスナを設定する
   * @else
   * @brief Set the listener
   * @endif
   */
  void FastRTPSInPort::setListener(ConnectorInfo& info,
                                           ConnectorListeners* listeners)
  {
    m_profile = info;
    m_listeners = listeners;
  }

  /*!
   * @if jp
   * @brief Connectorを設定する。
   * @else
   * @brief set Connector
   * @endif
   */
  void FastRTPSInPort::setConnector(InPortConnector* connector)
  {
    m_connector = connector;
  }

  /*!
   * @if jp
   * @brief 受信データをバッファに書き込む
   *
   *
   *
   * @param cdr データ
   *
   * @else
   * @brief
   *
   * @param cdr
   *
   *
   * @endif
   */
  void FastRTPSInPort::put(ByteData& cdr)
  {
      RTC_PARANOID(("FastRTPSInPort::put()"));
      RTC_VERBOSE(("read data length:%d", cdr.getDataLength()));
      if (m_connector == NULL)
      {
          onReceiverError(cdr);
      }
      else
      {
          onReceived(cdr);
          BufferStatus::Enum ret = m_connector->write(cdr);
          switch (ret)
          {
          case BufferStatus::BUFFER_OK:
              RTC_VERBOSE(("BUFFER_OK"));
              break;
          case BufferStatus::BUFFER_EMPTY:
              RTC_ERROR(("BUFFER_EMPTY"));
              break;
          case BufferStatus::TIMEOUT:
              RTC_ERROR(("TIMEOUT"));
              break;
          case BufferStatus::PRECONDITION_NOT_MET:
              RTC_ERROR(("PRECONDITION_NOT_MET"));
          default:
              RTC_ERROR(("PORT_ERROR"));
          }
      }

  }

  /*!
   * @if jp
   * @brief コンストラクタ
   *
   * コンストラクタ
   *
   * @else
   * @brief Constructor
   *
   * Constructor
   *
   * @endif
   */
  FastRTPSInPort::SubListener::SubListener(FastRTPSInPort* provider) : rtclog("FastRTPSInPort::SubListener"), m_provider(provider)
  {
  }

  /*!
   * @if jp
   * @brief デストラクタ
   *
   * デストラクタ
   *
   * @else
   * @brief Destructor
   *
   * Destructor
   *
   * @endif
   */
  FastRTPSInPort::SubListener::~SubListener()
  {
  }

  /*!
   * @if jp
   * @brief
   *
   * 同じトピックのPublisherを検出したときのコールバック関数
   *
   * @param sub Subscriber
   * @param info 一致情報
   *
   * @else
   * @brief
   *
   * @param sub
   * @param info
   *
   *
   * @endif
   */
  void FastRTPSInPort::SubListener::onSubscriptionMatched(eprosima::fastrtps::Subscriber* sub, eprosima::fastrtps::rtps::MatchingInfo& info)
  {
      (void)sub;
      (void)info;
  }

  /*!
   * @if jp
   * @brief
   *
   * 新規にメッセージを取得したときのコールバック関数
   *
   * @param sub Subscriber
   *
   * @else
   * @brief
   *
   * @param sub
   *
   *
   * @endif
   */
  void FastRTPSInPort::SubListener::onNewDataMessage(Subscriber* sub)
  {
    RTC_PARANOID(("~onNewDataMessage()"));

    RTC::ByteData st;
		
    RTC_PARANOID(("takeNextData"));
    if(sub->takeNextData(&st, &m_info))
    {
      if(m_info.sampleKind == ALIVE)
      {
          m_provider->put(st);
      }
    }
  }


  /*!
  * @if jp
  * @brief リターンコード変換
  * @else
  * @brief Return codes conversion
  * @endif
  */
  void
  FastRTPSInPort::convertReturn(BufferStatus::Enum status,
	    ByteData& data)
  {
      switch (status)
      {
        case BufferStatus::BUFFER_OK:
            onBufferWrite(data);
            break;

        case BufferStatus::BUFFER_ERROR:
            onReceiverError(data);
            break;

        case BufferStatus::BUFFER_FULL:
            onBufferFull(data);
            onReceiverFull(data);
            break;

        case BufferStatus::BUFFER_EMPTY:
            // never come here
            break;

        case BufferStatus::PRECONDITION_NOT_MET:
            onReceiverError(data);
            break;

        case BufferStatus::TIMEOUT:
            onBufferWriteTimeout(data);
            onReceiverTimeout(data);
            break;
    }
    onReceiverError(data);
  }

};     // namespace RTC
