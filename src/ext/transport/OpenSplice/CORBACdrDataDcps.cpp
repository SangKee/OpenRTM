﻿//******************************************************************
// 
//  Generated by IDL to C++ Translator
//  
//  File name: CORBACdrDataDcps.cpp
//  Source: CORBACdrDataDcps.idl
//  Generated: Wed Mar 27 20:28:43 2019
//  OpenSplice 6.9.190227OSS
//  
//******************************************************************

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__)
#pragma warning(push)
#pragma warning(disable:4819)
#endif
#include "CORBACdrDataDcps.h"
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__)
#pragma warning(pop)
#endif

#ifdef DDS_USE_EXPLICIT_TEMPLATES
#if DDS_USE_EXPLICIT_TEMPLATES
template class DDS_DCPSUVLSeq < OpenRTM_OpenSplice::CORBACdrData, struct CORBACdrDataSeq_uniq_>;
#endif
#endif

const char * OpenRTM_OpenSplice::CORBACdrDataTypeSupportInterface::_local_id = "IDL:OpenRTM/CORBACdrDataTypeSupportInterface:1.0";

OpenRTM_OpenSplice::CORBACdrDataTypeSupportInterface_ptr OpenRTM_OpenSplice::CORBACdrDataTypeSupportInterface::_duplicate (OpenRTM_OpenSplice::CORBACdrDataTypeSupportInterface_ptr p)
{
   if (p) p->m_count++;
   return p;
}

DDS::Boolean OpenRTM_OpenSplice::CORBACdrDataTypeSupportInterface::_local_is_a (const char * _id)
{
   if (strcmp (_id, OpenRTM_OpenSplice::CORBACdrDataTypeSupportInterface::_local_id) == 0)
   {
      return true;
   }

   using NestedBase_1 = DDS::TypeSupport;

   if (NestedBase_1::_local_is_a (_id))
   {
      return true;
   }

   return false;
}

OpenRTM_OpenSplice::CORBACdrDataTypeSupportInterface_ptr OpenRTM_OpenSplice::CORBACdrDataTypeSupportInterface::_narrow (DDS::Object_ptr p)
{
    OpenRTM_OpenSplice::CORBACdrDataTypeSupportInterface_ptr result = nullptr;
   if (p && p->_is_a (OpenRTM_OpenSplice::CORBACdrDataTypeSupportInterface::_local_id))
   {
      result = dynamic_cast <OpenRTM_OpenSplice::CORBACdrDataTypeSupportInterface_ptr> (p);
      if (result) result->m_count++;
   }
   return result;
}

OpenRTM_OpenSplice::CORBACdrDataTypeSupportInterface_ptr OpenRTM_OpenSplice::CORBACdrDataTypeSupportInterface::_unchecked_narrow (DDS::Object_ptr p)
{
    OpenRTM_OpenSplice::CORBACdrDataTypeSupportInterface_ptr result;
   result = dynamic_cast <OpenRTM_OpenSplice::CORBACdrDataTypeSupportInterface_ptr> (p);
   if (result) result->m_count++;
   return result;
}

const char * OpenRTM_OpenSplice::CORBACdrDataDataWriter::_local_id = "IDL:OpenRTM/CORBACdrDataDataWriter:1.0";

OpenRTM_OpenSplice::CORBACdrDataDataWriter_ptr OpenRTM_OpenSplice::CORBACdrDataDataWriter::_duplicate (OpenRTM_OpenSplice::CORBACdrDataDataWriter_ptr p)
{
   if (p) p->m_count++;
   return p;
}

DDS::Boolean OpenRTM_OpenSplice::CORBACdrDataDataWriter::_local_is_a (const char * _id)
{
   if (strcmp (_id, OpenRTM_OpenSplice::CORBACdrDataDataWriter::_local_id) == 0)
   {
      return true;
   }

   using NestedBase_1 = DDS::DataWriter;

   if (NestedBase_1::_local_is_a (_id))
   {
      return true;
   }

   return false;
}

OpenRTM_OpenSplice::CORBACdrDataDataWriter_ptr OpenRTM_OpenSplice::CORBACdrDataDataWriter::_narrow (DDS::Object_ptr p)
{
    OpenRTM_OpenSplice::CORBACdrDataDataWriter_ptr result = nullptr;
   if (p && p->_is_a (OpenRTM_OpenSplice::CORBACdrDataDataWriter::_local_id))
   {
      result = dynamic_cast <OpenRTM_OpenSplice::CORBACdrDataDataWriter_ptr> (p);
      if (result) result->m_count++;
   }
   return result;
}

