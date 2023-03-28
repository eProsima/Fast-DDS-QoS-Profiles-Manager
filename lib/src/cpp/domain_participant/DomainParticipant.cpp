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
#include <utils/ParseXML.hpp>
#include <utils/ParseXMLTags.hpp>

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
    xercesc::XercesDOMParser* parser = NULL;
    xercesc::DOMDocument* doc = NULL;
    xercesc::DOMNode* profiles_node = NULL;
    xercesc::DOMNode* participant_node = NULL;

    // Open xml_file
    try
    {
        parser = open_xml(xml_file);
        doc = parser->getDocument();
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
        // Obtain profiles from root
        profiles_node = get_node(doc, eprosima::qosprof::tag::PROFILES);
    }
    catch (eprosima::qosprof::ElementNotFound ex)
    {
        // Throw exception if no nodes
        throw eprosima::qosprof::ElementNotFound(ex);

        close_xml();
        return NULL;
    }

    // Get list of participants
    xercesc::DOMNodeList* participant_list = ((xercesc::DOMElement *) profiles_node)->getElementsByTagName(
        xercesc::XMLString::transcode(eprosima::qosprof::tag::PARTICIPANT));

    // Iterate throw the participants to check which one is default
    // TODO try with node->getNextSibling();
    xercesc::DOMNode* participant = NULL;
    for (int i=0, j=0, size=participant_list->getLength(); i<size && j==0; i++)
    {
        participant = participant_list->item(i);
        xercesc::DOMNode* default_profile_node = participant->getAttributes()->getNamedItem(
            xercesc::XMLString::transcode(eprosima::qosprof::tag::DEFAULT_PROF));
        if (default_profile_node != NULL)
        {
            if (default_profile_node->getNodeValue() == xercesc::XMLString::transcode("true"))
            {
                j++;
            }
            else
            {
                participant = NULL;
            }
        }
        else
        {
            participant = NULL;
        }
    }

    // Throw exception if there are not default participant profile
    if (participant == NULL)
    {
        // Given file does not exist
        throw eprosima::qosprof::ElementNotFound(
            "There is no default participant in " + xml_file + "\n");
        close_xml();
        return NULL;
    }

    // Return participant id as std::string
    return xercesc::XMLString::transcode(participant->getAttributes()->getNamedItem(
        xercesc::XMLString::transcode(eprosima::qosprof::tag::PROFILE_NAME))->getNodeValue());
}

std::string print_domain_id(
        const std::string& xml_file,
        const std::string& profile_id)
{
    xercesc::XercesDOMParser* parser = NULL;
    xercesc::DOMDocument* doc = NULL;
    xercesc::DOMNode* profiles_node = NULL;
    xercesc::DOMNode* participant_node = NULL;
    xercesc::DOMNode* domainIdNode = NULL;

    // Open xml_file
    try
    {
        parser = open_xml(xml_file);
        doc = parser->getDocument();
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
        profiles_node = get_node(doc, eprosima::qosprof::tag::PROFILES);
        participant_node = get_node(
            *profiles_node,
            eprosima::qosprof::tag::PARTICIPANT,
            eprosima::qosprof::tag::PROFILE_NAME,
            profile_id);
        domainIdNode = get_node(*participant_node, eprosima::qosprof::tag::DOMAIN_ID);
    }
    catch (eprosima::qosprof::ElementNotFound ex)
    {
        // Throw exception if no nodes
        throw eprosima::qosprof::ElementNotFound(ex);

        close_xml();
        return NULL;
    }

    // Print domainId
    return xercesc::XMLString::transcode(domainIdNode->getNodeValue());
}

