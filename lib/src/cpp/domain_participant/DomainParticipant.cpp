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

#include <fastdds_qos_profiles_manager/domain_participant/DomainParticipant.hpp>

#include <string>
#include <vector>

#include <fastdds_qos_profiles_manager/exception/Exception.hpp>

#include <utils/ParseXML.hpp>
#include <utils/ParseXMLTags.hpp>

namespace eprosima {
namespace qosprof {
namespace domain_participant {

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
    throw Unsupported("Unsupported");
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
        const std::string& index)
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
        const std::string& index)
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
        const std::string& index)
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
        const std::string& index)
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
    // Xerces document manage XML elements
    xercesc::DOMDocument* doc = nullptr;

    // XML nodes and values
    xercesc::DOMNode* profiles_node = nullptr;
    xercesc::DOMNode* participant_node = nullptr;
    xercesc::DOMNode* default_profile_node = nullptr;

    // Create XML manager and initialize the document
    eprosima::qosprof::utils::ParseXML* manager = new eprosima::qosprof::utils::ParseXML(xml_file, true);
    doc = manager->get_doc();

    // Obtain nodes
    profiles_node = manager->get_node(eprosima::qosprof::utils::tag::PROFILES);
    participant_node = manager->get_node(
        profiles_node,
        eprosima::qosprof::utils::tag::PARTICIPANT,
        eprosima::qosprof::utils::tag::PROFILE_NAME,
        profile_id);


    // Check if default profile already defined
    default_profile_node = participant_node->getAttributes()->getNamedItem(
        xercesc::XMLString::transcode(eprosima::qosprof::utils::tag::DEFAULT_PROFILE));
    if (default_profile_node != nullptr)
    {
        if (default_profile_node->getNodeValue() == xercesc::XMLString::transcode("true"))
        {
            // This profile is already the default profile
            return;
        }
    }

    // Set all participants as NOT default profile
    xercesc::DOMNodeList* participant_list = static_cast<xercesc::DOMElement*>(profiles_node)->getElementsByTagName(
        xercesc::XMLString::transcode(eprosima::qosprof::utils::tag::PARTICIPANT));
    // Iterate throw all the participants to set them as NOT default
    for (int i = 0, size = participant_list->getLength(); i < size; i++)
    {
        static_cast<xercesc::DOMElement*>(participant_list->item(i))->setAttribute(
            xercesc::XMLString::transcode(eprosima::qosprof::utils::tag::DEFAULT_PROFILE),
            xercesc::XMLString::transcode("false"));
    }

    // Set given participant as default profile
    static_cast<xercesc::DOMElement*>(participant_node)->setAttribute(
        xercesc::XMLString::transcode(eprosima::qosprof::utils::tag::DEFAULT_PROFILE),
        xercesc::XMLString::transcode("true"));

    // Validate new XML element and save it
    manager->validate_and_save_xml_document();
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
    // Xerces document manage XML elements
    xercesc::DOMDocument* doc = nullptr;

    // XML nodes and values
    xercesc::DOMNode* profiles_node = nullptr;
    xercesc::DOMNode* participant_node = nullptr;
    xercesc::DOMNode* rtps_node = nullptr;
    xercesc::DOMNode* name_node = nullptr;

    // Create XML manager and initialize the document
    eprosima::qosprof::utils::ParseXML* manager = new eprosima::qosprof::utils::ParseXML(xml_file, true);
    doc = manager->get_doc();

    // Obtain profiles node
    try
    {
        profiles_node = manager->get_node(eprosima::qosprof::utils::tag::PROFILES);
    }
    catch (const eprosima::qosprof::ElementNotFound& ex)
    {
        // Obtain root element
        xercesc::DOMElement* root_element = doc->getDocumentElement();

        // Add profiles
        profiles_node = static_cast<xercesc::DOMNode*>(doc->createElement(
                    xercesc::XMLString::transcode(eprosima::qosprof::utils::tag::PROFILES)));
        root_element->appendChild(profiles_node);
    }
    // Obtain participant node with the profile id
    try
    {
        participant_node = manager->get_node(
            profiles_node,
            eprosima::qosprof::utils::tag::PARTICIPANT,
            eprosima::qosprof::utils::tag::PROFILE_NAME,
            profile_id);
    }
    catch (const eprosima::qosprof::ElementNotFound& ex)
    {
        // create if not existent
        xercesc::DOMElement* participant_element = doc->createElement(
            xercesc::XMLString::transcode(eprosima::qosprof::utils::tag::PARTICIPANT));
        profiles_node->appendChild(participant_element);
        participant_element->setAttribute(
            xercesc::XMLString::transcode(eprosima::qosprof::utils::tag::PROFILE_NAME),
            xercesc::XMLString::transcode(profile_id.c_str()));
        participant_node = static_cast<xercesc::DOMNode*>(participant_element);
    }

    // Obtain rtps node
    try
    {
        rtps_node = manager->get_node(participant_node, eprosima::qosprof::utils::tag::RTPS);
    }
    catch (const eprosima::qosprof::ElementNotFound& ex)
    {
        // create if not existent
        rtps_node = static_cast<xercesc::DOMNode*>(doc->createElement(
                    xercesc::XMLString::transcode(eprosima::qosprof::utils::tag::RTPS)));
        participant_node->appendChild(rtps_node);
    }

    // Obtain name
    try
    {
        name_node = manager->get_node(rtps_node, eprosima::qosprof::utils::tag::NAME);
    }
    catch (const eprosima::qosprof::ElementNotFound& ex)
    {
        // create if not existent
        name_node = static_cast<xercesc::DOMNode*>(doc->createElement(
                    xercesc::XMLString::transcode(eprosima::qosprof::utils::tag::NAME)));
        rtps_node->appendChild(name_node);
    }

    // Set the name node value
    manager->set_value_to_node(name_node, name);

    // Validate new XML element and save it
    manager->validate_and_save_xml_document();
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

void set_user_transports(
        const std::string& xml_file,
        const std::string& profile_id,
        const std::string& transport_id,
        const std::string& index)
{
    throw Unsupported("Unsupported");
}

void set_user_data(
        const std::string& xml_file,
        const std::string& profile_id,
        const std::string& user_data,
        const std::string& index)
{
    throw Unsupported("Unsupported");
}

} // domain_participant
} // qosprof
} // eprosima