OpenRTM_OpenSplice::CORBACdrDataDataWriter_ptr OpenRTM_OpenSplice::CORBACdrDataDataWriter::_unchecked_narrow (DDS::Object_ptr p)
{
    OpenRTM_OpenSplice::CORBACdrDataDataWriter_ptr result;
   result = dynamic_cast <OpenRTM_OpenSplice::CORBACdrDataDataWriter_ptr> (p);
   if (result) result->m_count++;
   return result;
}

const char * OpenRTM_OpenSplice::CORBACdrDataDataReader::_local_id = "IDL:OpenRTM/CORBACdrDataDataReader:1.0";

OpenRTM_OpenSplice::CORBACdrDataDataReader_ptr OpenRTM_OpenSplice::CORBACdrDataDataReader::_duplicate (OpenRTM_OpenSplice::CORBACdrDataDataReader_ptr p)
{
   if (p) p->m_count++;
   return p;
}

DDS::Boolean OpenRTM_OpenSplice::CORBACdrDataDataReader::_local_is_a (const char * _id)
{
   if (strcmp (_id, OpenRTM_OpenSplice::CORBACdrDataDataReader::_local_id) == 0)
   {
      return true;
   }

   using NestedBase_1 = DDS::DataReader;

   if (NestedBase_1::_local_is_a (_id))
   {
      return true;
   }

   return false;
}

OpenRTM_OpenSplice::CORBACdrDataDataReader_ptr OpenRTM_OpenSplice::CORBACdrDataDataReader::_narrow (DDS::Object_ptr p)
{
    OpenRTM_OpenSplice::CORBACdrDataDataReader_ptr result = nullptr;
   if (p && p->_is_a (OpenRTM_OpenSplice::CORBACdrDataDataReader::_local_id))
   {
      result = dynamic_cast <OpenRTM_OpenSplice::CORBACdrDataDataReader_ptr> (p);
      if (result) result->m_count++;
   }
   return result;
}

OpenRTM_OpenSplice::CORBACdrDataDataReader_ptr OpenRTM_OpenSplice::CORBACdrDataDataReader::_unchecked_narrow (DDS::Object_ptr p)
{
    OpenRTM_OpenSplice::CORBACdrDataDataReader_ptr result;
   result = dynamic_cast <OpenRTM_OpenSplice::CORBACdrDataDataReader_ptr> (p);
   if (result) result->m_count++;
   return result;
}

const char * OpenRTM_OpenSplice::CORBACdrDataDataReaderView::_local_id = "IDL:OpenRTM/CORBACdrDataDataReaderView:1.0";

OpenRTM_OpenSplice::CORBACdrDataDataReaderView_ptr OpenRTM_OpenSplice::CORBACdrDataDataReaderView::_duplicate (OpenRTM_OpenSplice::CORBACdrDataDataReaderView_ptr p)
{
   if (p) p->m_count++;
   return p;
}

DDS::Boolean OpenRTM_OpenSplice::CORBACdrDataDataReaderView::_local_is_a (const char * _id)
{
   if (strcmp (_id, OpenRTM_OpenSplice::CORBACdrDataDataReaderView::_local_id) == 0)
   {
      return true;
   }

   using NestedBase_1 = DDS::DataReaderView;

   if (NestedBase_1::_local_is_a (_id))
   {
      return true;
   }

   return false;
}

OpenRTM_OpenSplice::CORBACdrDataDataReaderView_ptr OpenRTM_OpenSplice::CORBACdrDataDataReaderView::_narrow (DDS::Object_ptr p)
{
    OpenRTM_OpenSplice::CORBACdrDataDataReaderView_ptr result = nullptr;
   if (p && p->_is_a (OpenRTM_OpenSplice::CORBACdrDataDataReaderView::_local_id))
   {
      result = dynamic_cast <OpenRTM_OpenSplice::CORBACdrDataDataReaderView_ptr> (p);
      if (result) result->m_count++;
   }
   return result;
}

OpenRTM_OpenSplice::CORBACdrDataDataReaderView_ptr OpenRTM_OpenSplice::CORBACdrDataDataReaderView::_unchecked_narrow (DDS::Object_ptr p)
{
    OpenRTM_OpenSplice::CORBACdrDataDataReaderView_ptr result;
   result = dynamic_cast <OpenRTM_OpenSplice::CORBACdrDataDataReaderView_ptr> (p);
   if (result) result->m_count++;
   return result;
}



