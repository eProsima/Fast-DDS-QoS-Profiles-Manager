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

#include <fastdds_qos_profiles_manager_lib/domain_participant/builtin/InitialPeers.hpp>
#include <fastdds_qos_profiles_manager_lib/domain_participant/builtin/MetatrafficExternalUnicastLocators.hpp>
#include <fastdds_qos_profiles_manager_lib/domain_participant/DefaultExternalUnicastLocators.hpp>
#include <fastdds_qos_profiles_manager_lib/domain_participant/DomainParticipant.hpp>
#include <fastdds_qos_profiles_manager_lib/exception/Exception.hpp>
#include <fastdds_qos_profiles_manager_lib/QoSProfilesManager.hpp>

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
    std::function<std::string(const std::string&, const std::string&)> print_functor_;
    std::function<void(const std::string&, const std::string&, const std::string&)> set_functor_;
    std::function<void(const std::string&, const std::string&)> clear_functor_;

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
        set_functor_ = nullptr;
        clear_functor_ = nullptr;
    }

    void TearDown() override
    {
        // Clean test workspace
        std::remove(xml_filename_.c_str());
    }

    void print_set_clear_with_index_test()
    {
        // Functors must be initialized
        ASSERT_NE(print_functor_, nullptr);
        ASSERT_NE(set_functor_, nullptr);

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

        // Initialize the XML workspace
        EXPECT_NO_THROW(initialize(xml_filename_));

        // Passing an invalid index string must return BadParameter
        EXPECT_THROW(print_functor_(participant_profile_, std::string("invalid")), BadParameter);
        EXPECT_THROW(set_functor_(participant_profile_, valid_values_[0], std::string("invalid")),
                BadParameter);
        if (nullptr != clear_functor_)
        {
            EXPECT_THROW(clear_functor_(participant_profile_, std::string("invalid")), BadParameter);
        }

        // Try printing from non-existing file
        EXPECT_THROW(print_functor_(participant_profile_, std::string("0")), ElementNotFound);

        // Try updating in a non-existent file
        EXPECT_THROW(set_functor_(participant_profile_, valid_values_[0], std::string("0")),
                ElementNotFound);

        // Try clearing in a non-existent file
        if (nullptr != clear_functor_)
        {
            EXPECT_THROW(clear_functor_(participant_profile_, std::string("0")), ElementNotFound);
        }

        // Push invalid value
        if (!several_invalid_types)
        {
            EXPECT_THROW(set_functor_(participant_profile_, invalid_values_[0],
                    std::string()), ElementInvalid);
        }
        else
        {
            for (uint32_t i = 0; i < invalid_values_.size(); i++)
            {
                EXPECT_THAT(
                    [&]()
                    {
                        set_functor_(participant_profile_, invalid_values_[i], std::string());
                    },
                    testing::ThrowsMessage<ElementInvalid>(testing::HasSubstr(invalid_messages_[i])));
            }
        }

        // Push valid value (file is created)
        EXPECT_NO_THROW(set_functor_(participant_profile_, valid_values_[0], std::string()));

        // Try printing from non-existent profile
        EXPECT_THAT(
            [&]()
            {
                print_functor_(another_participant_profile_, std::string("0"));
            },
            testing::ThrowsMessage<ElementNotFound>(testing::HasSubstr("non-existent profile")));

        // Try updating from non-existent profile
        EXPECT_THAT(
            [&]()
            {
                set_functor_(another_participant_profile_, valid_values_[0], std::string("0"));
            },
            testing::ThrowsMessage<ElementNotFound>(testing::HasSubstr("non-existent profile")));

        // Try clearing from non-existent profile
        if (nullptr != clear_functor_)
        {
            EXPECT_THAT(
                [&]()
                {
                    clear_functor_(another_participant_profile_, std::string("0"));
                },
                testing::ThrowsMessage<ElementNotFound>(testing::HasSubstr("non-existent profile")));
        }

        // Create a second profile without the list element
        EXPECT_NO_THROW(set_name(another_participant_profile_, participant_name_));

        // Try printing from profile without the list element
        EXPECT_THAT(
            [&]()
            {
                print_functor_(another_participant_profile_, std::string("0"));
            },
            testing::ThrowsMessage<ElementNotFound>(testing::HasSubstr("profile does not have element list")));

        // Try updating from profile without the list element
        EXPECT_THAT(
            [&]()
            {
                set_functor_(another_participant_profile_, valid_values_[0], std::string("0"));
            },
            testing::ThrowsMessage<ElementNotFound>(testing::HasSubstr("profile does not have element list")));

        // Try clearing from profile without the list element
        if (nullptr != clear_functor_)
        {
            EXPECT_THAT(
                [&]()
                {
                    clear_functor_(another_participant_profile_, std::string("0"));
                },
                testing::ThrowsMessage<ElementNotFound>(testing::HasSubstr("profile does not have element list")));
        }

        // Try printing from a non-existent element in the list
        EXPECT_THAT(
            [&]()
            {
                print_functor_(participant_profile_, std::string("100"));
            },
            testing::ThrowsMessage<ElementNotFound>(testing::HasSubstr("list does not have an element in position")));

        // Try updating from a non-existent element in the list
        EXPECT_THAT(
            [&]()
            {
                set_functor_(participant_profile_, valid_values_[0], std::string("100"));
            },
            testing::ThrowsMessage<ElementNotFound>(testing::HasSubstr("list does not have an element in position")));

        // Try clearing from a non-existent element in the list
        if (nullptr != clear_functor_)
        {
            EXPECT_THAT(
                [&]()
                {
                    clear_functor_(participant_profile_, std::string("100"));
                },
                testing::ThrowsMessage<ElementNotFound>(testing::HasSubstr("list does not have an element in position")));
        }

        // Print valid value
        EXPECT_EQ(print_functor_(participant_profile_, std::string("0")),
                print_results_.empty() ? valid_values_[0] :
                print_results_[0]);

        // Push another valid value
        EXPECT_NO_THROW(set_functor_(participant_profile_, valid_values_[1], std::string()));

        // Print both elements
        EXPECT_EQ(print_functor_(participant_profile_, std::string("1")),
                print_results_.empty() ? valid_values_[1] :
                print_results_[1]);
        EXPECT_EQ(print_functor_(participant_profile_, std::string("-2")),
                print_results_.empty() ? valid_values_[0] :
                print_results_[0]);

        // Update element
        EXPECT_NO_THROW(set_functor_(participant_profile_, valid_values_[0], std::string("1")));

        // Print both elements
        EXPECT_EQ(print_functor_(participant_profile_, std::string("-1")),
                print_results_.empty() ? valid_values_[0] :
                print_results_[0]);
        EXPECT_EQ(print_functor_(participant_profile_, std::string("0")),
                print_results_.empty() ? valid_values_[0] :
                print_results_[0]);

        // Update invalid value
        if (!several_invalid_types)
        {
            EXPECT_THROW(set_functor_(participant_profile_, invalid_values_[0], std::string("0")),
                    ElementInvalid);
        }
        else
        {
            for (uint32_t i = 0; i < invalid_values_.size(); i++)
            {
                EXPECT_THAT(
                    [&]()
                    {
                        set_functor_(participant_profile_, invalid_values_[i], std::string("0"));
                    },
                    testing::ThrowsMessage<ElementInvalid>(testing::HasSubstr(invalid_messages_[i])));
            }
        }

        // Print both elements
        EXPECT_EQ(print_functor_(participant_profile_, std::string("0")),
                print_results_.empty() ? valid_values_[0] :
                print_results_[0]);
        EXPECT_EQ(print_functor_(participant_profile_, std::string("1")),
                print_results_.empty() ? valid_values_[0] :
                print_results_[0]);

        // Clear element
        if (nullptr != clear_functor_)
        {
            EXPECT_NO_THROW(clear_functor_(participant_profile_, std::string("0")));

            EXPECT_THAT(
                [&]()
                {
                    print_functor_(participant_profile_, std::string("0"));
                },
                testing::ThrowsMessage<ElementNotFound>(testing::HasSubstr("element does not have sought subelement")));

            // Clear already cleared element does not throw
            EXPECT_NO_THROW(clear_functor_(participant_profile_, std::string("0")));
        }

        // Terminate XML workspace
        EXPECT_NO_THROW(terminate());
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

    // Initialize the XML workspace
    EXPECT_NO_THROW(initialize(xml_filename_));

    // Try printing default profile for non-existing file
    EXPECT_THROW(print_default_profile(), ElementNotFound);

    // Set default profile to non-existent XML file
    EXPECT_THROW(set_default_profile(participant_profile_), ElementNotFound);

    // Clear default profile from a non-existent XML file
    EXPECT_THROW(clear_default_profile(), ElementNotFound);

    // Set participant name in order to create file
    EXPECT_NO_THROW(set_name(participant_profile_, participant_name_));

    // Print non-existing default profile
    EXPECT_THROW(print_default_profile(), ElementNotFound);

    // Set default profile to non-existent participant profile
    EXPECT_THROW(set_default_profile(another_participant_profile_), ElementNotFound);

    // Set default profile to existent profile
    EXPECT_NO_THROW(set_default_profile(participant_profile_));

    // Print existent default profile
    EXPECT_EQ(print_default_profile(), participant_profile_);

    // Create a second profile and change default profile to this second profile
    EXPECT_NO_THROW(set_name(another_participant_profile_, another_participant_name_));
    EXPECT_NO_THROW(set_default_profile(another_participant_profile_));

    // Print existent default profile
    EXPECT_EQ(print_default_profile(), another_participant_profile_);

    // Clear default profile
    EXPECT_NO_THROW(clear_default_profile());

    // Print non-existent default profile
    EXPECT_THROW(print_default_profile(), ElementNotFound);

    // Clear default profile from a file with no default profile
    EXPECT_NO_THROW(clear_default_profile());

    // Terminate XML workspace
    EXPECT_NO_THROW(terminate());
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
    print_functor_ =
            [](const std::string& profile_id, const std::string& index) -> std::string
            {
                return default_external_unicast_locators::print_kind(profile_id, index);
            };
    set_functor_ = [](const std::string& profile_id, const std::string& kind,
                    const std::string& index) -> void
            {
                default_external_unicast_locators::set_kind(profile_id, kind, index);
            };

    // Call test
    print_set_clear_with_index_test();
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
    print_functor_ =
            [](const std::string& profile_id, const std::string& index) -> std::string
            {
                return default_external_unicast_locators::print_port(profile_id, index);
            };
    set_functor_ = [](const std::string& profile_id, const std::string& kind,
                    const std::string& index) -> void
            {
                default_external_unicast_locators::set_port(profile_id, kind, index);
            };
    clear_functor_ = [](const std::string& profile_id, const std::string& index) -> void
            {
                default_external_unicast_locators::clear_port(profile_id, index);
            };

    // Call test
    print_set_clear_with_index_test();
}

