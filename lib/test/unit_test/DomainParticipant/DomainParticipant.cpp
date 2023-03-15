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
#include <vector>

#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include <domain_participant/DefaultExternalUnicastLocators.hpp>
#include <domain_participant/DomainParticipant.hpp>
#include <exception/Exception.hpp>

using namespace eprosima::qosprof;
using namespace eprosima::qosprof::domain_participant;

class DomainParticipantTests : public ::testing::Test
{
protected:

    // Test fixture variables
    std::string xml_filename_;
    std::string participant_profile_;
    std::string another_participant_profile_;
    std::string participant_name_;
    std::vector<std::string> valid_values_;
    std::vector<std::string> invalid_values_;
    std::vector<std::string> invalid_messages_;
    std::vector<std::string> print_results_;

    // Functors
    std::function<std::string(const std::string&, const std::string&, int32_t)> print_functor_;
    std::function<void(const std::string&, const std::string&, const std::string&)> push_functor_;
    std::function<void(const std::string&, const std::string&, const std::string&, int32_t)> update_functor_;
    std::function<void(const std::string&, const std::string&, int32_t)> clear_functor_;

    void SetUp() override
    {
        xml_filename_ = "test.xml";
        participant_profile_ = "test_profile";
        another_participant_profile_ = "second_test_profile";
        participant_name_ = "participant_test";
        valid_values_.clear();
        invalid_values_.clear();
        invalid_messages_.clear();
        print_results_.clear();
        print_functor_ = nullptr;
        push_functor_ = nullptr;
        update_functor_ = nullptr;
        clear_functor_ = nullptr;
    }

    void TearDown() override
    {
        // Clean test workspace
        std::remove(xml_filename_.c_str());
    }

    void print_push_update_test()
    {
        // Functors must be initialized
        ASSERT_NE(print_functor_, nullptr);
        ASSERT_NE(push_functor_, nullptr);
        ASSERT_NE(update_functor_, nullptr);

        // Valid data and invalid data vectors should have values
        // Valid data should have at least two elements to check update
        ASSERT_FALSE(valid_values_.empty());
        ASSERT_GE(valid_values_.size(), 2);
        ASSERT_FALSE(invalid_values_.empty());

        // Try printing from non-existing file
        EXPECT_THROW(print_functor_(xml_filename_, participant_profile_, 0), FileNotFound);

        // Try updating in a non-existent file
        EXPECT_THROW(update_functor_(xml_filename_, participant_profile_, valid_values_[0], 0), FileNotFound);

        // Push invalid value
        EXPECT_THROW(push_functor_(xml_filename_, participant_profile_, invalid_values_[0]), ElementInvalid);

        // Push valid value (file is created)
        EXPECT_NO_THROW(push_functor_(xml_filename_, participant_profile_, valid_values_[0]));

        // Try printing from non-existent profile
        EXPECT_THAT(
            [&]()
            {
                print_functor_(xml_filename_, another_participant_profile_, 0);
            },
            testing::ThrowsMessage<ElementNotFound>(testing::HasSubstr("non-existent profile")));

        // Try updating from non-existent profile
        EXPECT_THAT(
            [&]()
            {
                update_functor_(xml_filename_, another_participant_profile_, valid_values_[0], 0);
            },
            testing::ThrowsMessage<ElementNotFound>(testing::HasSubstr("non-existent profile")));

        // Create a second profile without the list element
        EXPECT_NO_THROW(set_name(xml_filename_, another_participant_profile_, participant_name_));

        // Try printing from profile without the list element
        EXPECT_THAT(
            [&]()
            {
                print_functor_(xml_filename_, another_participant_profile_, 0);
            },
            testing::ThrowsMessage<ElementNotFound>(testing::HasSubstr("profile does not have element list")));

        // Try updating from profile without the list element
        EXPECT_THAT(
            [&]()
            {
                update_functor_(xml_filename_, another_participant_profile_, valid_values_[0], 0);
            },
            testing::ThrowsMessage<ElementNotFound>(testing::HasSubstr("profile does not have element list")));

        // Try printing from a non-existent element in the list
        EXPECT_THAT(
            [&]()
            {
                print_functor_(xml_filename_, participant_profile_, 100);
            },
            testing::ThrowsMessage<ElementNotFound>(testing::HasSubstr("list does not have an element in position")));

        // Try updating from a non-existent element in the list
        EXPECT_THAT(
            [&]()
            {
                update_functor_(xml_filename_, participant_profile_, valid_values_[0], 100);
            },
            testing::ThrowsMessage<ElementNotFound>(testing::HasSubstr("list does not have an element in position")));

        // Print valid value
        EXPECT_EQ(print_functor_(xml_filename_, participant_profile_, 0), print_results_.empty() ? valid_values_[0] :
                print_results_[0]);

        // Push another valid value
        EXPECT_NO_THROW(push_functor_(xml_filename_, participant_profile_, valid_values_[1]));

        // Print both elements
        EXPECT_EQ(print_functor_(xml_filename_, participant_profile_, 1), print_results_.empty() ? valid_values_[1] :
                print_results_[1]);
        EXPECT_EQ(print_functor_(xml_filename_, participant_profile_, -2), print_results_.empty() ? valid_values_[0] :
                print_results_[0]);

        // Update element
        EXPECT_NO_THROW(update_functor_(xml_filename_, participant_profile_, valid_values_[0], 1));

        // Print both locator kinds
        EXPECT_EQ(print_functor_(xml_filename_, participant_profile_, -1), print_results_.empty() ? valid_values_[0] :
                print_results_[0]);
        EXPECT_EQ(print_functor_(xml_filename_, participant_profile_, 0), print_results_.empty() ? valid_values_[0] :
                print_results_[0]);

        // Update invalid locator kind
        EXPECT_THROW(update_functor_(xml_filename_, participant_profile_, invalid_values_[0], 0),
                ElementInvalid);

        // Print both locator kinds
        EXPECT_EQ(print_functor_(xml_filename_, participant_profile_, 0), print_results_.empty() ? valid_values_[0] :
                print_results_[0]);
        EXPECT_EQ(print_functor_(xml_filename_, participant_profile_, 1), print_results_.empty() ? valid_values_[0] :
                print_results_[0]);
    }

};

