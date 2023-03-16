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
 * @file ParseXMLErrorHandler.cpp
 */

#include <utils/ParseXMLErrorHandler.hpp>


ParseXMLErrorHandler::ParseXMLErrorHandler()
{
    kind = Kind::Unsupported;
}

ParseXMLErrorHandler::~ParseXMLErrorHandler() { }

ParseXMLErrorHandler::ParseXMLErrorHandler(Kind k)
{
    kind = k;
}

void ParseXMLErrorHandler::warning(const xercesc::SAXParseException& ex)
{
    reportParseException(ex);
}

void ParseXMLErrorHandler::error(const xercesc::SAXParseException& ex)
{
    reportParseException(ex);
}

void ParseXMLErrorHandler::fatalError(const xercesc::SAXParseException& ex)
{
    reportParseException(ex);
}

void ParseXMLErrorHandler::resetErrors() { }

void ParseXMLErrorHandler::reportParseException(const xercesc::SAXParseException& ex)
{
    switch (kind){
        case Kind::ElementInvalid:
            throw eprosima::qosprof::ElementInvalid(xercesc::XMLString::transcode(ex.getMessage()));
            break;
        case Kind::FileNotFound:
            throw eprosima::qosprof::FileNotFound(xercesc::XMLString::transcode(ex.getMessage()));
            break;
        case Kind::Unsupported:
        default:
            throw eprosima::qosprof::Unsupported(xercesc::XMLString::transcode(ex.getMessage()));
            break;
    }
    return;
}
