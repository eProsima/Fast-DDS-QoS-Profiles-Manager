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

#include <string>

#include "gtest/gtest.h"

#include <exception/Exception.hpp>
#include <TransportDescriptor.hpp>

using namespace eprosima::qosprof;
using namespace eprosima::qosprof::transport_descriptor;

/**
 * @brief Check query methods for TransportDescriptor profiles
 *
 * 1. Print TransportDescriptor profiles for a non-existent XML file: capture exception
 * 2. Create first profile by setting the TransportDescriptor kind
 * 3. Print XML TransportDescriptor profiles
 * 4. Query the number of TransportDescriptor profiles
 * 5. Query the keys of the TransportDescriptor profiles
 * 6. Create a second and third profiles
 * 7. Print XML file
 * 8. Query again the number of profiles and its keys
 * 9. Clear the first profile
 * 10. Print XML
 * 10. Query number of profiles and its keys
 * 11. Clear every profile
 * 12. Query number of profiles and its keys
 */
TEST(TransportDescriptorTests, TransportDescriptorProfiles)
{
    std::string filename("TransportDescriptorTests.xml");
    EXPECT_THROW(print(filename), FileNotFound);
}

/**
 * @brief Check related methods to TransportDescriptor kind
 *
 * 1. Set TransportDescriptor kind with a non-existent XML file.
 * 2. Print generated XML file
 * 3. Update TransportDescriptor kind
 * 4. Print TransportDescriptor kind
 * 5. Set another TransportDescriptor kind
 * 6. Print generated XML file
 */
TEST(TransportDescriptorTests, TransportDescriptorKind)
{
    //
}

int main(
        int argc,
        char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
