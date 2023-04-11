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

#include <common/LocatorList.hpp>

#include <string>

#include <fastdds_qos_profiles_manager/exception/Exception.hpp>

#include <utils/ParseXMLTags.hpp>

namespace eprosima {
namespace qosprof {
namespace common {
namespace locator_list {

std::string print(
        utils::ParseXML& manager,
        const xercesc::DOMElement& xml_node,
        const std::string& index,
        const bool is_external)
{
    throw Unsupported("Unsupported");
}

std::string print_kind(
        utils::ParseXML& manager,
        const xercesc::DOMElement& xml_node,
        const std::string& index,
        const bool is_external)
{
    throw Unsupported("Unsupported");
}

std::string print_port(
        utils::ParseXML& manager,
        const xercesc::DOMElement& xml_node,
        const std::string& index,
        const bool is_external)
{
    throw Unsupported("Unsupported");
}

std::string print_physical_port(
        utils::ParseXML& manager,
        const xercesc::DOMElement& xml_node,
        const std::string& index,
        const bool is_external)
{
    throw Unsupported("Unsupported");
}

std::string print_address(
        utils::ParseXML& manager,
        const xercesc::DOMElement& xml_node,
        const std::string& index,
        const bool is_external)
{
    throw Unsupported("Unsupported");
}

std::string print_unique_lan_id(
        utils::ParseXML& manager,
        const xercesc::DOMElement& xml_node,
        const std::string& index,
        const bool is_external)
{
    throw Unsupported("Unsupported");
}

std::string print_wan_address(
        utils::ParseXML& manager,
        const xercesc::DOMElement& xml_node,
        const std::string& index,
        const bool is_external)
{
    throw Unsupported("Unsupported");
}

uint32_t size(
        utils::ParseXML& manager,
        const xercesc::DOMElement& xml_node)
{
    throw Unsupported("Unsupported");
}

void clear(
        utils::ParseXML& manager,
        xercesc::DOMElement& xml_node,
        const std::string& index)
{
    throw Unsupported("Unsupported");
}

void clear_port(
        utils::ParseXML& manager,
        xercesc::DOMElement& xml_node,
        const std::string& index,
        const bool is_external)
{
    throw Unsupported("Unsupported");
}

void clear_physical_port(
        utils::ParseXML& manager,
        xercesc::DOMElement& xml_node,
        const std::string& index,
        const bool is_external)
{
    throw Unsupported("Unsupported");
}

void clear_address(
        utils::ParseXML& manager,
        xercesc::DOMElement& xml_node,
        const std::string& index,
        const bool is_external)
{
    throw Unsupported("Unsupported");
}

void clear_unique_lan_id(
        utils::ParseXML& manager,
        xercesc::DOMElement& xml_node,
        const std::string& index,
        const bool is_external)
{
    throw Unsupported("Unsupported");
}

void clear_wan_address(
        utils::ParseXML& manager,
        xercesc::DOMElement& xml_node,
        const std::string& index,
        const bool is_external)
{
    throw Unsupported("Unsupported");
}

void set_kind(
        utils::ParseXML& manager,
        xercesc::DOMElement& xml_node,
        const std::string& kind,
        const std::string& index,
        const bool is_external)
{
    throw Unsupported("Unsupported");
}

void set_port(
        utils::ParseXML& manager,
        xercesc::DOMNode* xml_node,
        const std::string& port,
        const std::string& index,
        const bool is_external)
{
    xercesc::DOMDocument* doc = manager.get_doc();
    xercesc::DOMNode* locator_node = nullptr;
    xercesc::DOMNode* kind_node = nullptr;
    xercesc::DOMNode* port_node = nullptr;

    // Create new locator and push it in the list
    if (index.empty())
    {
        // create default udp v4 kind
        kind_node = static_cast<xercesc::DOMNode*> (doc->createElement(
                    xercesc::XMLString::transcode(utils::tag::UDP_V4_LOCATOR)));

        // append the new kind node directly to the given parent
        if (is_external)
        {
            xml_node->appendChild(kind_node);
        }
        // create <locator> tag if required
        else
        {
            locator_node = static_cast<xercesc::DOMNode*> (doc->createElement(
                        xercesc::XMLString::transcode(utils::tag::LOCATOR)));
            xml_node->appendChild(locator_node);
            locator_node->appendChild(kind_node);
        }

        // add port node to the kind node
        port_node = static_cast<xercesc::DOMNode*> (doc->createElement(
                    xercesc::XMLString::transcode(utils::tag::PORT)));
        kind_node->appendChild(port_node);
    }
    // set the port value in the locator defined by the index
    else
    {
        std::string* ind = new std::string();
        ind->append(index);

        // obtain the locator kind directly
        if (is_external)
        {
            // TODO update this and the infraestructure
            kind_node = manager.get_node(xml_node, utils::tag::UDP_V4_LOCATOR, ind);
        }
        // obtain kind from <locator> tag
        else
        {
            locator_node = manager.get_node(xml_node, utils::tag::LOCATOR, ind);

            xercesc::DOMNodeList* kind_list = locator_node->getChildNodes();
            for (int i = 0, size = kind_list->getLength(); i < size; i++)
            {
                if (kind_list->item(i)->getNodeType() == xercesc::DOMNode::NodeType::ELEMENT_NODE)
                {
                    kind_node = kind_list->item(i);
                    break;
                }
            }
        }

        // obtain the port of the given locator
        try
        {
            port_node = manager.get_node(kind_node, utils::tag::PORT);
        }
        // create the port node in the given locator
        catch (const ElementNotFound& ex)
        {
            port_node = static_cast<xercesc::DOMNode*>(doc->createElement(
                        xercesc::XMLString::transcode(utils::tag::PORT)));
            kind_node->appendChild(port_node);
        }
    }
    // set port node value
    manager.set_value_to_node(port_node, port);
}

void set_physical_port(
        utils::ParseXML& manager,
        xercesc::DOMElement& xml_node,
        const std::string& physical_port,
        const std::string& index,
        const bool is_external)
{
    throw Unsupported("Unsupported");
}

void set_address(
        utils::ParseXML& manager,
        xercesc::DOMNode* xml_node,
        const std::string& address,
        const std::string& index,
        const bool is_external)
{
    xercesc::DOMDocument* doc = manager.get_doc();
    xercesc::DOMNode* locator_node = nullptr;
    xercesc::DOMNode* kind_node = nullptr;
    xercesc::DOMNode* address_node = nullptr;

    // Create new locator and push it in the list
    if (index.empty())
    {
        // create default udp v4 kind
        kind_node = static_cast<xercesc::DOMNode*> (doc->createElement(
                    xercesc::XMLString::transcode(utils::tag::UDP_V4_LOCATOR)));

        // append the new kind node directly to the given parent
        if (is_external)
        {
            xml_node->appendChild(kind_node);
        }
        // create <locator> tag if required
        else
        {
            locator_node = static_cast<xercesc::DOMNode*> (doc->createElement(
                        xercesc::XMLString::transcode(utils::tag::LOCATOR)));
            xml_node->appendChild(locator_node);
            locator_node->appendChild(kind_node);
        }

        // add address node to the kind node
        address_node = static_cast<xercesc::DOMNode*> (doc->createElement(
                    xercesc::XMLString::transcode(utils::tag::ADDRESS)));
        kind_node->appendChild(address_node);
    }
    // set the address value in the locator defined by the index
    else
    {
        std::string* ind = new std::string();
        ind->append(index);

        // obtain the locator kind directly
        if (is_external)
        {
            // TODO update this and the infraestructure
            kind_node = manager.get_node(xml_node, utils::tag::UDP_V4_LOCATOR, ind);
        }
        // obtain kind from <locator> tag
        else
        {
            locator_node = manager.get_node(xml_node, utils::tag::LOCATOR, ind);

            xercesc::DOMNodeList* kind_list = locator_node->getChildNodes();
            for (int i = 0, size = kind_list->getLength(); i < size; i++)
            {
                if (kind_list->item(i)->getNodeType() == xercesc::DOMNode::NodeType::ELEMENT_NODE)
                {
                    kind_node = kind_list->item(i);
                    break;
                }
            }
        }

        // obtain the address of the given locator
        try
        {
            address_node = manager.get_node(kind_node, utils::tag::ADDRESS);
        }
        // create the address node in the given locator
        catch (const ElementNotFound& ex)
        {
            address_node = static_cast<xercesc::DOMNode*>(doc->createElement(
                        xercesc::XMLString::transcode(utils::tag::ADDRESS)));
            kind_node->appendChild(address_node);
        }
    }
    // set port node value
    manager.set_value_to_node(address_node, address);
}

void set_unique_lan_id(
        utils::ParseXML& manager,
        xercesc::DOMElement& xml_node,
        const std::string& unique_lan_id,
        const std::string& index,
        const bool is_external)
{
    throw Unsupported("Unsupported");
}

void set_wan_address(
        utils::ParseXML& manager,
        xercesc::DOMElement& xml_node,
        const std::string& wan_address,
        const std::string& index,
        const bool is_external)
{
    throw Unsupported("Unsupported");
}

} // locator_list
} // common
} // qosprof
} // eprosima
