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

namespace eprosima {
namespace qosprof {
namespace domain_participant {

std::string print(
        const std::string& xml_file)
{
    throw eprosima::qosprof::Unsupported("Unsupported");
}

std::string print(
        const std::string& xml_file,
        const std::string& profile_id)
{
    throw eprosima::qosprof::Unsupported("Unsupported");
}

std::string print_default_profile(
        const std::string& xml_file)
{
    throw eprosima::qosprof::Unsupported("Unsupported");
}

std::string print_domain_id(
        const std::string& xml_file,
        const std::string& profile_id)
{
    xercesc::XercesDOMParser* xmlParser = NULL;
    xercesc::DOMNode* profilesNode = NULL;
    xercesc::DOMNode* participantNode = NULL;
    xercesc::DOMNode* domainIdNode = NULL;

    // Open xml_file
    try
    {
        xmlParser = openXML(xml_file);
    }
    catch (const eprosima::qosprof::FileNotFound ex)
    {
        // Given file does not exist
        throw eprosima::qosprof::FileNotFound(ex);
        return NULL;
    }
    catch (const eprosima::qosprof::Unsupported ex)
    {
        // Could not initialize XML workspace
        throw eprosima::qosprof::Unsupported(ex);
        return NULL;
    }

    // Obtain nodes
    try
    {
        profilesNode = getNode(*xmlParser, eprosima::qosprof::tag::PROFILES);
        participantNode = getNode(
            *profilesNode,
            eprosima::qosprof::tag::PARTICIPANT,
            eprosima::qosprof::tag::PROFILE_NAME,
            profile_id);
        domainIdNode = getNode(*participantNode, eprosima::qosprof::tag::DOMAIN_ID);
    }
    catch (eprosima::qosprof::ElementNotFound ex)
    {
        // Throw exception if no nodes
        throw eprosima::qosprof::ElementNotFound(ex);

        closeXML();
        return NULL;
    }

    // Print domainId
    return xercesc::XMLString::transcode(domainIdNode->getNodeValue());
}

std::string print_name(
        const std::string& xml_file,
        const std::string& profile_id)
{
    xercesc::XercesDOMParser* xmlParser = NULL;
    xercesc::DOMNode* profilesNode = NULL;
    xercesc::DOMNode* participantNode = NULL;
    xercesc::DOMNode* rtpsNode = NULL;
    xercesc::DOMNode* nameNode = NULL;

    // Open xml_file
    try
    {
        xmlParser = openXML(xml_file);
    }
    catch (const eprosima::qosprof::FileNotFound ex)
    {
        // Given file does not exist
        throw eprosima::qosprof::FileNotFound(ex);
        return NULL;
    }
    catch (const eprosima::qosprof::Unsupported ex)
    {
        // Could not initialize XML workspace
        throw eprosima::qosprof::Unsupported(ex);
        return NULL;
    }

    // Obtain nodes
    try
    {
        profilesNode = getNode(*xmlParser, eprosima::qosprof::tag::PROFILES);
        participantNode = getNode(
            *profilesNode,
            eprosima::qosprof::tag::PARTICIPANT,
            eprosima::qosprof::tag::PROFILE_NAME,
            profile_id);
        rtpsNode = getNode(*participantNode, eprosima::qosprof::tag::RTPS);
        nameNode = getNode(*rtpsNode, eprosima::qosprof::tag::NAME);
    }
    catch (eprosima::qosprof::ElementNotFound ex)
    {
        // Throw exception if no nodes
        throw eprosima::qosprof::ElementNotFound(ex);

        closeXML();
        return NULL;
    }

    // Print name
    return xercesc::XMLString::transcode(nameNode->getNodeValue());
}

std::string print_ignore_non_matching_locators(
        const std::string& xml_file,
        const std::string& profile_id)
{
    throw eprosima::qosprof::Unsupported("Unsupported");
}

std::string print_send_socket_buffer_size(
        const std::string& xml_file,
        const std::string& profile_id)
{
    throw eprosima::qosprof::Unsupported("Unsupported");
}

std::string print_listen_socket_buffer_size(
        const std::string& xml_file,
        const std::string& profile_id)
{
    throw eprosima::qosprof::Unsupported("Unsupported");
}

std::string print_participant_id(
        const std::string& xml_file,
        const std::string& profile_id)
{
    throw eprosima::qosprof::Unsupported("Unsupported");
}

std::string print_user_transport(
        const std::string& xml_file,
        const std::string& profile_id)
{
    throw eprosima::qosprof::Unsupported("Unsupported");
}

std::string print_user_transport(
        const std::string& xml_file,
        const std::string& profile_id,
        int32_t index)
{
    throw eprosima::qosprof::Unsupported("Unsupported");
}

std::string print_use_builtin_transports(
        const std::string& xml_file,
        const std::string& profile_id)
{
    throw eprosima::qosprof::Unsupported("Unsupported");
}

std::string print_user_data(
        const std::string& xml_file,
        const std::string& profile_id)
{
    throw eprosima::qosprof::Unsupported("Unsupported");
}

std::string print_user_data(
        const std::string& xml_file,
        const std::string& profile_id,
        int32_t index)
{
    throw eprosima::qosprof::Unsupported("Unsupported");
}

std::string print_prefix(
        const std::string& xml_file,
        const std::string& profile_id)
{
    throw eprosima::qosprof::Unsupported("Unsupported");
}

uint32_t user_transport_size(
        const std::string& xml_file,
        const std::string& profile_id)
{
    throw eprosima::qosprof::Unsupported("Unsupported");
}

uint32_t user_data_size(
        const std::string& xml_file,
        const std::string& profile_id)
{
    throw eprosima::qosprof::Unsupported("Unsupported");
}

void clear(
        const std::string& xml_file)
{
    throw eprosima::qosprof::Unsupported("Unsupported");
}

void clear(
        const std::string& xml_file,
        const std::string& profile_id)
{
    throw eprosima::qosprof::Unsupported("Unsupported");
}

void clear_default_profile(
        const std::string& xml_file)
{
    throw eprosima::qosprof::Unsupported("Unsupported");
}

void clear_domain_id(
        const std::string& xml_file,
        const std::string& profile_id)
{
    throw eprosima::qosprof::Unsupported("Unsupported");
}

void clear_name(
        const std::string& xml_file,
        const std::string& profile_id)
{
    xercesc::XercesDOMParser* xmlParser = NULL;
    xercesc::DOMDocument* xmlDoc = NULL;
    xercesc::DOMNode* profilesNode = NULL;
    xercesc::DOMNode* participantNode = NULL;
    xercesc::DOMNode* rtpsNode = NULL;
    xercesc::DOMNode* nameNode = NULL;

    // Open xml_file
    try
    {
        xmlParser = openXML(xml_file);
    }
    catch (const eprosima::qosprof::FileNotFound ex)
    {
        // Given file does not exist
        throw eprosima::qosprof::FileNotFound(ex);
        return NULL;
    }
    catch (const eprosima::qosprof::Unsupported ex)
    {
        // Could not initialize XML workspace
        throw eprosima::qosprof::Unsupported(ex);
        return NULL;
    }

    // Obtain nodes
    try
    {
        profilesNode = getNode(*xmlParser, eprosima::qosprof::tag::PROFILES);
        participantNode = getNode(
            *profilesNode,
            eprosima::qosprof::tag::PARTICIPANT,
            eprosima::qosprof::tag::PROFILE_NAME,
            profile_id);
        rtpsNode = getNode(*participantNode, eprosima::qosprof::tag::RTPS);
        nameNode = getNode(*rtpsNode, eprosima::qosprof::tag::NAME);
    }
    catch (eprosima::qosprof::ElementNotFound ex)
    {
        // Throw exception if no nodes
        throw eprosima::qosprof::ElementNotFound(ex);

        closeXML();
        return NULL;
    }

    // remove name
    rtpsNode->removeChild(nameNode);

    // Validate new element
    try {
        xmlDoc = xmlParser->getDocument();
        saveXML("temp.xml", *xmlDoc);
        validateXML("temp.xml", *xmlParser);
    }
    catch (const eprosima::qosprof::Unsupported& ex)
    {
        throw eprosima::qosprof::Unsupported(ex);
        closeXML();
        return;
    }
    catch (const eprosima::qosprof::ElementInvalid& ex)
    {
        throw eprosima::qosprof::ElementInvalid(ex);
        closeXML();
        return;
    }

    // Save if valid
    try
    {
        xmlDoc = xmlParser->getDocument();
        saveXML(xml_file, *xmlDoc);
    }
    catch(const eprosima::qosprof::Unsupported& ex)
    {
        throw eprosima::qosprof::Unsupported(ex);
    }

    closeXML();
    return;
}

void clear_ignore_non_matching_locators(
        const std::string& xml_file,
        const std::string& profile_id)
{
    throw eprosima::qosprof::Unsupported("Unsupported");
}

void clear_send_socket_buffer_size(
        const std::string& xml_file,
        const std::string& profile_id)
{
    throw eprosima::qosprof::Unsupported("Unsupported");
}

void clear_listen_socket_buffer_size(
        const std::string& xml_file,
        const std::string& profile_id)
{
    throw eprosima::qosprof::Unsupported("Unsupported");
}

void clear_participant_id(
        const std::string& xml_file,
        const std::string& profile_id)
{
    throw eprosima::qosprof::Unsupported("Unsupported");
}

void clear_user_transports(
        const std::string& xml_file,
        const std::string& profile_id)
{
    throw eprosima::qosprof::Unsupported("Unsupported");
}

void clear_user_transports(
        const std::string& xml_file,
        const std::string& profile_id,
        int32_t index)
{
    throw eprosima::qosprof::Unsupported("Unsupported");
}

void clear_use_builtin_transports(
        const std::string& xml_file,
        const std::string& profile_id)
{
    throw eprosima::qosprof::Unsupported("Unsupported");
}

void clear_user_data(
        const std::string& xml_file,
        const std::string& profile_id)
{
    throw eprosima::qosprof::Unsupported("Unsupported");
}

void clear_user_data(
        const std::string& xml_file,
        const std::string& profile_id,
        int32_t index)
{
    throw eprosima::qosprof::Unsupported("Unsupported");
}

void clear_prefix(
        const std::string& xml_file,
        const std::string& profile_id)
{
    throw eprosima::qosprof::Unsupported("Unsupported");
}

void set_default_profile(
        const std::string& xml_file,
        const std::string& profile_id)
{
    throw eprosima::qosprof::Unsupported("Unsupported");
}

void set_domain_id(
        const std::string& xml_file,
        const std::string& profile_id,
        const std::string& domain_id)
{
    throw eprosima::qosprof::Unsupported("Unsupported");
}

void set_name(
        const std::string& xml_file,
        const std::string& profile_id,
        const std::string& name)
{

    xercesc::XercesDOMParser* xmlParser = NULL;
    xercesc::DOMDocument* xmlDoc = NULL;
    xercesc::DOMNode* profilesNode = NULL;
    xercesc::DOMNode* participantNode = NULL;
    xercesc::DOMNode* rtpsNode = NULL;
    xercesc::DOMNode* nameNode = NULL;
    xercesc::DOMText* nameValue = NULL;

    // Open xml_file
    try
    {
        xmlParser = openXML(xml_file);
    }
    catch (const eprosima::qosprof::FileNotFound& ex)
    {
        // Given file does not exist
        throw eprosima::qosprof::FileNotFound(ex);
        return;
    }
    catch (const Unsupported& ex)
    {
        // Could not initialize XML workspace
        throw eprosima::qosprof::Unsupported(ex);
        return;
    }

    // Obtain profilesNode
    try
    {
        profilesNode = getNode(*xmlParser, "profiles");
    }
    catch (const eprosima::qosprof::ElementNotFound& ex)
    {
        // Create if not exist
        if (!profilesNode)
        {
            // Root does not exist, create element
            xercesc::DOMImplementation* xmlImplementation =
                xercesc::DOMImplementationRegistry::getDOMImplementation (xercesc::XMLString::transcode("Core"));
            if (xmlImplementation == NULL)
            {
                // Could not initialize XML workspace
                throw eprosima::qosprof::Unsupported("Could not initialize XML workspace");

                closeXML();
                return;
            }

            // Create root element as profiles plus xmls link
            xmlDoc = xmlImplementation->createDocument(0, xercesc::XMLString::transcode("dds"), 0);
            xercesc::DOMElement* rootElement = xmlDoc->getDocumentElement();
            rootElement->setAttribute(
                xercesc::XMLString::transcode("xmlns"),
                xercesc::XMLString::transcode("http://www.eprosima.com/XMLSchemas/fastRTPS_Profiles"));

            // Add profiles
            profilesNode = (xercesc::DOMNode*) xmlDoc->createElement(xercesc::XMLString::transcode("profiles"));
            rootElement->appendChild(profilesNode);
        }
    }

    // Obtain participantNode with the profile id
    try
    {
        participantNode = getNode(*profilesNode, "participant", "profile_name", profile_id);
    }
    catch (const eprosima::qosprof::ElementNotFound& ex)
    {
        // Create if not exist
        if (!participantNode)
        {
            xmlDoc = xmlParser->getDocument();
            xercesc::DOMElement * participantElement = xmlDoc->createElement(xercesc::XMLString::transcode("participant"));
            profilesNode->appendChild(participantElement);
            participantElement->setAttribute(
                xercesc::XMLString::transcode("profile_name"),
                xercesc::XMLString::transcode(profile_id.c_str()));
            participantNode = (xercesc::DOMNode*)participantElement;
        }
    }

    // Obtain rtpsNode
    try
    {
        rtpsNode = getNode(*participantNode, "rtps");
    }
    catch (const eprosima::qosprof::ElementNotFound& ex)
    {
        // Create if not exist
        if (!rtpsNode)
        {
            xmlDoc = xmlParser->getDocument();
            rtpsNode = (xercesc::DOMNode*) xmlDoc->createElement(xercesc::XMLString::transcode("rtps"));
            participantNode->appendChild(rtpsNode);
        }
    }

    // Obtain name
    try
    {
        nameNode = getNode(*rtpsNode, "name");
    }
    catch (const eprosima::qosprof::ElementNotFound& ex)
    {
        // Create if not exist
        if (!nameNode)
        {
            xmlDoc = xmlParser->getDocument();
            nameNode = (xercesc::DOMNode*) xmlDoc->createElement(xercesc::XMLString::transcode("name"));
            rtpsNode->appendChild(nameNode);
        }
    }

    // Set name value
    nameValue = xmlDoc->createTextNode(xercesc::XMLString::transcode(name.c_str()));
    nameNode->appendChild(nameValue);

    // Validate new element
    try {
        xmlDoc = xmlParser->getDocument();
        saveXML("temp.xml", *xmlDoc);
        validateXML("temp.xml", *xmlParser);
    }
    catch (const eprosima::qosprof::Unsupported& ex)
    {
        throw eprosima::qosprof::Unsupported(ex);
        closeXML();
        return;
    }
    catch (const eprosima::qosprof::ElementInvalid& ex)
    {
        throw eprosima::qosprof::ElementInvalid(ex);
        closeXML();
        return;
    }

    // Save if valid
    try
    {
        xmlDoc = xmlParser->getDocument();
        saveXML(xml_file, *xmlDoc);
    }
    catch(const eprosima::qosprof::Unsupported& ex)
    {
        throw eprosima::qosprof::Unsupported(ex);
    }

    closeXML();
    return;
}

void set_ignore_non_matching_locators(
        const std::string& xml_file,
        const std::string& profile_id,
        const std::string& ignore_non_matching_locators)
{
    throw eprosima::qosprof::Unsupported("Unsupported");
}

void set_send_socket_buffer_size(
        const std::string& xml_file,
        const std::string& profile_id,
        const std::string& send_socket_buffer_size)
{
    throw eprosima::qosprof::Unsupported("Unsupported");
}

void set_listen_socket_buffer_size(
        const std::string& xml_file,
        const std::string& profile_id,
        const std::string& listen_socket_buffer_size)
{
    throw eprosima::qosprof::Unsupported("Unsupported");
}

void set_participant_id(
        const std::string& xml_file,
        const std::string& profile_id,
        const std::string& participant_id)
{
    throw eprosima::qosprof::Unsupported("Unsupported");
}

void set_use_builtin_transports(
        const std::string& xml_file,
        const std::string& profile_id,
        const std::string& use_builtin_transports)
{
    throw eprosima::qosprof::Unsupported("Unsupported");
}

void set_prefix(
        const std::string& xml_file,
        const std::string& profile_id,
        const std::string& prefix)
{
    throw eprosima::qosprof::Unsupported("Unsupported");
}

void push_user_transports(
        const std::string& xml_file,
        const std::string& profile_id,
        const std::string& transport_id)
{
    throw eprosima::qosprof::Unsupported("Unsupported");
}

void update_user_transports(
        const std::string& xml_file,
        const std::string& profile_id,
        const std::string& transport_id,
        int32_t index)
{
    throw eprosima::qosprof::Unsupported("Unsupported");
}

void push_user_data(
        const std::string& xml_file,
        const std::string& profile_id,
        const std::string& user_data)
{
    throw eprosima::qosprof::Unsupported("Unsupported");
}

void update_user_data(
        const std::string& xml_file,
        const std::string& profile_id,
        const std::string& user_data,
        int32_t index)
{
    throw eprosima::qosprof::Unsupported("Unsupported");
}

} // domain_participant
} // qosprof
} // eprosima
