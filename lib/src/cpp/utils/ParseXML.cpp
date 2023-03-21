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

#include <utils/ParseXML.hpp>

xercesc::XercesDOMParser* openXML(
        const std::string& xml_file)
{
    // Try to initialize XML workspace
    try
    {
        xercesc::XMLPlatformUtils::Initialize();
    }
    catch (const xercesc::XMLException& toCatch)
    {
        // Unable to initialize XML workspace
        throw eprosima::qosprof::Unsupported(xercesc::XMLString::transcode(toCatch.getMessage()));
        return NULL;
    }

    // Create parser
    xercesc::XercesDOMParser* xmlParser = new xercesc::XercesDOMParser();

    // Declare error handler
    ParseXMLErrorHandler* xmlErrorHandler = new ParseXMLErrorHandler(ParseXMLErrorHandler::Kind::FileNotFound);
    xmlParser->setErrorHandler(xmlErrorHandler);

    // Try to open the given file
    try
    {
        xmlParser->parse(xercesc::XMLString::transcode(xml_file.c_str()));
    }
    catch (const eprosima::qosprof::FileNotFound& ex)
    {
        // Delete resources
        delete xmlParser;
        delete xmlErrorHandler;

        // Close XML workspace
        xercesc::XMLPlatformUtils::Terminate();

        // Given file does not exist
        throw eprosima::qosprof::FileNotFound(ex);
        return NULL;
    }

    return xmlParser;
}

void closeXML()
{
    // Close XML workspace
    xercesc::XMLPlatformUtils::Terminate();
}

xercesc::DOMNode* getNode(
        const xercesc::DOMNodeList& tagNodeList,
        const std::string& tagName,
        int32_t index,
        const std::string& attName,
        const std::string& attValue)
{
    // Throw exception if no nodes
    if (tagNodeList.getLength() == 0)
    {
        // Throw eprosima::qosprof::ElementNotFound exception
        throw eprosima::qosprof::ElementNotFound("non-existent " + tagName + " profile\n");

        return NULL;
    }
    // Complex element Node
    else if (tagNodeList.getLength() == 1)
    {
        // Return Node
        return tagNodeList.item(0);
    }
    // MAP or LIST element node
    else
    {
        // Obtain node based on MAP
        if (attName.c_str() != NULL){
            xercesc::DOMNode* tagNode = NULL;

            // Iterate throw the nodes
            // TODO try with node->getNextSibling();
            for (int i=0, j=0, size=tagNodeList.getLength(); i<size && j==0; i++)
            {
                tagNode = tagNodeList.item(i);
                if (tagNode->getAttributes()->getNamedItem(xercesc::XMLString::transcode(attName.c_str()))->getNodeValue()
                    == xercesc::XMLString::transcode(attValue.c_str()))
                {
                    j++;
                }
                else
                {
                    tagNode = NULL;
                }
            }

            // Throw exception if node not found
            if (tagNode == NULL)
            {
                // Given file does not exist
                throw eprosima::qosprof::ElementNotFound(
                    tagName + " does not have an element with key " + attValue + "\n");

                return NULL;
            }
            else
            {
                // Return Node
                return tagNode;
            }
        }
        // Obtain node based on LIST
        else
        {
            int32_t realIndex = index;

            // Transform index to real index
            if (index < 0)
            {
                realIndex = tagNodeList.getLength() + index;
            }

            // Check bounds
            if (realIndex < 0 || realIndex >= tagNodeList.getLength())
            {
                // Throw eprosima::qosprof::ElementNotFound exception
                throw eprosima::qosprof::ElementNotFound(
                    tagName + " does not have an element in position " + std::to_string(realIndex) + "\n");

                return NULL;
            }
            // Return Node
            return tagNodeList.item(realIndex);
        }
    }
}

