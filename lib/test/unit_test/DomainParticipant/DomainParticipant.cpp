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

#include <domain_participant/builtin/InitialPeers.hpp>
#include <domain_participant/builtin/MetatrafficExternalUnicastLocators.hpp>
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

    void print_push_update_clear_test()
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

        bool several_invalid_types = false;
        // In case that there are several invalid datas, the related error message must be set too
        if (1 < invalid_values_.size())
        {
            several_invalid_types = true;
            ASSERT_EQ(invalid_values_.size(), invalid_messages_.size());
        }

        // Try printing from non-existing file
        EXPECT_THROW(print_functor_(xml_filename_, participant_profile_, 0), FileNotFound);

        // Try updating in a non-existent file
        EXPECT_THROW(update_functor_(xml_filename_, participant_profile_, valid_values_[0], 0), FileNotFound);

        // Try clearing in a non-existent file
        if (nullptr != clear_functor_)
        {
            EXPECT_THROW(clear_functor_(xml_filename_, participant_profile_, 0), FileNotFound);
        }

        // Push invalid value
        if (!several_invalid_types)
        {
            EXPECT_THROW(push_functor_(xml_filename_, participant_profile_, invalid_values_[0]), ElementInvalid);
        }
        else
        {
            for (int i = 0; i < invalid_values_.size(); i++)
            {
                EXPECT_THAT(
                    [&]()
                    {
                        push_functor_(xml_filename_, participant_profile_, invalid_values_[i]);
                    },
                    testing::ThrowsMessage<ElementInvalid>(testing::HasSubstr(invalid_messages_[i])));
            }
        }

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

        // Try clearing from non-existent profile
        if (nullptr != clear_functor_)
        {
            EXPECT_THAT(
                [&]()
                {
                    clear_functor_(xml_filename_, another_participant_profile_, 0);
                },
                testing::ThrowsMessage<ElementNotFound>(testing::HasSubstr("non-existent profile")));
        }

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

        // Try clearing from profile without the list element
        if (nullptr != clear_functor_)
        {
            EXPECT_THAT(
                [&]()
                {
                    clear_functor_(xml_filename_, another_participant_profile_, 0);
                },
                testing::ThrowsMessage<ElementNotFound>(testing::HasSubstr("profile does not have element list")));
        }

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

        // Try clearing from a non-existent element in the list
        if (nullptr != clear_functor_)
        {
            EXPECT_THAT(
                [&]()
                {
                    clear_functor_(xml_filename_, participant_profile_, 100);
                },
                testing::ThrowsMessage<ElementNotFound>(testing::HasSubstr("list does not have an element in position")));
        }

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

        // Print both elements
        EXPECT_EQ(print_functor_(xml_filename_, participant_profile_, -1), print_results_.empty() ? valid_values_[0] :
                print_results_[0]);
        EXPECT_EQ(print_functor_(xml_filename_, participant_profile_, 0), print_results_.empty() ? valid_values_[0] :
                print_results_[0]);

        // Update invalid value
        if (!several_invalid_types)
        {
            EXPECT_THROW(update_functor_(xml_filename_, participant_profile_, invalid_values_[0], 0),
                    ElementInvalid);
        }
        else
        {
            for (int i = 0; i < invalid_values_.size(); i++)
            {
                EXPECT_THAT(
                    [&]()
                    {
                        update_functor_(xml_filename_, participant_profile_, invalid_values_[i], 0);
                    },
                    testing::ThrowsMessage<ElementInvalid>(testing::HasSubstr(invalid_messages_[i])));
            }
        }

        // Print both elements
        EXPECT_EQ(print_functor_(xml_filename_, participant_profile_, 0), print_results_.empty() ? valid_values_[0] :
                print_results_[0]);
        EXPECT_EQ(print_functor_(xml_filename_, participant_profile_, 1), print_results_.empty() ? valid_values_[0] :
                print_results_[0]);

        // Clear element
        if (nullptr != clear_functor_)
        {
            EXPECT_NO_THROW(clear_functor_(xml_filename_, participant_profile_, 0));

            EXPECT_THAT(
                [&]()
                {
                    print_functor_(xml_filename_, participant_profile_, 0);
                },
                testing::ThrowsMessage<ElementNotFound>(testing::HasSubstr("element does not have sought subelement")));

            // Clear already cleared element does not throw
            EXPECT_NO_THROW(clear_functor_(xml_filename_, participant_profile_, 0));
        }
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
    print_push_update_clear_test();
}

