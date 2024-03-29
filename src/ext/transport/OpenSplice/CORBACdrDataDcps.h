﻿//******************************************************************
// 
//  Generated by IDL to C++ Translator
//  
//  File name: CORBACdrDataDcps.h
//  Source: CORBACdrDataDcps.idl
//  Generated: Wed Mar 27 20:28:43 2019
//  OpenSplice 6.9.190227OSS
//  
//******************************************************************
#ifndef OPENSPLICE_CORBACDRDATADCPS_H_
#define OPENSPLICE_CORBACDRDATADCPS_H_

#include "sacpp_mapping.h"
#include "CORBACdrData.h"
#include "dds_cdrBlob.h"
#include "dds_dcps.h"


namespace OpenRTM_OpenSplice
{

   class CORBACdrDataTypeSupportInterface;

   using CORBACdrDataTypeSupportInterface_ptr = CORBACdrDataTypeSupportInterface *;
   using CORBACdrDataTypeSupportInterface_var = DDS_DCPSInterface_var < CORBACdrDataTypeSupportInterface>;
   using CORBACdrDataTypeSupportInterface_out = DDS_DCPSInterface_out < CORBACdrDataTypeSupportInterface>;


   class CORBACdrDataDataWriter;

   using CORBACdrDataDataWriter_ptr = CORBACdrDataDataWriter *;
   using CORBACdrDataDataWriter_var = DDS_DCPSInterface_var < CORBACdrDataDataWriter>;
   using CORBACdrDataDataWriter_out = DDS_DCPSInterface_out < CORBACdrDataDataWriter>;


   class CORBACdrDataDataReader;

   using CORBACdrDataDataReader_ptr = CORBACdrDataDataReader *;
   using CORBACdrDataDataReader_var = DDS_DCPSInterface_var < CORBACdrDataDataReader>;
   using CORBACdrDataDataReader_out = DDS_DCPSInterface_out < CORBACdrDataDataReader>;


   class CORBACdrDataDataReaderView;

   using CORBACdrDataDataReaderView_ptr = CORBACdrDataDataReaderView *;
   using CORBACdrDataDataReaderView_var = DDS_DCPSInterface_var < CORBACdrDataDataReaderView>;
   using CORBACdrDataDataReaderView_out = DDS_DCPSInterface_out < CORBACdrDataDataReaderView>;

   struct CORBACdrDataSeq_uniq_ {};
   using CORBACdrDataSeq = DDS_DCPSUVLSeq < CORBACdrData, struct CORBACdrDataSeq_uniq_>;
   using CORBACdrDataSeq_var = DDS_DCPSSequence_var < CORBACdrDataSeq>;
   using CORBACdrDataSeq_out = DDS_DCPSSequence_out < CORBACdrDataSeq>;
   class CORBACdrDataTypeSupportInterface
   :
      virtual public DDS::TypeSupport
   { 
   public:
      using _ptr_type = CORBACdrDataTypeSupportInterface_ptr;
      using _var_type = CORBACdrDataTypeSupportInterface_var;

      static CORBACdrDataTypeSupportInterface_ptr _duplicate (CORBACdrDataTypeSupportInterface_ptr obj);
      DDS::Boolean _local_is_a (const char * id) override;

      static CORBACdrDataTypeSupportInterface_ptr _narrow (DDS::Object_ptr obj);
      static CORBACdrDataTypeSupportInterface_ptr _unchecked_narrow (DDS::Object_ptr obj);
      static CORBACdrDataTypeSupportInterface_ptr _nil () { return nullptr; }
      static const char * _local_id;
      CORBACdrDataTypeSupportInterface_ptr _this () { return this; }


   protected:
      CORBACdrDataTypeSupportInterface () {}
      ~CORBACdrDataTypeSupportInterface () {}
   private:
      CORBACdrDataTypeSupportInterface (const CORBACdrDataTypeSupportInterface &);
      CORBACdrDataTypeSupportInterface & operator = (const CORBACdrDataTypeSupportInterface &);
   };

