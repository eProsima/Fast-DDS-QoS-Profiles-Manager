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

#include <domain_participant/builtin/discovery_config/discovery_servers/DiscoveryServers.hpp>

#include <string>
#include <vector>

#include <exception/Exception.hpp>

namespace eprosima {
namespace qosprof {
namespace domain_participant {
namespace builtin {
namespace discovery_config {
namespace discovery_servers {

std::string print(
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

std::vector<std::string> keys(
        const std::string& xml_file,
        const std::string& profile_id)
{
    throw Unsupported("Unsupported");
}

void clear(
        const std::string& xml_file,
        const std::string& profile_id,
        const std::string& prefix)
{
    throw Unsupported("Unsupported");
}

} // discovery_servers
} // discovery_config
} // builtin
} // domain_participant
} // qosprof
} // eprosima