TEST_F(DomainParticipantTests, default_external_unicast_locators_port)
{
    // Test variables
    valid_values_.push_back("11811");
    valid_values_.push_back("11812");
    invalid_values_.push_back("invalid");
    invalid_values_.push_back("65536");
    invalid_values_.push_back("-11811");
    invalid_messages_.push_back("does not match regular expression facet");
    invalid_messages_.push_back("must be less than or equal to maxInclusive facet value");
    invalid_messages_.push_back("must be greater than or equal to minInclusive facet value");

    // Initialize functors
    print_functor_ = [](const std::string& xml_file, const std::string& profile_id, int32_t index) -> std::string
            {
                return default_external_unicast_locators::print_port(xml_file, profile_id, index);
            };
    push_functor_ = [](const std::string& xml_file, const std::string& profile_id, const std::string& kind) -> void
            {
                default_external_unicast_locators::push_port(xml_file, profile_id, kind);
            };
    update_functor_ = [](const std::string& xml_file, const std::string& profile_id, const std::string& kind,
                    int32_t index) -> void
            {
                default_external_unicast_locators::update_port(xml_file, profile_id, kind, index);
            };
    clear_functor_ = [](const std::string& xml_file, const std::string& profile_id, int32_t index) -> void
            {
                default_external_unicast_locators::clear_port(xml_file, profile_id, index);
            };

    // Call test
    print_push_update_clear_test();
}

TEST_F(DomainParticipantTests, default_external_unicast_locators_address)
{
    // Test variables
    valid_values_.push_back("localhost");
    valid_values_.push_back("127.0.0.1");
    invalid_values_.push_back("");

    // Initialize functors
    print_functor_ = [](const std::string& xml_file, const std::string& profile_id, int32_t index) -> std::string
            {
                return default_external_unicast_locators::print_address(xml_file, profile_id, index);
            };
    push_functor_ = [](const std::string& xml_file, const std::string& profile_id, const std::string& kind) -> void
            {
                default_external_unicast_locators::push_address(xml_file, profile_id, kind);
            };
    update_functor_ = [](const std::string& xml_file, const std::string& profile_id, const std::string& kind,
                    int32_t index) -> void
            {
                default_external_unicast_locators::update_address(xml_file, profile_id, kind, index);
            };
    clear_functor_ = [](const std::string& xml_file, const std::string& profile_id, int32_t index) -> void
            {
                default_external_unicast_locators::clear_address(xml_file, profile_id, index);
            };

    // Call test
    print_push_update_clear_test();
}

TEST_F(DomainParticipantTests, default_external_unicast_locators_externality)
{
    // Test variables
    valid_values_.push_back("1");
    valid_values_.push_back("126");
    invalid_values_.push_back("invalid");
    invalid_values_.push_back("256");
    invalid_values_.push_back("0");
    invalid_messages_.push_back("does not match regular expression facet");
    invalid_messages_.push_back("must be less than or equal to maxInclusive facet value");
    invalid_messages_.push_back("must be greater than or equal to minInclusive facet value");

    // Initialize functors
    print_functor_ = [](const std::string& xml_file, const std::string& profile_id, int32_t index) -> std::string
            {
                return default_external_unicast_locators::print_externality(xml_file, profile_id, index);
            };
    push_functor_ = [](const std::string& xml_file, const std::string& profile_id, const std::string& kind) -> void
            {
                default_external_unicast_locators::push_externality(xml_file, profile_id, kind);
            };
    update_functor_ = [](const std::string& xml_file, const std::string& profile_id, const std::string& kind,
                    int32_t index) -> void
            {
                default_external_unicast_locators::update_externality(xml_file, profile_id, kind, index);
            };
    clear_functor_ = [](const std::string& xml_file, const std::string& profile_id, int32_t index) -> void
            {
                default_external_unicast_locators::clear_externality(xml_file, profile_id, index);
            };

    // Call test
    print_push_update_clear_test();
}