std::string print_name(
        const std::string& xml_file,
        const std::string& profile_id)
{
    xercesc::XercesDOMParser* parser = NULL;
    xercesc::DOMDocument* doc = NULL;
    xercesc::DOMNode* profiles_node = NULL;
    xercesc::DOMNode* participant_node = NULL;
    xercesc::DOMNode* rtps_node = NULL;
    xercesc::DOMNode* name_node = NULL;

    // Open xml_file
    try
    {
        parser = open_xml(xml_file);
        doc = parser->getDocument();
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
        profiles_node = get_node(doc, eprosima::qosprof::tag::PROFILES);
        participant_node = get_node(
            *profiles_node,
            eprosima::qosprof::tag::PARTICIPANT,
            eprosima::qosprof::tag::PROFILE_NAME,
            profile_id);
        rtps_node = get_node(*participant_node, eprosima::qosprof::tag::RTPS);
        name_node = get_node(*rtps_node, eprosima::qosprof::tag::NAME);
    }
    catch (eprosima::qosprof::ElementNotFound ex)
    {
        // Throw exception if no nodes
        throw eprosima::qosprof::ElementNotFound(ex);

        close_xml();
        return NULL;
    }

    // Print name
    return xercesc::XMLString::transcode(name_node->getNodeValue());
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
    xercesc::XercesDOMParser* parser = NULL;
    xercesc::DOMDocument* doc = NULL;
    xercesc::DOMNode* profiles_node = NULL;
    xercesc::DOMNode* participant_node = NULL;
    xercesc::DOMNode* rtps_node = NULL;
    xercesc::DOMNode* name_node = NULL;

    // Open xml_file
    try
    {
        parser = open_xml(xml_file);
        doc = parser->getDocument();
    }
    catch (const eprosima::qosprof::FileNotFound ex)
    {
        // Given file does not exist
        throw eprosima::qosprof::FileNotFound(ex);
        return;
    }
    catch (const eprosima::qosprof::Unsupported ex)
    {
        // Could not initialize XML workspace
        throw eprosima::qosprof::Unsupported(ex);
        return;
    }

    // Obtain nodes
    try
    {
        profiles_node = get_node(doc, eprosima::qosprof::tag::PROFILES);
        participant_node = get_node(
            *profiles_node,
            eprosima::qosprof::tag::PARTICIPANT,
            eprosima::qosprof::tag::PROFILE_NAME,
            profile_id);
        rtps_node = get_node(*participant_node, eprosima::qosprof::tag::RTPS);
        name_node = get_node(*rtps_node, eprosima::qosprof::tag::NAME);
    }
    catch (eprosima::qosprof::ElementNotFound ex)
    {
        // Throw exception if no nodes
        throw eprosima::qosprof::ElementNotFound(ex);

        close_xml();
        return;
    }

    // remove name
    rtps_node->removeChild(name_node);

    // Validate new element
    try {
        save_xml("temp.xml", *doc);
        validate_xml("temp.xml", *parser);
    }
    catch (const eprosima::qosprof::Unsupported& ex)
    {
        throw eprosima::qosprof::Unsupported(ex);
        close_xml();
        return;
    }
    catch (const eprosima::qosprof::ElementInvalid& ex)
    {
        throw eprosima::qosprof::ElementInvalid(ex);
        close_xml();
        return;
    }

    // Save if valid
    try
    {
        save_xml(xml_file, *doc);
    }
    catch(const eprosima::qosprof::Unsupported& ex)
    {
        throw eprosima::qosprof::Unsupported(ex);
    }

    close_xml();
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
    xercesc::XercesDOMParser* parser = NULL;
    xercesc::DOMDocument* doc = NULL;
    xercesc::DOMNode* profiles_node = NULL;
    xercesc::DOMNode* participant_node = NULL;
    xercesc::DOMNode* default_profile_node = NULL;

    // Open xml_file
    try
    {
        parser = open_xml(xml_file);
        doc = parser->getDocument();
    }
    // Given file does not exist
    catch (const eprosima::qosprof::FileNotFound& ex)
    {
        throw eprosima::qosprof::FileNotFound(ex);
        return;
    }

    // Obtain profiles_node
    try
    {
        profiles_node = get_node(doc, eprosima::qosprof::tag::PROFILES);
    }
    catch (const eprosima::qosprof::ElementNotFound& ex)
    {
        throw eprosima::qosprof::ElementNotFound(ex);
        return;
    }

    // Obtain participant_node with the profile id
    try
    {
        participant_node = get_node(
            *profiles_node,
            eprosima::qosprof::tag::PARTICIPANT,
            eprosima::qosprof::tag::PROFILE_NAME,
            profile_id);
    }
    catch (const eprosima::qosprof::ElementNotFound& ex)
    {
        throw eprosima::qosprof::ElementNotFound(ex);
        return;
    }

    // Check if default profile defined
    default_profile_node = participant_node->getAttributes()->getNamedItem(
            xercesc::XMLString::transcode(eprosima::qosprof::tag::DEFAULT_PROF));
    if (default_profile_node != NULL)
    {
        if (default_profile_node->getNodeValue() == xercesc::XMLString::transcode("true"))
        {
            // This profile is already the default profile
            close_xml();
            return;
        }
    }

    // Set all participants as NOT default profile
    xercesc::DOMNodeList* participant_list = ((xercesc::DOMElement *) profiles_node)->getElementsByTagName(
        xercesc::XMLString::transcode(eprosima::qosprof::tag::PARTICIPANT));

    // Iterate throw the participants to set them as NOT default
    // TODO try with node->getNextSibling();
    for (int i=0, size=participant_list->getLength(); i<size; i++)
    {
        ((xercesc::DOMElement*)participant_list->item(i))->setAttribute(
            xercesc::XMLString::transcode(eprosima::qosprof::tag::DEFAULT_PROF),
            xercesc::XMLString::transcode("false"));
    }

    // Set given participant as default profile
    ((xercesc::DOMElement*)participant_node)->setAttribute(
        xercesc::XMLString::transcode(eprosima::qosprof::tag::DEFAULT_PROF),
        xercesc::XMLString::transcode("true"));

    // Validate new element
    /*try {
        save_xml("temp.xml", *doc);
        validate_xml("temp.xml", *parser);
    }
    catch (const eprosima::qosprof::Unsupported& ex)
    {
        throw eprosima::qosprof::Unsupported(ex);
        close_xml();
        return;
    }
    catch (const eprosima::qosprof::ElementInvalid& ex)
    {
        throw eprosima::qosprof::ElementInvalid(ex);
        close_xml();
        return;
    }*/

    // Save if valid
    try
    {
        save_xml(xml_file, *doc);
    }
    catch(const eprosima::qosprof::Unsupported& ex)
    {
        throw eprosima::qosprof::Unsupported(ex);
    }

    close_xml();
    return;
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

    xercesc::XercesDOMParser* parser = NULL;
    xercesc::DOMDocument* doc = NULL;
    xercesc::DOMNode* profiles_node = NULL;
    xercesc::DOMNode* participant_node = NULL;
    xercesc::DOMNode* rtps_node = NULL;
    xercesc::DOMNode* name_node = NULL;
    xercesc::DOMText* name_value = NULL;

    // Open xml_file
    try
    {
        parser = open_xml(xml_file);
        doc = parser->getDocument();
    }
    // Given file does not exist
    catch (const eprosima::qosprof::FileNotFound& ex)
    {
        // Create file
        try
        {
            doc = create_xml(xml_file);
            parser = new xercesc::XercesDOMParser();
        }

        // ERROR
        catch (const eprosima::qosprof::FileNotFound& ex)
        {
            throw eprosima::qosprof::FileNotFound(ex);
            return;
        }
    }

    // Obtain profiles_node
    try
    {
        profiles_node = get_node(doc, eprosima::qosprof::tag::PROFILES);
    }
    catch (const eprosima::qosprof::ElementNotFound& ex)
    {
        // Obtain root element
        xercesc::DOMElement* rootElement = doc->getDocumentElement();

        // Add profiles
        profiles_node = (xercesc::DOMNode*) doc->createElement(xercesc::XMLString::transcode(eprosima::qosprof::tag::PROFILES));
        rootElement->appendChild(profiles_node);
    }

    // Obtain participant_node with the profile id
   try
    {
        participant_node = get_node(
            *profiles_node,
            eprosima::qosprof::tag::PARTICIPANT,
            eprosima::qosprof::tag::PROFILE_NAME,
            profile_id);
    }
    catch (const eprosima::qosprof::ElementNotFound& ex)
    {
        // Create if not exist
        xercesc::DOMElement * participant_element = doc->createElement(
            xercesc::XMLString::transcode(eprosima::qosprof::tag::PARTICIPANT));
        profiles_node->appendChild(participant_element);
        participant_element->setAttribute(
            xercesc::XMLString::transcode(eprosima::qosprof::tag::PROFILE_NAME),
            xercesc::XMLString::transcode(profile_id.c_str()));
        participant_node = (xercesc::DOMNode*)participant_element;

    }

    // Obtain rtps_node
    try
    {
        rtps_node = get_node(*participant_node, eprosima::qosprof::tag::RTPS);
    }
    catch (const eprosima::qosprof::ElementNotFound& ex)
    {
        // Create if not exist
        rtps_node = (xercesc::DOMNode*) doc->createElement(xercesc::XMLString::transcode(
            eprosima::qosprof::tag::RTPS));
        participant_node->appendChild(rtps_node);

    }

    // Obtain name
    try
    {
        name_node = get_node(*rtps_node, eprosima::qosprof::tag::NAME);
    }
    catch (const eprosima::qosprof::ElementNotFound& ex)
    {
        // Create if not exist
        name_node = (xercesc::DOMNode*) doc->createElement(xercesc::XMLString::transcode(
            eprosima::qosprof::tag::NAME));
        rtps_node->appendChild(name_node);
    }

    // Set name value
    name_value = doc->createTextNode(xercesc::XMLString::transcode(name.c_str()));
    name_node->appendChild(name_value);

    // Validate new element
    /*try {
        save_xml("temp.xml", *doc);
        validate_xml("temp.xml", *parser);
    }
    catch (const eprosima::qosprof::Unsupported& ex)
    {
        throw eprosima::qosprof::Unsupported(ex);
        close_xml();
        return;
    }
    catch (const eprosima::qosprof::ElementInvalid& ex)
    {
        throw eprosima::qosprof::ElementInvalid(ex);
        close_xml();
        return;
    }*/

    // Save if valid
    try
    {
        save_xml(xml_file, *doc);
    }
    catch(const eprosima::qosprof::Unsupported& ex)
    {
        throw eprosima::qosprof::Unsupported(ex);
    }

    close_xml();
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
