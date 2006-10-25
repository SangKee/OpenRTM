// -*- C++ -*-
/*!
 * @file Factory.h
 * @brief RT component manager class
 * @date $Date: 2006-10-25 17:35:52 $
 * @author Noriaki Ando <n-ando@aist.go.jp>
 *
 * Copyright (C) 2003-2005
 *     Task-intelligence Research Group,
 *     Intelligent Systems Research Institute,
 *     National Institute of
 *         Advanced Industrial Science and Technology (AIST), Japan
 *     All rights reserved.
 *
 * $Id: Factory.cpp,v 1.3 2006-10-25 17:35:52 n-ando Exp $
 *
 */

/*
 * $Log: not supported by cvs2svn $
 * Revision 1.2  2006/10/24 14:25:26  n-ando
 * Renamed RtcFactory.cpp to Factory.cpp
 *
 * Revision 1.1.1.1  2005/05/12 09:06:18  n-ando
 * Public release.
 *
 *
 */

#include "rtm/Factory.h"

namespace RTC 
{

  FactoryBase::FactoryBase(Properties profile)
    : m_Profile(profile), m_Number(-1)
  {
  }

  FactoryBase::~FactoryBase()
  {
  }


  Properties& FactoryBase::profile()
  {
    return m_Profile;
  }


  int FactoryBase::number()
  {
    return m_Number;
  }


  FactoryCXX::FactoryCXX(Properties profile,
			 RtcNewFunc new_func,
			 RtcDeleteFunc delete_func)
    : FactoryBase(profile),
      m_New(new_func),
      m_Delete(delete_func)
  {
  }


  RtcBase* FactoryCXX::create(Manager* mgr)
  {
    ++m_Number;
    return m_New(mgr);
  }

  void FactoryCXX::destroy(RtcBase* comp)
  {
    --m_Number;
    m_Delete(comp);
  }

};

