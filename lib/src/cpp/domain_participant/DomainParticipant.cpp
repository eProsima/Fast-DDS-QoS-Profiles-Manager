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

#include <domain_participant/DomainParticipant.hpp>

#include <string>
#include <vector>

#include <exception/Exception.hpp>

std::string xsdFilePath = "";

namespace eprosima {
namespace qosprof {
namespace domain_participant {

std::string print(
        const std::string& xml_file)
{
    throw Unsupported("Unsupported");
}

std::string print(
        const std::string& xml_file,
        const std::string& profile_id)
{
    throw Unsupported("Unsupported");
}

std::string print_default_profile(
        const std::string& xml_file)
{
    throw Unsupported("Unsupported");
}

std::string print_domain_id(
        const std::string& xml_file,
        const std::string& profile_id)
{
    throw Unsupported("Unsupported");
}

std::string print_name(
        const std::string& xml_file,
        const std::string& profile_id)
{
    XercesDOMParser* xmlParser = NULL;
    DOMNode* profilesNode = NULL;
    DOMNode* participantNode = NULL;
    DOMNode* rtpsNode = NULL;
    DOMNode* nameNode = NULL;

    // Open xml_file
    try
    {
        xmlParser = openXML(xml_file);
    }
    catch (FileNotFound ex)
    {
        // Given file does not exist
        throw FileNotFound(ex);
        return;
    }
    catch (Unsupported ex)
    {
        // Could not initialize XML workspace
        throw Unsupported(ex);
        return;
    }

    // Obtain nodes
    try
    {
        profilesNode = getNode(xmlParser, "profiles");
        participantNode = getNode(profilesNode, "participant", "profile_name", profile_id);
        rtpsNode = getNode(participantNode, "rtps");
        nameNode = getNode(rtpsNode, "name");
    }
    catch (ElementNotFound ex)
    {
        // Throw exception if no nodes
        throw ElementNotFound(ex);

        closeXML();
        return;
    }

    // Print name
    return XMLString::transcode(nameNode.getNodeValue());
}

std::string print_ignore_non_matching_locators(
        const std::string& xml_file,
        const std::string& profile_id)
{
    throw Unsupported("Unsupported");
}

std::string print_send_socket_buffer_size(
        const std::string& xml_file,
        const std::string& profile_id)
{
    throw Unsupported("Unsupported");
}

std::string print_listen_socket_buffer_size(
        const std::string& xml_file,
        const std::string& profile_id)
{
    throw Unsupported("Unsupported");
}

std::string print_participant_id(
        const std::string& xml_file,
        const std::string& profile_id)
{
    throw Unsupported("Unsupported");
}

std::string print_user_transport(
        const std::string& xml_file,
        const std::string& profile_id)
{
    throw Unsupported("Unsupported");
}

std::string print_user_transport(
        const std::string& xml_file,
        const std::string& profile_id,
        int32_t index)
{
    throw Unsupported("Unsupported");
}

std::string print_use_builtin_transports(
        const std::string& xml_file,
        const std::string& profile_id)
{
    throw Unsupported("Unsupported");
}

std::string print_user_data(
        const std::string& xml_file,
        const std::string& profile_id)
{
    throw Unsupported("Unsupported");
}

std::string print_user_data(
        const std::string& xml_file,
        const std::string& profile_id,
        int32_t index)
{
    throw Unsupported("Unsupported");
}

std::string print_prefix(
        const std::string& xml_file,
        const std::string& profile_id)
{
    throw Unsupported("Unsupported");
}

uint32_t user_transport_size(
        const std::string& xml_file,
        const std::string& profile_id)
{
    throw Unsupported("Unsupported");
}

uint32_t user_data_size(
        const std::string& xml_file,
        const std::string& profile_id)
{
    throw Unsupported("Unsupported");
}

void clear(
        const std::string& xml_file)
{
    throw Unsupported("Unsupported");
}

void clear(
        const std::string& xml_file,
        const std::string& profile_id)
{
    throw Unsupported("Unsupported");
}

void clear_default_profile(
        const std::string& xml_file)
{
    throw Unsupported("Unsupported");
}

void clear_domain_id(
        const std::string& xml_file,
        const std::string& profile_id)
{
    throw Unsupported("Unsupported");
}

void clear_name(
        const std::string& xml_file,
        const std::string& profile_id)
{
    throw Unsupported("Unsupported");
}

void clear_ignore_non_matching_locators(
        const std::string& xml_file,
        const std::string& profile_id)
{
    throw Unsupported("Unsupported");
}

void clear_send_socket_buffer_size(
        const std::string& xml_file,
        const std::string& profile_id)
{
    throw Unsupported("Unsupported");
}

void clear_listen_socket_buffer_size(
        const std::string& xml_file,
        const std::string& profile_id)
{
    throw Unsupported("Unsupported");
}

void clear_participant_id(
        const std::string& xml_file,
        const std::string& profile_id)
{
    throw Unsupported("Unsupported");
}

void clear_user_transports(
        const std::string& xml_file,
        const std::string& profile_id)
{
    throw Unsupported("Unsupported");
}

void clear_user_transports(
        const std::string& xml_file,
        const std::string& profile_id,
        int32_t index)
{
    throw Unsupported("Unsupported");
}

void clear_use_builtin_transports(
        const std::string& xml_file,
        const std::string& profile_id)
{
    throw Unsupported("Unsupported");
}

void clear_user_data(
        const std::string& xml_file,
        const std::string& profile_id)
{
    throw Unsupported("Unsupported");
}

void clear_user_data(
        const std::string& xml_file,
        const std::string& profile_id,
        int32_t index)
{
    throw Unsupported("Unsupported");
}

void clear_prefix(
        const std::string& xml_file,
        const std::string& profile_id)
{
    throw Unsupported("Unsupported");
}

void set_default_profile(
        const std::string& xml_file,
        const std::string& profile_id)
{
    throw Unsupported("Unsupported");
}

void set_domain_id(
        const std::string& xml_file,
        const std::string& profile_id,
        const std::string& domain_id)
{
    throw Unsupported("Unsupported");
}

void set_name(
        const std::string& xml_file,
        const std::string& profile_id,
        const std::string& name)
{

    XercesDOMParser* xmlParser = NULL;
    DOMDocument* xmlDoc = NULL;
    DOMNode* profilesNode = NULL;
    DOMNode* participantNode = NULL;
    DOMNode* rtpsNode = NULL;
    DOMNode* nameNode = NULL;

    // Open xml_file
    try
    {
        xmlParser = openXML(xml_file);
    }
    catch (const FileNotFound& ex)
    {
        // Given file does not exist
        throw FileNotFound(ex);
        return;
    }
    catch (const Unsupported& ex)
    {
        // Could not initialize XML workspace
        throw Unsupported(ex);
        return;
    }

    // Obtain profilesNode
    try
    {
        profilesNode = getNode(xmlParser, "profiles");
    }
    catch (const ElementNotFound& ex)
    {
        // Create if not exist
        if (!profilesNode)
        {
            // Root does not exist, create element
            DOMImplementation* xmlImplementation = DOMImplementationRegistry::getDOMImplementation (XMLString::transcode("Core"));
            if (xmlImplementation == NULL)
            {
                // Could not initialize XML workspace
                throw Unsupported("Could not initialize XML workspace");

                closeXML();
                return;
            }

            // Create root element as profiles plus xmls link
            xmlDoc = xmlImplementation->createDocument(0, XMLString::transcode("dds"), 0);
            DOMElement* rootElement = xmlDoc->getDocumentElement();
            rootElement->setAttribute(XMLString::transcode("xmlns"), XMLString::transcode("http://www.eprosima.com/XMLSchemas/fastRTPS_Profiles"));

            // Add profiles
            profilesNode = (DOMNode*) xmlDoc->createElement(XMLString::transcode("profiles"));
            rootElement->appendChild(profilesNode);
        }
    }

    // Obtain participantNode with the profile id
    try
    {
        participantNode = getNode(profilesNode, "participant", "profile_name", profile_id);
    }
    catch (const ElementNotFound& ex)
    {
        // Create if not exist
        if (!participantNode)
        {
            xmlDoc = xmlParser->getDocument();
            participantNode = (DOMNode*) xmlDoc->createElement(XMLString::transcode("participant"));
            profilesNode->appendChild(participantNode);
            participantNode->setAttribute(XMLString::transcode("profile_name"), XMLString::transcode(profile_id));
        }
    }

    // Obtain rtpsNode
    try
    {
        rtpsNode = getNode(participantNode, "rtps");
    }
    catch (const ElementNotFound& ex)
    {
        // Create if not exist
        if (!rtpsNode)
        {
            xmlDoc = xmlParser->getDocument();
            rtpsNode = (DOMNode*) xmlDoc->createElement(XMLString::transcode("rtps"));
            participantNode->appendChild(rtpsNode);
        }
    }

    // Obtain name
    try
    {
        nameNode = getNode(rtpsNode, "name");
    }
    catch (const ElementNotFound& ex)
    {
        // Create if not exist
        if (!nameNode)
        {
            xmlDoc = xmlParser->getDocument();
            nameNode = (DOMNode*) xmlDoc->createElement(XMLString::transcode("name"));
            rtpsNode->appendChild(nameNode);
        }
    }

    // Set name value
    DOMText* nameValue = xmlDoc->createTextNode(XMLString::transcode(name.c_str()));
    nameNode->appendChild(nameValue);

    // Validate new element
    try {
        xmlDoc = xmlParser->getDocument();
        saveXML("temp.xml", xmlDoc);
        validateXML("temp.xml", xmlParser);
    }
    catch (const Unsupported& ex)
    {
        throw Unsupported(ex);
        closeXML();
        return;
    }
    catch (const ElementInvalid& ex)
    {
        throw ElementInvalid(ex);
        closeXML();
        return;
    }

    // Save if valid
    try
    {
        xmlDoc = xmlParser->getDocument();
        saveXML(xml_file, xmlDoc);
    }
    catch(const Unsupported& e)
    {
        throw Unsupported(ex);
    }

    closeXML();
    return;
}

void set_ignore_non_matching_locators(
        const std::string& xml_file,
        const std::string& profile_id,
        const std::string& ignore_non_matching_locators)
{
    throw Unsupported("Unsupported");
}

void set_send_socket_buffer_size(
        const std::string& xml_file,
        const std::string& profile_id,
        const std::string& send_socket_buffer_size)
{
    throw Unsupported("Unsupported");
}

void set_listen_socket_buffer_size(
        const std::string& xml_file,
        const std::string& profile_id,
        const std::string& listen_socket_buffer_size)
{
    throw Unsupported("Unsupported");
}

void set_participant_id(
        const std::string& xml_file,
        const std::string& profile_id,
        const std::string& participant_id)
{
    throw Unsupported("Unsupported");
}

void set_use_builtin_transports(
        const std::string& xml_file,
        const std::string& profile_id,
        const std::string& use_builtin_transports)
{
    throw Unsupported("Unsupported");
}

void set_prefix(
        const std::string& xml_file,
        const std::string& profile_id,
        const std::string& prefix)
{
    throw Unsupported("Unsupported");
}

void push_user_transports(
        const std::string& xml_file,
        const std::string& profile_id,
        const std::string& transport_id)
{
    throw Unsupported("Unsupported");
}

void update_user_transports(
        const std::string& xml_file,
        const std::string& profile_id,
        const std::string& transport_id,
        int32_t index)
{
    throw Unsupported("Unsupported");
}

void push_user_data(
        const std::string& xml_file,
        const std::string& profile_id,
        const std::string& user_data)
{
    throw Unsupported("Unsupported");
}

void update_user_data(
        const std::string& xml_file,
        const std::string& profile_id,
        const std::string& user_data,
        int32_t index)
{
    throw Unsupported("Unsupported");
}

} // domain_participant
} // qosprof
} // eprosima