   class CORBACdrDataDataWriter
   :
      virtual public DDS::DataWriter
   { 
   public:
      using _ptr_type = CORBACdrDataDataWriter_ptr;
      using _var_type = CORBACdrDataDataWriter_var;

      static CORBACdrDataDataWriter_ptr _duplicate (CORBACdrDataDataWriter_ptr obj);
      DDS::Boolean _local_is_a (const char * id) override;

      static CORBACdrDataDataWriter_ptr _narrow (DDS::Object_ptr obj);
      static CORBACdrDataDataWriter_ptr _unchecked_narrow (DDS::Object_ptr obj);
      static CORBACdrDataDataWriter_ptr _nil () { return nullptr; }
      static const char * _local_id;
      CORBACdrDataDataWriter_ptr _this () { return this; }

      virtual DDS::LongLong register_instance (const CORBACdrData& instance_data) = 0;
      virtual DDS::LongLong register_instance_w_timestamp (const CORBACdrData& instance_data, const DDS::Time_t& source_timestamp) = 0;
      virtual DDS::Long unregister_instance (const CORBACdrData& instance_data, DDS::LongLong handle) = 0;
      virtual DDS::Long unregister_instance_w_timestamp (const CORBACdrData& instance_data, DDS::LongLong handle, const DDS::Time_t& source_timestamp) = 0;
      virtual DDS::Long write_cdr(const DDS::CDRSample& instance_data, DDS::LongLong handle) = 0;
      virtual DDS::Long write (const CORBACdrData& instance_data, DDS::LongLong handle) = 0;
      virtual DDS::Long write_w_timestamp (const CORBACdrData& instance_data, DDS::LongLong handle, const DDS::Time_t& source_timestamp) = 0;
      virtual DDS::Long dispose (const CORBACdrData& instance_data, DDS::LongLong handle) = 0;
      virtual DDS::Long dispose_w_timestamp (const CORBACdrData& instance_data, DDS::LongLong handle, const DDS::Time_t& source_timestamp) = 0;
      virtual DDS::Long writedispose (const CORBACdrData& instance_data, DDS::LongLong handle) = 0;
      virtual DDS::Long writedispose_w_timestamp (const CORBACdrData& instance_data, DDS::LongLong handle, const DDS::Time_t& source_timestamp) = 0;
      virtual DDS::Long get_key_value (CORBACdrData& key_holder, DDS::LongLong handle) = 0;
      virtual DDS::LongLong lookup_instance (const CORBACdrData& instance_data) = 0;

   protected:
      CORBACdrDataDataWriter () {}
      ~CORBACdrDataDataWriter () {}
   private:
      CORBACdrDataDataWriter (const CORBACdrDataDataWriter &);
      CORBACdrDataDataWriter & operator = (const CORBACdrDataDataWriter &);
   };

