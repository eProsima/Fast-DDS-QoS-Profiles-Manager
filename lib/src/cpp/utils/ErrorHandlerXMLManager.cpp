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

#include <utils/ErrorHandlerXMLManager.hpp>

#include <xercesc/sax/HandlerBase.hpp>

#include <fastdds_qos_profiles_manager_lib/exception/Exception.hpp>

namespace eprosima {
namespace qosprof {
namespace utils {

ErrorHandlerXMLManager::ErrorHandlerXMLManager(
        Kind k)
{
    kind = k;
}

void ErrorHandlerXMLManager::warning(
        const xercesc::SAXParseException& ex)
{
    report_parse_exception(ex);
}

void ErrorHandlerXMLManager::error(
        const xercesc::SAXParseException& ex)
{
    report_parse_exception(ex);
}

void ErrorHandlerXMLManager::fatalError(
        const xercesc::SAXParseException& ex)
{
    report_parse_exception(ex);
}

void ErrorHandlerXMLManager::resetErrors()
{

}

void ErrorHandlerXMLManager::report_parse_exception(
        const xercesc::SAXParseException& ex)
{
    // Throw custom Exceptions based on the selected kind
    switch (kind){
        case Kind::ElementInvalid:
            throw ElementInvalid(xercesc::XMLString::transcode(ex.getMessage()));
            break;
        case Kind::ElementNotFound:
        default:
            throw ElementNotFound(xercesc::XMLString::transcode(ex.getMessage()));
            break;
    }
}

} /* utils */
} /* qosprof */
} /* eprosima */