TEST_F(DomainParticipantTests, default_external_unicast_locators_cost)
{
    // Test variables
    valid_values_.push_back("0");
    valid_values_.push_back("126");
    invalid_values_.push_back("invalid");
    invalid_values_.push_back("256");
    invalid_values_.push_back("-1");
    invalid_messages_.push_back("does not match regular expression facet");
    invalid_messages_.push_back("must be less than or equal to maxInclusive facet value");
    invalid_messages_.push_back("must be greater than or equal to minInclusive facet value");

    // Initialize functors
    print_functor_ = [](const std::string& xml_file, const std::string& profile_id, int32_t index) -> std::string
            {
                return default_external_unicast_locators::print_cost(xml_file, profile_id, index);
            };
    push_functor_ = [](const std::string& xml_file, const std::string& profile_id, const std::string& kind) -> void
            {
                default_external_unicast_locators::push_cost(xml_file, profile_id, kind);
            };
    update_functor_ = [](const std::string& xml_file, const std::string& profile_id, const std::string& kind,
                    int32_t index) -> void
            {
                default_external_unicast_locators::update_cost(xml_file, profile_id, kind, index);
            };
    clear_functor_ = [](const std::string& xml_file, const std::string& profile_id, int32_t index) -> void
            {
                default_external_unicast_locators::clear_cost(xml_file, profile_id, index);
            };

    // Call test
    print_push_update_clear_test();
}

TEST_F(DomainParticipantTests, default_external_unicast_locators_mask)
{
    // Test variables
    // Default: UDP v4
    valid_values_.push_back("1");
    valid_values_.push_back("24");
    invalid_values_.push_back("invalid");
    invalid_values_.push_back("32");
    invalid_values_.push_back("0");
    invalid_messages_.push_back("does not match regular expression facet");
    invalid_messages_.push_back("must be less than or equal to maxInclusive facet value");
    invalid_messages_.push_back("must be greater than or equal to minInclusive facet value");

    // Initialize functors
    print_functor_ = [](const std::string& xml_file, const std::string& profile_id, int32_t index) -> std::string
            {
                return default_external_unicast_locators::print_mask(xml_file, profile_id, index);
            };
    push_functor_ = [](const std::string& xml_file, const std::string& profile_id, const std::string& kind) -> void
            {
                default_external_unicast_locators::push_mask(xml_file, profile_id, kind);
            };
    update_functor_ = [](const std::string& xml_file, const std::string& profile_id, const std::string& kind,
                    int32_t index) -> void
            {
                default_external_unicast_locators::update_mask(xml_file, profile_id, kind, index);
            };
    clear_functor_ = [](const std::string& xml_file, const std::string& profile_id, int32_t index) -> void
            {
                default_external_unicast_locators::clear_mask(xml_file, profile_id, index);
            };

    // Call test
    print_push_update_clear_test();
}

/**********************************************************************************************************************/
/* DOMAIN PARTICIPANT TESTS                                                                                           */
/* Builtin::MetatrafficExternalUnicastLocators                                                                        */
/**********************************************************************************************************************/
TEST_F(DomainParticipantTests, builtin_metatraffic_external_unicast_locators_kind)
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
                return builtin::metatraffic_external_unicast_locators::print_kind(xml_file, profile_id, index);
            };
    push_functor_ = [](const std::string& xml_file, const std::string& profile_id, const std::string& kind) -> void
            {
                builtin::metatraffic_external_unicast_locators::push_kind(xml_file, profile_id, kind);
            };
    update_functor_ = [](const std::string& xml_file, const std::string& profile_id, const std::string& kind,
                    int32_t index) -> void
            {
                builtin::metatraffic_external_unicast_locators::update_kind(xml_file, profile_id, kind, index);
            };

    // Call test
    print_push_update_clear_test();
}

TEST_F(DomainParticipantTests, builtin_metatraffic_external_unicast_locators_port)
{
    // Test variables
    valid_values_.push_back("11811");
    valid_values_.push_back("11812");
    invalid_values_.push_back("invalid");
    invalid_values_.push_back("65536");
    invalid_values_.push_back("-11811");
    invalid_messages_.push_back("does not match regular expression facet");
    invalid_messages_.push_back("must be less than or equal to maxInclusive facet value");
    invalid_messages_.push_back("must be greater than or equal to minInclusive facet value");

    // Initialize functors
    print_functor_ = [](const std::string& xml_file, const std::string& profile_id, int32_t index) -> std::string
            {
                return builtin::metatraffic_external_unicast_locators::print_port(xml_file, profile_id, index);
            };
    push_functor_ = [](const std::string& xml_file, const std::string& profile_id, const std::string& kind) -> void
            {
                builtin::metatraffic_external_unicast_locators::push_port(xml_file, profile_id, kind);
            };
    update_functor_ = [](const std::string& xml_file, const std::string& profile_id, const std::string& kind,
                    int32_t index) -> void
            {
                builtin::metatraffic_external_unicast_locators::update_port(xml_file, profile_id, kind, index);
            };
    clear_functor_ = [](const std::string& xml_file, const std::string& profile_id, int32_t index) -> void
            {
                builtin::metatraffic_external_unicast_locators::clear_port(xml_file, profile_id, index);
            };

    // Call test
    print_push_update_clear_test();
}