/**********************************************************************************************************************/
/* DOMAIN PARTICIPANT TESTS                                                                                           */
/* General functions (eprosima::qosprof::domain_participant namespace)                                                */
/**********************************************************************************************************************/
TEST_F(DomainParticipantTests, default_profile_test)
{
    // Test variables
    std::string another_participant_name_ = "second_participant_test";

    // Try printing default profile for non-existing file
    EXPECT_THROW(print_default_profile(xml_filename_), FileNotFound);

    // Set default profile to non-existent XML file
    EXPECT_THROW(set_default_profile(xml_filename_, participant_profile_), FileNotFound);

    // Clear default profile from a non-existent XML file
    EXPECT_THROW(clear_default_profile(xml_filename_), FileNotFound);

    // Set participant name in order to create file
    EXPECT_NO_THROW(set_name(xml_filename_, participant_profile_, participant_name_));

    // Print non-existing default profile
    EXPECT_THROW(print_default_profile(xml_filename_), ElementNotFound);

    // Set default profile to non-existent participant profile
    EXPECT_THROW(set_default_profile(xml_filename_, another_participant_profile_), ElementNotFound);

    // Set default profile to existent profile
    EXPECT_NO_THROW(set_default_profile(xml_filename_, participant_profile_));

    // Print existent default profile
    EXPECT_EQ(print_default_profile(xml_filename_), participant_profile_);

    // Create a second profile and change default profile to this second profile
    EXPECT_NO_THROW(set_name(xml_filename_, another_participant_profile_, another_participant_name_));
    EXPECT_NO_THROW(set_default_profile(xml_filename_, another_participant_profile_));

    // Print existent default profile
    EXPECT_EQ(print_default_profile(xml_filename_), another_participant_profile_);

    // Clear default profile
    EXPECT_NO_THROW(clear_default_profile(xml_filename_));

    // Print non-existent default profile
    EXPECT_THROW(print_default_profile(xml_filename_), ElementNotFound);

    // Clear default profile from a file with no default profile
    EXPECT_NO_THROW(clear_default_profile(xml_filename_));
}

/**********************************************************************************************************************/
/* DOMAIN PARTICIPANT TESTS                                                                                           */
/* DefaultExternalUnicastLocators                                                                                     */
/**********************************************************************************************************************/
TEST_F(DomainParticipantTests, default_external_unicast_locators_kind)
{
    // Test variables
    valid_values_.push_back("udp_v4");
    valid_values_.push_back("udp_v6");
    invalid_values_.push_back("tcp_v4");

    // Expected results
    print_results_.push_back("udpv4");
    print_results_.push_back("udpv6");

    // Initialize functors
    print_functor_ = [](const std::string& xml_file, const std::string& profile_id, int32_t index) -> std::string
            {
                return default_external_unicast_locators::print_kind(xml_file, profile_id, index);
            };
    push_functor_ = [](const std::string& xml_file, const std::string& profile_id, const std::string& kind) -> void
            {
                default_external_unicast_locators::push_kind(xml_file, profile_id, kind);
            };
    update_functor_ = [](const std::string& xml_file, const std::string& profile_id, const std::string& kind,
                    int32_t index) -> void
            {
                default_external_unicast_locators::update_kind(xml_file, profile_id, kind, index);
            };

    // Call test
    print_push_update_test();
}

TEST_F(DomainParticipantTests, default_external_unicast_locators_port)
{

}

int main(
        int argc,
        char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
