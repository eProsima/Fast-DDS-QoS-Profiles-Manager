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

#include <fastdds_qos_profiles_manager/domain_participant/builtin/MetatrafficExternalUnicastLocators.hpp>

#include <string>

#include <fastdds_qos_profiles_manager/exception/Exception.hpp>

#include <common/LocatorList.hpp>
#include <utils/ParseXML.hpp>
#include <utils/ParseXMLTags.hpp>

namespace eprosima {
namespace qosprof {
namespace domain_participant {
namespace builtin {
namespace metatraffic_external_unicast_locators {

std::string print(
        const std::string& xml_file,
        const std::string& profile_id,
        const std::string& index)
{
    throw Unsupported("Unsupported");
}

std::string print_kind(
        const std::string& xml_file,
        const std::string& profile_id,
        const std::string& index)
{
    throw Unsupported("Unsupported");
}

std::string print_port(
        const std::string& xml_file,
        const std::string& profile_id,
        const std::string& index)
{
    throw Unsupported("Unsupported");
}

std::string print_address(
        const std::string& xml_file,
        const std::string& profile_id,
        const std::string& index)
{
    throw Unsupported("Unsupported");
}

std::string print_externality(
        const std::string& xml_file,
        const std::string& profile_id,
        const std::string& index)
{
    throw Unsupported("Unsupported");
}

std::string print_cost(
        const std::string& xml_file,
        const std::string& profile_id,
        const std::string& index)
{
    throw Unsupported("Unsupported");
}

std::string print_mask(
        const std::string& xml_file,
        const std::string& profile_id,
        const std::string& index)
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
        const std::string& profile_id,
        const std::string& index)
{
    throw Unsupported("Unsupported");
}

void clear_port(
        const std::string& xml_file,
        const std::string& profile_id,
        const std::string& index)
{
    throw Unsupported("Unsupported");
}

void clear_address(
        const std::string& xml_file,
        const std::string& profile_id,
        const std::string& index)
{
    throw Unsupported("Unsupported");
}

void clear_externality(
        const std::string& xml_file,
        const std::string& profile_id,
        const std::string& index)
{
    throw Unsupported("Unsupported");
}

void clear_cost(
        const std::string& xml_file,
        const std::string& profile_id,
        const std::string& index)
{
    throw Unsupported("Unsupported");
}

void clear_mask(
        const std::string& xml_file,
        const std::string& profile_id,
        const std::string& index)
{
    throw Unsupported("Unsupported");
}

void set_kind(
        const std::string& xml_file,
        const std::string& profile_id,
        const std::string& kind,
        const std::string& index)
{
    throw Unsupported("Unsupported");
}

void set_port(
        const std::string& xml_file,
        const std::string& profile_id,
        const std::string& port,
        const std::string& index)
{
    // Xerces document manage XML elements
    xercesc::DOMDocument* doc = nullptr;

    // XML nodes and values
    xercesc::DOMNode* profiles_node = nullptr;
    xercesc::DOMNode* participant_node = nullptr;
    xercesc::DOMNode* rtps_node = nullptr;
    xercesc::DOMNode* builtin_node = nullptr;
    xercesc::DOMNode* locator_list_node = nullptr;
    xercesc::DOMNode* locator_node = nullptr;

    // Create XML manager and initialize the document
    utils::ParseXML* manager = new utils::ParseXML(xml_file, true);
    doc = manager->get_doc();

    // Obtain profiles node
    try
    {
        profiles_node = manager->get_node(utils::tag::PROFILES);
    }
    catch (const ElementNotFound& ex)
    {
        // Obtain root element
        xercesc::DOMElement* root_element = doc->getDocumentElement();

        // Add profiles
        profiles_node = static_cast<xercesc::DOMNode*>(doc->createElement(
                    xercesc::XMLString::transcode(utils::tag::PROFILES)));
        root_element->appendChild(profiles_node);
    }

    // Obtain participant node with the profile id
    try
    {
        participant_node = manager->get_node(
            profiles_node,
            utils::tag::PARTICIPANT,
            utils::tag::PROFILE_NAME,
            profile_id);
    }
    catch (const ElementNotFound& ex)
    {
        // create if not existent
        xercesc::DOMElement* participant_element = doc->createElement(
            xercesc::XMLString::transcode(utils::tag::PARTICIPANT));
        profiles_node->appendChild(participant_element);
        participant_element->setAttribute(
            xercesc::XMLString::transcode(utils::tag::PROFILE_NAME),
            xercesc::XMLString::transcode(profile_id.c_str()));
        participant_node = static_cast<xercesc::DOMNode*>(participant_element);
    }

    // Obtain rtps node
    try
    {
        rtps_node = manager->get_node(participant_node, utils::tag::RTPS);
    }
    catch (const ElementNotFound& ex)
    {
        // create if not existent
        rtps_node = static_cast<xercesc::DOMNode*>(doc->createElement(xercesc::XMLString::transcode(
                    utils::tag::RTPS)));
        participant_node->appendChild(rtps_node);
    }

    // Obtain builtin node
    try
    {
        builtin_node = manager->get_node(rtps_node, utils::tag::BUILTIN);
    }
    catch (const ElementNotFound& ex)
    {
        // create if not existent
        builtin_node = static_cast<xercesc::DOMNode*>(doc->createElement(xercesc::XMLString::transcode(
                    utils::tag::BUILTIN)));
        rtps_node->appendChild(builtin_node);
    }

    // Obtain meta-traffic external unicast locator list node
    try
    {
        locator_list_node = manager->get_node(builtin_node,
                        utils::tag::METATRAFFIC_EXTERNAL_UNICAST_LOCATOR_LIST);
    }
    catch (const ElementNotFound& ex)
    {
        // create if not existent
        locator_list_node = static_cast<xercesc::DOMNode*>(doc->createElement(xercesc::XMLString::transcode(
                    utils::tag::METATRAFFIC_EXTERNAL_UNICAST_LOCATOR_LIST)));
        builtin_node->appendChild(locator_list_node);
    }

    common::locator_list::set_port(*manager, locator_list_node, port, index, true);

    // Validate new XML element and save it
    manager->validate_and_save_xml_document();
}

void set_address(
        const std::string& xml_file,
        const std::string& profile_id,
        const std::string& address,
        const std::string& index)
{
    // Xerces document manage XML elements
    xercesc::DOMDocument* doc = nullptr;

    // XML nodes and values
    xercesc::DOMNode* profiles_node = nullptr;
    xercesc::DOMNode* participant_node = nullptr;
    xercesc::DOMNode* rtps_node = nullptr;
    xercesc::DOMNode* builtin_node = nullptr;
    xercesc::DOMNode* locator_list_node = nullptr;
    xercesc::DOMNode* locator_node = nullptr;

    // Create XML manager and initialize the document
    utils::ParseXML* manager = new utils::ParseXML(xml_file, true);
    doc = manager->get_doc();

    // Obtain profiles node
    try
    {
        profiles_node = manager->get_node(utils::tag::PROFILES);
    }
    catch (const ElementNotFound& ex)
    {
        // Obtain root element
        xercesc::DOMElement* root_element = doc->getDocumentElement();

        // Add profiles
        profiles_node = static_cast<xercesc::DOMNode*>(doc->createElement(
                    xercesc::XMLString::transcode(utils::tag::PROFILES)));
        root_element->appendChild(profiles_node);
    }

    // Obtain participant node with the profile id
    try
    {
        participant_node = manager->get_node(
            profiles_node,
            utils::tag::PARTICIPANT,
            utils::tag::PROFILE_NAME,
            profile_id);
    }
    catch (const ElementNotFound& ex)
    {
        // create if not existent
        xercesc::DOMElement* participant_element = doc->createElement(
            xercesc::XMLString::transcode(utils::tag::PARTICIPANT));
        profiles_node->appendChild(participant_element);
        participant_element->setAttribute(
            xercesc::XMLString::transcode(utils::tag::PROFILE_NAME),
            xercesc::XMLString::transcode(profile_id.c_str()));
        participant_node = static_cast<xercesc::DOMNode*>(participant_element);
    }

    // Obtain rtps node
    try
    {
        rtps_node = manager->get_node(participant_node, utils::tag::RTPS);
    }
    catch (const ElementNotFound& ex)
    {
        // create if not existent
        rtps_node = static_cast<xercesc::DOMNode*>(doc->createElement(xercesc::XMLString::transcode(
                    utils::tag::RTPS)));
        participant_node->appendChild(rtps_node);
    }

    // Obtain builtin node
    try
    {
        builtin_node = manager->get_node(rtps_node, utils::tag::BUILTIN);
    }
    catch (const ElementNotFound& ex)
    {
        // create if not existent
        builtin_node = static_cast<xercesc::DOMNode*>(doc->createElement(xercesc::XMLString::transcode(
                    utils::tag::BUILTIN)));
        rtps_node->appendChild(builtin_node);
    }

    // Obtain meta-traffic external unicast locator list node
    try
    {
        locator_list_node = manager->get_node(builtin_node,
                        utils::tag::METATRAFFIC_EXTERNAL_UNICAST_LOCATOR_LIST);
    }
    catch (const ElementNotFound& ex)
    {
        // create if not existent
        locator_list_node = static_cast<xercesc::DOMNode*>(doc->createElement(xercesc::XMLString::transcode(
                    utils::tag::METATRAFFIC_EXTERNAL_UNICAST_LOCATOR_LIST)));
        builtin_node->appendChild(locator_list_node);
    }

    common::locator_list::set_address(*manager, locator_list_node, address, index, true);

    // Validate new XML element and save it
    manager->validate_and_save_xml_document();
}

void set_externality(
        const std::string& xml_file,
        const std::string& profile_id,
        const std::string& externality,
        const std::string& index)
{
    // Xerces document manage XML elements
    xercesc::DOMDocument* doc = nullptr;

    // XML nodes and values
    xercesc::DOMNode* profiles_node = nullptr;
    xercesc::DOMNode* participant_node = nullptr;
    xercesc::DOMNode* rtps_node = nullptr;
    xercesc::DOMNode* builtin_node = nullptr;
    xercesc::DOMNode* locator_list_node = nullptr;
    xercesc::DOMNode* locator_node = nullptr;

    // Create XML manager and initialize the document
    utils::ParseXML* manager = new utils::ParseXML(xml_file, true);
    doc = manager->get_doc();

    // Obtain profiles node
    try
    {
        profiles_node = manager->get_node(utils::tag::PROFILES);
    }
    catch (const ElementNotFound& ex)
    {
        // Obtain root element
        xercesc::DOMElement* root_element = doc->getDocumentElement();

        // Add profiles
        profiles_node = static_cast<xercesc::DOMNode*>(doc->createElement(
                    xercesc::XMLString::transcode(utils::tag::PROFILES)));
        root_element->appendChild(profiles_node);
    }

    // Obtain participant node with the profile id
    try
    {
        participant_node = manager->get_node(
            profiles_node,
            utils::tag::PARTICIPANT,
            utils::tag::PROFILE_NAME,
            profile_id);
    }
    catch (const ElementNotFound& ex)
    {
        // create if not existent
        xercesc::DOMElement* participant_element = doc->createElement(
            xercesc::XMLString::transcode(utils::tag::PARTICIPANT));
        profiles_node->appendChild(participant_element);
        participant_element->setAttribute(
            xercesc::XMLString::transcode(utils::tag::PROFILE_NAME),
            xercesc::XMLString::transcode(profile_id.c_str()));
        participant_node = static_cast<xercesc::DOMNode*>(participant_element);
    }

    // Obtain rtps node
    try
    {
        rtps_node = manager->get_node(participant_node, utils::tag::RTPS);
    }
    catch (const ElementNotFound& ex)
    {
        // create if not existent
        rtps_node = static_cast<xercesc::DOMNode*>(doc->createElement(xercesc::XMLString::transcode(
                    utils::tag::RTPS)));
        participant_node->appendChild(rtps_node);
    }

    // Obtain builtin node
    try
    {
        builtin_node = manager->get_node(rtps_node, utils::tag::BUILTIN);
    }
    catch (const ElementNotFound& ex)
    {
        // create if not existent
        builtin_node = static_cast<xercesc::DOMNode*>(doc->createElement(xercesc::XMLString::transcode(
                    utils::tag::BUILTIN)));
        rtps_node->appendChild(builtin_node);
    }

    // Obtain meta-traffic external unicast locator list node
    try
    {
        locator_list_node = manager->get_node(builtin_node,
                        utils::tag::METATRAFFIC_EXTERNAL_UNICAST_LOCATOR_LIST);
    }
    catch (const ElementNotFound& ex)
    {
        // create if not existent
        locator_list_node = static_cast<xercesc::DOMNode*>(doc->createElement(xercesc::XMLString::transcode(
                    utils::tag::METATRAFFIC_EXTERNAL_UNICAST_LOCATOR_LIST)));
        builtin_node->appendChild(locator_list_node);
    }

    // Check if locator should be created
    if (index.empty())
    {
        locator_node = static_cast<xercesc::DOMNode*>(doc->createElement(xercesc::XMLString::transcode(
                    utils::tag::UDP_V4_LOCATOR)));
        locator_list_node->appendChild(locator_node);
    }
    // Update the locator of the given index
    else
    {
        locator_node = manager->get_node(locator_list_node, utils::tag::UDP_V4_LOCATOR, &index);
    }
    // Set the externality value
    static_cast<xercesc::DOMElement*>(locator_node)->setAttribute(
        xercesc::XMLString::transcode(utils::tag::EXTERNALITY),
        xercesc::XMLString::transcode(externality.c_str()));

    // Validate new XML element and save it
    manager->validate_and_save_xml_document();
}

void set_cost(
        const std::string& xml_file,
        const std::string& profile_id,
        const std::string& cost,
        const std::string& index)
{
    throw Unsupported("Unsupported");
}

void set_mask(
        const std::string& xml_file,
        const std::string& profile_id,
        const std::string& mask,
        const std::string& index)
{
    throw Unsupported("Unsupported");
}

} // metatraffic_external_unicast_locators
} // builtin
} // domain_participant
} // qosprof
} // eprosima