TEST_F(DomainParticipantTests, builtin_metatraffic_external_unicast_locators_address)
{
    // Test variables
    valid_values_.push_back("localhost");
    valid_values_.push_back("127.0.0.1");
    invalid_values_.push_back("");

    // Initialize functors
    print_functor_ = [](const std::string& xml_file, const std::string& profile_id, int32_t index) -> std::string
            {
                return builtin::metatraffic_external_unicast_locators::print_address(xml_file, profile_id, index);
            };
    push_functor_ = [](const std::string& xml_file, const std::string& profile_id, const std::string& kind) -> void
            {
                builtin::metatraffic_external_unicast_locators::push_address(xml_file, profile_id, kind);
            };
    update_functor_ = [](const std::string& xml_file, const std::string& profile_id, const std::string& kind,
                    int32_t index) -> void
            {
                builtin::metatraffic_external_unicast_locators::update_address(xml_file, profile_id, kind, index);
            };
    clear_functor_ = [](const std::string& xml_file, const std::string& profile_id, int32_t index) -> void
            {
                builtin::metatraffic_external_unicast_locators::clear_address(xml_file, profile_id, index);
            };

    // Call test
    print_push_update_clear_test();
}

TEST_F(DomainParticipantTests, builtin_metatraffic_external_unicast_locators_externality)
{
    // Test variables
    valid_values_.push_back("1");
    valid_values_.push_back("126");
    invalid_values_.push_back("invalid");
    invalid_values_.push_back("256");
    invalid_values_.push_back("0");
    invalid_messages_.push_back("does not match regular expression facet");
    invalid_messages_.push_back("must be less than or equal to maxInclusive facet value");
    invalid_messages_.push_back("must be greater than or equal to minInclusive facet value");

    // Initialize functors
    print_functor_ = [](const std::string& xml_file, const std::string& profile_id, int32_t index) -> std::string
            {
                return builtin::metatraffic_external_unicast_locators::print_externality(xml_file, profile_id, index);
            };
    push_functor_ = [](const std::string& xml_file, const std::string& profile_id, const std::string& kind) -> void
            {
                builtin::metatraffic_external_unicast_locators::push_externality(xml_file, profile_id, kind);
            };
    update_functor_ = [](const std::string& xml_file, const std::string& profile_id, const std::string& kind,
                    int32_t index) -> void
            {
                builtin::metatraffic_external_unicast_locators::update_externality(xml_file, profile_id, kind, index);
            };
    clear_functor_ = [](const std::string& xml_file, const std::string& profile_id, int32_t index) -> void
            {
                builtin::metatraffic_external_unicast_locators::clear_externality(xml_file, profile_id, index);
            };

    // Call test
    print_push_update_clear_test();
}

TEST_F(DomainParticipantTests, builtin_metatraffic_external_unicast_locators_cost)
{
    // Test variables
    valid_values_.push_back("0");
    valid_values_.push_back("126");
    invalid_values_.push_back("invalid");
    invalid_values_.push_back("256");
    invalid_values_.push_back("-1");
    invalid_messages_.push_back("does not match regular expression facet");
    invalid_messages_.push_back("must be less than or equal to maxInclusive facet value");
    invalid_messages_.push_back("must be greater than or equal to minInclusive facet value");

    // Initialize functors
    print_functor_ = [](const std::string& xml_file, const std::string& profile_id, int32_t index) -> std::string
            {
                return builtin::metatraffic_external_unicast_locators::print_cost(xml_file, profile_id, index);
            };
    push_functor_ = [](const std::string& xml_file, const std::string& profile_id, const std::string& kind) -> void
            {
                builtin::metatraffic_external_unicast_locators::push_cost(xml_file, profile_id, kind);
            };
    update_functor_ = [](const std::string& xml_file, const std::string& profile_id, const std::string& kind,
                    int32_t index) -> void
            {
                builtin::metatraffic_external_unicast_locators::update_cost(xml_file, profile_id, kind, index);
            };
    clear_functor_ = [](const std::string& xml_file, const std::string& profile_id, int32_t index) -> void
            {
                builtin::metatraffic_external_unicast_locators::clear_cost(xml_file, profile_id, index);
            };

    // Call test
    print_push_update_clear_test();
}