TEST_F(DomainParticipantTests, default_external_unicast_locators_address)
{
    // Test variables
    valid_values_.push_back("localhost");
    valid_values_.push_back("127.0.0.1");
    invalid_values_.push_back("");

    // Initialize functors
    print_functor_ =
            [](const std::string& profile_id, const std::string& index) -> std::string
            {
                return default_external_unicast_locators::print_address(profile_id, index);
            };
    set_functor_ = [](const std::string& profile_id, const std::string& kind,
                    const std::string& index) -> void
            {
                default_external_unicast_locators::set_address(profile_id, kind, index);
            };
    clear_functor_ = [](const std::string& profile_id, const std::string& index) -> void
            {
                default_external_unicast_locators::clear_address(profile_id, index);
            };

    // Call test
    print_set_clear_with_index_test();
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
    print_functor_ =
            [](const std::string& profile_id, const std::string& index) -> std::string
            {
                return default_external_unicast_locators::print_externality(profile_id, index);
            };
    set_functor_ = [](const std::string& profile_id, const std::string& kind,
                    const std::string& index) -> void
            {
                default_external_unicast_locators::set_externality(profile_id, kind, index);
            };
    clear_functor_ = [](const std::string& profile_id, const std::string& index) -> void
            {
                default_external_unicast_locators::clear_externality(profile_id, index);
            };

    // Call test
    print_set_clear_with_index_test();
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
    print_functor_ =
            [](const std::string& profile_id, const std::string& index) -> std::string
            {
                return default_external_unicast_locators::print_cost(profile_id, index);
            };
    set_functor_ = [](const std::string& profile_id, const std::string& kind,
                    const std::string& index) -> void
            {
                default_external_unicast_locators::set_cost(profile_id, kind, index);
            };
    clear_functor_ = [](const std::string& profile_id, const std::string& index) -> void
            {
                default_external_unicast_locators::clear_cost(profile_id, index);
            };

    // Call test
    print_set_clear_with_index_test();
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
    print_functor_ =
            [](const std::string& profile_id, const std::string& index) -> std::string
            {
                return default_external_unicast_locators::print_mask(profile_id, index);
            };
    set_functor_ = [](const std::string& profile_id, const std::string& kind,
                    const std::string& index) -> void
            {
                default_external_unicast_locators::set_mask(profile_id, kind, index);
            };
    clear_functor_ = [](const std::string& profile_id, const std::string& index) -> void
            {
                default_external_unicast_locators::clear_mask(profile_id, index);
            };

    // Call test
    print_set_clear_with_index_test();
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
    print_functor_ =
            [](const std::string& profile_id, const std::string& index) -> std::string
            {
                return builtin::metatraffic_external_unicast_locators::print_kind(profile_id, index);
            };
    set_functor_ = [](const std::string& profile_id, const std::string& kind,
                    const std::string& index) -> void
            {
                builtin::metatraffic_external_unicast_locators::set_kind(profile_id, kind, index);
            };

    // Call test
    print_set_clear_with_index_test();
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
    print_functor_ =
            [](const std::string& profile_id, const std::string& index) -> std::string
            {
                return builtin::metatraffic_external_unicast_locators::print_port(profile_id, index);
            };
    set_functor_ = [](const std::string& profile_id, const std::string& kind,
                    const std::string& index) -> void
            {
                builtin::metatraffic_external_unicast_locators::set_port(profile_id, kind, index);
            };
    clear_functor_ = [](const std::string& profile_id, const std::string& index) -> void
            {
                builtin::metatraffic_external_unicast_locators::clear_port(profile_id, index);
            };

    // Call test
    print_set_clear_with_index_test();
}

