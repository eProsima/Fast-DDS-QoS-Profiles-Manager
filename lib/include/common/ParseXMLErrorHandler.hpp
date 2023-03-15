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

#ifndef _FAST_DDS_QOS_PROFILES_MANAGER_COMMON_PARSE_XML_ERROR_HANDLER_HPP_
#define _FAST_DDS_QOS_PROFILES_MANAGER_COMMON_PARSE_XML_ERROR_HANDLER_HPP_

#include <string>

#include <fastdds_qos_profiles_manager_dll.h>

#include <xercesc/sax/ErrorHandler.hpp>

/*class ParseXMLErrorHandler : public ErrorHandler
{
    private:
        void reportParseException(const SAXParseException& ex)
        {
            throw Element (ex.getMessage());
        }

    public:
        void warning(const SAXParseException& ex)
        {
            reportParseException(ex);
        }
        void error(const SAXParseException& ex)
        {
            reportParseException(ex);
        }
        void fatalError(const SAXParseException& ex)
        {
            reportParseException(ex);
        }
        void resetErrors() { }
};*/
#endif // _FAST_DDS_QOS_PROFILES_MANAGER_COMMON_PARSE_XML_ERROR_HANDLER_HPP_
