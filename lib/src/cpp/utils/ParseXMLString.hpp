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
 * @file
 */

#ifndef _FAST_DDS_QOS_PROFILES_MANAGER_UTILS_PARSE_XML_STRING_HPP_
#define _FAST_DDS_QOS_PROFILES_MANAGER_UTILS_PARSE_XML_STRING_HPP_

#include <stdio.h>

#include <xercesc/framework/MemBufFormatTarget.hpp>

namespace eprosima {
namespace qosprof {
namespace utils {

/**
 * @brief ParseXMLString is a Memory buffer to save the XML document
 *  in memory. It aims validating the generated XML document before
 *  saving it in disk (in the given file).
 */
class ParseXMLString : public xercesc::XMLFormatTarget
{
public:

    ParseXMLString();

    /**
     * @brief Obtain the buffer pointer for validation
     *
     * @return char* of the memory buffer
     */
    char* buffer();

    /**
     * @brief Obtain the buffer size for validation
     *
     * @return unsigned long int with the buffer length
     */
    unsigned long int length();

    /**
     * @brief Override function to save the given bytes in
     *  the buffer.
     *
     * @param toWrite pointer of the XML document serialized as byte array
     * @param count size of the XML document serialized as byte array
     * @param formatter XML unicode format manager
     */
    virtual void writeChars(
            const XMLByte* const toWrite,
            const XMLSize_t count,
            xercesc::XMLFormatter* const formatter);

protected:

    char* m_pBuffer;
    unsigned long int m_nTotal;
};

} /* utils */
} /* qosprof */
} /* eprosima */

#endif // _FAST_DDS_QOS_PROFILES_MANAGER_UTILS_PARSE_XML_STRING_HPP_