TEST_F(DomainParticipantTests, builtin_metatraffic_external_unicast_locators_address)
{
    // Test variables
    valid_values_.push_back("localhost");
    valid_values_.push_back("127.0.0.1");
    invalid_values_.push_back("");

    // Initialize functors
    print_functor_ =
            [](const std::string& profile_id, const std::string& index) -> std::string
            {
                return builtin::metatraffic_external_unicast_locators::print_address(profile_id, index);
            };
    set_functor_ = [](const std::string& profile_id, const std::string& kind,
                    const std::string& index) -> void
            {
                builtin::metatraffic_external_unicast_locators::set_address(profile_id, kind, index);
            };
    clear_functor_ = [](const std::string& profile_id, const std::string& index) -> void
            {
                builtin::metatraffic_external_unicast_locators::clear_address(profile_id, index);
            };

    // Call test
    print_set_clear_with_index_test();
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
    print_functor_ =
            [](const std::string& profile_id, const std::string& index) -> std::string
            {
                return builtin::metatraffic_external_unicast_locators::print_externality(profile_id, index);
            };
    set_functor_ = [](const std::string& profile_id, const std::string& kind,
                    const std::string& index) -> void
            {
                builtin::metatraffic_external_unicast_locators::set_externality(profile_id, kind, index);
            };
    clear_functor_ = [](const std::string& profile_id, const std::string& index) -> void
            {
                builtin::metatraffic_external_unicast_locators::clear_externality(profile_id, index);
            };

    // Call test
    print_set_clear_with_index_test();
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
    print_functor_ =
            [](const std::string& profile_id, const std::string& index) -> std::string
            {
                return builtin::metatraffic_external_unicast_locators::print_cost(profile_id, index);
            };
    set_functor_ = [](const std::string& profile_id, const std::string& kind,
                    const std::string& index) -> void
            {
                builtin::metatraffic_external_unicast_locators::set_cost(profile_id, kind, index);
            };
    clear_functor_ = [](const std::string& profile_id, const std::string& index) -> void
            {
                builtin::metatraffic_external_unicast_locators::clear_cost(profile_id, index);
            };

    // Call test
    print_set_clear_with_index_test();
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
    print_functor_ =
            [](const std::string& profile_id, const std::string& index) -> std::string
            {
                return builtin::metatraffic_external_unicast_locators::print_mask(profile_id, index);
            };
    set_functor_ = [](const std::string& profile_id, const std::string& kind,
                    const std::string& index) -> void
            {
                builtin::metatraffic_external_unicast_locators::set_mask(profile_id, kind, index);
            };
    clear_functor_ = [](const std::string& profile_id, const std::string& index) -> void
            {
                builtin::metatraffic_external_unicast_locators::clear_mask(profile_id, index);
            };

    // Call test
    print_set_clear_with_index_test();
}

