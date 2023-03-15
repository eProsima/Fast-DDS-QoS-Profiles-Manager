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

XercesDOMParser* openXML(
        const std::string& xml_file)
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
        return NULL;
    }

    // Create parser
    XercesDOMParser* xmlParser = new XercesDOMParser();

    // Declare error handler
    ParseXMLErrorHandler* xmlErrorHandler = new ParseXMLErrorHandler(ParseXMLErrorHandler::Kind::FileNotFound);
    xmlParser->setErrorHandler(xmlErrorHandler);

    // Try to open the given file
    try
    {
        xmlParser->parse(XMLString::transcode(xml_file.c_str()));
    }
    catch (const FileNotFound& ex)
    {
        // Delete resources
        delete xmlParser;
        delete xmlErrorHandler;

        // Close XML workspace
        XMLPlatformUtils::Terminate();

        // Given file does not exist
        throw FileNotFound(ex.getMessage());
        return NULL;
    }

    return xmlParser;
}

void closeXML()
{
    // Close XML workspace
    XMLPlatformUtils::Terminate();
}

DOMNode* getNode(
        const DOMNodeList& tagNodeList,
        const std::string& tagName,
        int32_t index,
        const std::string& attName,
        const std::string& attValue)
{
    // Throw exception if no nodes
    if (tagNodeList->getLength() == 0)
    {
        // Throw ElementNotFound exception
        throw ElementNotFound("non-existent " << tagName << " profile\n");

        return NULL;
    }
    // Complex element Node
    else if (tagNodeList->getLength() == 1)
    {
        // Return Node
        return tagNodeList[0];
    }
    // MAP or LIST element node
    else
    {
        // Obtain node based on MAP
        if (attName != NULL){
            DOMNode* tagNode = NULL;

            // Iterate throw the nodes
            // TODO try with node->getNextSibling();
            for (int i=0, j=0, size=tagNodeList->getLength(); i<size && j==0; i++)
            {
                tagNode = tagNodeList[i];
                if (tagNode.getAttributes().getNamedItem(attName).getNodeValue().c_str() == attValue)
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
                throw ElementNotFound(tagName << " does not have an element with key " << attValue << "\n");

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
                realIndex = tagNodeList->getLength() + index;
            }

            // Check bounds
            if (realIndex < 0 || realIndex >= tagNodeList->getLength())
            {
                // Throw ElementNotFound exception
                throw ElementNotFound(tagName << " does not have an element in position " << realIndex << "\n");

                return NULL;
            }
            // Return Node
            return tagNodeList[realIndex];
        }
    }
}

void validateXML(
        const std::string& xmlFile
        const XercesDOMParser& xmlParser)
{
    // TODO make this static
    std::string xsdFile = "/home/jesus/Fast-DDS/src/fastrtps/resources/xsd/fastRTPS_profiles.xsd";

    // Create parser for validation
    string namespaceSchemaLocation = "http://www.eprosima.com/XMLSchemas/fastRTPS_Profiles " + xsdFile;

    // Load XSD schema
    xmlParser->loadGrammar(xsdFile.c_str(),Grammar::SchemaGrammarType, true);
    xmlParser->setExternalSchemaLocation(namespaceSchemaLocation.c_str());

    // Declare error handler
    ParseXMLErrorHandler* xmlErrorHandler = new ParseXMLErrorHandler(ParseXMLErrorHandler::Kind::ElementInvalid);
    xmlParser->setErrorHandler(xmlErrorHandler);

    // Validation configuration
    xmlParser->setValidationScheme(XercesDOMParser::Val_Auto);
    xmlParser->setDoNamespaces(true);
    xmlParser->setDoSchema(true);
    xmlParser->setValidationConstraintFatal(true);

    // Parse file
    try
    {
        xmlParser->parse(xmlFile.c_str());
    }
    catch (const ElementInvalid& ex)
    {
        throw ElementInvalid(ex);
    }

    delete xmlErrorHandler;

    return;
}