void validateXML(
        const std::string& xmlFile,
        xercesc::XercesDOMParser& xmlParser)
{
    // TODO make this static
    std::string xsdFile = "/home/jesus/Fast-DDS/src/fastrtps/resources/xsd/fastRTPS_profiles.xsd";

    // Create parser for validation
    std::string namespaceSchemaLocation = "http://www.eprosima.com/XMLSchemas/fastRTPS_Profiles " + xsdFile;

    // Load XSD schema
    xmlParser.loadGrammar(xsdFile.c_str(),xercesc::Grammar::SchemaGrammarType, true);
    xmlParser.setExternalSchemaLocation(namespaceSchemaLocation.c_str());

    // Declare error handler
    ParseXMLErrorHandler* xmlErrorHandler = new ParseXMLErrorHandler(ParseXMLErrorHandler::Kind::ElementInvalid);
    xmlParser.setErrorHandler(xmlErrorHandler);

    // Validation configuration
    xmlParser.setValidationScheme(xercesc::XercesDOMParser::Val_Auto);
    xmlParser.setDoNamespaces(true);
    xmlParser.setDoSchema(true);
    xmlParser.setValidationConstraintFatal(true);

    // Parse file
    try
    {
        xmlParser.parse(xmlFile.c_str());
    }
    catch (const eprosima::qosprof::ElementInvalid& ex)
    {
        throw eprosima::qosprof::ElementInvalid(ex);
    }

    delete xmlErrorHandler;

    return;
}

void saveXML(
        const std::string& xmlFile,
        const xercesc::DOMDocument& xmlDoc)
{
    // Create file
    xercesc::DOMImplementation* xmlImplementation =
        xercesc::DOMImplementationRegistry::getDOMImplementation (xercesc::XMLString::transcode("Core"));
    if (xmlImplementation == NULL)
    {
        closeXML();

        // Could not initialize XML workspace
        throw eprosima::qosprof::Unsupported("Could not initialize XML workspace");

        return;
    }
    // Save the created elements in the given file
    xercesc::DOMLSOutput* xmlOutput = xmlImplementation->createLSOutput();
    xercesc::DOMLSSerializer* xmlWriter = ((xercesc::DOMImplementationLS*)xmlImplementation)->createLSSerializer();;
    xercesc::XMLFormatTarget* xmlTargetName = new xercesc::LocalFileFormatTarget(
        xercesc::XMLString::transcode(xmlFile.c_str()));
    xmlOutput->setByteStream(xmlTargetName);
    xmlOutput->setEncoding(xercesc::XMLString::transcode("UTF-8"));
    xmlWriter->setNewLine(xercesc::XMLString::transcode("\n"));
    xercesc::DOMConfiguration* xmlConfiguration = xmlWriter->getDomConfig();
    xmlConfiguration->setParameter(xercesc::XMLUni::fgDOMWRTFormatPrettyPrint, true);
    xmlConfiguration->setParameter(xercesc::XMLUni::fgDOMXMLDeclaration, true);
    xercesc::DOMNode* rootNode = (xercesc::DOMNode*)xmlDoc.getDocumentElement();
    xmlWriter->write(rootNode, xmlOutput);

    // Ended working with the document, release resources
    delete xmlConfiguration;
    delete xmlWriter;
    delete xmlOutput;
    delete xmlTargetName;
}

void clearNode(
        const std::string& xmlFile,
        xercesc::DOMNode& parentNode,
        xercesc::DOMNode& removeNode)

{
    if (parentNode.hasChildNodes())
    {
        if (parentNode.getChildNodes()->getLength() == 1 &&
            parentNode.getChildNodes()->item(0)->getNodeName() == removeNode.getNodeName())
        {
            // report exception
            std::string message = "could not delete last element from ";
            message.append(xercesc::XMLString::transcode(parentNode.getNodeValue()));
            message.append(". Delete element by running the predecessor clear API.\n");
            throw eprosima::qosprof::ElementInvalid(message);
            return;
        }
    }
    parentNode.removeChild(&removeNode);
    removeNode.release();
    delete &removeNode;
}