/**********************************************************************************************************************/
/* DOMAIN PARTICIPANT TESTS                                                                                           */
/* Builtin::InitialPeers                                                                                              */
/**********************************************************************************************************************/
TEST_F(DomainParticipantTests, builtin_initial_peers_kind)
{
    // Test variables
    valid_values_.push_back("tcp_v4");
    valid_values_.push_back("udp_v6");
    invalid_values_.push_back("shm");

    // Expected results
    print_results_.push_back("tcpv4");
    print_results_.push_back("udpv6");

    // Initialize functors
    print_functor_ =
            [](const std::string& profile_id, const std::string& index) -> std::string
            {
                return builtin::initial_peers::print_kind(profile_id, index);
            };
    set_functor_ = [](const std::string& profile_id, const std::string& kind,
                    const std::string& index) -> void
            {
                builtin::initial_peers::set_kind(profile_id, kind, index);
            };

    // Call test
    print_set_clear_with_index_test();
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
    print_functor_ =
            [](const std::string& profile_id, const std::string& index) -> std::string
            {
                return builtin::initial_peers::print_port(profile_id, index);
            };
    set_functor_ = [](const std::string& profile_id, const std::string& kind,
                    const std::string& index) -> void
            {
                builtin::initial_peers::set_port(profile_id, kind, index);
            };
    clear_functor_ = [](const std::string& profile_id, const std::string& index) -> void
            {
                builtin::initial_peers::clear_port(profile_id, index);
            };

    // Call test
    print_set_clear_with_index_test();
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
    print_functor_ =
            [](const std::string& profile_id, const std::string& index) -> std::string
            {
                return builtin::initial_peers::print_physical_port(profile_id, index);
            };
    set_functor_ = [](const std::string& profile_id, const std::string& kind,
                    const std::string& index) -> void
            {
                builtin::initial_peers::set_physical_port(profile_id, kind, index);
            };
    clear_functor_ = [](const std::string& profile_id, const std::string& index) -> void
            {
                builtin::initial_peers::clear_physical_port(profile_id, index);
            };

    // Call test
    print_set_clear_with_index_test();
}

