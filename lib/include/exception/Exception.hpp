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

#ifndef _FAST_DDS_QOS_PROFILES_MANAGER_EXCEPTION_EXCEPTION_HPP_
#define _FAST_DDS_QOS_PROFILES_MANAGER_EXCEPTION_EXCEPTION_HPP_

#include <exception>
#include <string>

#include <fastdds_qos_profiles_manager_dll.h>

namespace eprosima {
namespace qosprof {

/**
 * @brief Base class for all exceptions thrown by the eProsima Fast DDS QoS Profiles Manager
 */
class Exception : public std::exception
{
public:

    /**
     * @brief Construct a new qosprof::Exception object
     *
     * @param message The message to be returned by what()
     */
    FASTDDS_QOS_PROFILES_MANAGER_DllAPI Exception(
            const char* message) noexcept;

    /**
     * @brief Construct a new qosprof::Exception object
     *
     * @param message The message to be returned by what()
     */
    FASTDDS_QOS_PROFILES_MANAGER_DllAPI Exception(
            const std::string& message);

    /**
     * @brief Copies the qosprof::Exception object into a new one
     *
     * @param other The original exception object to copy
     */
    FASTDDS_QOS_PROFILES_MANAGER_DllAPI Exception(
            const Exception& other) = default;

    /**
     * @brief Copies the qosprof::Exception object into the current one
     *
     * @param other The original exception object to copy
     * @return the current qosprof::Exception object after the copy
     */
    FASTDDS_QOS_PROFILES_MANAGER_DllAPI Exception& operator =(
            const Exception& other) = default;

    /**
     * @brief Returns the explanatory string of the exception
     *
     * @return Null-terminated string with the explanatory information
     */
    FASTDDS_QOS_PROFILES_MANAGER_DllAPI virtual const char* what() const noexcept override;

protected:

    std::string message_;

};

/**
 * @brief Exception to signal that the provided XML file does not exist
 */
class FileNotFound : public Exception
{

public:

    // Use parent constructors.
    using Exception::Exception;

    /**
     * @brief Copies the qosprof::FileNotFound exception into a new one
     *
     * @param other The original exception object to copy
     */
    FASTDDS_QOS_PROFILES_MANAGER_DllAPI FileNotFound(
            const FileNotFound& other) = default;

    /**
     * @brief Copies the qosprof::FileNotFound exception into the current one
     *
     * @param other The original qosprof::FileNotFound exception to copy
     * @return the current qosprof::FileNotFound exception after the copy
     */
    FASTDDS_QOS_PROFILES_MANAGER_DllAPI FileNotFound& operator =(
            const FileNotFound& other) = default;
};

/**
 * @brief Exception to signal that the queried XML element does not exist
 */
class ElementNotFound : public Exception
{

public:

    // Use parent constructors.
    using Exception::Exception;

    /**
     * @brief Copies the qosprof::ElementNotFound exception into a new one
     *
     * @param other The original exception object to copy
     */
    FASTDDS_QOS_PROFILES_MANAGER_DllAPI ElementNotFound(
            const ElementNotFound& other) = default;

    /**
     * @brief Copies the qosprof::ElementNotFound exception into the current one
     *
     * @param other The original qosprof::ElementNotFound exception to copy
     * @return the current qosprof::ElementNotFound exception after the copy
     */
    FASTDDS_QOS_PROFILES_MANAGER_DllAPI ElementNotFound& operator =(
            const ElementNotFound& other) = default;
};

/**
 * @brief Exception to signal that the provided XML element is not valid according to the XSD Schema
 *
 * Query the `what` in order to have more information about the validation failure
 */
class ElementInvalid : public Exception
{

public:

    // Use parent constructors.
    using Exception::Exception;

    /**
     * @brief Copies the qosprof::ElementInvalid exception into a new one
     *
     * @param other The original exception object to copy
     */
    FASTDDS_QOS_PROFILES_MANAGER_DllAPI ElementInvalid(
            const ElementInvalid& other) = default;

    /**
     * @brief Copies the qosprof::ElementInvalid exception into the current one
     *
     * @param other The original qosprof::ElementInvalid exception to copy
     * @return the current qosprof::ElementInvalid exception after the copy
     */
    FASTDDS_QOS_PROFILES_MANAGER_DllAPI ElementInvalid& operator =(
            const ElementInvalid& other) = default;
};

/**
 * @brief Exception to signal that an operation is not supported
 *
 * Query the `what` in order to have more information about the validation failure
 */
class Unsupported : public Exception
{

public:

    // Use parent constructors.
    using Exception::Exception;

    /**
     * @brief Copies the qosprof::Unsupported exception into a new one
     *
     * @param other The original exception object to copy
     */
    FASTDDS_QOS_PROFILES_MANAGER_DllAPI Unsupported(
            const Unsupported& other) = default;

    /**
     * @brief Copies the qosprof::Unsupported exception into the current one
     *
     * @param other The original qosprof::Unsupported exception to copy
     * @return the current qosprof::Unsupported exception after the copy
     */
    FASTDDS_QOS_PROFILES_MANAGER_DllAPI Unsupported& operator =(
            const Unsupported& other) = default;
};

} // qosprof
} // eprosima

#endif // _FAST_DDS_QOS_PROFILES_MANAGER_EXCEPTION_EXCEPTION_HPP_