xercesc::DOMNode* getNode(
        const xercesc::XercesDOMParser& xmlParser,
        const std::string& tagName)
{
    try
    {
        return getNode(xmlParser, tagName, 0, NULL, NULL);
    }
    catch (const eprosima::qosprof::ElementNotFound& ex)
    {
        // Throw exception if no nodes
        throw eprosima::qosprof::ElementNotFound(ex);
    }
    return NULL;
}

xercesc::DOMNode* getNode(
        const xercesc::XercesDOMParser& xmlParser,
        const std::string& tagName,
        int32_t index)
{
    try
    {
        return getNode(xmlParser, tagName, index, NULL, NULL);
    }
    catch (const eprosima::qosprof::ElementNotFound& ex)
    {
        // Throw exception if no nodes
        throw eprosima::qosprof::ElementNotFound(ex);
    }
    return NULL;
}

xercesc::DOMNode* getNode(
        const xercesc::XercesDOMParser& xmlParser,
        const std::string& tagName,
        const std::string& attName,
        const std::string& attValue)
{
    try
    {
        return getNode(xmlParser, tagName, 0, attName, attValue);
    }
    catch (const eprosima::qosprof::ElementNotFound& ex)
    {
        // Throw exception if no nodes
        throw eprosima::qosprof::ElementNotFound(ex);
    }
    return NULL;
}

xercesc::DOMNode* getNode(
        xercesc::XercesDOMParser& xmlParser,
        const std::string& tagName,
        int32_t index,
        const std::string& attName,
        const std::string& attValue)
{
    // Open document
    xercesc::DOMDocument* xmlDoc = xmlParser.getDocument();

    // Obtain root element
    xercesc::DOMElement* xmlRoot = xmlDoc->getDocumentElement();

    xercesc::DOMNode* node = NULL;

    // Obtain node from root
    try
    {
        node = getNode(*xmlRoot->getElementsByTagName(xercesc::XMLString::transcode(tagName.c_str())), tagName, index, attName, attValue);
    }
    catch (const eprosima::qosprof::ElementNotFound& ex)
    {
        // Throw exception if no nodes
        throw eprosima::qosprof::ElementNotFound(ex);

    }
    // Delete resources
    delete xmlRoot;
    delete xmlDoc;

    return node;
}

xercesc::DOMNode* getNode(
        const xercesc::DOMNode& parentNode,
        const std::string& tagName)
{
    try
    {
        return getNode(parentNode, tagName, 0, NULL, NULL);
    }
    catch (const eprosima::qosprof::ElementNotFound& ex)
    {
        // Throw exception if no nodes
        throw eprosima::qosprof::ElementNotFound(ex);
    }
    return NULL;
}

xercesc::DOMNode* getNode(
        const xercesc::DOMNode& parentNode,
        const std::string& tagName,
        int32_t index)
{
    try
    {
        return getNode(parentNode, tagName, index, NULL, NULL);
    }
    catch (const eprosima::qosprof::ElementNotFound& ex)
    {
        // Throw exception if no nodes
        throw eprosima::qosprof::ElementNotFound(ex);
    }
    return NULL;
}

xercesc::DOMNode* getNode(
        const xercesc::DOMNode& parentNode,
        const std::string& tagName,
        const std::string& attName,
        const std::string& attValue)
{
    try
    {
        return getNode(parentNode, tagName, 0, attName, attValue);
    }
    catch (const eprosima::qosprof::ElementNotFound& ex)
    {
        // Throw exception if no nodes
        throw eprosima::qosprof::ElementNotFound(ex);
    }
    return NULL;
}

xercesc::DOMNode* getNode(
        const xercesc::DOMNode& parentNode,
        const std::string& tagName,
        int32_t index,
        const std::string& attName,
        const std::string& attValue)
{
    // Obtain node from parent node
    try
    {
        return getNode(*parentNode.getChildNodes(), tagName, index, attName, attValue);
    }
    catch (const eprosima::qosprof::ElementNotFound& ex)
    {
        // Throw exception if no nodes
        throw eprosima::qosprof::ElementNotFound(ex);
    }
    return NULL;
}
