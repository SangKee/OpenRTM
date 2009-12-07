// -*- C++ -*-
/*!
 * @file PortCallback.h
 * @brief PortCallback class
 * @date $Date: 2007-12-31 03:08:05 $
 * @author Noriaki Ando <n-ando@aist.go.jp>
 *
 * Copyright (C) 2006-2008
 *     Noriaki Ando
 *     Task-intelligence Research Group,
 *     Intelligent Systems Research Institute,
 *     National Institute of
 *         Advanced Industrial Science and Technology (AIST), Japan
 *     All rights reserved.
 *
 * $Id$
 *
 */

#ifndef RTC_PORTCALLBACK_H
#define RTC_PORTCALLBACK_H

class cdrStream;

namespace RTC
{



  //============================================================
  // callback functor base classes
  /*!
   * @if jp
   * @class ConnectCallback
   * @brief connect/notify_connect() ���Υ�����Хå���ݥ��饹
   *
   * Port���Ф���connect/notify_connect() �����ƤӽФ������˸ƤӽФ����
   * ������Хå��ե��󥯥��������� RTC::ConnectorProfile ���롣
   *
   * @param profile ConnectorProfile
   *
   * @since 1.0.0
   *
   * @else
   * @class ConnectCallback
   * @brief Callback functor abstract for connect/notify_connect() funcs
   *
   * This is the interface for callback functor for connect/notify_connect()
   * invocation in Port. Argument is RTC::ConnectorProfile that is given
   * these functions.
   *
   * @param profile ConnectorProfile
   *
   * @since 1.0.0
   *
   * @endif
   */
  class ConnectionCallback
  {
  public:
    virtual ~ConnectionCallback(void){}
    virtual void operator()(RTC::ConnectorProfile& profile) = 0;
  };

  /*!
   * @if jp
   * @class DisconnectCallback
   * @brief disconnect/notify_disconnect() ���Υ�����Хå���ݥ��饹
   *
   * Port���Ф���disconnect/notify_disconnect() �����ƤӽФ������˸ƤӽФ����
   * ������Хå��ե��󥯥�����������³ID���롣
   *
   * @param connector_id Connector ID
   *
   * @since 1.0.0
   *
   * @else
   * @class DisconnectCallback
   * @brief Callback functor abstract for disconnect/notify_disconnect() funcs
   *
   * This is the interface for callback functor for 
   * disconnect/notify_disconnect() invocation in Port.
   * Argument is connector ID is given these functions.
   *
   * @param connector_id Connector ID
   *
   * @since 1.0.0
   *
   * @endif
   */
  class DisconnectCallback
  {
  public:
    virtual ~DisconnectCallback(void){}
    virtual void operator()(const char* connector_id) = 0;
  };

  /*!
   * @if jp
   * @class OnWrite
   * @brief write() ���Υ�����Хå���ݥ��饹
   *
   * OutPort���Ф��ƥǡ�����write()�����ľ���˸ƤӽФ���륳����Хå���
   * �ե��󥯥���
   *
   * @param DataType �Хåե��˽񤭹���ǡ�����
   *
   * @since 0.4.0
   *
   * @else
   * @class OnWrite
   * @brief Callback abstract class on write()
   *
   * This is the interface for callback invoked immediately before
   * data is done write() into the DataPort's buffer.
   *
   * @param DataType Data type to write into the buffer
   *
   * @since 0.4.0
   *
   * @endif
   */
  template <class DataType>
  class OnWrite
  {
  public:
    virtual ~OnWrite(void){}
    
    /*!
     * @if jp
     *
     * @brief ������Хå��ؿ�
     *
     * �Хåե��˥ǡ������񤭹��ޤ��ľ���˸ƤӽФ���륳����Хå��ؿ�
     *
     * @param value �Хåե��˽񤭹��ޤ��ǡ���
     *
     * @else
     *
     * @brief Callback method
     *
     * This is the callback method invoked immediately before data is written
     * into the buffer.
     *
     * @param value Data that is written into the buffer
     *
     * @endif
     */
    virtual void operator()(const DataType& value) = 0;
  };
  
