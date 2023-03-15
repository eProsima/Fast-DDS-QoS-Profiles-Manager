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

#include <domain_participant/DefaultUnicastLocators.hpp>
#include <exception/Exception.hpp>

#include <xercesc/dom/DOM.hpp>
#include <xercesc/parsers/XercesDOMParser.hpp>
#include <xercesc/util/XMLString.hpp>

#include <string>

class ParserErrorHandler : public ErrorHandler
{
    private:
        void reportParseException(const SAXParseException& ex)
        {
            throw ex;
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
};

namespace eprosima {
namespace qosprof {
namespace domain_participant {
namespace default_unicast_locators {

std::string print(
        const std::string& xml_file,
        const std::string& profile_id)
{
    // Try to initialize XML workspace
    try
    {
        XMLPlatformUtils::Initialize();
    }
    catch (const XMLException& toCatch)
    {
        // Unable to initialize XML workspace
        throw Unsupported(toCatch.getMessage());
        return;
    }

    // Create parser
    XercesDOMParser* xmlParser = new XercesDOMParser();

    // Declare error handler
    ParserErrorHandler* xmlErrorHandler = new ParserErrorHandler();
    xmlParser->setErrorHandler(xmlErrorHandler);

    // Try to open the given file
    try
    {
        xmlParser->parse(XMLString::transcode(xml_file.c_str()));
    }
    catch (const SAXParseException& ex)
    {
        // Delete resources
        delete xmlParser;
        delete xmlErrorHandler;

        // Given file does not exist
        throw FileNotFound(ex.getMessage());

        // Close XML workspace
        XMLPlatformUtils::Terminate();
        return;
    }

    // Open document
    DOMDocument* xmlDoc = xmlParser->getDocument();

    // Obtain root element
    DOMElement* xmlRoot = xmlDoc->getDocumentElement();

    // Obtain profiles node from root (no matter if standalone or rooted definition), only 1 profiles node per file
    DOMNode* profilesNode = xmlRoot->getElementsByTagName(XMLString::transcode("profiles"))[0];

    // Obtain participant based on the given identifier
    DOMNodeList* participantNodeList = profilesNode->getElementsByTagName(XMLString::transcode("participant"));

    // Throw exception if no participants
    if (participantNodeList->getLength() == 0)
    {
        // Delete resources
        delete profilesNode;
        delete xmlDoc;
        delete xmlRoot;
        delete xmlErrorHandler;
        delete xmlParser;

        // Given file does not exist
        throw ElementNotFound("participant " << profile_id << " is not defined in " << xml_file << "\n");

        // Close XML workspace
        XMLPlatformUtils::Terminate();
        return;
    }

    DOMNode* participantNode = nullptr;

    // Iterate throw the participants
    // TODO try with node->getNextSibling();
    for (int i=0, j=0; i<participantNodeList->getLength() && j==0; i++)
    {
        participantNode = participantNodeList[i];
        if (participantNode.getAttributes().getNamedItem("profile_name").getNodeValue().c_str() == profile_id)
        {
            j++;
        }
    }

    // Throw exception if participant not found
    if (participantNode == nullptr)
    {
        // Delete resources
        delete profilesNode;
        delete xmlDoc;
        delete xmlRoot;
        delete xmlErrorHandler;
        delete xmlParser;

        // Given file does not exist
        throw ElementNotFound("participant " << profile_id << " is not defined in " << xml_file << "\n");

        // Close XML workspace
        XMLPlatformUtils::Terminate();
        return;
    }

    // TODO pass node to the common locator.
    // Obtain rtps
    DOMNodeList* rtpsNodeList = participantNode->getElementsByTagName(XMLString::transcode("rtps"));

    // Throw exception if no participants
    if (rtpsNodeList->getLength() == 0)
    {
        // Delete resources
        delete participantNode;
        delete profilesNode;
        delete xmlDoc;
        delete xmlRoot;
        delete xmlErrorHandler;
        delete xmlParser;

        // Given file does not exist
        throw ElementNotFound("participant " << profile_id << " is not defined in " << xml_file << "\n");

        // Close XML workspace
        XMLPlatformUtils::Terminate();
        return;
    }

    DOMNode* participantNode = nullptr;

    // Iterate throw the participants
    // TODO try with node->getNextSibling();
    for (int i=0, j=0; i<participantNodeList->getLength() && j==0; i++)
    {
        participantNode = participantNodeList[i];
        if (participantNode.getAttributes().getNamedItem("profile_name").getNodeValue().c_str() == profile_id)
        {
            j++;
        }
    }

    // Throw exception if participant not found
    if (participantNode == nullptr)
    {
        // Delete resources
        delete xmlDoc;
        delete xmlRoot;
        delete profilesNode;
        delete xmlErrorHandler;
        delete xmlParser;

        // Given file does not exist
        throw ElementNotFound("participant " << profile_id << " in " << xml_file
                              << " does not contain a default unicast locator\n");

        // Close XML workspace
        XMLPlatformUtils::Terminate();
        return;
    }


}

std::string print(
        const std::string& xml_file,
        const std::string& profile_id,
        int32_t index)
{
    throw Unsupported("Unsupported");
}

std::string print_kind(
        const std::string& xml_file,
        const std::string& profile_id,
        int32_t index)
{
    throw Unsupported("Unsupported");
}

std::string print_port(
        const std::string& xml_file,
        const std::string& profile_id,
        int32_t index)
{
    throw Unsupported("Unsupported");
}

std::string print_physical_port(
        const std::string& xml_file,
        const std::string& profile_id,
        int32_t index)
{
    throw Unsupported("Unsupported");
}

std::string print_address(
        const std::string& xml_file,
        const std::string& profile_id,
        int32_t index)
{
    throw Unsupported("Unsupported");
}

std::string print_unique_lan_id(
        const std::string& xml_file,
        const std::string& profile_id,
        int32_t index)
{
    throw Unsupported("Unsupported");
}

std::string print_wan_address(
        const std::string& xml_file,
        const std::string& profile_id,
        int32_t index)
{
    throw Unsupported("Unsupported");
}

uint32_t size(
        const std::string& xml_file,
        const std::string& profile_id)
{
    throw Unsupported("Unsupported");
}

void clear(
        const std::string& xml_file,
        const std::string& profile_id)
{
    throw Unsupported("Unsupported");
}

void clear(
        const std::string& xml_file,
        const std::string& profile_id,
        int32_t index)
{
    throw Unsupported("Unsupported");
}

void clear_port(
        const std::string& xml_file,
        const std::string& profile_id,
        int32_t index)
{
    throw Unsupported("Unsupported");
}

void clear_physical_port(
        const std::string& xml_file,
        const std::string& profile_id,
        int32_t index)
{
    throw Unsupported("Unsupported");
}

void clear_address(
        const std::string& xml_file,
        const std::string& profile_id,
        int32_t index)
{
    throw Unsupported("Unsupported");
}

void clear_unique_lan_id(
        const std::string& xml_file,
        const std::string& profile_id,
        int32_t index)
{
    throw Unsupported("Unsupported");
}

void clear_wan_address(
        const std::string& xml_file,
        const std::string& profile_id,
        int32_t index)
{
    throw Unsupported("Unsupported");
}

void push_kind(
        const std::string& xml_file,
        const std::string& profile_id,
        const std::string& kind)
{
    throw Unsupported("Unsupported");
}

void update_kind(
        const std::string& xml_file,
        const std::string& profile_id,
        const std::string& kind,
        int32_t index)
{
    throw Unsupported("Unsupported");
}

void push_port(
        const std::string& xml_file,
        const std::string& profile_id,
        const std::string& port)
{
    throw Unsupported("Unsupported");
}

void update_port(
        const std::string& xml_file,
        const std::string& profile_id,
        const std::string& port,
        int32_t index)
{
    throw Unsupported("Unsupported");
}

void push_physical_port(
        const std::string& xml_file,
        const std::string& profile_id,
        const std::string& physical_port)
{
    throw Unsupported("Unsupported");
}

void update_physical_port(
        const std::string& xml_file,
        const std::string& profile_id,
        const std::string& physical_port,
        int32_t index)
{
    throw Unsupported("Unsupported");
}

void push_address(
        const std::string& xml_file,
        const std::string& profile_id,
        const std::string& address)
{
    throw Unsupported("Unsupported");
}

void update_address(
        const std::string& xml_file,
        const std::string& profile_id,
        const std::string& address,
        int32_t index)
{
    throw Unsupported("Unsupported");
}

void push_unique_lan_id(
        const std::string& xml_file,
        const std::string& profile_id,
        const std::string& unique_lan_id)
{
    throw Unsupported("Unsupported");
}

void update_unique_lan_id(
        const std::string& xml_file,
        const std::string& profile_id,
        const std::string& unique_lan_id,
        int32_t index)
{
    throw Unsupported("Unsupported");
}

void push_wan_address(
        const std::string& xml_file,
        const std::string& profile_id,
        const std::string& wan_address)
{
    throw Unsupported("Unsupported");
}

void update_wan_address(
        const std::string& xml_file,
        const std::string& profile_id,
        const std::string& wan_address,
        int32_t index)
{
    throw Unsupported("Unsupported");
}

} // default_unicast_locators
} // domain_participant
} // qosprof
} // eprosima
