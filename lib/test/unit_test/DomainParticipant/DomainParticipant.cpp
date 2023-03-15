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

#include <cstdio>
#include <string>

#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include <domain_participant/DefaultExternalUnicastLocators.hpp>
#include <domain_participant/DomainParticipant.hpp>
#include <exception/Exception.hpp>

using namespace eprosima::qosprof;
using namespace eprosima::qosprof::domain_participant;

/**********************************************************************************************************************/
/* DOMAIN PARTICIPANT TESTS                                                                                           */
/* General functions (eprosima::qosprof::domain_participant namespace)                                                */
/**********************************************************************************************************************/
TEST(DomainParticipant, default_profile_test)
{
    // Test variables
    std::string xml_filename = "test.xml";
    std::string non_existent_xml = "non_existent.xml";
    std::string participant_profile = "test_profile";
    std::string another_participant_profile = "second_test_profile";
    std::string participant_name = "participant_test";
    std::string another_participant_name = "second_participant_test";

    // Try printing default profile for non-existing file
    EXPECT_THROW(print_default_profile(xml_filename), FileNotFound);

    // Set participant name in order to create file
    EXPECT_NO_THROW(set_name(xml_filename, participant_profile, participant_name));

    // Print non-existing default profile
    EXPECT_THROW(print_default_profile(xml_filename), ElementNotFound);

    // Set default profile to non-existent XML file
    EXPECT_THROW(set_default_profile(non_existent_xml, participant_profile), FileNotFound);

    // Set default profile to non-existent participant profile
    EXPECT_THROW(set_default_profile(xml_filename, another_participant_profile), ElementNotFound);

    // Set default profile to existent profile
    EXPECT_NO_THROW(set_default_profile(xml_filename, participant_profile));

    // Print existent default profile
    EXPECT_EQ(print_default_profile(xml_filename), participant_profile);

    // Create a second profile and change default profile to this second profile
    EXPECT_NO_THROW(set_name(xml_filename, another_participant_profile, another_participant_name));
    EXPECT_NO_THROW(set_default_profile(xml_filename, another_participant_profile));

    // Print existent default profile
    EXPECT_EQ(print_default_profile(xml_filename), another_participant_profile);

    // Clear default profile
    EXPECT_NO_THROW(clear_default_profile(xml_filename));

    // Print non-existent default profile
    EXPECT_THROW(print_default_profile(xml_filename), ElementNotFound);

    // Clear default profile from a file with no default profile
    EXPECT_NO_THROW(clear_default_profile(xml_filename));

    // Clear default profile from a non-existent XML file
    EXPECT_THROW(clear_default_profile(non_existent_xml), FileNotFound);

    // Clean test workspace
    std::remove(xml_filename.c_str());
}