void saveXML(
        const std::string& xmlFile,
        const DOMDocument& xmlDoc)
{
    // Create file
    DOMImplementation* xmlImplementation = DOMImplementationRegistry::getDOMImplementation (XMLString::transcode("Core"));
    if (xmlImplementation == NULL)
    {
        closeXML();

        // Could not initialize XML workspace
        throw Unsupported("Could not initialize XML workspace");

        return;
    }
    // Save the created elements in the given file
    DOMLSOutput* xmlOutput = xmlImplementation->createLSOutput();
    DOMLSSerializer* xmlWriter = ((DOMImplementationLS*)xmlImplementation)->createLSSerializer();;
    XMLFormatTarget* xmlTargetName = new LocalFileFormatTarget(XMLString::transcode(xmlFile.c_str()));
    xmlOutput->setByteStream(xmlTargetName);
    xmlOutput->setEncoding(XMLString::transcode("UTF-8"));
    xmlWriter->setNewLine(XMLString::transcode("\n"));
    DOMConfiguration* xmlConfiguration = xmlWriter->getDomConfig();
    xmlConfiguration->setParameter(XMLUni::fgDOMWRTFormatPrettyPrint, true);
    xmlConfiguration->setParameter(XMLUni::fgDOMXMLDeclaration, true);
    xmlWriter->write(xmlDoc, xmlOutput);

    // Ended working with the document, release resources
    delete xmlConfiguration;
    delete xmlWriter;
    delete xmlOutput;
    delete xmlTargetName;
}





DOMNode* getNode(
        const XercesDOMParser& xmlParser,
        const std::string& tagName)
{
    try
    {
        return getNode(xmlParser, tagName, 0, NULL, NULL);
    }
    catch (const ElementNotFound& ex)
    {
        // Throw exception if no nodes
        throw ElementNotFound(ex);
        return NULL;
    }
}

DOMNode* getNode(
        const XercesDOMParser& xmlParser,
        const std::string& tagName,
        int32_t index)
{
    try
    {
        return getNode(xmlParser, tagName, index, NULL, NULL);
    }
    catch (const ElementNotFound& ex)
    {
        // Throw exception if no nodes
        throw ElementNotFound(ex);
        return NULL;
    }
}

DOMNode* getNode(
        const XercesDOMParser& xmlParser,
        const std::string& tagName,
        const std::string& attName,
        const std::string& attValue)
{
    try
    {
        return getNode(xmlParser, tagName, 0, attName, attValue);
    }
    catch (const ElementNotFound& ex)
    {
        // Throw exception if no nodes
        throw ElementNotFound(ex);
        return NULL;
    }
}

DOMNode* getNode(
        const XercesDOMParser& xmlParser,
        const std::string& tagName,
        int32_t index,
        const std::string& attName,
        const std::string& attValue)
{
    // Open document
    DOMDocument* xmlDoc = xmlParser->getDocument();

    // Obtain root element
    DOMElement* xmlRoot = xmlDoc->getDocumentElement();

    DOMNode* node = NULL;

    // Obtain node from root
    try
    {
        node = getNode(xmlRoot->getElementsByTagName(XMLString::transcode(tagName)), tagName, index, attName, attValue);
    }
    catch (const ElementNotFound& ex)
    {
        // Throw exception if no nodes
        throw ElementNotFound(ex);

    }
    // Delete resources
    delete xmlRoot;
    delete xmlDoc;

    return node;
}

DOMNode* getNode(
        const DOMNode& parentNode,
        const std::string& tagName)
{
    try
    {
        return getNode(parentNode, tagName, 0, NULL, NULL);
    }
    catch (const ElementNotFound& ex)
    {
        // Throw exception if no nodes
        throw ElementNotFound(ex);
        return NULL;
    }
}

DOMNode* getNode(
        const DOMNode& parentNode,
        const std::string& tagName,
        int32_t index)
{
    try
    {
        return getNode(parentNode, tagName, index, NULL, NULL);
    }
    catch (const ElementNotFound& ex)
    {
        // Throw exception if no nodes
        throw ElementNotFound(ex);
        return NULL;
    }
}

DOMNode* getNode(
        const DOMNode& parentNode,
        const std::string& tagName,
        const std::string& attName,
        const std::string& attValue)
{
    try
    {
        return getNode(parentNode, tagName, 0, attName, attValue);
    }
    catch (const ElementNotFound& ex)
    {
        // Throw exception if no nodes
        throw ElementNotFound(ex);
        return NULL;
    }
}

DOMNode* getNode(
        const DOMNode& parentNode,
        const std::string& tagName,
        int32_t index,
        const std::string& attName,
        const std::string& attValue)
{
    // Obtain node from parent node
    try
    {
        node = getNode(parentNode->getElementsByTagName(XMLString::transcode(tagName)), tagName, index, attName, attValue);
    }
    catch (const ElementNotFound& ex)
    {
        // Throw exception if no nodes
        throw ElementNotFound(ex);

    }

    return node;
}