  /*!
   * @if jp
   * @class OnWriteConvert
   * @brief write() ���Υǡ����Ѵ�������Хå���ݥ��饹
   *
   * InPort/OutPort�ΥХåե��˥ǡ����� write()�������˸ƤӽФ����
   * ������Хå��ѥ��󥿡��ե�������
   * ���Υ�����Хå�������ͤ��Хåե��˳�Ǽ����롣
   *
   * @since 0.4.0
   *
   * @else
   * @class OnWriteConvert
   * @brief Data convert callback abstract class on write()
   *
   * This is the interface for callback invoked when data is done write()
   * into the InPort/OutPort's buffer.
   * The return value of this callback will be stored in the buffer.
   *
   * @since 0.4.0
   *
   * @endif
   */
  template <class DataType>
  struct OnWriteConvert
  {
    virtual ~OnWriteConvert(void){}
    
    /*!
     * @if jp
     *
     * @brief ������Хå��᥽�å�
     *
     * �Хåե��˥ǡ������񤭹��ޤ��ݤ˸ƤӽФ���륳����Хå��᥽�å�
     *
     * @param value �Ѵ����ǡ���
     *
     * @return �Ѵ���ǡ���
     *
     * @else
     *
     * @brief Callback method
     *
     * This is the callback method invoked when data is written into the
     * buffer.
     *
     * @param value Data before the convert
     *
     * @return Data after the convert
     *
     * @endif
     */
    virtual DataType operator()(const DataType& value) = 0;
  };
  
  /*!
   * @if jp
   * @class OnRead
   * @brief read() ���Υ�����Хå���ݥ��饹
   *
   * InPort/OutPort�ΥХåե�����ǡ����� read()�����ľ���˸ƤӽФ����
   * ������Хå��ѥ��󥿡��ե�������
   *
   * @since 0.4.0
   *
   * @else
   * @class OnRead
   * @brief Callback abstract class on read()
   *
   * This is the interface for callback invoked immediately before
   * data is done read() from the InPort/OutPort's buffer.
   *
   * @since 0.4.0
   *
   * @endif
   */
  template <class DataType>
  struct OnRead
  {
    /*!
     * @if jp
     *
     * @brief �ǥ��ȥ饯��
     *
     * �ǥ��ȥ饯��
     *
     * @else
     *
     * @brief Destructor
     *
     * Destructor
     *
     * @endif
     */
    virtual ~OnRead(void){}
    
    /*!
     * @if jp
     *
     * @brief ������Хå��᥽�å�
     *
     * �Хåե�����ǡ������ɤ߽Ф����ľ���˸ƤӽФ���륳����Хå��᥽�å�
     *
     * @else
     *
     * @brief Callback method
     *
     * This is the callback method invoked immediately before data is readout
     * from the buffer.
     *
     * @endif
     */
    virtual void operator()() = 0;
  };
  
  /*!
   * @if jp
   * @class OnReadConvert
   * @brief read() ���Υǡ����Ѵ�������Хå���ݥ��饹
   *
   * InPort/OutPort�ΥХåե�����ǡ����� read()�����ݤ˸ƤӽФ����
   * ������Хå��ѥ��󥿡��ե�������
   * ���Υ�����Хå�������ͤ�read()������ͤȤʤ롣
   *
   * @since 0.4.0
   *
   * @else
   * @class OnReadConvert
   * @brief Data convert callback abstract class on read()
   *
   * This is the interface for callback invoked when data is done read()
   * from the InPort/OutPort's buffer.
   * The return value of this callback will be the return value of read().
   *
   * @since 0.4.0
   *
   * @endif
   */
  template <class DataType>
  struct OnReadConvert
  {
    /*!
     * @if jp
     *
     * @brief �ǥ��ȥ饯��
     *
     * �ǥ��ȥ饯��
     *
     * @else
     *
     * @brief Destructor
     *
     * Destructor
     *
     * @endif
     */
    virtual ~OnReadConvert(void){}
    
    /*!
     * @if jp
     *
     * @brief ������Хå��᥽�å�
     *
     * �Хåե�����ǡ������ɤ߽Ф����ݤ˸ƤӽФ���륳����Хå��᥽�å�
     *
     * @else
     *
     * @brief Callback method
     *
     * This is the callback method invoked when data is readout from the
     * buffer.
     *
     * @endif
     */
    virtual DataType operator()(const DataType& value) = 0;
  };
  

};
#endif // RTC_PORTCALLBACK_H