/**********************************************************************************************************************/
/* DOMAIN PARTICIPANT TESTS                                                                                           */
/* DefaultExternalUnicastLocators                                                                                     */
/**********************************************************************************************************************/
TEST(DomainParticipant, default_external_unicast_locators_kind)
{
    std::string xml_filename = "test.xml";
    std::string participant_profile = "test_profile";
    std::string another_participant_profile = "second_test_profile";
    std::string participant_name = "participant_test";
    std::string invalid_kind = "tcp_v4";
    std::string udp_v4_kind = "udp_v4";
    std::string udp_v6_kind = "udp_v6";

    // Try printing locator kind from a non-existent file
    EXPECT_THROW(default_external_unicast_locators::print_kind(xml_filename, participant_profile, 0), FileNotFound);

    // Push invalid locator kind
    EXPECT_THROW(default_external_unicast_locators::push_kind(xml_filename, participant_profile, invalid_kind),
            ElementInvalid);

    // Try updating locator in a non-existent file
    EXPECT_THROW(default_external_unicast_locators::update_kind(xml_filename, participant_profile, udp_v4_kind, 0),
            FileNotFound);

    // Push valid locator kind
    EXPECT_NO_THROW(default_external_unicast_locators::push_kind(xml_filename, participant_profile, udp_v4_kind));

    // Try printing locator kind from non-existent participant profile
    EXPECT_THAT(
        [&]()
        {
            default_external_unicast_locators::print_kind(xml_filename, another_participant_profile, 0);
        },
        testing::ThrowsMessage<ElementNotFound>(testing::HasSubstr("non-existent participant profile"))
        );

    // Try updating locator kind from non-existent participant profile
    EXPECT_THAT(
        [&]()
        {
            default_external_unicast_locators::update_kind(xml_filename, another_participant_profile, udp_v4_kind, 0);
        },
        testing::ThrowsMessage<ElementNotFound>(testing::HasSubstr("non-existent participant profile"))
        );

    // Create a second profile without a default external unicast locator list
    EXPECT_NO_THROW(set_name(xml_filename, another_participant_profile, participant_name));

    // Try printing locator kind from participant profile with no default external unicast locator list
    EXPECT_THAT(
        [&]()
        {
            default_external_unicast_locators::print_kind(xml_filename, another_participant_profile, 0);
        },
        testing::ThrowsMessage<ElementNotFound>(testing::HasSubstr(
            "participant profile does not have default external unicast locator list"))
        );

    // Try updating locator kind from participant profile with no default external unicast locator list
    EXPECT_THAT(
        [&]()
        {
            default_external_unicast_locators::update_kind(xml_filename, another_participant_profile, udp_v4_kind, 0);
        },
        testing::ThrowsMessage<ElementNotFound>(testing::HasSubstr(
            "participant profile does not have default external unicast locator list"))
        );

    // Try printing locator kind from a non-existent element in the list
    EXPECT_THAT(
        [&]()
        {
            default_external_unicast_locators::print_kind(xml_filename, participant_profile, 100);
        },
        testing::ThrowsMessage<ElementNotFound>(testing::HasSubstr(
            "default external unicast locator list does not have an element in position"))
        );

    // Try updating locator kind from a non-existent element in the list
    EXPECT_THAT(
        [&]()
        {
            default_external_unicast_locators::update_kind(xml_filename, participant_profile, udp_v4_kind, 100);
        },
        testing::ThrowsMessage<ElementNotFound>(testing::HasSubstr(
            "default external unicast locator list does not have an element in position"))
        );

    // Print valid locator kind
    EXPECT_EQ(default_external_unicast_locators::print_kind(xml_filename, participant_profile, 0), "udpv4");

    // Push another valid locator kind
    EXPECT_NO_THROW(default_external_unicast_locators::push_kind(xml_filename, participant_profile, udp_v6_kind));

    // Print both locator kinds
    EXPECT_EQ(default_external_unicast_locators::print_kind(xml_filename, participant_profile, 1), "udpv6");
    EXPECT_EQ(default_external_unicast_locators::print_kind(xml_filename, participant_profile, -2), "udpv4");

    // Update locator kind
    EXPECT_NO_THROW(default_external_unicast_locators::update_kind(xml_filename, participant_profile, udp_v4_kind, 1));

    // Print both locator kinds
    EXPECT_EQ(default_external_unicast_locators::print_kind(xml_filename, participant_profile, -1), "udpv4");
    EXPECT_EQ(default_external_unicast_locators::print_kind(xml_filename, participant_profile, 0), "udpv4");

    // Update invalid locator kind
    EXPECT_THROW(default_external_unicast_locators::update_kind(xml_filename, participant_profile, invalid_kind, 0),
            ElementInvalid);

    // Print both locator kinds
    EXPECT_EQ(default_external_unicast_locators::print_kind(xml_filename, participant_profile, 0), "udpv4");
    EXPECT_EQ(default_external_unicast_locators::print_kind(xml_filename, participant_profile, 1), "udpv4");
}

int main(
        int argc,
        char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
