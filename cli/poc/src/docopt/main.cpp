#include <iostream>
#include <regex>

#include <docopt.h>

/*
 * Second level parsing function
 * */

static const char set_USAGE[] =
        R"(SET.

    Usage:
      set <where> <what> ...
      set (-h | --help)

    Options:
      -h --help     Show this screen.
)";

int set_verb(
        int argc,
        char** argv)
{
    std::map<std::string, docopt::value> args_set = docopt::docopt(
        set_USAGE,
        { argv + 1, argv + argc },
        true,                                                               // show help if requested
        {},
        true);

    for (auto const& arg : args_set)
    {
        std::cout << arg.first << ": " << arg.second << std::endl;
    }

    // Parsing of the contents in the <where> field, using regular expressions

    std::string field = args_set["<where>"].asString();

    std::regex dot_pattern("[^\\.]+");
    std::smatch match;

    // Parse the fields separated by dots
    std::vector<std::string> field_parts;

    while (std::regex_search(field, match, dot_pattern))
    {
        field_parts.push_back(match[0]);
        field = match.suffix();
    }

    // Print the individual fields
    for (auto part : field_parts)
    {
        std::cout << "Separated by dot: " << part << std::endl;

        std::regex brackets_pattern("\\[([^\\]]*)\\]");

        if (std::regex_search(part, match, brackets_pattern))
        {
            // Here, match[1] will store the content inside "[]", or an empty string if there is no content between the brackets
            std::cout << "Between-brackets match found: " << match[1] << std::endl;
        }
    }

    return 0;
}

// *******************************************************************************************
// ************************** Proof Of Concept test for docopt library ***********************
// *******************************************************************************************

/*
 * This PoC tests how could an example of input command could be effectively parsed, using cxxopts library.
 * The command line inputs tested are:
 * - ./poc_docopt file.xml set datareader["datareader_profile_name"].locators.unicast[] udpv4
 * - ./poc_docopt file.xml set participant["participant_profile_name"].locators.default_unicast[-1].physical_port 5100
 * - ./poc_docopt file.xml set participant["participant_profile_name"].locators.default_unicast[].type tcpv4
 * - ./poc_docopt file.xml set participant["participant_profile_name"].locators.default_unicast[] tcpv6 ::1 8844
 * There are two parsing levels:
 * - The first "global" parser locates the file name and the verb type.
 * - The second parser level is the verb related parser. In this case, the "set" parser, locates the "where to add/edit" and "what to add/edit"
 * The "dot" parser here is performed using regular expressions.
 * The parsing of the "[]" operators is performed using regular expressions.
 * The help message can be printed automatically when typing help flags.
 * To print the help message with "help" verbs instead of flags, the print should be done manually with an std::cout.
 * */

static const char USAGE[] =
        R"(PoC docopt.

    Usage:
      poc_docopt [--version] [--help] <file_name> <verb> [<args>...]
      poc_docopt (-h | --help | --version)

    Options:
      -h --help     Show this screen.
      --version     Show version.
    
    The allowed <verb> commands are:
      set       Sets
      validate  Validates
      print     Prints
      query     Answers
      clear     Clears
)";

int main(
        int argc,
        char** argv)
{
    std::map<std::string, docopt::value> args = docopt::docopt(
        USAGE,
        { argv + 1, argv + argc },
        true,                                                         // show help if requested
        "poc_docopt 1.0",                                             // version string
        true);                                                        // options_first

    for (auto const& arg : args)
    {
        std::cout << arg.first << ": " << arg.second << std::endl;
    }

    if (args["<verb>"].asString() == "set")
    {
        std::cout << "set verb!" << std::endl;
        set_verb(argc - 2, argv + 2);
    }
    else
    {
        std::cout << args["<verb>"].asString() << " verb not supported!!!" << std::endl;
        std::cout << USAGE << std::endl;
        exit(1);
    }

    return 0;
}
