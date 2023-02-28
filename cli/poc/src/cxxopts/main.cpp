#include <iostream>
#include <unordered_map>

#include <cxxopts.hpp>

std::unordered_map<std::string, std::string> verbs_list =
{
    {"help", "Helps"},

    {"set", "Sets"},

    {"validate", "Validates"},

    {"print", "Prints"},

    {"query", "Answers"},

    {"clear", "Clears"}
};

int set_verb(
        cxxopts::Options global_parser,
        int argc,
        char** argv)
{

    // Second level parser
    cxxopts::Options set_parser("<set> options", "<VERB>=set help description");

    set_parser.add_options("set")
        ("where", "Element to set", cxxopts::value<std::string>())
        ("what", "Value to set", cxxopts::value<std::vector<std::string>>());

    set_parser.parse_positional({"where", "what"});
    set_parser.allow_unrecognised_options();

    // Parsing
    auto set_result = set_parser.parse(argc, argv);

    // Case evaluation using argc
    // The commands that are used in this PoC, could have either one or three elements on the "what" field
    // This corresponds to this numbers "3" and "5"
    if (3 == argc || 5 == argc)
    {
        if (set_result.count("where"))
        {
            std::string where = set_result["where"].as<std::string>();

            // Third level parser
            // CXXOPTS_VECTOR_DELIMITER definition has been modified in cxxopts library,
            // to identify the delimiter as '.' instead of ',' (default value).
            cxxopts::Options where_parser("<where> options", "<VERB>=set help description");

            where_parser.add_options("set")
                ("where", "Element to set", cxxopts::value<std::vector<std::string>>());

            where_parser.parse_positional({"where"});
            where_parser.allow_unrecognised_options();

            int argc_indexer;
            if (3 == argc)
            {
                argc_indexer = 1;
            }
            else
            {
                argc_indexer = 3;
            }
            auto where_result = where_parser.parse(argc - argc_indexer, argv);

            std::cout << "Debug: \"where\" content:" << std::endl;
            for (auto content : where_result["where"].as<std::vector<std::string>>())
            {
                std::cout << content << std::endl;
            }
        }
        else
        {
            std::cout << "No \"where\" parsed" << std::endl;
        }

        if (set_result.count("what"))
        {
            std::vector<std::string> what = set_result["what"].as<std::vector<std::string>>();
            std::cout << "Debug: \"what\" content:" << std::endl;
            for (auto content : what)
            {
                std::cout << content << std::endl;
            }
        }
        else
        {
            std::cout << "No \"what\" parsed" << std::endl;
        }

        if (3 == argc)
        {
            // Just one argument in "what"
            std::cout << "Debug: \"what\" has one argument" << std::endl;
            // Corresponds to command lines as theese examples:
            // fastddsqosprof file.xml set datareader["datareader_profile_name"].locators.unicast[] udpv4
            // fastddsqosprof file.xml set participant["participant_profile_name"].locators.default_unicast[].type tcpv4
            // fastddsqosprof file.xml set participant["participant_profile_name"].locators.default_unicast[-1].port 7400
            // ...
        }
        else if (5 == argc)
        {
            // Three arguments in "what"
            std::cout << "Debug: \"what\" has three arguments" << std::endl;
            // Corresponds to command lines as this example:
            // fastddsqosprof file.xml set participant["participant_profile_name"].locators.default_unicast[] tcpv6 ::1 8844
        }
    }
    else
    {
        // If number of arguments is different from 2 and 4 (3 and 5), the "what" content is not correct, so: print help
        std::cout << global_parser.help({ "global", "" }) << std::endl;
        std::cout << set_parser.help({ "set", "" }) << std::endl;
        exit(1);
    }

    return 0;
}

// *******************************************************************************************
// ************************** Proof Of Concept test for cxxopts library **********************
// *******************************************************************************************

/*
 * This PoC tests how could an example of input command could be effectively parsed, using cxxopts library.
 * The command line inputs tested are:
 * - ./poc_cxxopts file.xml set datareader["datareader_profile_name"].locators.unicast[] udpv4
 * - ./poc_cxxopts file.xml set participant["participant_profile_name"].locators.default_unicast[-1].physical_port 5100
 * - ./poc_cxxopts file.xml set participant["participant_profile_name"].locators.default_unicast[].type tcpv4
 * - ./poc_cxxopts file.xml set participant["participant_profile_name"].locators.default_unicast[] tcpv6 ::1 8844
 * There are three parsing levels:
 * - The first "global" parser locates the file name and the verb type.
 * - The second parser level is the verb related parser. In this case, the "set" parser, locates the "where to add/edit" and "what to add/edit"
 * - A third parser level, the "dot" parser, takes the "where to add/edit" and returns a vector of strings, whose elements are the
 *   different dot-separated elements of this field. To do this, the definition CXXOPTS_VECTOR_DELIMITER is modified to '.' value.
 * - The parsing of the "[]" operators is not performed in this PoC, as the cxxopts library does not provide any mechanism to do so. Thus,
 *   this work would need to be done afterwards.
 * */

int main(
        int argc,
        char** argv)
{

    // First level parser
    cxxopts::Options global_parser("poc_cxxopts",
            "PoC for cxxopts argument parsing library for Fast DDS QoS Profiles Manager");

    // Options
    global_parser.custom_help("<-h, help>");
    global_parser.positional_help("<VERB> <sub_args>");
    global_parser.show_positional_help();

    // Fields expected in command
    global_parser.add_options("global")
        ("file", "File to edit/create", cxxopts::value<std::string>())
        ("verb", "Command verb for the operation to perform on the XML file", cxxopts::value<std::string>())
        ("rest", "The rest of the arguments", cxxopts::value<std::vector<std::string>>());

    global_parser.parse_positional({"file", "verb", "rest"});
    global_parser.allow_unrecognised_options();

    // Parsing
    auto result = global_parser.parse(argc, argv);

    // "file" field
    if (result.count("file"))
    {
        std::cout << "Debug print: file = " << result["file"].as<std::string>() << std::endl;
    }

    // "verb" field
    if (result.count("verb"))
    {
        std::cout << "Debug print: verb = " << result["verb"].as<std::string>() << std::endl;
    }

    // Global help print
    if (result["file"].as<std::string>() == "help" || result.count("verb") == 0 ||
            result["verb"].as<std::string>() == "help")
    {
        std::cout << global_parser.help({ "global", "" }) << std::endl;
        std::vector<std::string> keys;
        for (auto& c : verbs_list)
        {
            keys.push_back(c.first);
        }

        std::cerr << "Supported values for <VERB>: " << std::endl;
        for (auto& k : keys)
        {
            std::cout << "  " << k << std::endl;
        }
        std::cout << std::endl;
        exit(0);
    }


    // "verb" switch/case
    if (result["verb"].as<std::string>() == "set")
    {
        // Call to the set verb parser
        set_verb(global_parser, argc - 2, argv + 2); // That 2 is the number of elements already read (file and verb).
        exit(0);
    }
    // else if (<rest of verbs>)
    else
    {
        // Not recognized verb
        std::cout << global_parser.help({ "global", "" }) << std::endl;
        exit(1);
    }

    return 0;
}
