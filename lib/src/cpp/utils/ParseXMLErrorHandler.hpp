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

#ifndef _FAST_DDS_QOS_PROFILES_MANAGER_UTILS_PARSE_XML_ERROR_HANDLER_HPP_
#define _FAST_DDS_QOS_PROFILES_MANAGER_UTILS_PARSE_XML_ERROR_HANDLER_HPP_

#include <string>

#include <xercesc/sax/ErrorHandler.hpp>

namespace eprosima {
namespace qosprof {
namespace utils {

/**
 * @brief ParseXMLErrorHandler is an error handler that would
 *  throw a eProsima QoS Profiles Manager Exception defined in
 *  its construction or default.
 *
 */
class ParseXMLErrorHandler : public xercesc::ErrorHandler
{
public:
    /**
     * @brief Kind of Exception to be thrown
     *
     */
    enum class Kind {
        FileNotFound,
        ElementInvalid,
        ElementNotFound,
    };

    /**
     * @brief Construct a new Parse XML Error Handler object
     *
     * @param Kind kind of exception to be thrown
     */
    ParseXMLErrorHandler(Kind kind = Kind::FileNotFound);

    /**
     * @brief Destroy the Parse XML Error Handler object
     *
     */
    ~ParseXMLErrorHandler() = default;

    /**
     * @brief Catch Xerces warning exceptions
     *
     * @param ex exception caught
     */
    void warning(const xercesc::SAXParseException& ex) override;

    /**
     * @brief Catch Xerces error exceptions
     *
     * @param ex exception caught
     */
    void error(const xercesc::SAXParseException& ex) override;

    /**
     * @brief Catch Xerces fatal error exceptions
     *
     * @param ex exception caught
     */
    void fatalError(const xercesc::SAXParseException& ex) override;

    /**
     * @brief Reset error caught (empty impl)
     *
     */
    void resetErrors() override;

private:
    /**
     * @brief Selected kind of exception to be thrown
     *
     */
    Kind kind;

    /**
     * @brief Report the caught exception based on the selected kind
     *
     * @param ex exception caught
     */
    void report_parse_exception(const xercesc::SAXParseException& ex);

};

} /* utils */
} /* qosprof */
} /* eprosima */

#endif // _FAST_DDS_QOS_PROFILES_MANAGER_UTILS_PARSE_XML_ERROR_HANDLER_HPP_