   class CORBACdrDataDataReader
   :
      virtual public DDS::DataReader
   { 
   public:
      using _ptr_type = CORBACdrDataDataReader_ptr;
      using _var_type = CORBACdrDataDataReader_var;

      static CORBACdrDataDataReader_ptr _duplicate (CORBACdrDataDataReader_ptr obj);
      DDS::Boolean _local_is_a (const char * id) override;

      static CORBACdrDataDataReader_ptr _narrow (DDS::Object_ptr obj);
      static CORBACdrDataDataReader_ptr _unchecked_narrow (DDS::Object_ptr obj);
      static CORBACdrDataDataReader_ptr _nil () { return nullptr; }
      static const char * _local_id;
      CORBACdrDataDataReader_ptr _this () { return this; }

      virtual DDS::Long read (CORBACdrDataSeq& received_data, DDS::SampleInfoSeq& info_seq, DDS::Long max_samples, DDS::ULong sample_states, DDS::ULong view_states, DDS::ULong instance_states) = 0;
      virtual DDS::Long read_cdr (DDS::CDRSample& received_data, DDS::SampleInfo& info, DDS::ULong sample_states, DDS::ULong view_states, ::DDS::InstanceStateMask instance_states) = 0;
      virtual DDS::Long take (CORBACdrDataSeq& received_data, DDS::SampleInfoSeq& info_seq, DDS::Long max_samples, DDS::ULong sample_states, DDS::ULong view_states, DDS::ULong instance_states) = 0;
      virtual DDS::Long read_w_condition (CORBACdrDataSeq& received_data, DDS::SampleInfoSeq& info_seq, DDS::Long max_samples, DDS::ReadCondition_ptr a_condition) = 0;
      virtual DDS::Long take_w_condition (CORBACdrDataSeq& received_data, DDS::SampleInfoSeq& info_seq, DDS::Long max_samples, DDS::ReadCondition_ptr a_condition) = 0;
      virtual DDS::Long read_next_sample (CORBACdrData& received_data, DDS::SampleInfo& sample_info) = 0;
      virtual DDS::Long take_next_sample (CORBACdrData& received_data, DDS::SampleInfo& sample_info) = 0;
      virtual DDS::Long read_instance (CORBACdrDataSeq& received_data, DDS::SampleInfoSeq& info_seq, DDS::Long max_samples, DDS::LongLong a_handle, DDS::ULong sample_states, DDS::ULong view_states, DDS::ULong instance_states) = 0;
      virtual DDS::Long take_instance (CORBACdrDataSeq& received_data, DDS::SampleInfoSeq& info_seq, DDS::Long max_samples, DDS::LongLong a_handle, DDS::ULong sample_states, DDS::ULong view_states, DDS::ULong instance_states) = 0;
      virtual DDS::Long read_next_instance (CORBACdrDataSeq& received_data, DDS::SampleInfoSeq& info_seq, DDS::Long max_samples, DDS::LongLong a_handle, DDS::ULong sample_states, DDS::ULong view_states, DDS::ULong instance_states) = 0;
      virtual DDS::Long take_next_instance (CORBACdrDataSeq& received_data, DDS::SampleInfoSeq& info_seq, DDS::Long max_samples, DDS::LongLong a_handle, DDS::ULong sample_states, DDS::ULong view_states, DDS::ULong instance_states) = 0;
      virtual DDS::Long read_next_instance_w_condition (CORBACdrDataSeq& received_data, DDS::SampleInfoSeq& info_seq, DDS::Long max_samples, DDS::LongLong a_handle, DDS::ReadCondition_ptr a_condition) = 0;
      virtual DDS::Long take_next_instance_w_condition (CORBACdrDataSeq& received_data, DDS::SampleInfoSeq& info_seq, DDS::Long max_samples, DDS::LongLong a_handle, DDS::ReadCondition_ptr a_condition) = 0;
      virtual DDS::Long return_loan (CORBACdrDataSeq& received_data, DDS::SampleInfoSeq& info_seq) = 0;
      virtual DDS::Long get_key_value (CORBACdrData& key_holder, DDS::LongLong handle) = 0;
      virtual DDS::LongLong lookup_instance (const CORBACdrData& instance) = 0;

   protected:
      CORBACdrDataDataReader () {}
      ~CORBACdrDataDataReader () {}
   private:
      CORBACdrDataDataReader (const CORBACdrDataDataReader &);
      CORBACdrDataDataReader & operator = (const CORBACdrDataDataReader &);
   };