TEST_F(DomainParticipantTests, builtin_metatraffic_external_unicast_locators_mask)
{
    // Test variables
    // Default: UDP v4
    valid_values_.push_back("1");
    valid_values_.push_back("24");
    invalid_values_.push_back("invalid");
    invalid_values_.push_back("32");
    invalid_values_.push_back("0");
    invalid_messages_.push_back("does not match regular expression facet");
    invalid_messages_.push_back("must be less than or equal to maxInclusive facet value");
    invalid_messages_.push_back("must be greater than or equal to minInclusive facet value");

    // Initialize functors
    print_functor_ = [](const std::string& xml_file, const std::string& profile_id, int32_t index) -> std::string
            {
                return builtin::metatraffic_external_unicast_locators::print_mask(xml_file, profile_id, index);
            };
    push_functor_ = [](const std::string& xml_file, const std::string& profile_id, const std::string& kind) -> void
            {
                builtin::metatraffic_external_unicast_locators::push_mask(xml_file, profile_id, kind);
            };
    update_functor_ = [](const std::string& xml_file, const std::string& profile_id, const std::string& kind,
                    int32_t index) -> void
            {
                builtin::metatraffic_external_unicast_locators::update_mask(xml_file, profile_id, kind, index);
            };
    clear_functor_ = [](const std::string& xml_file, const std::string& profile_id, int32_t index) -> void
            {
                builtin::metatraffic_external_unicast_locators::clear_mask(xml_file, profile_id, index);
            };

    // Call test
    print_push_update_clear_test();
}

/**********************************************************************************************************************/
/* DOMAIN PARTICIPANT TESTS                                                                                           */
/* Builtin::InitialPeers                                                                                              */
/**********************************************************************************************************************/
TEST_F(DomainParticipantTests, builtin_initial_peers_kind)
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
                return builtin::initial_peers::print_kind(xml_file, profile_id, index);
            };
    push_functor_ = [](const std::string& xml_file, const std::string& profile_id, const std::string& kind) -> void
            {
                builtin::initial_peers::push_kind(xml_file, profile_id, kind);
            };
    update_functor_ = [](const std::string& xml_file, const std::string& profile_id, const std::string& kind,
                    int32_t index) -> void
            {
                builtin::initial_peers::update_kind(xml_file, profile_id, kind, index);
            };

    // Call test
    print_push_update_clear_test();
}

TEST_F(DomainParticipantTests, builtin_initial_peers_port)
{
    // Test variables
    valid_values_.push_back("11811");
    valid_values_.push_back("11812");
    invalid_values_.push_back("invalid");
    invalid_values_.push_back("65536");
    invalid_values_.push_back("-11811");
    invalid_messages_.push_back("does not match regular expression facet");
    invalid_messages_.push_back("must be less than or equal to maxInclusive facet value");
    invalid_messages_.push_back("must be greater than or equal to minInclusive facet value");

    // Initialize functors
    print_functor_ = [](const std::string& xml_file, const std::string& profile_id, int32_t index) -> std::string
            {
                return builtin::initial_peers::print_port(xml_file, profile_id, index);
            };
    push_functor_ = [](const std::string& xml_file, const std::string& profile_id, const std::string& kind) -> void
            {
                builtin::initial_peers::push_port(xml_file, profile_id, kind);
            };
    update_functor_ = [](const std::string& xml_file, const std::string& profile_id, const std::string& kind,
                    int32_t index) -> void
            {
                builtin::initial_peers::update_port(xml_file, profile_id, kind, index);
            };
    clear_functor_ = [](const std::string& xml_file, const std::string& profile_id, int32_t index) -> void
            {
                builtin::initial_peers::clear_port(xml_file, profile_id, index);
            };

    // Call test
    print_push_update_clear_test();
}

