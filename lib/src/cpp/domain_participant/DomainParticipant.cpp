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
 * @file DomainParticipant.cpp
 */

#include <fastdds_qos_profiles_manager/domain_participant/DomainParticipant.hpp>

#include <string>
#include <vector>

#include <fastdds_qos_profiles_manager/exception/Exception.hpp>

#include <utils/ParseXML.hpp>
#include <utils/ParseXMLErrorHandler.hpp>
#include <utils/ParseXMLString.hpp>
#include <utils/ParseXMLTags.hpp>

namespace eprosima {
namespace qosprof {
namespace domain_participant {

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
    throw eprosima::qosprof::Unsupported("Unsupported");
}

std::string print_name(
        const std::string& xml_file,
        const std::string& profile_id)
{
    throw eprosima::qosprof::Unsupported("Unsupported");
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
        const std::string& index)
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
        const std::string& index)
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
    // Xerces objects to manage XML elements
    xercesc::DOMConfiguration* config = NULL;
    xercesc::DOMDocument* doc = NULL;
    eprosima::qosprof::parse::ParseXMLErrorHandler* error_handler = NULL;
    xercesc::DOMImplementation* implementation = NULL;
    xercesc::DOMLSOutput* output = NULL;
    xercesc::XercesDOMParser* parser = NULL;
    xercesc::DOMLSSerializer* serializer = NULL;
    xercesc::XMLFormatTarget* target = NULL;

    // XML nodes and values
    xercesc::DOMNode* profiles_node = NULL;
    xercesc::DOMNode* participant_node = NULL;
    xercesc::DOMNode* rtps_node = NULL;
    xercesc::DOMNode* name_node = NULL;
    xercesc::DOMText* name_value = NULL;

    // Try to initialize XML workspace
    try
    {
        xercesc::XMLPlatformUtils::Initialize();
    }
    catch (const xercesc::XMLException& toCatch)
    {
        // Unable to initialize XML workspace
        throw eprosima::qosprof::FileNotFound(xercesc::XMLString::transcode(toCatch.getMessage()));
        return;
    }

    // Try to set up Xerces tools
    if (!initialize_tools(config, doc, error_handler, implementation, output, parser, serializer, target, xml_file))
    {
        // Close XML workspace
        xercesc::XMLPlatformUtils::Terminate();
        return;
    }

    // Obtain profiles node
    try
    {
        profiles_node = get_node(doc, eprosima::qosprof::tag::PROFILES);
    }
    catch (const eprosima::qosprof::ElementNotFound& ex)
    {
        // Obtain root element
        xercesc::DOMElement* root_element = doc->getDocumentElement();

        // Add profiles
        profiles_node = (xercesc::DOMNode*) doc->createElement(xercesc::XMLString::transcode(eprosima::qosprof::tag::PROFILES));
        root_element->appendChild(profiles_node);
    }

    // Obtain participant node with the profile id
   try
    {
        participant_node = get_node(
            profiles_node,
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

    // Obtain rtps node
    try
    {
        rtps_node = get_node(participant_node, eprosima::qosprof::tag::RTPS);
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
        name_node = get_node(rtps_node, eprosima::qosprof::tag::NAME);
    }
    catch (const eprosima::qosprof::ElementNotFound& ex)
    {
        // Create if not exist
        name_node = (xercesc::DOMNode*) doc->createElement(xercesc::XMLString::transcode(
            eprosima::qosprof::tag::NAME));
        rtps_node->appendChild(name_node);
    }

    // Remove all childs
    reset_node(name_node);

    // Set name value
    name_value = doc->createTextNode(xercesc::XMLString::transcode(name.c_str()));
    name_node->appendChild(name_value);

    // Validate new XML element and save it
    validate_and_save_xml_document(doc, error_handler, output, parser, serializer, target);

    // Close XML workspace
    xercesc::XMLPlatformUtils::Terminate();
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

void set_user_transports(
        const std::string& xml_file,
        const std::string& profile_id,
        const std::string& transport_id,
        const std::string& index)
{
    throw eprosima::qosprof::Unsupported("Unsupported");
}

void set_user_data(
        const std::string& xml_file,
        const std::string& profile_id,
        const std::string& user_data,
        const std::string& index)
{
    throw eprosima::qosprof::Unsupported("Unsupported");
}

} // domain_participant
} // qosprof
} // eprosima