   class CORBACdrDataDataReaderView
   :
      virtual public DDS::DataReaderView
   { 
   public:
      using _ptr_type = CORBACdrDataDataReaderView_ptr;
      using _var_type = CORBACdrDataDataReaderView_var;

      static CORBACdrDataDataReaderView_ptr _duplicate (CORBACdrDataDataReaderView_ptr obj);
      DDS::Boolean _local_is_a (const char * id) override;

      static CORBACdrDataDataReaderView_ptr _narrow (DDS::Object_ptr obj);
      static CORBACdrDataDataReaderView_ptr _unchecked_narrow (DDS::Object_ptr obj);
      static CORBACdrDataDataReaderView_ptr _nil () { return nullptr; }
      static const char * _local_id;
      CORBACdrDataDataReaderView_ptr _this () { return this; }

      virtual DDS::Long read (CORBACdrDataSeq& received_data, DDS::SampleInfoSeq& info_seq, DDS::Long max_samples, DDS::ULong sample_states, DDS::ULong view_states, DDS::ULong instance_states) = 0;
      virtual DDS::Long take (CORBACdrDataSeq& received_data, DDS::SampleInfoSeq& info_seq, DDS::Long max_samples, DDS::ULong sample_states, DDS::ULong view_states, DDS::ULong instance_states) = 0;
      virtual DDS::Long read_w_condition (CORBACdrDataSeq& received_data, DDS::SampleInfoSeq& info_seq, DDS::Long max_samples, DDS::ReadCondition_ptr a_condition) = 0;
      virtual DDS::Long take_w_condition (CORBACdrDataSeq& received_data, DDS::SampleInfoSeq& info_seq, DDS::Long max_samples, DDS::ReadCondition_ptr a_condition) = 0;
      virtual DDS::Long read_next_sample (CORBACdrData& received_data, DDS::SampleInfo& sample_info) = 0;
      virtual DDS::Long take_next_sample (CORBACdrData& received_data, DDS::SampleInfo& sample_info) = 0;
      virtual DDS::Long read_instance (CORBACdrDataSeq& received_data, DDS::SampleInfoSeq& info_seq, DDS::Long max_samples, DDS::LongLong a_handle, DDS::ULong sample_states, DDS::ULong view_states, DDS::ULong instance_states) = 0;
      virtual DDS::Long take_instance (CORBACdrDataSeq& received_data, DDS::SampleInfoSeq& info_seq, DDS::Long max_samples, DDS::LongLong a_handle, DDS::ULong sample_states, DDS::ULong view_states, DDS::ULong instance_states) = 0;
      virtual DDS::Long read_next_instance (CORBACdrDataSeq& received_data, DDS::SampleInfoSeq& info_seq, DDS::Long max_samples, DDS::LongLong a_handle, DDS::ULong sample_states, DDS::ULong view_states, DDS::ULong instance_states) = 0;
      virtual DDS::Long take_next_instance (CORBACdrDataSeq& received_data, DDS::SampleInfoSeq& info_seq, DDS::Long max_samples, DDS::LongLong a_handle, DDS::ULong sample_states, DDS::ULong view_states, DDS::ULong instance_states) = 0;
      virtual DDS::Long read_next_instance_w_condition (CORBACdrDataSeq& received_data, DDS::SampleInfoSeq& info_seq, DDS::Long max_samples, DDS::LongLong a_handle, DDS::ReadCondition_ptr a_condition) = 0;
      virtual DDS::Long take_next_instance_w_condition (CORBACdrDataSeq& received_data, DDS::SampleInfoSeq& info_seq, DDS::Long max_samples, DDS::LongLong a_handle, DDS::ReadCondition_ptr a_condition) = 0;
      virtual DDS::Long return_loan (CORBACdrDataSeq& received_data, DDS::SampleInfoSeq& info_seq) = 0;
      virtual DDS::Long get_key_value (CORBACdrData& key_holder, DDS::LongLong handle) = 0;
      virtual DDS::LongLong lookup_instance (const CORBACdrData& instance) = 0;

   protected:
      CORBACdrDataDataReaderView () {}
      ~CORBACdrDataDataReaderView () {}
   private:
      CORBACdrDataDataReaderView (const CORBACdrDataDataReaderView &);
      CORBACdrDataDataReaderView & operator = (const CORBACdrDataDataReaderView &);
   };

}




#endif