TEST_F(DomainParticipantTests, builtin_initial_peers_physical_port)
{
    // Test variables
    valid_values_.push_back("11811");
    valid_values_.push_back("11812");
    invalid_values_.push_back("invalid");
    invalid_values_.push_back("65536");
    invalid_values_.push_back("-11811");
    invalid_messages_.push_back("does not match regular expression facet");
    invalid_messages_.push_back("must be less than or equal to maxInclusive facet value");
    invalid_messages_.push_back("must be greater than or equal to minInclusive facet value");

    // Initialize functors
    print_functor_ = [](const std::string& xml_file, const std::string& profile_id, int32_t index) -> std::string
            {
                return builtin::initial_peers::print_physical_port(xml_file, profile_id, index);
            };
    push_functor_ = [](const std::string& xml_file, const std::string& profile_id, const std::string& kind) -> void
            {
                builtin::initial_peers::push_physical_port(xml_file, profile_id, kind);
            };
    update_functor_ = [](const std::string& xml_file, const std::string& profile_id, const std::string& kind,
                    int32_t index) -> void
            {
                builtin::initial_peers::update_physical_port(xml_file, profile_id, kind, index);
            };
    clear_functor_ = [](const std::string& xml_file, const std::string& profile_id, int32_t index) -> void
            {
                builtin::initial_peers::clear_physical_port(xml_file, profile_id, index);
            };

    // Call test
    print_push_update_clear_test();
}

TEST_F(DomainParticipantTests, builtin_initial_peers_address)
{
    // Test variables
    valid_values_.push_back("localhost");
    valid_values_.push_back("127.0.0.1");
    invalid_values_.push_back("");

    // Initialize functors
    print_functor_ = [](const std::string& xml_file, const std::string& profile_id, int32_t index) -> std::string
            {
                return builtin::initial_peers::print_address(xml_file, profile_id, index);
            };
    push_functor_ = [](const std::string& xml_file, const std::string& profile_id, const std::string& kind) -> void
            {
                builtin::initial_peers::push_address(xml_file, profile_id, kind);
            };
    update_functor_ = [](const std::string& xml_file, const std::string& profile_id, const std::string& kind,
                    int32_t index) -> void
            {
                builtin::initial_peers::update_address(xml_file, profile_id, kind, index);
            };
    clear_functor_ = [](const std::string& xml_file, const std::string& profile_id, int32_t index) -> void
            {
                builtin::initial_peers::clear_address(xml_file, profile_id, index);
            };

    // Call test
    print_push_update_clear_test();
}

TEST_F(DomainParticipantTests, builtin_initial_peers_unique_lan_id)
{
    // Test variables
    valid_values_.push_back("localhost");
    valid_values_.push_back("127.0.0.1");
    invalid_values_.push_back("");

    // Initialize functors
    print_functor_ = [](const std::string& xml_file, const std::string& profile_id, int32_t index) -> std::string
            {
                return builtin::initial_peers::print_unique_lan_id(xml_file, profile_id, index);
            };
    push_functor_ = [](const std::string& xml_file, const std::string& profile_id, const std::string& kind) -> void
            {
                builtin::initial_peers::push_unique_lan_id(xml_file, profile_id, kind);
            };
    update_functor_ = [](const std::string& xml_file, const std::string& profile_id, const std::string& kind,
                    int32_t index) -> void
            {
                builtin::initial_peers::update_unique_lan_id(xml_file, profile_id, kind, index);
            };
    clear_functor_ = [](const std::string& xml_file, const std::string& profile_id, int32_t index) -> void
            {
                builtin::initial_peers::clear_unique_lan_id(xml_file, profile_id, index);
            };

    // Call test
    print_push_update_clear_test();
}

TEST_F(DomainParticipantTests, builtin_initial_peers_wan_address)
{
    // Test variables
    valid_values_.push_back("127.0.0.1");
    valid_values_.push_back("192.168.1.2");
    invalid_values_.push_back("localhost");

    // Initialize functors
    print_functor_ = [](const std::string& xml_file, const std::string& profile_id, int32_t index) -> std::string
            {
                return builtin::initial_peers::print_wan_address(xml_file, profile_id, index);
            };
    push_functor_ = [](const std::string& xml_file, const std::string& profile_id, const std::string& kind) -> void
            {
                builtin::initial_peers::push_wan_address(xml_file, profile_id, kind);
            };
    update_functor_ = [](const std::string& xml_file, const std::string& profile_id, const std::string& kind,
                    int32_t index) -> void
            {
                builtin::initial_peers::update_wan_address(xml_file, profile_id, kind, index);
            };
    clear_functor_ = [](const std::string& xml_file, const std::string& profile_id, int32_t index) -> void
            {
                builtin::initial_peers::clear_wan_address(xml_file, profile_id, index);
            };

    // Call test
    print_push_update_clear_test();
}

int main(
        int argc,
        char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
