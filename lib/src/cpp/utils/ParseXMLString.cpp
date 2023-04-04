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
#include <utils/ParseXMLString.hpp>

#include <cstring>

namespace eprosima {
namespace qosprof {
namespace utils {

ParseXMLString::ParseXMLString()
{
    m_pBuffer = nullptr;
    m_nTotal = 0;
}

char* ParseXMLString::buffer()
{
    return m_pBuffer;
}

unsigned long int ParseXMLString::length()
{
    return m_nTotal;
}

void ParseXMLString::writeChars(
        const XMLByte* const toWrite,
        const XMLSize_t count,
        xercesc::XMLFormatter* const formatter)
{
    if (toWrite)
    {
        char* pTmp = new char[m_nTotal + count + 1];

        if (m_pBuffer)
        {
            memcpy(pTmp, m_pBuffer, m_nTotal);
            delete m_pBuffer;
        }

        memcpy(&pTmp[m_nTotal], toWrite, count);

        m_nTotal += count;
        m_pBuffer = pTmp;

        if (m_pBuffer)
        {
            m_pBuffer[m_nTotal] = 0;
        }
    }
}

} /* utils */
} /* qosprof */
} /* eprosima */