TEST_F(DomainParticipantTests, builtin_initial_peers_address)
{
    // Test variables
    valid_values_.push_back("localhost");
    valid_values_.push_back("127.0.0.1");
    invalid_values_.push_back("");

    // Initialize functors
    print_functor_ =
            [](const std::string& profile_id, const std::string& index) -> std::string
            {
                return builtin::initial_peers::print_address(profile_id, index);
            };
    set_functor_ = [](const std::string& profile_id, const std::string& kind,
                    const std::string& index) -> void
            {
                builtin::initial_peers::set_address(profile_id, kind, index);
            };
    clear_functor_ = [](const std::string& profile_id, const std::string& index) -> void
            {
                builtin::initial_peers::clear_address(profile_id, index);
            };

    // Call test
    print_set_clear_with_index_test();
}

TEST_F(DomainParticipantTests, builtin_initial_peers_unique_lan_id)
{
    // Test variables
    valid_values_.push_back("localhost");
    valid_values_.push_back("127.0.0.1");
    invalid_values_.push_back("");

    // Initialize functors
    print_functor_ =
            [](const std::string& profile_id, const std::string& index) -> std::string
            {
                return builtin::initial_peers::print_unique_lan_id(profile_id, index);
            };
    set_functor_ = [](const std::string& profile_id, const std::string& kind,
                    const std::string& index) -> void
            {
                builtin::initial_peers::set_unique_lan_id(profile_id, kind, index);
            };
    clear_functor_ = [](const std::string& profile_id, const std::string& index) -> void
            {
                builtin::initial_peers::clear_unique_lan_id(profile_id, index);
            };

    // Call test
    print_set_clear_with_index_test();
}

TEST_F(DomainParticipantTests, builtin_initial_peers_wan_address)
{
    // Test variables
    valid_values_.push_back("127.0.0.1");
    valid_values_.push_back("192.168.1.2");
    invalid_values_.push_back("localhost");

    // Initialize functors
    print_functor_ =
            [](const std::string& profile_id, const std::string& index) -> std::string
            {
                return builtin::initial_peers::print_wan_address(profile_id, index);
            };
    set_functor_ = [](const std::string& profile_id, const std::string& kind,
                    const std::string& index) -> void
            {
                builtin::initial_peers::set_wan_address(profile_id, kind, index);
            };
    clear_functor_ = [](const std::string& profile_id, const std::string& index) -> void
            {
                builtin::initial_peers::clear_wan_address(profile_id, index);
            };

    // Call test
    print_set_clear_with_index_test();
}

int main(
        int argc,
        char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
