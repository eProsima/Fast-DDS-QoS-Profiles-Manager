// Copyright 2023 Proyectos y Sistemas de Mantenimiento SL (eProsima).
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

/**
 * @file ParseXMLString.hpp
 */

#ifndef _FAST_DDS_QOS_PROFILES_MANAGER_UTILS_PARSE_XML_STRING_HPP_
#define _FAST_DDS_QOS_PROFILES_MANAGER_UTILS_PARSE_XML_STRING_HPP_

#include <string>
#include <stdio.h>

#include <fastdds_qos_profiles_manager_dll.h>

#include <xercesc/framework/MemBufFormatTarget.hpp>

class ParseXMLString : public xercesc::XMLFormatTarget
{
public:
    ParseXMLString();

    char* buffer();

    unsigned long int length();

    virtual void writeChars(
        const XMLByte* const toWrite,
        const XMLSize_t count,
        xercesc::XMLFormatter* const formatter);

protected:
    char* m_pBuffer;
    unsigned long int  m_nTotal;
};
#endif // _FAST_DDS_QOS_PROFILES_MANAGER_UTILS_PARSE_XML_STRING_HPP_
